#ifndef __FilterApplier_h__
#define __FilterApplier_h__

#include <memory>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

namespace Model {
class FilterList;
class AVVideo;
}

namespace Utility {
/**
 * Applies filters of a given FilterList to a video.
 */
class FilterApplier {
  public:
    /**
     * @brief FilterApplier Constructor.
     * @param list The list with the filters to apply.
     */
    FilterApplier(Model::FilterList& list);

    /**
     * @brief applyToVideo Applies the given filters to the video.
     * @param target The video to which the new frames are added to.
     * @param video The video to apply the filters on.
     */
    void applyToVideo(Model::AVVideo& target, Model::AVVideo& video);

  private:
    /**
     * @brief initFilters Initializes the filters.
     */
    void initFilters();

  private:
    Model::FilterList* list_;

    /**
     * @brief applyToFrame Applies the filters to one frame.
     * @param frame The frame to apply the filters on.
     * @return The filtered frame.
     */
    std::unique_ptr<AVFrame> applyToFrame(AVFrame& frame);
};
}

#endif
