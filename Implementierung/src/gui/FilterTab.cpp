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
#include <QListWidget>
#include <QSpacerItem>
#include <QTimer>
#include <QTabWidget>

#include "../memento/FilterTabMemento.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"
#include "../model/YuvVideo.h"
#include "FrameView.h"
#include "PlayerControlPanel.h"
#include "FilterContainerTab.h"
#include "YuvFileOpenDialog.h"
#include "YuvInfoDialog.h"
#include "../undo_framework/UndoStack.h"
#include "../undo_framework/LoadFilterVideo.h"
#include "VideoPlayer.h"
#include "Timer.h"

GUI::FilterTab::FilterTab(QWidget* parent):QFrame(parent) {
	createUi();
	connectActions();

	player_=std::make_unique<VideoPlayer>();
	player_->addView(*frameView_);
	player_->setTimer(std::make_shared<Timer>());
	playerPanel_->setMasterVideoPlayer(*player_);
	player_->setMasterControlPanel(*playerPanel_);
}


std::unique_ptr<Memento::FilterTabMemento> GUI::FilterTab::getMemento() {
	return std::make_unique<Memento::FilterTabMemento>();
}

void GUI::FilterTab::restore(Memento::FilterTabMemento &memento) {
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

	list_filterList_=new QListWidget;
	list_filterList_->setMaximumWidth(400);
	list_filterList_->setMinimumWidth(250);

	frameView_=new FrameView;
	frameView_->setMaximumWidth(600);
	frameView_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);

	playerPanel_=new PlayerControlPanel;
	playerPanel_->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
	playerPanel_->setMaximumWidth(600);

	filterTabs_=new QTabWidget;
	FilterContainerTab* filterTab=new FilterContainerTab;

	FilterContainerTab* artefactsTab=new FilterContainerTab;

	filterContainerTab_.push_back(filterTab);
	filterContainerTab_.push_back(artefactsTab);

	filterTabs_->addTab(filterContainerTab_[0],tr("Filters"));
	filterTabs_->addTab(filterContainerTab_[1],tr("Artefacts"));
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

	QVBoxLayout* v_player=new QVBoxLayout;
	v_player->addWidget(frameView_);
	v_player->addWidget(playerPanel_);

	h_buttons_player->addLayout(v_player,1);
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

	v_content->addSpacing(30);

	v_content->addWidget(filterTabs_);

    setLayout(v_content);
}

void GUI::FilterTab::up() {
}

void GUI::FilterTab::down() {

}

void GUI::FilterTab::remove() {
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
}

void GUI::FilterTab::loadConf() {
}

void GUI::FilterTab::reset() {
	player_->reset();
}

void GUI::FilterTab::save() {
}

void GUI::FilterTab::insertFilter(Model::Filter& filter, int index) {
	throw "Not yet implemented";
}

void GUI::FilterTab::listSelectionChanged(QModelIndex* index) {
	throw "Not yet implemented";
}

void GUI::FilterTab::removeFilter(std::string filterName) {
	throw "Not yet implemented";
}

void GUI::FilterTab::showVideo() {
	throw "Not yet implemented";
}

void GUI::FilterTab::showPreview() {
	throw "Not yet implemented";
}

void GUI::FilterTab::resetFilters() {
	throw "Not yet implemented";
}

void GUI::FilterTab::setFilterList(Model::FilterList list) {
	throw "Not yet implemented";
}

void GUI::FilterTab::setRawVideo(std::unique_ptr<Model::YuvVideo> video) {
	reset();
	rawVideo_=std::move(video);
    player_->setVideo(rawVideo_->getVideo());
}

std::unique_ptr<Model::YuvVideo> GUI::FilterTab::releaseVideo() {
	auto video=std::move(rawVideo_);
	reset();
	return std::move(video);
}

void GUI::FilterTab::moveFilter(int old, int new_3) {
	throw "Not yet implemented";
}
