#include <QApplication>
#include "gui/MainWindow.h"
#include "gui/FilterContainerTab.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavfilter/avfiltergraph.h>
#include <libavformat/avformat.h>
}

int main(int argc, char *argv[]) {
    av_register_all();
	avcodec_register_all();
	avfilter_register_all();

	QApplication a(argc, argv);
	GUI::MainWindow mw;
	mw.show();

	return a.exec();
}
