#ifndef TESTRGBHISTOGRAMCALCULATOR_H
#define TESTRGBHISTOGRAMCALCULATOR_H

#include <QObject>
#include <QtTest/QtTest>
#include <QImage>
extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}
#include "../../src/model/Video.h"
#include "../../src/model/graphvideo.h"
#include "../../src/utility/RGBHistogramCalculator.h"

class TestRGBHistogramCalculator : public QObject {
	Q_OBJECT
  private slots:
	void init();
	void testCalculate();
  private:
	std::unique_ptr<Model::GraphVideo>      redHisto_;
	std::unique_ptr<Model::GraphVideo>      greenHisto_;
	std::unique_ptr<Model::GraphVideo>      blueHisto_;
	Model::Video            video_;
	std::unique_ptr<Utility::RGBHistogramCalculator> rgbHistoCalculator_;
};

#endif // TESTRGBHISTOGRAMCALCULATOR_H
