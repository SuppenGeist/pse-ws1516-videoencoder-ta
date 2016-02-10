#ifndef __FilterTabMemento_h__
#define __FilterTabMemento_h__

#include <memory>

#include "../model/YuvVideo.h"
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

    Model::YuvVideo* getRawVideo();

    void setFilterList(Model::FilterList& filterlist);

    std::unique_ptr<Model::FilterList> getFilterList();

    void setIsPreviewShown(bool isShown);

    bool isPreviewShow();

private:
    Model::YuvVideo*                    rawVideo_;
    std::unique_ptr<Model::FilterList>  filterlist_;
    bool                                isPreviewShow_;

};
}

#endif

