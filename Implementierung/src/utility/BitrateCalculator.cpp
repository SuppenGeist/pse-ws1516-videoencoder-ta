#include "BitrateCalculator.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include "../model/AVVideo.h"
#include "../model/Graph.h"

Utility::BitrateCalculator::BitrateCalculator(Model::AVVideo& video):video_(&video) {

}

Model::Graph Utility::BitrateCalculator::calculate() {
	Model::Graph bitrateGraph;

	for(std::size_t i=0; i<video_->getNumberOfFrames(); i++) {
		bitrateGraph.setValue(i,video_->getFrame(i)->pkt_size*8/(double)1000);
	}

	return std::move(bitrateGraph);
}
