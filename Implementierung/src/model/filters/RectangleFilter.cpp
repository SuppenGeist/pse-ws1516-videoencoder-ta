#include "RectangleFilter.h"

#include <QString>
#include <QStringList>
#include <QColor>
#include <iomanip>

#include "Filter.h"

const QString Model::RectangleFilter::FILTERNAME="Rectangle";

Model::RectangleFilter::RectangleFilter():x_(10),y_(20),width_(100),height_(60),color_(QColor(0,0,
	        0)),opacity_(255) {
}

std::string Model::RectangleFilter::getFilterDescription() {
	std::stringstream stream;
	stream << std::hex << opacity_;
	std::string str = std::string("drawbox");
	str+="=";
	str+="x";
	str+="=";
	str+=std::to_string(x_);
	str+=":";
	str+="y";
	str+="=";
	str+=std::to_string(y_);
	str+=":";
	str+="w";
	str+="=";
	str+=std::to_string(width_);
	str+=":";
	str+="h";
	str+="=";
	str+=std::to_string(height_);
	str+=":";
	str+="color";
	str+="=";
	str+=color_.name().toUtf8().constData();
	str+="@0x";
	str+=stream.str();
	str+=":t=max";
	return str;
}

QColor Model::RectangleFilter::getColor() {
	return color_;
}

void Model::RectangleFilter::setColor(QColor color) {
	color_ = color;
}

int Model::RectangleFilter::getWidth() {
	return width_;
}

void Model::RectangleFilter::setWidth(int width) {
	width_ = width;
}

int Model::RectangleFilter::getHeight() {
	return height_;
}

void Model::RectangleFilter::setHeight(int height) {
	height_ = height;
}

int Model::RectangleFilter::getX() {
	return x_;
}

QString Model::RectangleFilter::getName() const {
	return FILTERNAME;
}

void Model::RectangleFilter::setX(int x) {
	x_ = x;
}

int Model::RectangleFilter::getY() {
	return y_;
}

void Model::RectangleFilter::setY(int y) {
	y_ = y;
}

int Model::RectangleFilter::getOpacity() {
	return opacity_;
}

void Model::RectangleFilter::setOpacity(int opacity) {
    if(opacity<0||opacity>255)
        return;
    opacity_ = opacity;
}

void Model::RectangleFilter::restore(QString description) {
    QStringList list  = description.split(";");
    if(!list.size() == 6){
        return;
    }
    setWidth(list[0].QString::toInt());
	setHeight(list[1].QString::toInt());
	setX(list[2].QString::toInt());
	setY(list[3].QString::toInt());
	setOpacity(list[4].QString::toInt());
	setColor(QColor(list[5]));
}

QString Model::RectangleFilter::getSaveString() const {
	QString str =QString::number(width_);
	str+=";";
	str+=QString::number(height_);
	str+=";";
	str+=QString::number(x_);
	str+=";";
	str+=QString::number(y_);
	str+=";";
	str+=QString::number(opacity_);
	str+=";";
	str+=color_.QColor::name();
	return str;
}
