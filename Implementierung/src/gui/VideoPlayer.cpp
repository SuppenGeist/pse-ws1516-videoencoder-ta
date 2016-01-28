#include "VideoPlayer.h"

#include <vector>
#include <algorithm>
#include <memory>

#include "ControlPanel.h"
#include "../model/Video.h"
#include "FrameView.h"
#include "Timer.h"
#include "Player.h"

GUI::VideoPlayer::VideoPlayer() noexcept :position_(0) {
}

void GUI::VideoPlayer::addView(FrameView& view) {
    if(std::find(views_.begin(), views_.end(), &view) == views_.end())
        return;
    views_.push_back(&view);
}

void GUI::VideoPlayer::removeView(FrameView& view) {
    std::size_t pos = std::find(views_.begin(), views_.end(), &view) - views_.begin();
    if(pos<views_.size()) {
        views_.erase(views_.begin()+pos);
    }
}

void GUI::VideoPlayer::setVideo(Model::Video& video) noexcept {
    video_=&video;
    stop();
}

Model::Video* GUI::VideoPlayer::getVideo() noexcept {
    return video_;
}

void GUI::VideoPlayer::setTimer(std::shared_ptr<GUI::Timer> timer) noexcept {
    timer_=timer;
}

void GUI::VideoPlayer::clearTimer() noexcept {
    timer_.reset();
}

int GUI::VideoPlayer::getFps() const noexcept {
    if(!timer_.get())
        return 0;
    return timer_->getFps();
}

void GUI::VideoPlayer::setMasterControlPanel(ControlPanel& controlPanel) noexcept {
    masterPanel_=&controlPanel;
    throw "Not yet implemented";
}

void GUI::VideoPlayer::play() {
    if(!timer_.get())
        return;
    timer_->start();
}

void GUI::VideoPlayer::pause() {
    if(!timer_.get())
        return;
    timer_->pause();
}

void GUI::VideoPlayer::stop() {
    if(!timer_.get())
        return;
    timer_->pause();
    setPosition(0);
}

void GUI::VideoPlayer::nextFrame() {
    setPosition(getPosition()+1);
}

void GUI::VideoPlayer::previousFrame() {
    setPosition(getPosition()==0?0:getPosition()-1);
}

void GUI::VideoPlayer::setSpeed(float speed) {
    if(!timer_.get())
        return;
    timer_->setSpeed(speed);
}

void GUI::VideoPlayer::setPosition(std::size_t position) {
    if(!video_)
        return;
    if(video_->getNumberOfFrames()==0)
        return;

    if(position>=video_->getNumberOfFrames())
        position=video_->getNumberOfFrames()-1;

    position_=position;
    for(auto view:views_) {
        view->setFrame(*(video_->getFrame(position_)));
    }
}

std::size_t GUI::VideoPlayer::getPosition() const noexcept{
    return position_;
}

float GUI::VideoPlayer::getSpeed() const noexcept {
    if(!timer_.get())
        return 0;
    return timer_->getSpeed();
}

bool GUI::VideoPlayer::isPlaying() const {
    return timer_.get()?timer_->isPlaying():false;
}

bool GUI::VideoPlayer::isStopped() const {
    return (!isPlaying())&&(getPosition()==0);
}

void GUI::VideoPlayer::reset() {
	throw "Not yet implemented";
}
