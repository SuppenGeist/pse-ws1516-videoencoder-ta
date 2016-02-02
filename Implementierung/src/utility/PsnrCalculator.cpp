#include "PsnrCalculator.h"

#include <stdexcept>
#include <cmath>

#include "../model/Video.h"
#include "../model/Graph.h"
#include "meansquareerrorcalculator.h"

Utility::PsnrCalculator::PsnrCalculator(Model::Video& referenceVideo, Model::Video& compareVideo):referenceVideo_(&referenceVideo),video_(&compareVideo) {
    if(referenceVideo.getWidth()!=compareVideo.getWidth() || referenceVideo.getHeight()!=compareVideo.getHeight() || referenceVideo.getNumberOfFrames()!=compareVideo.getNumberOfFrames()) {
        throw std::invalid_argument("Cant calculate psnr of two completly different videos!");
    }
}

Model::Graph Utility::PsnrCalculator::calculate() {
    Model::Graph psnrGraph;

    MeanSquareErrorCalculator mseCalc(*referenceVideo_,*video_);
    auto mseGraph=mseCalc.calculate();

    std::size_t maxVal=mseGraph.getSize();
    for(std::size_t i=0;i<maxVal;i++) {
        double psnr=-1;
        double mse=mseGraph.getValue(i);
        if(mse!=0) {
            psnr=10*std::log10(65025/mse);
        }
        psnrGraph.setValue(i,psnr);
    }

    return std::move(psnrGraph);
}
