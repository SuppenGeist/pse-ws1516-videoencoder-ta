#ifndef TESTBITRATECALCULATOR_H
#define TESTBITRATECALCULATOR_H

#include <QObject>
#include <QtTest/QtTest>
#include <QImage>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
}

#include "../../src/model/AVVideo.h"
#include "../../src/model/Graph.h"
#include "../../src/utility/BitrateCalculator.h"


class TestBitrateCalculator : public QObject
{
    Q_OBJECT
private slots:
    void init();
    void testCalculate();
private:
        AVFrame* frame_;
        Model::Graph* graph_;
        Model::AVVideo* avVideo_;
        Utility::BitrateCalculator* bitrateCalculator_;
};

#endif // TESTBITRATECALCULATOR_H
