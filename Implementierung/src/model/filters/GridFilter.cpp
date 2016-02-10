#include "GridFilter.h"

#include <QString>
#include <QStringList>
#include <QColor>
#include <iomanip>

#include "Filter.h"

const QString Model::GridFilter::FILTERNAME="Grid";

Model::GridFilter::GridFilter():horizontalCells_(3),verticalCells_(5),thickness_(10),
	color_(QColor(0,0,0)),opacity_(255) {
}

std::string Model::GridFilter::getFilterDescription() {
	std::stringstream stream;
	stream << std::hex << opacity_;
	std::string str = std::string("drawgrid");
	str+="=";
	str+="w";
	str+="=";
	str+="iw/"+ std::to_string(horizontalCells_);
	str+=":";
	str+="h";
	str+="=";
	str+="ih/"+std::to_string(verticalCells_);
	str+=":";
	str+="t";
	str+="=";
	str+=std::to_string(thickness_);
	str+=":";
	str+="c";
	str+="=";
	str+=color_.name().toUtf8().constData();
	str+="@0x";
	str+=stream.str();
	return str;
}

int Model::GridFilter::getHorizontalCells() {
	return horizontalCells_;
}

void Model::GridFilter::setHorizontalCells(int horizontalCells) {
	horizontalCells_ = horizontalCells;
}

int Model::GridFilter::getVerticalCells() {
	return verticalCells_;
}

void Model::GridFilter::setVerticalCells(int verticalCells) {
	verticalCells_ = verticalCells;
}

QColor Model::GridFilter::getColor() {
	return color_;
}

void Model::GridFilter::setColor(QColor color) {
	color_ = color;
}

int Model::GridFilter::getThickness() {
	return thickness_;
}

void Model::GridFilter::setThickness(int thickness) {
	thickness_ = thickness;
}

int Model::GridFilter::getOpacity() {
	return opacity_;
}

void Model::GridFilter::setOpacity(int opacity) {
    if(opacity<0||opacity>255)
        return;
	opacity_ = opacity;
}

QString Model::GridFilter::getName() const {
	return FILTERNAME;
}

void Model::GridFilter::restore(QString description) {
	QStringList list  = description.split(";");
	setHorizontalCells(list[0].QString::toInt());
	setVerticalCells(list[1].QString::toInt());
	setThickness(list[2].QString::toInt());
	setOpacity(list[3].QString::toInt());
	setColor(QColor(list[4]));
}

QString Model::GridFilter::getSaveString() const {
	QString str = QString::number(horizontalCells_);
	str+=";";
	str+=QString::number(verticalCells_);
	str+=";";
	str+=QString::number(thickness_);
	str+=";";
	str+=QString::number(opacity_);
	str+=";";
	str+=color_.QColor::name();
	return str;
}
