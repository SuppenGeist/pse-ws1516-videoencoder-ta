#ifndef TESTYUVFILESAVER_H
#define TESTYUVFILESAVER_H

#include <QObject>
#include <QtTest/QtTest>
#include <QColor>

class TestYuvFileSaver : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testRgbToY();

	void testRgbToU();

	void testRgbToV();

  private:
	QRgb pixel;

};

#endif // TESTYUVFILESAVER_H
