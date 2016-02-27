#include "maintestsuite.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavfilter/avfiltergraph.h>
#include <libavformat/avformat.h>
}

int main(int argc,char* argv[]) {
    av_register_all();
    avcodec_register_all();
    avfilter_register_all();
	MainTestSuit mainTestSuite(argc,argv);
	mainTestSuite.runAllTests();

}
