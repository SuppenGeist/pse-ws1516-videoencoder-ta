#include "GlobalControlPanel.h"

#include <QDebug>

#include "Player.h"

GUI::GlobalControlPanel::GlobalControlPanel() {
}

void GUI::GlobalControlPanel::updateUi() {
	//No gui to update
}

void GUI::GlobalControlPanel::play() {
	if(masterPlayer_)
		masterPlayer_->play();

	for(auto player:players_) {
		player->play();
	}
}

void GUI::GlobalControlPanel::pause() {
	if(masterPlayer_)
		masterPlayer_->pause();

	for(auto player:players_) {
		player->pause();
	}
}

void GUI::GlobalControlPanel::stop() {
	if(masterPlayer_)
		masterPlayer_->stop();

	for(auto player:players_) {
		player->stop();
	}
}

void GUI::GlobalControlPanel::nextFrame() {
	if(masterPlayer_)
		masterPlayer_->nextFrame();

	for(auto player:players_) {
        player->nextFrame();
    }
}

void GUI::GlobalControlPanel::previousFrame() {
	if(masterPlayer_)
		masterPlayer_->previousFrame();

	for(auto player:players_) {
        player->previousFrame();
    }
}

void GUI::GlobalControlPanel::setPosition(int position) {
	if(masterPlayer_)
		masterPlayer_->setPosition(position);

	for(auto player:players_) {
		player->setPosition(position);
	}
}

void GUI::GlobalControlPanel::setSpeed(float speed) {
	if(masterPlayer_)
		masterPlayer_->setSpeed(speed);

	for(auto player:players_) {
		player->setSpeed(speed);
    }
}

int GUI::GlobalControlPanel::getPosition()
{
    if(masterPlayer_) {
        return masterPlayer_->getPosition();
    }
    return 0;
}
