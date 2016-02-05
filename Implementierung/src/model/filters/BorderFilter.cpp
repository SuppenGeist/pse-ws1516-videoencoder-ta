#include "BorderFilter.h"

#include <QString>
#include <QStringList>
#include <QColor>

#include "Filter.h"

const QString Model::BorderFilter::FILTERNAME="Border";

Model::BorderFilter::BorderFilter() {
}

bool Model::BorderFilter::getTop() {
	return this->top;
}

void Model::BorderFilter::setTop(bool top) {
	this->top = top;
}

bool Model::BorderFilter::getBottom() {
	return this->bottom;
}

void Model::BorderFilter::setBottom(bool bottom) {
	this->bottom = bottom;
}

bool Model::BorderFilter::getRight() {
	return this->right;
}

void Model::BorderFilter::setRight(bool right) {
	this->right = right;
}

bool Model::BorderFilter::getLeft() {
	return this->left;
}

void Model::BorderFilter::setLeft(bool left) {
	this->left = left;
}

int Model::BorderFilter::getThickness() {
	return this->thickness;
}

void Model::BorderFilter::setThickness(int thickness) {
	this->thickness = thickness;
}

QRgb Model::BorderFilter::getColor() {
	return this->color;
}

void Model::BorderFilter::setColor(QRgb color) {
	this->color = color;
}

QString Model::BorderFilter::getName() {
    return FILTERNAME;
}

std::string Model::BorderFilter::getFilterDescription() {
	throw "Not yet implemented";
}

void Model::BorderFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setTop(list[0].QString::toInt());
    setBottom(list[1].QString::toInt());
    setRight(list[2].QString::toInt());
    setLeft(list[3].QString::toInt());
    setThickness(list[4].QString::toInt());
    setColor(list[5].QString::toInt());
}

QString Model::BorderFilter::getSaveString() {
    QString str = QString::number(top);
    str+=";";
    str+=QString::number(bottom);
    str+=";";
    str+=QString::number(right);
    str+=";";
    str+=QString::number(left);
    str+=";";
    str+=QString::number(thickness);
    str+=";";
    str+=QString::number(color);
    return str;
}
