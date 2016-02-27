#ifndef TESTYUV444FILEREADER_H
#define TESTYUV444FILEREADER_H

#include <QObject>
#include <QtTest/QtTest>


class TestYuv444FileReader : public QObject {
	Q_OBJECT

  private slots:
	void init();

    void testYuv444ToRgb888();

  private:

};

#endif // TESTYUV444FILEREADER_H
