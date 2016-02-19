#ifndef TESTCONTRASTFILTER_H
#define TESTCONTRASTFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/ContrastFilter.h"

class TestContrastFilter : public QObject
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
    Model::ContrastFilter   filter_;
};


#endif // TESTCONTRASTFILTER_H
