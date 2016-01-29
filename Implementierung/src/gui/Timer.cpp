#include "Timer.h"

#include <algorithm>

#include <QTimer>
#include <QObject>

#include "VideoPlayer.h"

GUI::Timer::Timer(QObject *parent):QObject(parent),timer_(this),speed_(1.0),fps_(30) {
	connect(&timer_,SIGNAL(timeout()),this,SLOT(update()));
}

void GUI::Timer::setFps(int fps) noexcept {
	if(fps<1)
		return;
	fps_ = fps;
}

void GUI::Timer::setSpeed(float speed) noexcept {
	if(speed_<=0.0)
		return;
	speed_ = speed;
}

float GUI::Timer::getSpeed() const noexcept {
	return speed_;
}

int GUI::Timer::getFps() const noexcept {
	return fps_;
}

void GUI::Timer::pause() {
	timer_.stop();
}

void GUI::Timer::start() {
	if(isPlaying())
		return;
	timer_.start(((double)1000/fps_)*speed_);
}

void GUI::Timer::addPlayer(VideoPlayer& player) {
	if(std::find(players_.begin(), players_.end(), &player) == players_.end())
		return;
	players_.push_back(&player);
}

bool GUI::Timer::isPlaying() {
	return timer_.isActive();
}

void GUI::Timer::update() {
	for(auto player:players_) {
		player->nextFrame();
	}
}

void GUI::Timer::removePlayer(VideoPlayer& player) {
	std::size_t pos = std::find(players_.begin(), players_.end(), &player) - players_.begin();
	if(pos<players_.size()) {
		players_.erase(players_.begin()+pos);
	}
}
