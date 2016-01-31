#include <QApplication>
#include "gui/MainWindow.h"
#include "gui/FilterContainerTab.h"

extern "C" {
#include <libavcodec/avcodec.h>
}

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	avcodec_register_all();
	GUI::MainWindow mw;
	mw.show();

	return a.exec();
}
