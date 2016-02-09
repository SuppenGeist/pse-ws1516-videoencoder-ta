#include "LoadAnalysisVideo.h"

#include <QUndoCommand>

#include "../gui/AnalysisTab.h"
#include "../model/YuvVideo.h"


UndoRedo::LoadAnalysisVideo::LoadAnalysisVideo(GUI::AnalysisTab* anaTab, std::unique_ptr<Model::YuvVideo> video) {
    video_ = std::move(video);
    anaTab_ = anaTab;

}

void UndoRedo::LoadAnalysisVideo::undo() {
    video_ = std::move(anaTab_->removeYuvVideo());
}

void UndoRedo::LoadAnalysisVideo::redo() {
   anaTab_->loadYuvVideo(std::move(video_));
}


