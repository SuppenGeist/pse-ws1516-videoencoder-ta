/*/*#include <exception>
#include <string>

#include "BorderFilter.h"
#include "Filter.h"

BorderFilter::BorderFilter() {
}

bool BorderFilter::getTop() {
	return this->top;
}

void BorderFilter::setTop(bool top) {
	this->top = top;
}

bool BorderFilter::getBottom() {
	return this->bottom;
}

void BorderFilter::setBottom(bool bottom) {
	this->bottom = bottom;
}

bool BorderFilter::getRight() {
	return this->right;
}

void BorderFilter::setRight(bool right) {
	this->right = right;
}

bool BorderFilter::getLeft() {
	return this->left;
}

void BorderFilter::setLeft(bool left) {
	this->left = left;
}

int BorderFilter::getThickness() {
	return this->thickness;
}

void BorderFilter::setThickness(int thickness) {
	this->thickness = thickness;
}

QRgb BorderFilter::getColor() {
	return this->color;
}

void BorderFilter::setColor(QRgb color) {
	this->color = color;
}

string BorderFilter::getName() {
	throw "Not yet implemented";
}

string BorderFilter::getFilterDescription() {
	throw "Not yet implemented";
}

*/

