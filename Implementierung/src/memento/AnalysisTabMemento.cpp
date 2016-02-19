#include "AnalysisTabMemento.h"

#include "../gui/AnalysisTab.h"

#include "../model/YuvVideo.h"

Memento::AnalysisTabMemento::AnalysisTabMemento():rawVideo_(nullptr),graph_(GUI::AnalysisGraph::BITRATE),video_(GUI::AnalysisVideo::MACROBLOCK),position_(0) {

}

void Memento::AnalysisTabMemento::setRawVideo(Model::YuvVideo *video) {
	rawVideo_=video;
}

Model::YuvVideo *Memento::AnalysisTabMemento::getRawVideo() {
	return rawVideo_;
}

void Memento::AnalysisTabMemento::setAnalysisBoxContainerMemento(std::unique_ptr<AnalysisBoxContainerMemento> analysisBoxMemento){
    analysisBoxMemento_ = std::move(analysisBoxMemento);
}

Memento::AnalysisBoxContainerMemento *Memento::AnalysisTabMemento::getAnalysisBoxContainerMemento(){
    return analysisBoxMemento_.get();
}

GUI::AnalysisGraph Memento::AnalysisTabMemento::getAnalysisGraph()
{
    return graph_;
}

void Memento::AnalysisTabMemento::setAnalysisGraph(GUI::AnalysisGraph graph)
{
    graph_=graph;
}

GUI::AnalysisVideo Memento::AnalysisTabMemento::getAnalysisVideo()
{
    return video_;
}

void Memento::AnalysisTabMemento::setAnalysisVideo(GUI::AnalysisVideo video)
{
    video_=video;
}

int Memento::AnalysisTabMemento::getPlayerPosition()
{
    return position_;
}

void Memento::AnalysisTabMemento::setPlayerPosition(int position)
{
    position_=position;
}
