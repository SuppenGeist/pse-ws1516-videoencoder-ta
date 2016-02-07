#ifndef __FilterApplier_h__
#define __FilterApplier_h__

#include <memory>
#include <string>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfiltergraph.h>
#include <libavfilter/buffersink.h>
#include <libavfilter/buffersrc.h>
#include <libavutil/opt.h>
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
	FilterApplier(Model::FilterList& list, int width, int height, int pixelFormat);

	~FilterApplier();

	/**
	 * @brief applyToVideo Applies the given filters to the video.
	 * @param target The video to which the new frames are added to.
	 * @param video The video to apply the filters on.
	 */
	void applyToVideo(Model::AVVideo& target, Model::AVVideo& video);

	/**
	 * @brief applyToFrame
	 * CAUTION: An owning pointer is returned.
	 * @param source
	 * @return
	 */
	AVFrame *applyToFrame(AVFrame& source);

  private:
	/**
	 * @brief initFilters Initializes the filters.
	 */
	void initFilters();

  private:
	int                 width_;
	int                 height_;
	int                 pixelFormat_;
	Model::FilterList*  list_;
	AVFilterGraph*      filterGraph_;
	AVFilterContext*    buffersinkContext_;
	AVFilterContext*    buffersourceContext_;
	std::string         filterDescription_;

	void createFilterString();
};
}

#endif
