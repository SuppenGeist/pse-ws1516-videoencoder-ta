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
}

void GUI::PreviewControlPanel::updateUi() {
    Player *player;

    if(masterPlayer_)
        player=masterPlayer_;
    else {
        if(players_.size()>0)
            player=players_[0];
        else
            return;
    }
    label_position->setText(QString::number(player->getPosition())+"/"+QString::number(player->getNumberOfFrames()));
}

void GUI::PreviewControlPanel::createUi() {
    QHBoxLayout *h_layout=new QHBoxLayout;

    button_nextFrame=new QPushButton;
    button_previousFrame=new QPushButton;
    label_position=new QLabel("0/0");

    button_nextFrame->setFlat(true);
    button_previousFrame->setFlat(true);

    button_nextFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button_previousFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label_position->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    button_nextFrame->setIcon(QIcon(":/icons/resources/next.png"));
    button_previousFrame->setIcon(QIcon(":/icons/resources/prev.png"));

    label_position->setAlignment(Qt::AlignCenter);

    QFont labelFont("Arial",15);
    label_position->setFont(labelFont);

    h_layout->addWidget(button_previousFrame);
    h_layout->addWidget(label_position);
    h_layout->addWidget(button_nextFrame);

    setLayout(h_layout);
    setStyleSheet("background: rgb(175, 175, 175)");
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


