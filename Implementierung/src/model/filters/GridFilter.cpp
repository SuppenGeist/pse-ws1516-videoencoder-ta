#include "GridFilter.h"

#include <QString>
#include <QStringList>
#include <QColor>

#include "Filter.h"

const QString Model::GridFilter::FILTERNAME="Grid";

Model::GridFilter::GridFilter() {
}

std::string Model::GridFilter::getFilterDescription() {
    std::string str = std::string("drawgrid");
    str+="=";
    str+="w";
    str+="=";
    str+=std::to_string(horizontalLines);
    str+=":";
    str+="h";
    str+="=";
    str+=std::to_string(verticalLines);
    str+=":";
    str+="t";
    str+="=";
    str+=std::to_string(thickness);
    str+="c";
    str+="=";
    str+=color.QColor::name().toStdString();
    str+="@";
    str+=std::to_string(opacity);
    return str;
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

QColor Model::GridFilter::getColor() {
	return this->color;
}

void Model::GridFilter::setColor(QColor color) {
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
    setHorizontalLines(list[0].QString::toInt());
    setVerticalLines(list[1].QString::toInt());
    setThickness(list[2].QString::toInt());
    setOpacity(list[3].QString::toInt());
    setColor(QColor(list[4]));
}

QString Model::GridFilter::getSaveString() {
    QString str = QString::number(horizontalLines);
    str+=";";
    str+=QString::number(verticalLines);
    str+=";";
    str+=QString::number(thickness);
    str+=";";
    str+=QString::number(opacity);
    str+=";";
    str+=color.QColor::name();
    return str;
}
