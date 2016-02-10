#include <QApplication>
#include "gui/MainWindow.h"
#include "gui/FilterContainerTab.h"
#include "mainwindowfv.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavfilter/avfiltergraph.h>
}

int main(int argc, char *argv[]) {
	avcodec_register_all();
	avfilter_register_all();

	QApplication a(argc, argv);
	GUI::MainWindow mw;
	mw.show();

	return a.exec();
}
