#include "meansquareerrorcalculator.h"

#include <QColor>
#include <QImage>

#include "../model/Graph.h"
#include "../model/Video.h"

MeanSquareErrorCalculator::MeanSquareErrorCalculator(Model::Video &video1, Model::Video &video2):video1_(&video1),video2_(&video2)
{
    if(video1.getWidth()!=video2.getWidth() || video1.getHeight()!=video2.getHeight() || video1.getNumberOfFrames()!=video2.getNumberOfFrames()) {
        throw std::invalid_argument("Cant calculate psnr of two completly different videos!");
    }
}

Model::Graph MeanSquareErrorCalculator::calculate()
{
    Model::Graph mseGraph;

    double mse=0;
    int diffR=0;
    int diffG=0;
    int diffB=0;

    std::size_t frames=video1_->getNumberOfFrames();
    int width=video1_->getWidth();
    int height=video1_->getHeight();
    for(std::size_t i=0;i<frames;i++) {
        mse=0;
        diffR=0;
        diffG=0;
        diffB=0;

        auto frame1=video1_->getFrame(i);
        auto frame2=video2_->getFrame(i);

        for(int k=0;k<width;k++) {
            for(int j=0;j<height;j++) {
                auto color1=frame1->pixel(k,j);
                auto color2=frame2->pixel(k,j);

                diffR=qRed(color1)-qRed(color2);
                diffG=qGreen(color1)-qGreen(color2);
                diffB=qBlue(color1)-qBlue(color2);

                mse+=diffR*diffR+diffG*diffG+diffB*diffB;
            }
        }

        mse=mse/(width*height);
        mse=mse/3;

        mseGraph.setValue(i,mse);
    }


    return std::move(mseGraph);
}

