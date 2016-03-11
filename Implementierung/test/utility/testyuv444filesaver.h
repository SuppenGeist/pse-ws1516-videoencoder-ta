#ifndef TESTYUV444FILESAVER_H
#define TESTYUV444FILESAVER_H

#include <QObject>
#include <QtTest/QtTest>
#include <QColor>

class TestYuv444FileSaver : public QObject {
    Q_OBJECT

  private slots:
    void init();

    void testRgb888ToYuv444();

  private:
    QRgb pixel;

};

#endif // TESTYUV444FILESAVER_H

