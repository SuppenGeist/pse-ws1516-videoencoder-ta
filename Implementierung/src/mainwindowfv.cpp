#include "mainwindowfv.h"

#include <QHBoxLayout>
#include "gui/PreviewControlPanel.h"
#include "gui/GraphWidget.h"
#include "model/Graph.h"
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QRadialGradient>
#include "utility/PsnrCalculator.h"
#include "gui/FilterTab.h"

mainwindowfv::mainwindowfv(QWidget *parent):QMainWindow(parent) {
	setCentralWidget(new QWidget);
	QHBoxLayout *l=new QHBoxLayout;
	GUI::FilterTab* ft=new GUI::FilterTab(this);
	l->addWidget(ft);
	centralWidget()->setLayout(l);

}

