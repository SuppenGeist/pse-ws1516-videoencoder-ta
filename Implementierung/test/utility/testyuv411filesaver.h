#ifndef TESTYUV411FILESAVER_H
#define TESTYUV411FILESAVER_H

#include <QObject>
#include <QtTest/QtTest>


class TestYuv411FileSaver : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testRgb888ToYuv411();

  private:
	QRgb pixel1;
	QRgb pixel2;
	QRgb pixel3;
	QRgb pixel4;

};


#endif // TESTYUV411FILESAVER_H


