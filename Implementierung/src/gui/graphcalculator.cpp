#include "graphcalculator.h"

#include <QPainter>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QTextDocument>
#include <qmath.h>

GUI::GraphCalculator::GraphCalculator():graph_(nullptr),fixedMaxYVal_(-1)
{
    QFont markFont;
    markFont.setPixelSize(7);

    QFont labelFont;
    labelFont.setPixelSize(12);

    setAxisLabels("x","y");
    setIsFilled(false);
    setMarkLength(5,3);
    setShowLabels(true);
    setMarkDistance(30,20);
    setLabelFont(labelFont);
    setMarkFont(markFont);

    updateLabelSizes();
}

void GUI::GraphCalculator::setGraph(Model::Graph *graph)
{
    graph_=graph;

    updateLabelSizes();
}

Model::Graph *GUI::GraphCalculator::getGraph()
{
    return graph_;
}

void GUI::GraphCalculator::setLinePen(QPen linePen)
{
    linePen_=linePen;
}

void GUI::GraphCalculator::setFillPen(QPen fillPen)
{
    fillPen_=fillPen;
}

void GUI::GraphCalculator::setFillBrush(QBrush fillBrush)
{
    fillBrush_=fillBrush;
}

void GUI::GraphCalculator::setAxisLabels(QString xLabel, QString yLabel)
{
    xLabel_=xLabel;
    yLabel_=yLabel;

    updateLabelSizes();
}

void GUI::GraphCalculator::setIsFilled(bool isFilled)
{
    isFilled_=isFilled;
}

void GUI::GraphCalculator::setShowLabels(bool showLabels)
{
    showLabels_=showLabels;
}

void GUI::GraphCalculator::setMarkLength(int xMarkLen, int yMarkLen)
{
    if(xMarkLen>=0)
        markLenX_=xMarkLen;
    if(yMarkLen>=0)
        markLenY_=yMarkLen;
}

void GUI::GraphCalculator::setBackgroundColor(QColor bColor)
{
    fillBrush_=QBrush(bColor,Qt::SolidPattern);
}

void GUI::GraphCalculator::setMarkDistance(int disX, int disY)
{
    if(disX>0) {
        markDistanceX_=disX;
    }
    if(disY>0) {
        markDistanceY_=disY;
    }
}

void GUI::GraphCalculator::setLabelFont(QFont labelFont)
{
    labelFont_=labelFont;

    updateLabelSizes();
}

void GUI::GraphCalculator::setMarkFont(QFont markFont)
{
    markFont_=markFont;

    updateLabelSizes();
}

void GUI::GraphCalculator::setFixedMaxYValue(double maxYVal)
{
    fixedMaxYVal_=maxYVal;
}

std::unique_ptr<QImage> GUI::GraphCalculator::toImage(int width, int height)
{
    auto img=std::make_unique<QImage>(width,height,QImage::Format_ARGB32_Premultiplied);
    QPainter painter(img.get());
    painter.setRenderHint(QPainter::Antialiasing);
    QGraphicsScene scene;
    buildScene(&scene,graph_,width,height);
    scene.render(&painter);
    painter.end();

    return std::move(img);
}

void GUI::GraphCalculator::drawGraph(QGraphicsScene *scene, int width, int height)
{
    buildScene(scene,graph_,width,height);
}

int GUI::GraphCalculator::calculateFrame(int x, int y, int vwidth, int vheight)
{
    if(!graph_) {
        return 0;
    }

    //Pixelcoordinates of the point (0|0)
    int zero_x=0;
    int zero_y=0;

    if(showLabels_) {
        zero_x=markLenY_+yLabelWidth_+5;
        zero_y=vheight-markLenX_-xLabelHeight_-markFont_.pixelSize();
    } else {
        zero_x=5;
        zero_y=vheight-5;
    }

    //Width and height of the coordinate system
    const int width_x=vwidth-zero_x;
    const int width_y=zero_y;

    //Biggest x and y val in the graph
    const std::size_t maxXVal=graph_->getSize();

    if(maxXVal==0)
        return 0;

    //Biggest drawable x and y val
    std::size_t max_x_val=maxXVal;

    //The number of pixel for each unit in the graph
    double space_x=((double)width_x)/(max_x_val-1);

    //Check if the click was on the actual graph
    if(!(x>zero_x&&x<=(zero_x+width_x))) {
        return 0;
    }
    if(!(y<=zero_y&&y>=(zero_y-width_y))) {
        return 0;
    }

    x=x-zero_x;

    int frame=x/space_x;
    if(x>frame*space_x+space_x/2) {
        frame++;
    }

    return frame;
}

int GUI::GraphCalculator::clamp(int val, int max, int min)
{
    if(val>max)
        return max;
    if(val<min)
        return min;
    return val;
}

void GUI::GraphCalculator::updateLabelSizes()
{
    QGraphicsTextItem xLab(xLabel_);
    QGraphicsTextItem yLab(yLabel_);
    xLab.setFont(labelFont_);
    yLab.setFont(labelFont_);

    xLabelHeight_=xLab.document()->size().height();
    if(xLabel_=="")
        xLabelHeight_=10;
    yLabelWidth_=yLab.document()->size().width();
    if(yLabel_=="")
        yLabelWidth_=0;

    if(graph_) {
        double val=graph_->getBiggestValue();
        if(fixedMaxYVal_>0)
            val=fixedMaxYVal_;
        QGraphicsTextItem yval(QString::number(qCeil(val)));
        yval.setFont(markFont_);
        yLabelWidth_+=yval.document()->size().width();
    }
}

void GUI::GraphCalculator::buildScene(QGraphicsScene *scene, Model::Graph *graph, int vwidth, int vheight)
{
    if(!scene)
        return;
    scene->clear();

    scene->setSceneRect(0,0,vwidth,vheight);
    scene->addRect(0,0,vwidth,vheight,QPen(QColor(255,255,255)),QBrush(QColor(255,255,255)));

    if(!graph)
        return;

    //Pixelcoordinates of the point (0|0)
    int zero_x=0;
    int zero_y=0;

    if(showLabels_) {
        zero_x=markLenY_+yLabelWidth_+5;
        zero_y=vheight-markLenX_-xLabelHeight_-markFont_.pixelSize();
    } else {
        zero_x=5;
        zero_y=vheight-5;
    }

    //zero_y=zero_y+20;

    zero_x++;
    zero_y--;

    //Width and height of the coordinate system
    int width_x=vwidth-zero_x-10;
    int width_y=zero_y-10;

    if(width_x<=0)
        width_x=1;
    if(width_y<=0)
        width_y=1;

    //Biggest x and y val in the graph
    const std::size_t maxXVal=graph->getSize();
    const double maxYVal=graph->getBiggestValue();

    if(maxXVal==0)
        return;

    //Biggest drawable x and y val
    std::size_t max_x_val=maxXVal;
    int max_y_val=qCeil(maxYVal);

    if(fixedMaxYVal_>0) {
        if(max_y_val>fixedMaxYVal_) {
            fixedMaxYVal_=max_y_val;
        }
        max_y_val=fixedMaxYVal_;
    }

    //The number of pixel for each unit in the graph
    double space_x=((double)width_x)/(max_x_val-1);
    double space_y=((double)width_y)/max_y_val;

    if(showLabels_) {
        zero_x--;
        zero_y++;
        int xMarks=clamp(width_x/markDistanceX_,max_x_val,1);
        int yMarks=clamp(width_y/markDistanceY_,max_y_val,1);

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

        for(int i=0; i<=yMarks; i++) {
            double point1_x=zero_x;
            double point1_y=zero_y-i*yMarkWidth;
            double point2_x=zero_x-markLenY_;
            double point2_y=zero_y-i*yMarkWidth;

            scene->addLine(point1_x,point1_y,point2_x,point2_y);

            auto lab=scene->addText(QString::number(i*ratioY),markFont_);
            lab->setPos(point2_x-lab->document()->size().width(),point2_y-lab->document()->size().height()/2);
        }
        for(int i=0; i<=xMarks; i++) {
            double point1_x=zero_x+i*xMarkWidth;
            double point1_y=zero_y;
            double point2_x=zero_x+i*xMarkWidth;
            double point2_y=zero_y+markLenX_;

            scene->addLine(point1_x,point1_y,point2_x,point2_y);

            auto lab=scene->addText(QString::number(i*ratioX),markFont_);
            lab->setPos(point2_x-lab->document()->size().width()/2,point2_y);
        }

        auto xLab=scene->addText(xLabel_,labelFont_);
        xLab->setPos(zero_x+width_x-xLab->document()->size().width(),
                     zero_y+markLenX_+markFont_.pixelSize());
        auto yLab=scene->addText(yLabel_,labelFont_);
        yLab->setPos(zero_x-markLenY_-yLabelWidth_,zero_y-width_y);

        zero_x++;
        zero_y--;
    }

    int last_x=0;
    double last_y=graph->getValue(last_x);

    for(std::size_t i=1; i<maxXVal; i++) {
        double val=clamp(graph->getValue(i),max_y_val,0);

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
            scene->addPolygon(pol,fillPen_,fillBrush_);
        }

        scene->addLine(point1_x,point1_y,point2_x,point2_y,linePen_);

        last_x=i;
        last_y=val;
    }
    zero_x--;
    zero_y++;
    //Draw coordinate system
    scene->addLine(zero_x,zero_y,zero_x+width_x,zero_y);
    scene->addLine(zero_x,zero_y-width_y,zero_x,zero_y);
}

