#include "PsnrCalculator.h"

#include "../model/AVVideo.h"
#include "../model/Graph.h"

Utility::PsnrCalculator::PsnrCalculator(Model::AVVideo& referenceVideo, Model::AVVideo& compareVideo):referenceVideo_(&referenceVideo),video_(&compareVideo) {
    init();
}

Model::Graph Utility::PsnrCalculator::calculate() {
    Model::Graph psnrGraph;


    return std::move(psnrGraph);
}

void Utility::PsnrCalculator::init() {

}
