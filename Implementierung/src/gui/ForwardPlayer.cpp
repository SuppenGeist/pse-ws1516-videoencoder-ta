#include "ForwardPlayer.h"

#include <stdexcept>

#include "GlobalControlPanel.h"

GUI::ForwardPlayer::ForwardPlayer() noexcept {
}

void GUI::ForwardPlayer::setForwardControlPanel(GlobalControlPanel *panel) noexcept {
    forwardPanel_=panel;
}

void GUI::ForwardPlayer::play() {
    if(!forwardPanel_)
        return;
    forwardPanel_->play();
}

void GUI::ForwardPlayer::pause() {
    if(!forwardPanel_)
        return;
    forwardPanel_->pause();
}

void GUI::ForwardPlayer::stop() {
    if(!forwardPanel_)
        return;
    forwardPanel_->stop();
}

void GUI::ForwardPlayer::nextFrame() {
    if(!forwardPanel_)
        return;
    forwardPanel_->nextFrame();
}

void GUI::ForwardPlayer::previousFrame() {
    if(!forwardPanel_)
        return;
    forwardPanel_->previousFrame();
}

void GUI::ForwardPlayer::setSpeed(float speed) {
    if(!forwardPanel_)
        return;
    forwardPanel_->setSpeed(speed);
}

void GUI::ForwardPlayer::setPosition(std::size_t position) {
    if(!forwardPanel_)
        return;
    forwardPanel_->setPosition(position);
}

std::size_t GUI::ForwardPlayer::getPosition() const {
    throw std::logic_error("Dont call this method");
}

float GUI::ForwardPlayer::getSpeed() const {
    throw std::logic_error("Dont call this method");
}

bool GUI::ForwardPlayer::isPlaying() const {
    throw std::logic_error("Dont call this method");
}

bool GUI::ForwardPlayer::isStopped() const {
    throw std::logic_error("Dont call this method");
}

void GUI::ForwardPlayer::reset() {
    throw std::logic_error("Dont call this method");
}

std::size_t GUI::ForwardPlayer::getNumberOfFrames() const {
    throw std::logic_error("Dont call this method");
}
