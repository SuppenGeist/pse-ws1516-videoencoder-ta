#ifndef __FilterApplier_h__
#define __FilterApplier_h__

#include <memory>
#include <string>
#include <thread>

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
class Video;
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

    void applyToVideo(Model::Video& target, Model::Video& source);

    void applyToVideo(Model::Video& target,Model::AVVideo& source);

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
    std::thread         applier_;
    Model::Video*       source_;
    Model::AVVideo*     source1_;
    Model::Video*       target_;
    bool                isRunning_;

	void createFilterString();
    void applyToVideoP();
    void applyToAVVideoP();
};
}

#endif
