#include "meansquareerrorcalculator.h"

#include "model/Graph.h"
#include "model/AVVideo.h"

MeanSquareErrorCalculator::MeanSquareErrorCalculator(Model::AVVideo &video1, Model::AVVideo &video2):video1_(&video1),video2_(&video2)
{

}

Model::Graph MeanSquareErrorCalculator::calculate()
{
    Model::Graph mseGraph;

    return std::move(mseGraph);
}

