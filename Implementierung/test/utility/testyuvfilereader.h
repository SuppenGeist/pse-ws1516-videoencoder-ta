#ifndef TESTYUVFILEREADER_H
#define TESTYUVFILEREADER_H

#include <QObject>
#include <QtTest/QtTest>


class TestYuvFileReader : public QObject {
    Q_OBJECT

  private slots:
    void init();

    void testClamp();

  private:

};

#endif // TESTYUVFILEREADER_H
