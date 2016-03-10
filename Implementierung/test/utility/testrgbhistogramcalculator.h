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

class TestRGBHistogramCalculator : public QObject
{
    Q_OBJECT
private slots:
    void init();
    void testCalculate();
private:
        Model::GraphVideo*      red_;
        Model::GraphVideo*      green_;
        Model::GraphVideo*      blue_;
        Model::Video            video_;
        Utility::RGBHistogramCalculator* rgbHistogramCalculator_;
};

#endif // TESTRGBHISTOGRAMCALCULATOR_H
