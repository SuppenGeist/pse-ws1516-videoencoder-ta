#include "RGBHistogrammCalculator.h"
#include "../model/Video.h"
#include "../model/Graph.h"
#include "../model/graphvideo.h"

#include <QColor>
#include <QDebug>

Utility::RGBHistogrammCalculator::RGBHistogrammCalculator(Model::Video& video) {
    video_ = &video;
}

Utility::RGBHistogrammCalculator::~RGBHistogrammCalculator()
{
    isRunning_=false;
    if(calculator_.joinable()) {
        calculator_.join();
    }
}

void Utility::RGBHistogrammCalculator::calculate(Model::GraphVideo *targetRed, Model::GraphVideo *targetGreen, Model::GraphVideo *targetBlue) {
    if(!targetBlue||!targetGreen||!targetRed)
        return;

    red_=targetRed;
    blue_=targetBlue;
    green_=targetGreen;

    calculator_=std::thread(&RGBHistogrammCalculator::calculateP,this);
}

void Utility::RGBHistogrammCalculator::calculateP()
{
    isRunning_=true;
    std::size_t i=0;
    do {
    for(; i < video_->getNumberOfFrames()&&isRunning_; i++) {
        QImage *currentFrame = video_->getFrame(i);

        Model::Graph redg;
        Model::Graph greeng;
        Model::Graph blueg;

        for(int j = 0; j < currentFrame->height(); j++) {
            for(int k = 0; k < currentFrame->width(); k++) {
                auto pixel=currentFrame->pixel(k,j);
                int blue=qBlue(pixel);
                blueg.setValue(blue,blueg.getValue(blue)+1);

                int red=qRed(pixel);
                redg.setValue(red,redg.getValue(red)+1);

                int green=qGreen(pixel);
                greeng.setValue(green,greeng.getValue(green)+1);
            }
        }

        for(int k=0;k<256;k++) {
            blueg.setValue(k,blueg.getValue(k)+1);
            redg.setValue(k,redg.getValue(k)+1);
            greeng.setValue(k,greeng.getValue(k)+1);
        }

        red_->appendGraph(redg);
        green_->appendGraph(greeng);
        blue_->appendGraph(blueg);
    }
    }while (isRunning_&&!video_->isComplete());
    isRunning_=false;
}
