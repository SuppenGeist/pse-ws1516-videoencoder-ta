#include "PreviewControlPanel.h"

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QFont>
#include <QString>

#include "Player.h"

GUI::PreviewControlPanel::PreviewControlPanel(QWidget* parent):QFrame(parent) {
	createUi();

	connect(button_nextFrame,SIGNAL(clicked()),this,SLOT(nextFrame()));
	connect(button_previousFrame,SIGNAL(clicked()),this,SLOT(previousFrame()));
}

void GUI::PreviewControlPanel::updateUi() {
	Player *player=nullptr;

	if(masterPlayer_)
		player=masterPlayer_;
	else {
		if(players_.size()>0)
			player=players_[0];
		else
			return;
	}
	if(player->getNumberOfFrames()==0) {
		label_position->setText("0/0");
	} else {
		label_position->setText(QString::number(player->getPosition()+1)+"/"+QString::number(
		                            player->getNumberOfFrames()));
	}
}

void GUI::PreviewControlPanel::createUi() {
	QHBoxLayout *h_layout=new QHBoxLayout;

	button_nextFrame=new QPushButton;
	button_previousFrame=new QPushButton;
	label_position=new QLabel("0/0");

	button_nextFrame->setFlat(true);
	button_previousFrame->setFlat(true);

	button_nextFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
	button_previousFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
	label_position->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

	button_nextFrame->setIcon(QIcon(":/icons/resources/icons/next.png"));
	button_previousFrame->setIcon(QIcon(":/icons/resources/icons/prev.png"));

	label_position->setAlignment(Qt::AlignCenter);

	QFont labelFont("Arial",15);
	label_position->setFont(labelFont);

	h_layout->addWidget(button_previousFrame);
	h_layout->addWidget(label_position);
	h_layout->addWidget(button_nextFrame);

	setLayout(h_layout);
	setFixedHeight(60);
	setObjectName("playerPanel");
	setStyleSheet("QFrame#playerPanel {"
	              "border-width:1px;"
	              "border-radius:4px;"
	              "border-color:rgb(0,0,0);"
	              "border-style:outset;"
	              "background: rgb(200, 200, 200);"
	              "}"
	              "");
}

void GUI::PreviewControlPanel::nextFrame() {
	if(masterPlayer_)
		masterPlayer_->nextFrame();

	for(auto player:players_) {
		player->nextFrame();
	}

	updateUi();
}

void GUI::PreviewControlPanel::previousFrame() {
	if(masterPlayer_)
		masterPlayer_->previousFrame();

	for(auto player:players_) {
		player->previousFrame();
	}

	updateUi();
}


