#include "GridFilter.h"

#include <QString>
#include <QStringList>
#include <QColor>

#include "Filter.h"

const QString Model::GridFilter::FILTERNAME="Grid";

Model::GridFilter::GridFilter() {
}

std::string Model::GridFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::GridFilter::getHorizontalLines() {
	return this->horizontalLines;
}

void Model::GridFilter::setHorizontalLines(int horizontalLines) {
	this->horizontalLines = horizontalLines;
}

int Model::GridFilter::getVerticalLines() {
	return this->verticalLines;
}

void Model::GridFilter::setVerticalLines(int verticalLines) {
	this->verticalLines = verticalLines;
}

QRgb Model::GridFilter::getColor() {
	return this->color;
}

void Model::GridFilter::setColor(QRgb color) {
	this->color = color;
}

int Model::GridFilter::getThickness() {
	return this->thickness;
}

void Model::GridFilter::setThickness(int thickness) {
	this->thickness = thickness;
}

int Model::GridFilter::getOpacity() {
	return this->opacity;
}

void Model::GridFilter::setOpacity(int opacity) {
	this->opacity = opacity;
}

QString Model::GridFilter::getName() {
    return FILTERNAME;
}

void Model::GridFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setHorizontalLines(list[1].QString::toInt());
    setVerticalLines(list[2].QString::toInt());
    setThickness(list[3].QString::toInt());
    setOpacity(list[4].QString::toInt());
    setColor(list[5].QString::toInt());
}

QString Model::GridFilter::getSaveString() {
    QString str(getName());
    str+=";";
    str+=QString::number(horizontalLines);
    str+=";";
    str+=QString::number(verticalLines);
    str+=";";
    str+=QString::number(thickness);
    str+=";";
    str+=QString::number(opacity);
    str+=";";
    str+=QString::number(color);
    return str;
}
