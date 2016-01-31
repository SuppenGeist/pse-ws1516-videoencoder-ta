
#include <string>
#include <QColor>
#include "GridFilter.h"
#include "Filter.h"

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

std::string Model::GridFilter::getName() {
    return "Grid";
}

void Model::GridFilter::restoreFilter(string description){
    throw "Not yet implemented";
}
