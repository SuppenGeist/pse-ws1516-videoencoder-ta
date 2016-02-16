#include "graphvideo.h"


Model::GraphVideo::GraphVideo()
{

}

void Model::GraphVideo::appendGraph(std::unique_ptr<Graph> graph)
{
    graphs_.push_back(std::move(graph));
}

Model::Graph *Model::GraphVideo::getGraph(std::size_t index)
{
    if(index>=graphs_.size())
        return nullptr;
    return graphs_[index].get();
}

std::size_t Model::GraphVideo::getNumberOfGraphs()
{
    return graphs_.size();
}

