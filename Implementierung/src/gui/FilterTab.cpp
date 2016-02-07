#include "FilterTab.h"

#include <string>

#include <QWidget>
#include <QFrame>
#include <QModelIndex>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QString>
#include <QListView>
#include <QFileDialog>
#include <QSpacerItem>
#include <QTimer>
#include <QStringListModel>
#include <QTabWidget>
#include <QStringList>
#include <QModelIndexList>
#include <QScrollArea>

#include "../memento/FilterTabMemento.h"
#include "../model/FilterList.h"
#include "../utility/FilterApplier.h"
#include "../model/filters/Filter.h"
#include "../model/YuvVideo.h"
#include "FrameView.h"
#include "PlayerControlPanel.h"
#include "PreviewControlPanel.h"
#include "FilterContainerTab.h"
#include "../utility/VideoConverter.h"
#include "YuvFileOpenDialog.h"
#include "YuvInfoDialog.h"
#include "../undo_framework/UndoStack.h"
#include "../undo_framework/LoadFilterVideo.h"
#include "../undo_framework/RemoveFilter.h"
#include "../undo_framework/MoveFilterUp.h"
#include "../undo_framework/MoveFilterDown.h"
#include "VideoPlayer.h"
#include "../undo_framework/LoadFilterconfig.h"
#include "Timer.h"
#include "../utility/FilterConfigurationSaver.h"
#include "../utility/FilterConfigurationLoader.h"
#include "../model/AVVideo.h"

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
#include "../model/filters/ZoomFilter.h"

extern "C" {
#include <libavutil/pixfmt.h>
}

GUI::FilterTab::FilterTab(QWidget* parent):QFrame(parent),isPreviewShown_(false) {
	createUi();
	connectActions();

	player_=std::make_unique<VideoPlayer>();
	player_->addView(*frameView_);
	player_->setTimer(std::make_shared<Timer>());
	playerPanel_->setMasterVideoPlayer(*player_);
	previewPanel_->setMasterVideoPlayer(*player_);
	player_->setMasterControlPanel(*playerPanel_);

	filterList_=std::make_unique<Model::FilterList>();
}


std::unique_ptr<Memento::FilterTabMemento> GUI::FilterTab::getMemento() {
	return std::make_unique<Memento::FilterTabMemento>();
}

void GUI::FilterTab::restore(Memento::FilterTabMemento &memento) {
}

Model::Filter* GUI::FilterTab::addFilter(QString filtername) {
	if(!rawVideo_.get())
		return nullptr;

	filterList_->appendFilter(filtername);
	auto modelList=model_list_->stringList();
	modelList.append(filtername+" filter");
	model_list_->setStringList(modelList);

	updatePreview();

	return filterList_->getFilter(filterList_->getSize()-1);
}

Model::FilterList *GUI::FilterTab::getFilterList() {
    return filterList_.get();
}

std::unique_ptr<Model::FilterList> GUI::FilterTab::releaseFilterList()
{
    return std::move(std::move(filterList_));
}


void GUI::FilterTab::connectActions() {
	connect(button_apply_,SIGNAL(clicked()),this,SLOT(apply()));
	connect(button_down_,SIGNAL(clicked()),this,SLOT(down()));
	connect(button_load_,SIGNAL(clicked()),this,SLOT(load()));
	connect(button_loadConf_,SIGNAL(clicked()),this,SLOT(loadConf()));
	connect(button_remove_,SIGNAL(clicked()),this,SLOT(remove()));
	connect(button_reset_,SIGNAL(clicked()),this,SLOT(reset()));
	connect(button_save_,SIGNAL(clicked()),this,SLOT(save()));
	connect(button_saveConf_,SIGNAL(clicked()),this,SLOT(saveConf()));
	connect(button_up_,SIGNAL(clicked()),this,SLOT(up()));
}

void GUI::FilterTab::createUi() {
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
	                               "background: rgb(115, 115, 115);"
	                               "border-width: 1px;"
	                               "border-color:rgb(255, 255, 255);"
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

	label_selectedFilters_=new QLabel(tr("Selected filters:"));
	label_filterOptions_=new QLabel(tr("Filter options:"));

	list_filterList_=new QListView;
	list_filterList_->setMaximumWidth(400);
	list_filterList_->setMinimumWidth(250);
	list_filterList_->setEditTriggers(QAbstractItemView::NoEditTriggers);

	model_list_=new QStringListModel;
	list_filterList_->setModel(model_list_);

	frameView_=new FrameView;
	frameView_->setMaximumWidth(600);
	frameView_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

	playerPanel_=new PlayerControlPanel;
	playerPanel_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
	playerPanel_->setMaximumWidth(600);

	previewPanel_=new PreviewControlPanel;
	previewPanel_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
	previewPanel_->setMaximumWidth(600);

	filterTabs_=new QTabWidget;
	FilterContainerTab* filterTab=new FilterContainerTab;
	filterTab->setParentTab(*this);

	FilterContainerTab* artefactsTab=new FilterContainerTab;
	artefactsTab->setParentTab(*this);

	filterContainerTab_.push_back(filterTab);
	filterContainerTab_.push_back(artefactsTab);

	filterTab->addFilter(Model::BlurFilter::FILTERNAME);
	filterTab->addFilter(Model::BrightnessFilter::FILTERNAME);
	filterTab->addFilter(Model::ColorbalanceFilter::FILTERNAME);
	filterTab->addFilter(Model::ContrastFilter::FILTERNAME);
	filterTab->addFilter(Model::EdgeFilter::FILTERNAME);
	filterTab->addFilter(Model::GrayscaleFilter::FILTERNAME);
    //filterTab->addFilter(Model::MirrorFilter::FILTERNAME);
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
	//filterTab->addFilter(Model::ZoomFilter::FILTERNAME);

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

	filterTabs_->addTab(scrollArea_filters,tr("Filters"));
	filterTabs_->addTab(scrollArea_artefacts,tr("Artefacts"));
	filterTabs_->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);


	//build gui
	QVBoxLayout* v_content=new QVBoxLayout;

	v_content->addWidget(label_selectedFilters_);

	QHBoxLayout* h_list_button_player_filterconf=new QHBoxLayout;

	h_list_button_player_filterconf->addWidget(list_filterList_);
	h_list_button_player_filterconf->addSpacing(20);

	QVBoxLayout* v_player_buttons_filterconf=new QVBoxLayout;

	QHBoxLayout* h_buttons_player=new QHBoxLayout;

	QVBoxLayout* v_buttonBlock=new QVBoxLayout;
	v_buttonBlock->addWidget(button_load_);
	v_buttonBlock->addWidget(button_apply_);
	v_buttonBlock->addWidget(button_save_);
	v_buttonBlock->addSpacing(20);
	v_buttonBlock->addWidget(button_up_);
	v_buttonBlock->addWidget(button_down_);
	v_buttonBlock->addWidget(button_remove_);
	v_buttonBlock->addSpacing(20);
	v_buttonBlock->addWidget(button_loadConf_);
	v_buttonBlock->addWidget(button_saveConf_);
	v_buttonBlock->addSpacing(20);
	v_buttonBlock->addWidget(button_reset_);

	h_buttons_player->addLayout(v_buttonBlock);
	h_buttons_player->addSpacing(30);
	QSpacerItem* sp=new QSpacerItem(0,0,QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
	h_buttons_player->addSpacerItem(sp);

	v_player_=new QVBoxLayout;
	v_player_->addWidget(frameView_);
	v_player_->addWidget(playerPanel_);

	h_buttons_player->addLayout(v_player_,1);
	QSpacerItem* sp1=new QSpacerItem(0,0,QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
	h_buttons_player->addSpacerItem(sp1);

	v_player_buttons_filterconf->addLayout(h_buttons_player);

	v_player_buttons_filterconf->addSpacing(20);
	v_player_buttons_filterconf->addWidget(label_filterOptions_);

	QFrame* buffer=new QFrame;
	buffer->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	buffer->setStyleSheet("background: rgb(200, 200, 200)");
	buffer->setMinimumHeight(50);
	buffer->setMaximumWidth(300);

	v_player_buttons_filterconf->addWidget(buffer);

	h_list_button_player_filterconf->addLayout(v_player_buttons_filterconf,1);

	v_content->addLayout(h_list_button_player_filterconf);

	v_content->addSpacing(20);

	v_content->addWidget(filterTabs_);

	setLayout(v_content);
}

void GUI::FilterTab::updatePreview() {
	if(!isPreviewShown_) {
		if(!rawVideo_.get())
			return;
		player_->stop();
		v_player_->removeWidget(playerPanel_);
		playerPanel_->hide();
		v_player_->addWidget(previewPanel_);
		previewPanel_->show();
		previewFrames_=std::make_unique<Model::AVVideo>(1,rawVideo_->getWidth(),rawVideo_->getHeight());

		static int numberOfPreviewFrames=5;
		int videoFramecount=rawVideo_->getVideo().getNumberOfFrames();
		int stepsize=videoFramecount/numberOfPreviewFrames;
		if(videoFramecount<numberOfPreviewFrames) {
			numberOfPreviewFrames=videoFramecount;
			stepsize=1;
		}
		for(std::size_t i=0; i<numberOfPreviewFrames; i++) {
			auto frame=Utility::VideoConverter::convertQImageToAVFrame(*rawVideo_->getVideo().getFrame(
			               i*stepsize));
			previewFrames_->appendFrame(frame);
		}

		isPreviewShown_=true;
	}
	player_->setVideo(nullptr);
	filteredPreviewFrames_=std::make_unique<Model::Video>(1,rawVideo_->getWidth(),
	                       rawVideo_->getHeight());

	Utility::FilterApplier filterApplier(*filterList_,rawVideo_->getWidth(),rawVideo_->getHeight(),
	                                     AV_PIX_FMT_RGB24);
	Model::AVVideo filteredVideo(1,rawVideo_->getWidth(),rawVideo_->getHeight());
	filterApplier.applyToVideo(filteredVideo,*previewFrames_);

	for(std::size_t i=0; i<filteredVideo.getNumberOfFrames(); i++) {
		filteredPreviewFrames_->appendFrame(Utility::VideoConverter::convertAVFrameToQImage(
		                                        *filteredVideo.getFrame(i)));
	}

	player_->setVideo(filteredPreviewFrames_.get());
	previewPanel_->updateUi();
}

void GUI::FilterTab::insertFilter(std::unique_ptr<Model::Filter> filter, std::size_t index) {
	auto stringlist=model_list_->stringList();
	stringlist.insert(index,filter->getName());
	filterList_->insertFilter(std::move(filter),index);
}

void GUI::FilterTab::up() {
	QModelIndexList selected = list_filterList_->selectionModel()->selectedIndexes();
	if (!selected.isEmpty()) {
		UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::MoveFilterUp(*this,selected.first().row()));
	}
}

void GUI::FilterTab::down() {
	QModelIndexList selected = list_filterList_->selectionModel()->selectedIndexes();
	if (!selected.isEmpty()) {
		UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::MoveFilterDown(*this,
		        selected.first().row()));
	}
}

void GUI::FilterTab::remove() {
	QModelIndexList selected = list_filterList_->selectionModel()->selectedIndexes();
	if (!selected.isEmpty()) {
		UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::RemoveFilter(*this,selected.first().row()));
	}
}

void GUI::FilterTab::load() {
	YuvFileOpenDialog fileOpenDiag(this);

	int result=fileOpenDiag.exec();

	if(!(result==QDialog::Accepted))
		return;

	auto path=fileOpenDiag.getFilename();

	if(path.isEmpty())
		return;

	std::unique_ptr<YuvInfoDialog> infoDialog;
	bool inputValid=true;
	do {
		infoDialog=std::make_unique<YuvInfoDialog>(this);
		inputValid=true;

		result=infoDialog->exec();
		if(!(result==QDialog::Accepted))
			return;

		if(infoDialog->getFps()<=0) {
			inputValid=false;
			continue;
		}
		if(infoDialog->getHeight()<=0) {
			inputValid=false;
			continue;
		}
		if(infoDialog->getWidth()<=0) {
			inputValid=false;
			continue;
		}

	} while(!inputValid);

	auto yuvVideo=std::make_unique<Model::YuvVideo>(path,infoDialog->getPixelSheme(),
	              infoDialog->getCompression(),infoDialog->getWidth(),infoDialog->getHeight(),infoDialog->getFps());
	UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::LoadFilterVideo(*this,std::move(yuvVideo),
	        std::move(getMemento())));
}

void GUI::FilterTab::apply() {

}

void GUI::FilterTab::saveConf() {
    if(filterList_->getSize()==0)
        return;

    auto filename = QFileDialog::getSaveFileName(this,tr("Save filter configuration"),QDir::homePath(),"*.conf");

    if(filename.isEmpty())
        return;

    if(!filename.endsWith(".conf"))
        filename+=".conf";

    Utility::FilterConfigurationSaver saver(filename,*filterList_);
    saver.save();
}

void GUI::FilterTab::loadConf() {
    if(!rawVideo_.get())
        return;

    auto filename=QFileDialog::getOpenFileName(this,tr("Open filterconfiguration"),QDir::homePath(),"*.conf");

    if(filename.isEmpty())
        return;

    Utility::FilterConfigurationLoader loader(filename);
    auto filterlist=loader.getConfiguration();

    UndoRedo::UndoStack::getUndoStack().push(new UndoRedo::LoadFilterconfig(*this,std::move(filterlist)));
}

void GUI::FilterTab::reset() {
	player_->stop();
	filterList_=std::make_unique<Model::FilterList>();
	model_list_->removeRows(0,model_list_->rowCount());
	playerPanel_->updateUi();
	previewPanel_->updateUi();
	if(isPreviewShown_) {
		v_player_->removeWidget(previewPanel_);
		v_player_->addWidget(playerPanel_);
		previewPanel_->hide();
		playerPanel_->show();
		player_->setVideo(&rawVideo_->getVideo());
		playerPanel_->updateUi();
		isPreviewShown_=false;
	}
}

void GUI::FilterTab::save() {

}

void GUI::FilterTab::listSelectionChanged(QModelIndex* index) {
	throw "Not yet implemented";
}

std::unique_ptr<Model::Filter> GUI::FilterTab::removeFilter(int index) {
	std::unique_ptr<Model::Filter> f;
	if(index<0||index>=filterList_->getSize()) {
		f.release();
		return std::move(f);
	}
	auto stringlist=model_list_->stringList();
	stringlist.removeAt(index);
	model_list_->setStringList(stringlist);
	auto filter=filterList_->removeFilter(index);

	if(filterList_->getSize()==0) {
		reset();
	} else {
		updatePreview();
	}

	return std::move(filter);
}

void GUI::FilterTab::setFilterList(std::unique_ptr<Model::FilterList> list) {
    if(!list.get())
        return;
    filterList_=std::move(list);
    QStringList filterlist;
    for(std::size_t i=0;i<filterList_->getSize();i++) {
        filterlist<<filterList_->getFilter(i)->getName();
    }
    model_list_->setStringList(filterlist);
    updatePreview();
}

void GUI::FilterTab::setRawVideo(std::unique_ptr<Model::YuvVideo> video) {
	reset();
	player_->setVideo(&video->getVideo());
	rawVideo_=std::move(video);
}

std::unique_ptr<Model::YuvVideo> GUI::FilterTab::releaseVideo() {
	auto video=std::move(rawVideo_);
	reset();
	return std::move(video);
}

void GUI::FilterTab::moveFilter(int old, int newPos) {
	if(old<0||old>=filterList_->getSize()||newPos<0||newPos>=filterList_->getSize()||old==newPos)
		return;
	filterList_->moveFilter(old,newPos);
	auto stringlist=model_list_->stringList();
	auto filname=stringlist.at(old);
	stringlist.removeAt(old);
	stringlist.insert(newPos,filname);
	model_list_->setStringList(stringlist);

	updatePreview();
}
