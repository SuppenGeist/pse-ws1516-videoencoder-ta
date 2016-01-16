#include "mainwindow.h"
#include <QApplication>
#include <QImage>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>

#include "bitrate.h"
#include "graphics.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    QImage *image = new QImage("C:/Users/Carina/versuche pse/letzterversuch/trailerpark.jpg");


    bitrate bitrate;

    int bits = bitrate.getBitrate(image);

    w.addBitrate(bits);
    w.addPicture(image);
    w.show();





    return a.exec();
}
