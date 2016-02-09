#ifndef TESTBRIGHTNESSFILTER_H
#define TESTBRIGHTNESSFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/BrightnessFilter.h"

class TestBrightnessFilter : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void testSetIntensity();

    void testRestore();

    void testGetSaveString();

    void testFilterCopy();

    void testGetFilterDescription();

private:
    Model::BrightnessFilter   filter_;
};

#endif // TESTBRIGHTNESSFILTER_H
