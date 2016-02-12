#include "FilterApplier.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfiltergraph.h>
#include <libavfilter/buffersink.h>
#include <libavfilter/buffersrc.h>
#include <libavutil/opt.h>
}

#include <memory>
#include <stdexcept>
#include <string>
#include <thread>

#include <QDebug>
#include <QString>

#include "../model/FilterList.h"
#include "../model/Video.h"
#include "../model/AVVideo.h"
#include "../model/filters/Filter.h"
#include "../gui/FilterTab.h"
#include "VideoConverter.h"

Utility::FilterApplier::FilterApplier(Model::FilterList& list, int width, int height,
                                      int pixelFormat):width_(width),height_(height),pixelFormat_(pixelFormat),list_(&list),isRunning_(false) {
	createFilterString();
	initFilters();
}

Utility::FilterApplier::~FilterApplier() {
	if(filterGraph_) {
		avfilter_graph_free(&filterGraph_);
	}
    isRunning_=false;
    if(applier_.joinable()) {
        applier_.join();
    }
}

void Utility::FilterApplier::applyToVideo(Model::Video &target, Model::Video &source,GUI::FilterTab* filtertab)
{
    if(isRunning_)
        return;

    filterTab_=filtertab;
    target_=&target;
    source_=&source;

    applier_=std::thread(&FilterApplier::applyToVideoP,this);
}

void Utility::FilterApplier::applyToVideo(Model::Video &target, Model::AVVideo &source)
{
    if(isRunning_)
        return;
    target_=&target;
    source1_=&source;

    applier_=std::thread(&FilterApplier::applyToAVVideoP,this);
}

AVFrame* Utility::FilterApplier::applyToFrame(AVFrame &source) {
	auto frame=av_frame_alloc();

	if(av_buffersrc_add_frame_flags(buffersourceContext_, &source, AV_BUFFERSRC_FLAG_KEEP_REF) < 0) {
		av_frame_free(&frame);
		throw std::runtime_error("Could not feed the frame into the filtergraph.");
	}

	if(av_buffersink_get_frame(buffersinkContext_, frame)<0) {
		av_frame_free(&frame);
		throw std::runtime_error("Could not pull the filtered frame from the filtergraph.");
	}

	return frame;
}

void Utility::FilterApplier::initFilters() {
	int ret=0;

	filterGraph_=avfilter_graph_alloc();
	if(!filterGraph_) {
		throw std::runtime_error("Could not create filtergraph");
	}

	AVFilter *buffersrc  = avfilter_get_by_name("buffer");
	AVFilter *buffersink = avfilter_get_by_name("buffersink");

	std::string args="video_size="+std::to_string(width_)+"x"+std::to_string(
	                     height_)+":pix_fmt="+std::to_string(pixelFormat_)+":time_base=1/1";
	ret=avfilter_graph_create_filter(&buffersourceContext_, buffersrc, "in",args.c_str(), NULL,
	                                 filterGraph_);
	if(ret<0) {
		throw std::runtime_error("Could not create the buffersource for the filtergraph.");
	}

	ret = avfilter_graph_create_filter(&buffersinkContext_, buffersink, "out",NULL, NULL, filterGraph_);
	if(ret<0) {
		throw std::runtime_error("Could not create the buffersink for the filtergraph.");
	}

	enum AVPixelFormat pixelFormats[]= {AV_PIX_FMT_RGB24,AV_PIX_FMT_NONE};
	ret = av_opt_set_int_list(buffersinkContext_, "pix_fmts", pixelFormats,AV_PIX_FMT_NONE,
	                          AV_OPT_SEARCH_CHILDREN);
	if (ret < 0) {
		throw std::runtime_error("Could net set output pixelformat for the graph");
	}

	AVFilterInOut *outputs = avfilter_inout_alloc();
	AVFilterInOut *inputs  = avfilter_inout_alloc();

	outputs->name       = av_strdup("in");
	outputs->filter_ctx = buffersourceContext_;
	outputs->pad_idx    = 0;
	outputs->next       = NULL;

	inputs->name       = av_strdup("out");
	inputs->filter_ctx = buffersinkContext_;
	inputs->pad_idx    = 0;
	inputs->next       = NULL;

	ret = avfilter_graph_parse_ptr(filterGraph_, filterDescription_.c_str(), &inputs, &outputs, NULL);
	if(ret<0) {
		avfilter_inout_free(&inputs);
		avfilter_inout_free(&outputs);
		throw std::runtime_error("Could not parse the filter descritopns.");
	}

	ret = avfilter_graph_config(filterGraph_, NULL);
	if(ret<0) {
		avfilter_inout_free(&inputs);
		avfilter_inout_free(&outputs);
		throw std::runtime_error("Could not configure filtergraph.");
	}

}

void Utility::FilterApplier::createFilterString() {
	if(list_->getSize()==0) {
		filterDescription_="null";
		return;
	}
	for(std::size_t i =0; i<list_->getSize(); i++) {
		filterDescription_+=list_->getFilter(i)->getFilterDescription();
		if(i!=list_->getSize()-1) {
			filterDescription_+=",";
		}
    }
}

void Utility::FilterApplier::applyToVideoP()
{
    isRunning_=true;
    std::size_t i=0;
    do {
    for(;i<source_->getNumberOfFrames()&&isRunning_;i++) {
        auto image=VideoConverter::convertQImageToAVFrame(*source_->getFrame(i));
        auto filteredImage=applyToFrame(*image);
        target_->appendFrame(VideoConverter::convertAVFrameToQImage(*filteredImage));

        av_frame_free(&image);
        av_frame_free(&filteredImage);
    }
    if(source_->isComplete()) {
        break;
    }
    }while(isRunning_);
    target_->setIsComplete(true);
    if(filterTab_) {
        filterTab_->applyComplete(isRunning_);
    }
    isRunning_=false;
}

void Utility::FilterApplier::applyToAVVideoP()
{
    isRunning_=true;
    for(std::size_t i=0;i<source1_->getNumberOfFrames()&&isRunning_;i++) {
        auto filteredImage=applyToFrame(*source1_->getFrame(i));
        target_->appendFrame(VideoConverter::convertAVFrameToQImage(*filteredImage));

        av_frame_free(&filteredImage);
    }
    isRunning_=false;
}

