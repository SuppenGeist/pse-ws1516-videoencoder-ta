#ifndef TESTBLURFILTER_H
#define TESTBLURFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/BlurFilter.h"

class TestBlurFilter : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void testSetIntensity();

    void testRestore();

    void testGetSaveString();

private:
    Model::BlurFilter   testFilter_;
};

#endif // TESTBLURFILTER_H
