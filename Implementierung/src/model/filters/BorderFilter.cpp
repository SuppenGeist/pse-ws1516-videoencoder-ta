#include "BorderFilter.h"

#include <QString>
#include <QStringList>
#include <QColor>

#include <string>
#include <iomanip>

#include "Filter.h"

const QString Model::BorderFilter::FILTERNAME="Border";

Model::BorderFilter::BorderFilter():top_(true),bottom_(true),right_(true),left_(true),
	thickness_(35),color_(QColor(0,0,0)) {

}

bool Model::BorderFilter::getTop() {
	return top_;
}

void Model::BorderFilter::setTop(bool top) {
	top_ = top;
}

bool Model::BorderFilter::getBottom() {
	return bottom_;
}

void Model::BorderFilter::setBottom(bool bottom) {
	bottom_ = bottom;
}

bool Model::BorderFilter::getRight() {
	return right_;
}

void Model::BorderFilter::setRight(bool right) {
	right_ = right;
}

bool Model::BorderFilter::getLeft() {
	return left_;
}

void Model::BorderFilter::setLeft(bool left) {
	left_ = left;
}

int Model::BorderFilter::getThickness() {
	return thickness_;
}

void Model::BorderFilter::setThickness(int thickness) {
	if(thickness<0)
		return;
	thickness_ = thickness;
}

QColor Model::BorderFilter::getColor() {
	return color_;
}

void Model::BorderFilter::setColor(QColor color) {
	color_ = color;
}

QString Model::BorderFilter::getName() const {
	return FILTERNAME;
}

std::string Model::BorderFilter::getFilterDescription() {
	std::string str;
	std::string thickness=std::to_string(thickness_);
	std::string color=color_.name().toUtf8().constData();
	str+="pad=iw";
	if(right_) {
		str+="+"+thickness;
	}

	if(left_) {
		str+="+"+thickness;
	}
	str+=":ih";
	if(top_) {
		str+="+"+thickness;
	}

	if(bottom_) {
		str+="+"+thickness;
	}
	str+=":";
	if(right_ && left_) {
		str+="(ow-iw)/2:";
	} else if(right_ && !left_) {
		str+="0:";
	} else if(!right_ && left_) {
		str+=thickness+":";
	} else {
		str+="0:";
	}
	if(bottom_&& top_) {
		str+="(oh-ih)/2:";
	} else if(bottom_&& !top_) {
		str+="0:";
	} else if(!bottom_&& top_) {
		str+=thickness+":";
	} else {
		str+="0:";
	}

	str+=color;
	return str;
}

void Model::BorderFilter::restore(QString description) {
	QStringList list  = description.split(";");
	if(list.size()!=6)
		return;
	setTop(list[0].toInt());
	setBottom(list[1].toInt());
	setRight(list[2].toInt());
	setLeft(list[3].toInt());
	setThickness(list[4].toInt());
	setColor(QColor(list[5]));
}

QString Model::BorderFilter::getSaveString() const {
	QString str = QString::number(top_);
	str+=";";
	str+=QString::number(bottom_);
	str+=";";
	str+=QString::number(right_);
	str+=";";
	str+=QString::number(left_);
	str+=";";
	str+=QString::number(thickness_);
	str+=";";
	str+=color_.name();
	return str;
}
