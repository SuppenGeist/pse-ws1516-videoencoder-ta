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

    connect(button_play,SIGNAL(clicked()),this,SLOT(play()));
    connect(button_pause,SIGNAL(clicked()),this,SLOT(pause()));
    connect(button_stop,SIGNAL(clicked()),this,SLOT(stop()));
    connect(button_nextFrame,SIGNAL(clicked()),this,SLOT(nextFrame()));
    connect(button_previousFrame,SIGNAL(clicked()),this,SLOT(previousFrame()));
    connect(comboBox_speed,SIGNAL(currentIndexChanged(int)),this,SLOT(changeSpeed(int)));
    connect(slider_timeline,SIGNAL(valueChanged(int)),this,SLOT(changeTimeline(int)));
}

void GUI::PlayerControlPanel::updateUi() {
    Player *player=nullptr;

    if(masterPlayer_)
        player=masterPlayer_;
    else {
        if(players_.size()>0)
            player=players_[0];
        else
            return;
    }

    slider_timeline->setMaximum(player->getNumberOfFrames());
    slider_timeline->setValue(player->getPosition());
}

void GUI::PlayerControlPanel::createUi() {
    QVBoxLayout *v_layout=new QVBoxLayout;

        QHBoxLayout *h_layout=new QHBoxLayout;

        button_play=new QPushButton;
        button_pause=new QPushButton;
        button_stop=new QPushButton;
        button_nextFrame=new QPushButton;
        button_previousFrame=new QPushButton;
        comboBox_speed=new QComboBox;

        button_play->setIcon(QIcon(":/icons/resources/icons/stop.png"));
        button_pause->setIcon(QIcon(":/icons/resources/icons/pause.png"));
        button_stop->setIcon(QIcon(":/icons/resources/icons/stop.png"));
        button_nextFrame->setIcon(QIcon(":/icons/resources/icons/next.png"));
        button_previousFrame->setIcon(QIcon(":/icons/resources/icons/prev.png"));

        button_play->setFlat(true);
        button_pause->setFlat(true);
        button_stop->setFlat(true);
        button_nextFrame->setFlat(true);
        button_previousFrame->setFlat(true);

        button_play->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button_pause->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button_stop->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button_nextFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button_previousFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        QStringList speedItems = QStringList() << tr("0.25x") <<tr("0.50x") << tr("0.75x") << tr("1.00x") << tr("1.25x") << tr("1.50x") << tr("1.75x") << tr("2.00x");
        comboBox_speed->addItems(speedItems);
        comboBox_speed->setCurrentIndex(3);
        comboBox_speed->setMinimumWidth(80);

        h_layout->addWidget(button_play);
        h_layout->addWidget(button_pause);
        h_layout->addWidget(button_stop);
        h_layout->addWidget(button_previousFrame);
        h_layout->addWidget(button_nextFrame);
        h_layout->addWidget(comboBox_speed);

        v_layout->addLayout(h_layout);


        slider_timeline=new QSlider(Qt::Horizontal);

        v_layout->addWidget(slider_timeline);

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
    if(masterPlayer_)
        masterPlayer_->nextFrame();

    for(auto player:players_) {
        player->nextFrame();
    }

    updateUi();
}

void GUI::PlayerControlPanel::previousFrame() {
    if(masterPlayer_)
        masterPlayer_->previousFrame();

    for(auto player:players_) {
        player->previousFrame();
    }

    updateUi();
}

void GUI::PlayerControlPanel::changeSpeed(int index) {
    float newSpeed=1.0;

    switch(index) {
    case 0:
        newSpeed=0.25;
        break;
    case 1:
        newSpeed=0.50;
        break;
    case 2:
        newSpeed=0.75;
        break;
    case 3:
        newSpeed=1.0;
        break;
    case 4:
        newSpeed=1.25;
        break;
    case 5:
        newSpeed=1.5;
        break;
    case 6:
        newSpeed=1.75;
        break;
    case 7:
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
