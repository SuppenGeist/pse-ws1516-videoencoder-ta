#ifndef TESTYUV411FILEREADER_H
#define TESTYUV411FILEREADER_H

#include <QObject>
#include <QtTest/QtTest>


class TestYuv411FileReader : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testYuv411ToRgb888();

};


#endif // TESTYUV411FILEREADER_H
