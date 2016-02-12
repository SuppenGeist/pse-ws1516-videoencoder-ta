#ifndef TESTSHARPNESSFILTER_H
#define TESTSHARPNESSFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/SharpnessFilter.h"

class TestSharpnessFilter : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void testSetIntensity();

    void testRestore();

    void testGetSaveString();

    void testFilterCopy();

    void testGetFilterdescrition();

private:
    Model::SharpnessFilter   filter_;
};


#endif // TESTSHARPNESSFILTER_H
