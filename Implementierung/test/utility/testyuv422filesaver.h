#ifndef TESTYUV422FILESAVER_H
#define TESTYUV422FILESAVER_H

#include <QObject>
#include <QtTest/QtTest>

class TestYuv422FileSaver : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testRgb888ToYuv422();

  private:
	QRgb pixel1;
	QRgb pixel2;
};

#endif // TESTYUV422FILESAVER_H

