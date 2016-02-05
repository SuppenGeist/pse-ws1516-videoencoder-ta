#include "RectangleFilter.h"

#include <QString>
#include <QStringList>
#include <QColor>

#include "Filter.h"

const QString Model::RectangleFilter::FILTERNAME="Rectangle";

Model::RectangleFilter::RectangleFilter() {
}

std::string Model::RectangleFilter::getFilterDescription() {
	throw "Not yet implemented";
}

QRgb Model::RectangleFilter::getColor() {
	return this->color;
}

void Model::RectangleFilter::setColor(QRgb color) {
	this->color = color;
}

int Model::RectangleFilter::getWidth() {
	return this->width;
}

void Model::RectangleFilter::setWidth(int width) {
	this->width = width;
}

int Model::RectangleFilter::getHeight() {
	return this->height;
}

void Model::RectangleFilter::setHeight(int height) {
	this->height = height;
}

int Model::RectangleFilter::getX() {
	return this->x;
}

QString Model::RectangleFilter::getName() {
    return FILTERNAME;
}

void Model::RectangleFilter::setX(int x) {
	this->x = x;
}

int Model::RectangleFilter::getY() {
	return this->y;
}

void Model::RectangleFilter::setY(int y) {
	this->y = y;
}

int Model::RectangleFilter::getOpacity() {
	return this->opacity;
}

void Model::RectangleFilter::setOpacity(int opacity) {
	this->opacity = opacity;
}

void Model::RectangleFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setWidth(list[0].QString::toInt());
    setHeight(list[1].QString::toInt());
    setX(list[2].QString::toInt());
    setY(list[3].QString::toInt());
    setOpacity(list[4].QString::toInt());
    setColor(list[5].QString::toInt());
}

QString Model::RectangleFilter::getSaveString() {
    QString str =QString::number(width);
    str+=";";
    str+=QString::number(height);
    str+=";";
    str+=QString::number(x);
    str+=";";
    str+=QString::number(y);
    str+=";";
    str+=QString::number(opacity);
    str+=";";
    str+=QString::number(color);
    return str;
}
