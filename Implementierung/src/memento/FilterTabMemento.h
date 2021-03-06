#ifndef __FilterTabMemento_h__
#define __FilterTabMemento_h__

#include <memory>

#include "../model/YuvVideo.h"
#include "../model/Video.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"

namespace Memento {
/**
 * This class is the memento for the FilterTab.
 */
class FilterTabMemento {

  public:
	/**
	 * @brief FilterTabMemento
	 */
	FilterTabMemento();

	void setRawVideo(Model::YuvVideo* rawVideo);

	void setRawVideo(std::unique_ptr<Model::YuvVideo> video);

	std::unique_ptr<Model::YuvVideo> releaseVideo();

	Model::YuvVideo* getRawVideo();

	void setFilterList(std::unique_ptr<Model::FilterList> filterlist);

	std::unique_ptr<Model::FilterList> getFilterList();

	void setIsPreviewShown(bool isShown);

	bool isPreviewShow();

	void setIsFilteredVideoShown(bool isShown);

	bool isFilteredVideoShown();

	void setCurrentFrame(int currentFrame);

	int getCurrentFrame();

	void setCurrentlySelectedFilter(int filter);

	int getCurrentlySelectedFilter();

  private:
	Model::YuvVideo*                    rawVideo_;
	std::unique_ptr<Model::YuvVideo>    ownedRawVideo_;
	std::unique_ptr<Model::FilterList>  filterlist_;
	bool                                isPreviewShown_;
	int                                 currentFrame_;
	int                                 currentlySelectedFilter_;
	bool                                isFilteredVideoShown_;



};
}

#endif

