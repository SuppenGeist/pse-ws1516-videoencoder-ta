#ifndef TESTYUV422FILEREADER_H
#define TESTYUV422FILEREADER_H

#include <QObject>
#include <QtTest/QtTest>



class TestYuv422FileReader : public QObject {
	Q_OBJECT

  private slots:
	void init();

    void testYuv422ToRgb888();

};

#endif // TESTYUV422FILEREADER_H
