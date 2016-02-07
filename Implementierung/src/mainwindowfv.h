#ifndef MAINWINDOWFV_H
#define MAINWINDOWFV_H

#include <QMainWindow>
#include <QWidget>
#include "gui/FrameView.h"
#include "model/Graph.h"

class mainwindowfv:public QMainWindow {
  public:
	mainwindowfv(QWidget *parent=0);
	Model::Graph g;
};

#endif // MAINWINDOWFV_H
