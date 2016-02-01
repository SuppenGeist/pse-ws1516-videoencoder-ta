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

#include "GlobalControlPanel.h"
#include "../model/Graph.h"

GUI::GraphWidget::GraphWidget(QWidget *parent):QGraphicsView(parent),lineColor_(QColor(0,0,0).rgb()),fillColor_(QColor(200,200,200).rgb()),controlPanel_(nullptr),scene_(nullptr),isFilled_(false) {
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    buildScene();
    setScene(scene_);
}

void GUI::GraphWidget::drawGraph(Model::Graph graph, bool filled) {
    isFilled_=filled;
    graph_=graph;
}

void GUI::GraphWidget::setLineColor(QRgb color) {
    lineColor_=color;
}

void GUI::GraphWidget::setFillColor(QRgb color) {
    fillColor_=color;
}

void GUI::GraphWidget::setControlPanel(GlobalControlPanel* panel) {
	throw "Not yet implemented";
}

void GUI::GraphWidget::mouseReleaseEvent(QMouseEvent* event) {
    //throw "Not yet implemented";
}

void GUI::GraphWidget::resizeEvent(QResizeEvent* event) {
    buildScene();
    update();
}

void GUI::GraphWidget::buildScene()
{
    if(!scene_) {
        scene_=new QGraphicsScene();
    }
    scene_->clear();

    auto visibleArea=mapToScene(viewport()->geometry()).boundingRect();

    const int marginWidth=10;
    const int marginHeight=10;

    const int cwidth=visibleArea.width()-5;
    const int cheight=visibleArea.height()-5;

    setSceneRect(QRect(0,0,cwidth,cheight));

    const int zero_x=marginWidth;
    const int zero_y=cheight-marginHeight;

    std::size_t maxVal=graph_.getLength();
    double space_x=((double)cwidth-2*marginWidth)/(maxVal-1);
    double space_y=((double)cheight-2*marginHeight)/graph_.getBiggestValue();

    //Draw coordinate system
    scene_->addLine(zero_x,zero_y,cwidth-marginWidth+1,cheight-marginHeight);
    scene_->addLine(marginWidth,marginHeight,marginWidth,zero_y);

    int last_x=0;
    int last_y=graph_.getValue(0);

    std::size_t len=graph_.getLength();
    for(std::size_t i=1;i<len;i++) {
        double val=graph_.getValue(i);
        QPen pen;
        pen.setColor(QColor(lineColor_));
        scene_->addLine(zero_x+last_x*space_x+1,zero_y-last_y*space_y-1,zero_x+i*space_x+1,zero_y-val*space_y-1,pen);
        if(isFilled_) {
            QPen pen;
            pen.setColor(QColor(fillColor_));
            QBrush b(Qt::BrushStyle::SolidPattern);
            b.setColor(QColor(fillColor_));
            QPolygon pol(5);
            pol.setPoint(0,zero_x+last_x*space_x+1,zero_y-last_y*space_y-1);
            pol.setPoint(1,zero_x+i*space_x+1,zero_y-val*space_y-1);
            pol.setPoint(2,zero_x+i*space_x+1,zero_y-1);
            pol.setPoint(3,zero_x+last_x*space_x+1,zero_y-1);
            pol.setPoint(4,zero_x+last_x*space_x+1,zero_y-last_y*space_y-1);
            scene_->addPolygon(pol,pen,b);
        }
        last_x=i;
        last_y=val;
    }
}
