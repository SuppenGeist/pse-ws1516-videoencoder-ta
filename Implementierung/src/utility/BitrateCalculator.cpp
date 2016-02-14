#include "BitrateCalculator.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include "../model/AVVideo.h"
#include "../model/Graph.h"

Utility::BitrateCalculator::BitrateCalculator(Model::AVVideo& video):video_(&video),isRunning_(false) {

}

Utility::BitrateCalculator::~BitrateCalculator()
{
    isRunning_=false;
    if(calculator_.joinable()) {
        calculator_.join();
    }
}

void Utility::BitrateCalculator::calculate(Model::Graph *target) {
    if(!target)
        return;

    target_=target;
    calculator_=std::thread(&BitrateCalculator::calculateP,this);

}

void Utility::BitrateCalculator::calculateP()
{
    isRunning_=true;
    std::size_t i=0;
    do {
    for(; i<video_->getNumberOfFrames()&&isRunning_; i++) {
        target_->setValue(i,video_->getFrame(i)->pkt_size*8/(double)1000);
    }
    }while(isRunning_&&!video_->isComplete());
    isRunning_=false;
}
