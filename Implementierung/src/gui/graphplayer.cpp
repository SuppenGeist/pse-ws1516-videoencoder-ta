#include "graphplayer.h"

#include <QDebug>

GUI::GraphPlayer::GraphPlayer():position_(0),video_(nullptr),view_(nullptr)
{
}


void GUI::GraphPlayer::play()
{
    if(!timer_.get())
        return;
    timer_->start();
}

void GUI::GraphPlayer::pause()
{
    if(!timer_.get())
        return;
    timer_->pause();
}

void GUI::GraphPlayer::stop()
{
    if(!timer_.get())
        return;
    timer_->pause();
    setPosition(0);
}

void GUI::GraphPlayer::nextFrame()
{
    setPosition(getPosition()+1);
}

void GUI::GraphPlayer::previousFrame()
{
    setPosition(getPosition()==0?0:getPosition()-1);
}

void GUI::GraphPlayer::setSpeed(float speed)
{
    if(!timer_.get())
        return;
    timer_->setSpeed(speed);
}

void GUI::GraphPlayer::setPosition(std::size_t position)
{
    if(!video_)
        return;
    if(video_->getNumberOfGraphs()==0)
        return;

    if(position>=video_->getNumberOfGraphs()) {
        position=video_->getNumberOfGraphs()-1;
        pause();
    }

    position_=position;
    if(view_) {
        view_->drawGraph(video_->getGraph(position));
    }
}

std::size_t GUI::GraphPlayer::getPosition() const
{
    return position_;
}

float GUI::GraphPlayer::getSpeed() const
{
    if(!timer_.get())
        return 0;
    return timer_->getSpeed();
}

bool GUI::GraphPlayer::isPlaying() const
{
    return timer_.get()?timer_->isPlaying():false;
}

bool GUI::GraphPlayer::isStopped() const
{
    return (!isPlaying())&&(getPosition()==0);
}

void GUI::GraphPlayer::reset()
{
    stop();
    position_=0;
    video_=nullptr;

    if(view_) {
        view_->drawGraph(nullptr);
    }
}

std::size_t GUI::GraphPlayer::getNumberOfFrames() const
{
    if(!video_)
        return 0;
    return video_->getNumberOfGraphs();
}

void GUI::GraphPlayer::setGraphVideo(Model::GraphVideo *video)
{
    video_=video;

    updateView();
}

void GUI::GraphPlayer::setView(GUI::GraphWidget *view)
{
    view_=view;
}

void GUI::GraphPlayer::setTimer(std::shared_ptr<GUI::Timer> timer)
{
    if(timer_.get())
        timer_->removePlayer(*this);
    timer_=timer;
    timer_->addPlayer(*this);
}

void GUI::GraphPlayer::clearTimer()
{
    if(!timer_.get())
        return;
    timer_->removePlayer(*this);
    timer_.reset();
}

void GUI::GraphPlayer::updateView()
{
    if(!isPlaying())  {
        if(video_) {
            if(video_->getNumberOfGraphs()>0) {
                if(view_) {
                    view_->drawGraph(video_->getGraph(position_));
                }
            }
        } else {
            if(view_) {
                view_->drawGraph(nullptr);
            }
        }
    }
}
