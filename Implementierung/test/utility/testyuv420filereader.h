#ifndef TESTYUV420FILEREADER_H
#define TESTYUV420FILEREADER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/utility/Yuv420FileReader.h"

class TestYuv420FileReader : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testParseNextFrame();

	void testReadNextVector();


  private:
	Utility::Yuv420FileReader fileReader_;

};

#endif // TESTYUV420FILEREADER_H
