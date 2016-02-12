#ifndef TESTSEPIAFILTER_H
#define TESTSEPIAFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/SepiaFilter.h"

class TestSepiaFilter : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void testGetName();

    void testGetFilterDescription();

private:
    Model::SepiaFilter   filter_;
};

#endif // TESTSEPIAFILTER_H
