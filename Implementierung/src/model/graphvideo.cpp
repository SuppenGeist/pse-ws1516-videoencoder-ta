#include "graphvideo.h"


Model::GraphVideo::GraphVideo(int fps):fps_(fps),isComplete_(false) {

}

void Model::GraphVideo::appendGraph(std::unique_ptr<Graph> graph) {
	graphs_.push_back(std::move(graph));
}

Model::Graph *Model::GraphVideo::getGraph(std::size_t index) {
	if(index>=graphs_.size())
		return nullptr;
	return graphs_[index].get();
}

std::size_t Model::GraphVideo::getNumberOfGraphs() {
    return graphs_.size();
}

int Model::GraphVideo::getFps()
{
    return fps_;
}

void Model::GraphVideo::setFps(int fps)
{
    fps_=fps;
}

bool Model::GraphVideo::isComplete()
{
    return isComplete_;
}

void Model::GraphVideo::setIsComplete(bool isComplete)
{
    isComplete_=isComplete;
}

