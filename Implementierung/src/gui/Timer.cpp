#include "Timer.h"
#include "VideoPlayer.h"

GUI::Timer::Timer(int fps) {
}

void GUI::Timer::setFps(int fps) {
	this->fps = fps;
}

void GUI::Timer::setSpeed(float speed) {
	this->speed = speed;
}

float GUI::Timer::getSpeed() {
	return this->speed;
}

int GUI::Timer::getFps() {
	return this->fps;
}

void GUI::Timer::pause() {
	throw "Not yet implemented";
}

void GUI::Timer::start() {
	throw "Not yet implemented";
}

void GUI::Timer::addPlayer(VideoPlayer& player) {
	throw "Not yet implemented";
}

bool GUI::Timer::isPlaying() {
	throw "Not yet implemented";
}

void GUI::Timer::update() {
	throw "Not yet implemented";
}

void GUI::Timer::removePlayer(VideoPlayer& player) {
	throw "Not yet implemented";
}
