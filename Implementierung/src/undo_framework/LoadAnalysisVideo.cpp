#include "LoadAnalysisVideo.h"

#include <QUndoCommand>

#include "../gui/AnalysisTab.h"
#include "../model/YuvVideo.h"


UndoRedo::LoadAnalysisVideo::LoadAnalysisVideo(GUI::AnalysisTab* anaTab,
        std::unique_ptr<Model::YuvVideo> video):anaTab_(anaTab),rawVideo_(std::move(video)) {
    memento_=anaTab->getMemento();
}

void UndoRedo::LoadAnalysisVideo::undo() {
    anaTab_->restore(memento_.get());
}

void UndoRedo::LoadAnalysisVideo::redo() {
    anaTab_->setRawVideo(rawVideo_.get());
}


