#include "FrameView.h"

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QPaintEvent>
#include <QImage>
#include <QRect>
#include <QSize>

GUI::FrameView::FrameView(QWidget* parent):QWidget(parent),xOffset_(0),yOffset_(0),
	originalFrame_(nullptr) {
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

void GUI::FrameView::setFrame(QImage& frame) {
	if(frame.isNull())
		return;

	originalFrame_=&frame;

	currentFrame_=originalFrame_->scaled(width(),height(),Qt::KeepAspectRatio);

	updateOffset();
	update();
}

void GUI::FrameView::clear() {
	originalFrame_=nullptr;
	update();
}

void GUI::FrameView::resizeEvent(QResizeEvent* event) {
	if( size().isEmpty() || !originalFrame_ )
		return;

	QSize eRect=event->size();
    currentFrame_=originalFrame_->scaled(eRect.width(),eRect.height(),Qt::KeepAspectRatio);

	updateOffset();
	update();
}

void GUI::FrameView::paintEvent(QPaintEvent* event) {
	if(visibleRegion().isEmpty())
		return;

	if(size().isEmpty())
		return;

	QPainter p(this);

	//Draw the default background color
    QColor defaultBackground(220,220,220);
	p.fillRect(event->rect(),QBrush(defaultBackground));

    p.drawRoundedRect(QRect(0,0,width()-1,height()-1),0,0);

	//Draw the frame
	if(originalFrame_) {
        p.drawPixmap(xOffset_+1,yOffset_+1,currentFrame_.width()-2,currentFrame_.height()-2,
		             QPixmap::fromImage(currentFrame_));
	}


	p.end();
}

void GUI::FrameView::updateOffset() {
	if(!originalFrame_)
		return;

	if(width()>currentFrame_.width()) {
		int diff=width()-currentFrame_.width();
		xOffset_=diff/2;
		yOffset_=0;
	} else if(height()>currentFrame_.height()) {
		int diff=height()-currentFrame_.height();
		xOffset_=0;
		yOffset_=diff/2;
	} else {
		xOffset_=0;
		yOffset_=0;
	}
}


