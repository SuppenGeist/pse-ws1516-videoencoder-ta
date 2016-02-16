#include "AnalysisTabMemento.h"

#include "../model/YuvVideo.h"

Memento::AnalysisTabMemento::AnalysisTabMemento():rawVideo_(nullptr) {

}

void Memento::AnalysisTabMemento::setRawVideo(Model::YuvVideo *video) {
	rawVideo_=video;
}

Model::YuvVideo *Memento::AnalysisTabMemento::getRawVideo() {
	return rawVideo_;
}

void Memento::AnalysisTabMemento::setAnalysisBoxMemento(Memento::AnalysisBoxMemento* analysisBoxMemento){
    analysisBoxMemento_ = analysisBoxMemento;
}

Memento::AnalysisBoxMemento *Memento::AnalysisTabMemento::getAnalysisBoxMemento(){
    return analysisBoxMemento_;
}
