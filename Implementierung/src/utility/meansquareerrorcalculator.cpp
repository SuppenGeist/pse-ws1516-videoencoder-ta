#include "meansquareerrorcalculator.h"

#include "../model/Graph.h"
#include "../model/Video.h"

MeanSquareErrorCalculator::MeanSquareErrorCalculator(Model::Video &video1, Model::Video &video2):video1_(&video1),video2_(&video2)
{

}

Model::Graph MeanSquareErrorCalculator::calculate()
{
    Model::Graph mseGraph;

    return std::move(mseGraph);
}

