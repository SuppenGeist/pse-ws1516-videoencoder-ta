#ifndef TESTSATURATIONFILTER_H
#define TESTSATURATIONFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/SaturationFilter.h"

class TestSaturationFilter : public QObject
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
    Model::SaturationFilter   filter_;
};

#endif // TESTSATURATIONFILTER_H
