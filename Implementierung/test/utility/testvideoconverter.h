#ifndef TESTVIDEOCONVERTER_H
#define TESTVIDEOCONVERTER_H

#include <QObject>
#include <QtTest/QtTest>
#include <QImage>
extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}
#include "../../src/model/AVVideo.h"
#include "../../src/model/Video.h"

class TestVideoConverter : public QObject {
	Q_OBJECT
  private slots:
	void init();
	void testConvertAVFrameToQImage();
	void testConvertQImageToAVFrame();
	void testConvertGraphToImage();
  private:
	AVFrame* frame_;
	Model::AVVideo* avVideo_;
	Model::Video video_;
	QImage* image_;
};

#endif // TESTVIDEOCONVERTER_H
