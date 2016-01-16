#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <sstream>
#include <QString>
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int size = 10;
    double points[size];
    for (int i = 0; i < size; i++) {
        points[i]=i*10;
    }

    QGraphicsScene *scene = new QGraphicsScene;
    for (int i = 0; i < size - 1; i++) {
            double x1 = i;
            double y1 = points[i];
            double x2 = i+1;
            double y2 = points[i+1];
            scene->addLine(x1, y1, x2, y2);
    }

    ui->graphicsView->setScene(scene);
}




void MainWindow::addBitrate(int bitrate) {
    std::ostringstream convert;
    convert << bitrate;
    std::string text = "Bitrate: " + convert.str();
    QString bits = QString::fromStdString(text);
    ui->textBrowser->setText(bits);

}

void MainWindow::addPicture(QImage *image){
    ui->label->setPixmap(QPixmap::fromImage(*image));
}


MainWindow::~MainWindow()
{
    delete ui;
}
