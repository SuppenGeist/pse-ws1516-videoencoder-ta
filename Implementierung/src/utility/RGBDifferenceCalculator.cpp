#include "RGBDifferenceCalculator.h"

Utility::RGBDifferenceCalculator::RGBDifferenceCalculator(Model::Video& referenceVideo, Model::Video& video) {
    this->referenceVideo = &referenceVideo;
    this->video = &video;
}

void Utility::RGBDifferenceCalculator::calculateVideo(Model::Video& target) {
    //TODO: Calculate
}
