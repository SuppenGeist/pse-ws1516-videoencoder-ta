#ifndef TESTROTATIONFILTER_H
#define TESTROTATIONFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/RotationFilter.h"

class TestRotationFilter : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void testSetAngle();

    void testRestore();

    void testGetSaveString();

    void testGetFilterDescrition();

    void testFilterCopy();

private:
    Model::RotationFilter   filter_;
};

#endif // TESTROTATIONFILTER_H
