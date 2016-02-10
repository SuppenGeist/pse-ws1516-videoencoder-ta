#include "FilterTab.h"

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QString>
#include <QPushButton>
#include <QListView>
#include <QScrollArea>
#include <QStringListModel>
#include <QSpacerItem>
#include <QItemSelection>
#include <QDebug>
#include <QStringList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>

#include "FrameView.h"
#include "PlayerControlPanel.h"
#include "PreviewControlPanel.h"
#include "FilterContainerTab.h"
#include "YuvFileOpenDialog.h"
#include "YuvInfoDialog.h"
#include "VideoPlayer.h"
#include "Timer.h"
#include "filter_boxes/FilterConfigurationBox.h"
#include "filter_boxes/PlainFilterBox.h"

#include "../model/YuvVideo.h"
#include "../model/FilterList.h"

#include "../undo_framework/UndoStack.h"
#include "../undo_framework/LoadFilterVideo.h"
#include "../undo_framework/FilterReset.h"

#include "../memento/FilterTabMemento.h"

#include "../utility/VideoConverter.h"
#include "../utility/FilterApplier.h"

#include "../model/filters/Filter.h"
#include "../model/filters/BlurFilter.h"
#include "../model/filters/BorderFilter.h"
#include "../model/filters/BrightnessFilter.h"
#include "../model/filters/ColorbalanceFilter.h"
#include "../model/filters/ContrastFilter.h"
#include "../model/filters/EdgeFilter.h"
#include "../model/filters/GrayscaleFilter.h"
#include "../model/filters/GridFilter.h"
#include "../model/filters/MirrorFilter.h"
#include "../model/filters/NegativeFilter.h"
#include "../model/filters/NoiseFilter.h"
#include "../model/filters/PosterFilter.h"
#include "../model/filters/RectangleFilter.h"
#include "../model/filters/RGBFilter.h"
#include "../model/filters/RotationFilter.h"
#include "../model/filters/SaturationFilter.h"
#include "../model/filters/ScaleFilter.h"
#include "../model/filters/SepiaFilter.h"
#include "../model/filters/SharpnessFilter.h"
#include "../model/filters/VintageFilter.h"

extern "C" {
#include <libavutil/pixfmt.h>
}

GUI::FilterTab::FilterTab(QWidget *parent):QFrame(parent),rawVideo_(nullptr) {
    createUi();
    connectAtions();

    initPlayer();
    initFilterList();
}

std::unique_ptr<Memento::FilterTabMemento> GUI::FilterTab::getMemento()
{
    auto memento=std::make_unique<Memento::FilterTabMemento>();

    memento->setRawVideo(rawVideo_);
    memento->setFilterList(*filterlist_);
    memento->setIsPreviewShown(PreviewControlPanel_->isVisible());

    return std::move(memento);
}

void GUI::FilterTab::restore(Memento::FilterTabMemento *memento)
{
    setRawVideo(memento->getRawVideo());
    setFilterList(memento->getFilterList());
    if(memento->isPreviewShow()) {
        showFilterPreview();
    }else {
        showRawVideo();
    }
}

void GUI::FilterTab::setRawVideo(Model::YuvVideo *rawVideo)
{
    player_->stop();
    if(rawVideo) {
        player_->setVideo(&rawVideo->getVideo());
    }
    else {
        player_->setVideo(nullptr);
    }

    rawVideo_=rawVideo;

    resetFilters();
}

void GUI::FilterTab::showRawVideo()
{
    if(PreviewControlPanel_->isVisible()) {
        v_player_->removeWidget(PreviewControlPanel_);
        v_player_->addWidget(playerControlPanel_);
    }

    PreviewControlPanel_->hide();
    playerControlPanel_->show();

    player_->setMasterControlPanel(*playerControlPanel_);
    if(rawVideo_) {
        player_->setVideo(&rawVideo_->getVideo());
    }
    else {
        player_->setVideo(nullptr);
    }
    playerControlPanel_->updateUi();
}

void GUI::FilterTab::showFilterPreview()
{
    if(playerControlPanel_->isVisible()) {
        v_player_->removeWidget(playerControlPanel_);
        v_player_->addWidget(PreviewControlPanel_);
    }

    playerControlPanel_->hide();
    PreviewControlPanel_->show();

    player_->setMasterControlPanel(*PreviewControlPanel_);
    player_->setVideo(filteredPreviewFrames_.get());
    PreviewControlPanel_->updateUi();
}

void GUI::FilterTab::updateFilterPreview()
{
    if(!rawVideo_)
        return;

    if(!originalPreviewFrames_.get()||originalPreviewFrames_->getNumberOfFrames()==0) {
        calculatePreviewFrames();
    }

    auto changeVideo=PreviewControlPanel_->isVisible();

    if(changeVideo)
        player_->setVideo(nullptr);

    filteredPreviewFrames_=std::make_unique<Model::Video>();

    Utility::FilterApplier applier(*filterlist_,rawVideo_->getWidth(),rawVideo_->getHeight(),AV_PIX_FMT_RGB24);

    Model::AVVideo filteredVideo;
    applier.applyToVideo(filteredVideo,*originalPreviewFrames_);

    filteredPreviewFrames_=Utility::VideoConverter::convertAVVideoToVideo(filteredVideo);

    if(changeVideo)
        player_->setVideo(filteredPreviewFrames_.get());
}

Model::Filter *GUI::FilterTab::appendFilter(QString filtername)
{
    if(!rawVideo_)
        return nullptr;

    if(filterlist_->getSize()==0) {
        showFilterPreview();
    }

    auto filter=filterlist_->appendFilter(filtername);

    auto model=model_filterlist_->stringList();
    model.append(filtername+" filter");
    model_filterlist_->setStringList(model);

    updateFilterPreview();

    return filter;
}

std::unique_ptr<Model::Filter> GUI::FilterTab::removeFilter(std::size_t index)
{
    if(index>=filterlist_->getSize())
        return std::unique_ptr<Model::Filter>();

    auto model=model_filterlist_->stringList();
    model.removeAt(index);
    model_filterlist_->setStringList(model);

    auto filter=filterlist_->removeFilter(index);

    if(filterlist_->getSize()==0) {
        showRawVideo();
        currentFilterOptionsBox_->hide();
    }
    else {
        updateFilterPreview();
        QModelIndex index(model_filterlist_->index(static_cast<int>(filterlist_->getSize()-1),0));
        list_filterlist_->setCurrentIndex(index);
    }

    return std::move(filter);
}

Model::FilterList *GUI::FilterTab::getFilterList()
{
    return filterlist_.get();
}

void GUI::FilterTab::setFilterList(std::unique_ptr<Model::FilterList> filterlist)
{
    resetFilters();
    filterlist_=std::move(filterlist);
    QStringList model;
    for(std::size_t i=0;i<filterlist_->getSize();i++) {
        model<<filterlist_->getFilter(i)->getName()+" filter";
    }
    model_filterlist_->setStringList(model);
    updateFilterPreview();
}

void GUI::FilterTab::resetFilters()
{
    initFilterList();
    model_filterlist_->removeRows(0,model_filterlist_->rowCount());
    originalPreviewFrames_.release();
    showRawVideo();
}

void GUI::FilterTab::up()
{

}

void GUI::FilterTab::down()
{

}

void GUI::FilterTab::remove()
{

}

void GUI::FilterTab::load()
{
    YuvFileOpenDialog fileOpenDiag(this);

    int result=fileOpenDiag.exec();

    if(result!=QDialog::Accepted)
        return;

    auto path=fileOpenDiag.getFilename();

    if(path.isEmpty())
        return;

    std::unique_ptr<YuvInfoDialog> infoDialog;
    bool inputIsValid=true;
    do {
        infoDialog=std::make_unique<YuvInfoDialog>(this);

        inputIsValid=true;

        result=infoDialog->exec();

        if(result!=QDialog::Accepted)
            return;

        if(infoDialog->getFps()<=0||infoDialog->getHeight()<=0||infoDialog->getWidth()<=0) {
            inputIsValid=false;
        }

    }while(!inputIsValid);

    auto video=std::make_unique<Model::YuvVideo>(path,infoDialog->getPixelSheme(),infoDialog->getCompression(),infoDialog->getWidth(),infoDialog->getHeight(),infoDialog->getFps());
    auto command=new UndoRedo::LoadFilterVideo(*this,std::move(video),getMemento());

    UndoRedo::UndoStack::getUndoStack().push(command);
}

void GUI::FilterTab::apply()
{

}

void GUI::FilterTab::save()
{

}

void GUI::FilterTab::saveConfiguration()
{

}

void GUI::FilterTab::loadConfiguration()
{

}

void GUI::FilterTab::reset()
{
    if(filterlist_->getSize()==0)
        return;

    auto command=new UndoRedo::FilterReset(*this,std::make_unique<Model::FilterList>(*filterlist_));
    UndoRedo::UndoStack::getUndoStack().push(command);
}

void GUI::FilterTab::listSelectionChanged(QItemSelection selection)
{
    if(selection.indexes().isEmpty())
        return;

    auto filter=filterlist_->getFilter(selection.indexes().first().row());

    h_filterOptions_->removeWidget(currentFilterOptionsBox_);
    currentFilterOptionsBox_->hide();
    delete currentFilterOptionsBox_;

    auto filterbox=FilterConfigurationBox::CreateConfigurationBox(*this,*filter);
    auto ptr=filterbox.release();
    currentFilterOptionsBox_=ptr;

    h_filterOptions_->addWidget(currentFilterOptionsBox_);
    h_filterOptions_->removeItem(spacer_filterOptions_);
    h_filterOptions_->addItem(spacer_filterOptions_);
}

void GUI::FilterTab::createUi()
{
    createButtons();
    createListView();
    createVideoPlayer();
    createFilterTabs();

    //Start building ui
    QVBoxLayout* v_content=new QVBoxLayout;
    v_content->addSpacing(10);

    QHBoxLayout* h_list_button_player=new QHBoxLayout;

    h_list_button_player->addWidget(list_filterlist_);
    h_list_button_player->addSpacing(20);

    QVBoxLayout* v_buttons=new QVBoxLayout;
    v_buttons->addWidget(button_load_);
    v_buttons->addWidget(button_apply_);
    v_buttons->addWidget(button_save_);
    v_buttons->addSpacing(20);
    v_buttons->addWidget(button_up_);
    v_buttons->addWidget(button_down_);
    v_buttons->addWidget(button_remove_);
    v_buttons->addSpacing(20);
    v_buttons->addWidget(button_loadConf_);
    v_buttons->addWidget(button_saveConf_);
    v_buttons->addSpacing(20);
    v_buttons->addWidget(button_reset_);

    QSpacerItem* spacer_buttons=new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::MinimumExpanding);
    v_buttons->addSpacerItem(spacer_buttons);

    h_list_button_player->addLayout(v_buttons);
    h_list_button_player->addSpacing(30);

    QSpacerItem* spacer_player1=new QSpacerItem(0,0,QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    h_list_button_player->addSpacerItem(spacer_player1);

    v_player_=new QVBoxLayout;
    v_player_->addWidget(frameView_);
    v_player_->addWidget(playerControlPanel_);

    h_list_button_player->addLayout(v_player_,1);

    QSpacerItem* spacer_player2=new QSpacerItem(0,0,QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    h_list_button_player->addSpacerItem(spacer_player2);

    v_content->addLayout(h_list_button_player);

    v_content->addSpacing(20);

    v_content->addWidget(tab_filtertabs_);

    setLayout(v_content);

    setObjectName("filterTab");
    setStyleSheet("QFrame#filterTab {"
                  "background-color:rgb(235,235,235);"
                  "}"
    );
}

void GUI::FilterTab::createButtons()
{
    button_apply_=new QPushButton(tr("Apply to video"));
    button_down_=new QPushButton(tr("Filter down"));
    button_loadConf_=new QPushButton(tr("Load configuration"));
    button_load_=new QPushButton(tr("Load video"));
    button_remove_=new QPushButton(tr("Remove filter"));
    button_reset_=new QPushButton(tr("Reset"));
    button_saveConf_=new QPushButton(tr("Save configuration"));
    button_save_=new QPushButton(tr("Save video"));
    button_up_=new QPushButton(tr("Filter up"));

    button_apply_->setFlat(true);
    button_down_->setFlat(true);
    button_loadConf_->setFlat(true);
    button_load_->setFlat(true);
    button_remove_->setFlat(true);
    button_reset_->setFlat(true);
    button_saveConf_->setFlat(true);
    button_save_->setFlat(true);
    button_up_->setFlat(true);

    QString styleSheet_buttonGroup("QPushButton {"
                                    "color: rgb(255, 255, 255);"
                                    "border-color: rgb(69, 62, 62);"
                                    "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c);"
                                    "background: rgb(140, 140, 140);"
                                    "border-width: 1px;"
                                    "border-color:rgb(0, 0, 0);"
                                    "border-style: outset;"
                                    "border-radius: 7;"
                                    "padding: 3px;"
                                    "font-size: 18px;"
                                    "padding-left: 5px;"
                                    "padding-right: 5px;"
                                    "}"
                                    "QPushButton:pressed {"
                                    "background-color: rgb(69, 62, 62);"
                                    "border-style: inset;"
                                    "}"
    );

    button_apply_->setStyleSheet(styleSheet_buttonGroup);
    button_down_->setStyleSheet(styleSheet_buttonGroup);
    button_loadConf_->setStyleSheet(styleSheet_buttonGroup);
    button_load_->setStyleSheet(styleSheet_buttonGroup);
    button_remove_->setStyleSheet(styleSheet_buttonGroup);
    button_reset_->setStyleSheet(styleSheet_buttonGroup);
    button_saveConf_->setStyleSheet(styleSheet_buttonGroup);
    button_save_->setStyleSheet(styleSheet_buttonGroup);
    button_up_->setStyleSheet(styleSheet_buttonGroup);
}

void GUI::FilterTab::createListView()
{
    list_filterlist_=new QListView;
    list_filterlist_->setFixedWidth(250);
    list_filterlist_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    list_filterlist_->setStyleSheet("font-size:17px;");

    model_filterlist_=new QStringListModel;
    list_filterlist_->setModel(model_filterlist_);
}

void GUI::FilterTab::createVideoPlayer()
{
    frameView_=new FrameView;
    frameView_->setMaximumWidth(600);
    frameView_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

    playerControlPanel_=new PlayerControlPanel;
    playerControlPanel_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
    playerControlPanel_->setMaximumWidth(600);

    PreviewControlPanel_=new PreviewControlPanel;
    PreviewControlPanel_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
    PreviewControlPanel_->setMaximumWidth(600);
}

void GUI::FilterTab::createFilterTabs()
{
    tab_filtertabs_=new QTabWidget;

    FilterContainerTab* filterTab=new FilterContainerTab;
    filterTab->setParentTab(*this);

    FilterContainerTab* artefactsTab=new FilterContainerTab;
    artefactsTab->setParentTab(*this);

    //Add all filters
    filterTab->addFilter(Model::BlurFilter::FILTERNAME);
    filterTab->addFilter(Model::BrightnessFilter::FILTERNAME);
    filterTab->addFilter(Model::ColorbalanceFilter::FILTERNAME);
    filterTab->addFilter(Model::ContrastFilter::FILTERNAME);
    filterTab->addFilter(Model::EdgeFilter::FILTERNAME);
    filterTab->addFilter(Model::GrayscaleFilter::FILTERNAME);
    filterTab->addFilter(Model::MirrorFilter::FILTERNAME);
    filterTab->addFilter(Model::NegativeFilter::FILTERNAME);
    filterTab->addFilter(Model::NoiseFilter::FILTERNAME);
    filterTab->addFilter(Model::PosterFilter::FILTERNAME);
    filterTab->addFilter(Model::RGBFilter::FILTERNAME);
    filterTab->addFilter(Model::RotationFilter::FILTERNAME);
    filterTab->addFilter(Model::SaturationFilter::FILTERNAME);
    filterTab->addFilter(Model::ScaleFilter::FILTERNAME);
    filterTab->addFilter(Model::SepiaFilter::FILTERNAME);
    filterTab->addFilter(Model::SharpnessFilter::FILTERNAME);
    filterTab->addFilter(Model::VintageFilter::FILTERNAME);

    //Add all artefacts
    artefactsTab->addFilter(Model::BorderFilter::FILTERNAME);
    artefactsTab->addFilter(Model::GridFilter::FILTERNAME);
    artefactsTab->addFilter(Model::RectangleFilter::FILTERNAME);

    QScrollArea* scrollArea_filters=new QScrollArea;
    scrollArea_filters->setWidget(filterTab);
    scrollArea_filters->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scrollArea_filters->setFixedHeight(245);

    QScrollArea* scrollArea_artefacts=new QScrollArea;
    scrollArea_artefacts->setWidget(artefactsTab);
    scrollArea_artefacts->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scrollArea_artefacts->setFixedHeight(245);

    QFrame* optionsWidget=new QFrame;

    optionsWidget->setObjectName("OptWid");
    optionsWidget->setStyleSheet("QFrame#OptWid {"
                                 "background-color:rgb(235,235,235);"
                                 "}");

    optionsWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    h_filterOptions_=new QHBoxLayout;

    QSpacerItem* spacer=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    h_filterOptions_->addSpacerItem(spacer);
    currentFilterOptionsBox_=new PlainFilterBox;
    h_filterOptions_->addWidget(currentFilterOptionsBox_);
    spacer_filterOptions_=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    h_filterOptions_->addSpacerItem(spacer_filterOptions_);

    optionsWidget->setLayout(h_filterOptions_);

    tab_filtertabs_->addTab(scrollArea_filters,tr("Filters"));
    tab_filtertabs_->addTab(scrollArea_artefacts,tr("Artefacts"));
    tab_filtertabs_->addTab(optionsWidget,tr("Filter options"));
    tab_filtertabs_->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
}

void GUI::FilterTab::connectAtions()
{
    connect(button_apply_,SIGNAL(clicked()),this,SLOT(apply()));
    connect(button_down_,SIGNAL(clicked()),this,SLOT(down()));
    connect(button_load_,SIGNAL(clicked()),this,SLOT(load()));
    connect(button_loadConf_,SIGNAL(clicked()),this,SLOT(loadConfiguration()));
    connect(button_remove_,SIGNAL(clicked()),this,SLOT(remove()));
    connect(button_reset_,SIGNAL(clicked()),this,SLOT(reset()));
    connect(button_save_,SIGNAL(clicked()),this,SLOT(save()));
    connect(button_saveConf_,SIGNAL(clicked()),this,SLOT(saveConfiguration()));
    connect(button_up_,SIGNAL(clicked()),this,SLOT(up()));
    connect(list_filterlist_->selectionModel(),SIGNAL(selectionChanged(QItemSelection,
                                                                       QItemSelection)),this,SLOT(listSelectionChanged(QItemSelection)));
}

void GUI::FilterTab::initPlayer()
{
    player_=std::make_unique<VideoPlayer>();
    player_->addView(*frameView_);
    player_->setTimer(std::make_shared<Timer>());
    playerControlPanel_->setMasterVideoPlayer(*player_);
    PreviewControlPanel_->setMasterVideoPlayer(*player_);

    player_->setMasterControlPanel(*playerControlPanel_);
}

void GUI::FilterTab::initFilterList()
{
    filterlist_=std::make_unique<Model::FilterList>();
}

void GUI::FilterTab::calculatePreviewFrames()
{
    if(!rawVideo_)
        return;

    originalPreviewFrames_=std::make_unique<Model::AVVideo>();

    static std::size_t numberOfPreviewFrames=5;

    auto videoFramecount=rawVideo_->getVideo().getNumberOfFrames();
    std::size_t stepsize=videoFramecount/numberOfPreviewFrames;

    if(videoFramecount<numberOfPreviewFrames) {
        numberOfPreviewFrames=videoFramecount;
        stepsize=1;
    }

    for(std::size_t i=0; i<numberOfPreviewFrames; i++) {
        auto frame=Utility::VideoConverter::convertQImageToAVFrame(*rawVideo_->getVideo().getFrame(i*stepsize));
        originalPreviewFrames_->appendFrame(frame);
    }
}
