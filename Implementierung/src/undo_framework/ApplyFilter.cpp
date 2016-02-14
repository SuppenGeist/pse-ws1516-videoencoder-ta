#include "ApplyFilter.h"

#include <memory>

extern "C" {
#include <libavutil/pixfmt.h>
}

#include "../gui/FilterTab.h"
#include "../model/Video.h"
#include "../utility/FilterApplier.h"

UndoRedo::ApplyFilter::ApplyFilter(GUI::FilterTab& filterTab, Model::Video *origVideo,
                                   std::unique_ptr<Model::FilterList> filterlist):filterTab_(&filterTab),originalVideo_(origVideo),
	filterlist_(std::move(filterlist)) {
	filteredVideo_=std::make_unique<Model::Video>(origVideo->getFps());
	applier_=std::make_unique<Utility::FilterApplier>(*filterlist_,origVideo->getWidth(),
	         origVideo->getHeight(),AV_PIX_FMT_RGB24);
	applier_->applyToVideo(*filteredVideo_,*origVideo,&filterTab);
	originalVideo_=origVideo;
	memento_=filterTab.getMemento();
}

void UndoRedo::ApplyFilter::undo() {
	filterTab_->restore(memento_.get());
}

void UndoRedo::ApplyFilter::redo() {
	filterTab_->setFilteredVideo(filteredVideo_.get());
	filterTab_->showFilteredVideo();
}
