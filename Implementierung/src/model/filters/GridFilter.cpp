
#include <string>

#include "GridFilter.h"
#include "Filter.h"

Model::GridFilter::GridFilter() {
}

std::string Model::GridFilter::getFilterDescription() {
	throw "Not yet implemented";
}
/*
int GridFilter::getHorizontalLines() {
	return this->horizontalLines;
}

void GridFilter::setHorizontalLines(int horizontalLines) {
	this->horizontalLines = horizontalLines;
}

int GridFilter::getVerticalLines() {
	return this->verticalLines;
}

void GridFilter::setVerticalLines(int verticalLines) {
	this->verticalLines = verticalLines;
}

QRgb GridFilter::getColor() {
	return this->color;
}

void GridFilter::setColor(QRgb color) {
	this->color = color;
}

int GridFilter::getThickness() {
	return this->thickness;
}

void GridFilter::setThickness(int thickness) {
	this->thickness = thickness;
}

int GridFilter::getOpacity() {
	return this->opacity;
}

void GridFilter::setOpacity(int opacity) {
	this->opacity = opacity;
}
*/
std::string Model::GridFilter::getName() {
    return "Grid";
}


