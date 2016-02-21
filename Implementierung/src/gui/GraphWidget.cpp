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
	graph_(nullptr),scene_(nullptr),fixedMaxYVal_(-1) {
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
	buildScene();

    connect(&updater_,SIGNAL(timeout()),this,SLOT(updateView()));
}

void GUI::GraphWidget::drawGraph(Model::Graph* graph) {
	if(graph==graph_)
		return;

	graph_=graph;

    updater_.start(500);

	updateLabelSizes();
	buildScene();
	update();
}

Model::Graph *GUI::GraphWidget::getGraph() {
	return graph_;
}

void GUI::GraphWidget::setLinePen(QPen linePen) {
	linePen_=linePen;

	buildScene();
	update();
}

void GUI::GraphWidget::setFillPen(QPen fillPen) {
	fillPen_=fillPen;

	buildScene();
	update();
}

void GUI::GraphWidget::setFillBrush(QBrush fillBrush) {
	fillBrush_=fillBrush;

	buildScene();
	update();
}

void GUI::GraphWidget::setControlPanel(GlobalControlPanel *panel) {
	controlPanel_=panel;
}

void GUI::GraphWidget::setAxisLabels(QString xLabel, QString yLabel) {
	xLabel_=xLabel;
	yLabel_=yLabel;

	updateLabelSizes();
	buildScene();
	update();
}

void GUI::GraphWidget::setIsFilled(bool isFilled) {
	isFilled_=isFilled;

	buildScene();
	update();
}

void GUI::GraphWidget::setShowLabels(bool showLabels) {
	showLabels_=showLabels;

	buildScene();
	update();
}

void GUI::GraphWidget::setMarkLength(int xMarkLen, int yMarkLen) {
	if(xMarkLen>=0)
		markLenX_=xMarkLen;
	if(yMarkLen>=0)
		markLenY_=yMarkLen;

	buildScene();
	update();
}

void GUI::GraphWidget::setBackgroundColor(QColor bColor) {
	scene_->setBackgroundBrush(QBrush(bColor,Qt::SolidPattern));

	buildScene();
	update();
}

void GUI::GraphWidget::setMarkDistance(int disX, int disY) {
	if(disX>0) {
		markDistanceX_=disX;
	}
	if(disY>0) {
		markDistanceY_=disY;
	}

	buildScene();
	update();
}

void GUI::GraphWidget::setLabelFont(QFont labelFont) {
	labelFont_=labelFont;

	updateLabelSizes();
	buildScene();
	update();
}

void GUI::GraphWidget::setMarkFont(QFont markFont) {
	markFont_=markFont;

	updateLabelSizes();
	buildScene();
	update();
}

void GUI::GraphWidget::setFixedMaxYValue(double maxYVal) {
	fixedMaxYVal_=maxYVal;
}

void GUI::GraphWidget::mouseReleaseEvent(QMouseEvent* event) {
	if(!controlPanel_) {
		return;
	}

	if(!graph_) {
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
		return;

	//Biggest drawable x and y val
	std::size_t max_x_val=maxXVal;

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
	if(!scene_) {
		scene_=new QGraphicsScene();
        setScene(scene_);
    }

	auto visibleArea=mapToScene(viewport()->geometry()).boundingRect();

	const int vwidth=visibleArea.width();
	const int vheight=visibleArea.height();

    buildScene(scene_,graph_,vwidth,vheight);

	setSceneRect(QRect(0,0,vwidth,vheight));
}

QImage GUI::GraphWidget::graphToImage(Model::Graph *graph, int width, int height)
{

}

int GUI::GraphWidget::clamp(int val, int max, int min) {
	if(val>max)
		return max;
	if(val<min)
		return min;
	return val;

}

void GUI::GraphWidget::updateLabelSizes() {
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

void GUI::GraphWidget::buildScene(QGraphicsScene *scene, Model::Graph *graph, int vwidth, int vheight)
{
    if(!scene)
        return;

    scene->clear();

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

            scene_->addLine(point1_x,point1_y,point2_x,point2_y);

            auto lab=scene_->addText(QString::number(i*ratioY),markFont_);
            lab->setPos(point2_x-lab->document()->size().width(),point2_y-lab->document()->size().height()/2);
        }
        for(int i=0; i<=xMarks; i++) {
            double point1_x=zero_x+i*xMarkWidth;
            double point1_y=zero_y;
            double point2_x=zero_x+i*xMarkWidth;
            double point2_y=zero_y+markLenX_;

            scene->addLine(point1_x,point1_y,point2_x,point2_y);

            auto lab=scene_->addText(QString::number(i*ratioX),markFont_);
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
