#include <exception>
#include <string>

#include "RectangleFilter.h"
#include "Filter.h"

RectangleFilter::RectangleFilter() {
}

string RectangleFilter::getFilterDescription() {
	throw "Not yet implemented";
}

QRgb RectangleFilter::getColor() {
	return this->color;
}

void RectangleFilter::setColor(QRgb color) {
	this->color = color;
}

int RectangleFilter::getWidth() {
	return this->width;
}

void RectangleFilter::setWidth(int width) {
	this->width = width;
}

int RectangleFilter::getHeight() {
	return this->height;
}

void RectangleFilter::setHeight(int height) {
	this->height = height;
}

int RectangleFilter::getX() {
	return this->x;
}

string RectangleFilter::getName() {
	throw "Not yet implemented";
}

void RectangleFilter::setX(int x) {
	this->x = x;
}

int RectangleFilter::getY() {
	return this->y;
}

void RectangleFilter::setY(int y) {
	this->y = y;
}

int RectangleFilter::getOpacity() {
	return this->opacity;
}

void RectangleFilter::setOpacity(int opacity) {
	this->opacity = opacity;
}

