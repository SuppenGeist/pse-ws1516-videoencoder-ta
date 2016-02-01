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

GUI::GraphWidget::GraphWidget(QWidget *parent):QGraphicsView(parent),lineColor_(QColor(0,0,0).rgb()),fillColor_(QColor(200,200,200).rgb()),controlPanel_(nullptr),scene_(nullptr),isFilled_(false),marginWidth_(5),marginHeight_(3),maxY_(-1),markLenX_(3),markLenY_(3),showLabels_(true) {
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setAchsisLabels("sec","bits");

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

void GUI::GraphWidget::setAchsisLabels(QString xLabel, QString yLabel) {
    QGraphicsTextItem xLab(xLabel);
    QGraphicsTextItem yLab(yLabel);

    xLabel_=xLabel;
    yLabel_=yLabel;

    xLabelHeight_=xLab.document()->size().height();
    yLabelWidth_=yLab.document()->size().width();
}

void GUI::GraphWidget::buildScene()
{
    if(!scene_) {
        scene_=new QGraphicsScene();
    }
    scene_->clear();

    //Get visible area (is not exact)
    auto visibleArea=mapToScene(viewport()->geometry()).boundingRect();

    //Width and height of the visible area
    const int vwidth=visibleArea.width()-5;
    const int vheight=visibleArea.height()-5;

    //Pixelcoordinates of the point (0|0)
    int zero_x=0;
    int zero_y=0;

    if(showLabels_) {
        zero_x=marginWidth_+markLenY_+yLabelWidth_;
        zero_y=vheight-marginHeight_-markLenX_-xLabelHeight_;
    }
    else {
        zero_x=marginWidth_+5;
        zero_y=vheight-marginHeight_-5;
    }

    //Width and height of the coordinate system
    const int width_x=vwidth-zero_x-marginWidth_;
    const int width_y=zero_y-marginHeight_;

    //Biggest x and y val in the graph
    const std::size_t maxXVal=graph_.getLength();
    const double maxYVal=graph_.getBiggestValue();

    if(maxXVal==0)
        return;

    //Biggest drawable x and y val
    std::size_t max_x_val=maxXVal;
    int max_y_val=qCeil(maxY_);

    //If no max y value is set.
    if(max_y_val<=0) {
        max_y_val=qCeil(maxYVal);
    }

    //The number of pixel for each unit in the graph
    double space_x=((double)width_x)/(max_x_val-1);
    double space_y=((double)width_y)/max_y_val;

    if(showLabels_) {
        static const int minimumPixelX=30;
        static const int minimumPixelY=20;

        int xMarks=clamp(width_x/minimumPixelX,max_x_val,1);
        int yMarks=clamp(width_y/minimumPixelY,max_y_val,1);

        int ratioX=(qCeil((width_x/(space_x*xMarks))));
        int ratioY=(qCeil((width_y/(space_y*yMarks))));

        double xMarkWidth=ratioX*space_x;
        double yMarkWidth=ratioY*space_y;

        //if there is wrong rounding.
        while(xMarkWidth*xMarks>width_x) {
            xMarks--;
        }
        while(yMarkWidth*yMarks>width_y) {
            yMarks--;
        }

        QFont labelFont;
        labelFont.setPixelSize(7);

        for(int i=0;i<=yMarks;i++) {
            double point1_x=zero_x;
            double point1_y=zero_y-i*yMarkWidth;
            double point2_x=zero_x-markLenY_;
            double point2_y=zero_y-i*yMarkWidth;

            scene_->addLine(point1_x,point1_y,point2_x,point2_y);

            auto lab=scene_->addText(QString::number(i*ratioY+1),labelFont);
            lab->setPos(point2_x-lab->document()->size().width(),point2_y-lab->document()->size().height()/2);

        }
        for(int i=0;i<=xMarks;i++) {
            double point1_x=zero_x+i*xMarkWidth;
            double point1_y=zero_y;
            double point2_x=zero_x+i*xMarkWidth;
            double point2_y=zero_y+markLenX_;

            scene_->addLine(point1_x,point1_y,point2_x,point2_y);

            auto lab=scene_->addText(QString::number(i*ratioX+1),labelFont);
            lab->setPos(point2_x-lab->document()->size().width()/2,point2_y);
        }

        auto xLab=scene_->addText(xLabel_);
        xLab->setPos(zero_x+width_x-xLab->document()->size().width(),vheight-xLabelHeight_);
        auto yLab=scene_->addText(yLabel_);
        yLab->setPos(0,0);

    }

    int last_x=0;
    double last_y=graph_.getValue(last_x);

    QPen pen;
    pen.setColor(QColor(lineColor_));

    QPen pen1;
    pen.setColor(QColor(fillColor_));
    QBrush b(Qt::BrushStyle::SolidPattern);
    b.setColor(QColor(fillColor_));

    for(std::size_t i=1;i<maxXVal;i++) {
        double val=graph_.getValue(i);

        //Functionality for non steady graphs
        if(val<0) {
            last_y=-1;
            last_x=i;
            continue;
        }
        if(last_y<0) {
            last_y=val;
            last_x=i;
            continue;
        }

        double point1_x=clamp(zero_x+last_x*space_x,width_x+zero_x,zero_x);
        double point1_y=clamp(zero_y-last_y*space_y,zero_y,zero_y-width_y);
        double point2_x=clamp(zero_x+i*space_x,width_x+zero_x,zero_x);
        double point2_y=clamp(zero_y-val*space_y,zero_y,zero_y-width_y);

        if(isFilled_) {
            double point3_x=clamp(zero_x+i*space_x,width_x+zero_x,zero_x);
            double point3_y=clamp(zero_y,zero_y,zero_y-width_y);
            double point4_x=clamp(zero_x+last_x*space_x,width_x+zero_x,zero_x);
            double point4_y=clamp(zero_y,zero_y,zero_y-width_y);

            QPolygon pol(5);
            pol.setPoint(0,point1_x,point1_y);
            pol.setPoint(1,point2_x,point2_y);
            pol.setPoint(2,point3_x,point3_y);
            pol.setPoint(3,point4_x,point4_y);
            pol.setPoint(4,point1_x,point1_y);
            scene_->addPolygon(pol,pen1,b);
        }

        scene_->addLine(point1_x,point1_y,point2_x,point2_y,pen1);

        last_x=i;
        last_y=val;
    }

    //Draw coordinate system
    scene_->addLine(zero_x,zero_y,zero_x+width_x,zero_y);
    scene_->addLine(zero_x,zero_y-width_y,zero_x,zero_y);

    setSceneRect(QRect(0,0,vwidth,vheight));
}

int GUI::GraphWidget::clamp(int val, int max, int min)
{
    if(val>max)
        return max;
    if(val<min)
        return min;
    return val;

}
