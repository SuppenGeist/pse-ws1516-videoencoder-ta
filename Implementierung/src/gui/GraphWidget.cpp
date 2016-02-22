#include "GraphWidget.h"

#include <vector>

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRgb>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QColor>
#include <QDebug>
#include <QPolygon>
#include <QtCore/qmath.h>
#include <QGraphicsTextItem>
#include <QTextDocument>

#include "GlobalControlPanel.h"
#include "../model/Graph.h"


GUI::GraphWidget::GraphWidget(QWidget *parent):QGraphicsView(parent),controlPanel_(nullptr),
    graph_(nullptr),scene_(nullptr),calculator_(nullptr) {
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene_=new QGraphicsScene;
    setScene(scene_);

    connect(&updater_,SIGNAL(timeout()),this,SLOT(updateView()));
    updater_.start(500);
}

void GUI::GraphWidget::drawGraph(Model::Graph* graph) {
	if(graph==graph_)
		return;

	graph_=graph;
    calculator_->setGraph(graph);

	buildScene();
	update();
}

Model::Graph *GUI::GraphWidget::getGraph() {
    return graph_;
}

void GUI::GraphWidget::setGraphCalculator(GUI::GraphCalculator *calculator)
{
    calculator_=calculator;

    buildScene();
}

void GUI::GraphWidget::setControlPanel(GlobalControlPanel *panel) {
	controlPanel_=panel;
}

void GUI::GraphWidget::mouseReleaseEvent(QMouseEvent* event) {
	if(!controlPanel_) {
		return;
	}

    auto frame=calculator_->calculateFrame(event->pos().x(),event->pos().y(),sceneRect().width(),sceneRect().height());

	controlPanel_->setPosition(frame);
	controlPanel_->pause();
}

void GUI::GraphWidget::resizeEvent(QResizeEvent *event) {
	Q_UNUSED(event);

	buildScene();
}

void GUI::GraphWidget::updateView() {
	if(!graph_)
		return;
	buildScene();
	repaint();
}

void GUI::GraphWidget::buildScene() {
	auto visibleArea=mapToScene(viewport()->geometry()).boundingRect();

	const int vwidth=visibleArea.width();
	const int vheight=visibleArea.height();

    if(vwidth==0||vheight==0)
        return;

    calculator_->drawGraph(scene_,vwidth,vheight);
}


