#include "PlayerControlPanel.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSlider>

#include "Player.h"

GUI::PlayerControlPanel::PlayerControlPanel(QWidget* parent):QFrame(parent) {
	createUi();

	connect(button_play_,SIGNAL(clicked()),this,SLOT(play()));
	connect(button_pause_,SIGNAL(clicked()),this,SLOT(pause()));
	connect(button_stop_,SIGNAL(clicked()),this,SLOT(stop()));
	connect(button_nextFrame_,SIGNAL(clicked()),this,SLOT(nextFrame()));
	connect(button_previousFrame_,SIGNAL(clicked()),this,SLOT(previousFrame()));
	connect(comboBox_speed_,SIGNAL(currentIndexChanged(int)),this,SLOT(changeSpeed(int)));
	connect(slider_timeline_,SIGNAL(valueChanged(int)),this,SLOT(changeTimeline(int)));
}

void GUI::PlayerControlPanel::updateUi() {
	Player *player=nullptr;

	if(masterPlayer_)
		player=masterPlayer_;
	else {
		if(players_.size()>0)
			player=players_[0];
		else {
			button_nextFrame_->setEnabled(false);
			button_pause_->setEnabled(false);
			button_play_->setEnabled(false);
			button_previousFrame_->setEnabled(false);
			button_stop_->setEnabled(false);
			slider_timeline_->setRange(0,0);
			return;
		}
	}

	slider_timeline_->setRange(0,player->getNumberOfFrames()-1);
	slider_timeline_->setValue(player->getPosition());


	if(player->getPosition()==0) {
		button_previousFrame_->setEnabled(false);
		if(player->getNumberOfFrames()>1) {
			button_nextFrame_->setEnabled(true);
		} else {
			button_nextFrame_->setEnabled(false);
		}
	} else if(player->getPosition()==player->getNumberOfFrames()-1) {
		button_nextFrame_->setEnabled(false);
		button_previousFrame_->setEnabled(true);
	} else {
		button_nextFrame_->setEnabled(true);
		button_previousFrame_->setEnabled(true);
	}

	if(player->isPlaying()) {
		button_play_->setEnabled(false);
		button_pause_->setEnabled(true);
		button_stop_->setEnabled(true);
	} else {
		if(player->getNumberOfFrames()>1&&player->getPosition()!=player->getNumberOfFrames()-1) {
			button_play_->setEnabled(true);
		} else {
			button_play_->setEnabled(false);
		}
		button_pause_->setEnabled(false);
		if(player->isStopped()) {
			button_stop_->setEnabled(false);
		} else {
			button_stop_->setEnabled(true);
		}
	}
}

void GUI::PlayerControlPanel::createUi() {
	QVBoxLayout *v_layout=new QVBoxLayout;

	QHBoxLayout *h_layout=new QHBoxLayout;

	button_play_=new QPushButton;
	button_pause_=new QPushButton;
	button_stop_=new QPushButton;
	button_nextFrame_=new QPushButton;
	button_previousFrame_=new QPushButton;
	comboBox_speed_=new QComboBox;

	button_play_->setIcon(QIcon(":/icons/resources/icons/play.png"));
	button_pause_->setIcon(QIcon(":/icons/resources/icons/pause.png"));
	button_stop_->setIcon(QIcon(":/icons/resources/icons/stop.png"));
	button_nextFrame_->setIcon(QIcon(":/icons/resources/icons/next.png"));
	button_previousFrame_->setIcon(QIcon(":/icons/resources/icons/prev.png"));

	button_play_->setFlat(true);
	button_pause_->setFlat(true);
	button_stop_->setFlat(true);
	button_nextFrame_->setFlat(true);
	button_previousFrame_->setFlat(true);

	button_play_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
	button_pause_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
	button_stop_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
	button_nextFrame_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
	button_previousFrame_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

	QStringList speedItems = QStringList() << tr("0.25x") <<tr("0.50x") << tr("0.75x") << tr("1.00x") <<
	                         tr("1.25x") << tr("1.50x") << tr("1.75x") << tr("2.00x");
	comboBox_speed_->addItems(speedItems);
	comboBox_speed_->setCurrentIndex(3);
	comboBox_speed_->setMinimumWidth(80);

	h_layout->addWidget(button_play_);
	h_layout->addWidget(button_pause_);
	h_layout->addWidget(button_stop_);
	h_layout->addWidget(button_previousFrame_);
	h_layout->addWidget(button_nextFrame_);
	h_layout->addWidget(comboBox_speed_);

	v_layout->addLayout(h_layout);


	slider_timeline_=new QSlider(Qt::Horizontal);

	v_layout->addWidget(slider_timeline_);

	setLayout(v_layout);
	setStyleSheet("background: rgb(175, 175, 175)");
}

void GUI::PlayerControlPanel::play() {
	if(masterPlayer_)
		masterPlayer_->play();

	for(auto player:players_) {
		player->play();
	}
}

void GUI::PlayerControlPanel::pause() {
	if(masterPlayer_)
		masterPlayer_->pause();

	for(auto player:players_) {
		player->pause();
	}
}

void GUI::PlayerControlPanel::stop() {
	if(masterPlayer_)
		masterPlayer_->stop();

	for(auto player:players_) {
		player->stop();
	}
}

void GUI::PlayerControlPanel::nextFrame() {
	if(masterPlayer_) {
		masterPlayer_->nextFrame();
		masterPlayer_->pause();
	}

	for(auto player:players_) {
		player->nextFrame();
		player->pause();
	}

	updateUi();
}

void GUI::PlayerControlPanel::previousFrame() {
	if(masterPlayer_)
		masterPlayer_->previousFrame();

	for(auto player:players_) {
		player->previousFrame();
		player->pause();
	}

	updateUi();
}

void GUI::PlayerControlPanel::changeSpeed(int index) {
	float newSpeed=1.0;

	switch(index) {
	case 7:
		newSpeed=0.25;
		break;
	case 6:
		newSpeed=0.50;
		break;
	case 5:
		newSpeed=0.75;
		break;
	case 4:
		newSpeed=1.0;
		break;
	case 3:
		newSpeed=1.25;
		break;
	case 2:
		newSpeed=1.5;
		break;
	case 1:
		newSpeed=1.75;
		break;
	case 0:
		newSpeed=2.0;
		break;
	default:
		newSpeed=1.0;
	}

	if(masterPlayer_)
		masterPlayer_->setSpeed(newSpeed);

	for(auto player:players_) {
		player->setSpeed(newSpeed);
	}
}

void GUI::PlayerControlPanel::changeTimeline(int value) {
	if(masterPlayer_)
		masterPlayer_->setPosition(value);

	for(auto player:players_) {
		player->setPosition(value);
	}
}
