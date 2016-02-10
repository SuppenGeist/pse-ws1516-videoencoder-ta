#include "LoadFilterVideo.h"

#include <memory>

#include "../gui/FilterTab.h"
#include "../memento/FilterTabMemento.h"
#include "../model/YuvVideo.h"

UndoRedo::LoadFilterVideo::LoadFilterVideo(GUI::FilterTab& filterTab,
        std::unique_ptr<Model::YuvVideo> video,
        std::unique_ptr<Memento::FilterTabMemento> memento):memento_(std::move(memento)),
	filterTab_(&filterTab),video_(std::move(video)) {

}

void UndoRedo::LoadFilterVideo::undo() {
	filterTab_->restore(memento_.get());
}

void UndoRedo::LoadFilterVideo::redo() {
	filterTab_->setRawVideo(video_.get());
}


