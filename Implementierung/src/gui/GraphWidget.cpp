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

GUI::GraphWidget::GraphWidget(QWidget *parent):QGraphicsView(parent),controlPanel_(nullptr),graph_(nullptr),scene_(nullptr) {
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setAxisLabels("x","y");
    setIsFilled(false);
    setMargin(5,3);
    setMaxYValue(-1);
    setMarkLength(5,3);
    setShowLabels(true);

    buildScene();
    setScene(scene_);
}

void GUI::GraphWidget::drawGraph(Model::Graph& graph) {
    graph_=&graph;
    buildScene();
    update();
}

void GUI::GraphWidget::setLinePen(QPen linePen)
{
    linePen_=linePen;
}

void GUI::GraphWidget::setFillPen(QPen fillPen)
{
    fillPen_=fillPen;
}

void GUI::GraphWidget::setFillBrush(QBrush fillBrush)
{
    fillBrush_=fillBrush;
}

void GUI::GraphWidget::setControlPanel(GlobalControlPanel& panel) {
    controlPanel_=&panel;
}

void GUI::GraphWidget::setAxisLabels(QString xLabel, QString yLabel)
{
    QGraphicsTextItem xLab(xLabel);
    QGraphicsTextItem yLab(yLabel);

    xLabel_=xLabel;
    yLabel_=yLabel;

    xLabelHeight_=xLab.document()->size().height();
    yLabelWidth_=yLab.document()->size().width();
}

void GUI::GraphWidget::setIsFilled(bool isFilled)
{
    isFilled_=isFilled;
}

void GUI::GraphWidget::setMargin(int marginX, int marginY)
{
    marginWidth_=marginX;
    marginHeight_=marginY;
}

void GUI::GraphWidget::setShowLabels(bool showLabels)
{
    showLabels_=showLabels;
}

void GUI::GraphWidget::setMaxYValue(double value)
{
    maxY_=value;
}

void GUI::GraphWidget::setMarkLength(int xMarkLen, int yMarkLen)
{
    markLenX_=xMarkLen;
    markLenY_=yMarkLen;
}

void GUI::GraphWidget::setBackgroundColor(QColor bColor)
{
    scene_->setBackgroundBrush(QBrush(bColor,Qt::SolidPattern));
}

void GUI::GraphWidget::mouseReleaseEvent(QMouseEvent* event) {
    if(!controlPanel_) {
        return;
    }

    int x=event->pos().x();
    int y=event->pos().y();

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
    const std::size_t maxXVal=graph_->getSize();
    const double maxYVal=graph_->getBiggestValue();

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

    //Check if the click was on the actual graph
    if(!(x>zero_x&&x<=(zero_x+width_x))) {
        return;
    }
    if(!(y<=zero_y&&y>=(zero_y-width_y))) {
        return;
    }

    x=x-zero_x;

    int frame=x/space_x;
    if(x>frame*space_x+space_x/2) {
        frame++;
    }
    controlPanel_->setPosition(frame);

}

void GUI::GraphWidget::resizeEvent(QResizeEvent* event) {
    Q_UNUSED(event);

    buildScene();
    update();
}

void GUI::GraphWidget::buildScene()
{
    if(!scene_) {
        scene_=new QGraphicsScene();
    }
    scene_->clear();

    if(!graph_)
        return;

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
    const std::size_t maxXVal=graph_->getSize();
    const double maxYVal=graph_->getBiggestValue();

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

            auto lab=scene_->addText(QString::number(i*ratioY),labelFont);
            lab->setPos(point2_x-lab->document()->size().width(),point2_y-lab->document()->size().height()/2);

        }
        for(int i=0;i<=xMarks;i++) {
            double point1_x=zero_x+i*xMarkWidth;
            double point1_y=zero_y;
            double point2_x=zero_x+i*xMarkWidth;
            double point2_y=zero_y+markLenX_;

            scene_->addLine(point1_x,point1_y,point2_x,point2_y);

            auto lab=scene_->addText(QString::number(i*ratioX),labelFont);
            lab->setPos(point2_x-lab->document()->size().width()/2,point2_y);
        }

        auto xLab=scene_->addText(xLabel_);
        xLab->setPos(zero_x+width_x-xLab->document()->size().width(),vheight-xLabelHeight_);
        auto yLab=scene_->addText(yLabel_);
        yLab->setPos(0,0);

    }

    int last_x=0;
    double last_y=graph_->getValue(last_x);

    for(std::size_t i=1;i<maxXVal;i++) {
        double val=graph_->getValue(i);

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
            scene_->addPolygon(pol,fillPen_,fillBrush_);
        }

        scene_->addLine(point1_x,point1_y,point2_x,point2_y,linePen_);

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
