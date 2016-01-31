#include <exception>
#include <string>
#include <QColor>

#include "BorderFilter.h"
#include "Filter.h"

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

std::string Model::BorderFilter::getName() {
	return "Border";
}

std::string Model::BorderFilter::getFilterDescription() {
	throw "Not yet implemented";
}

void Model::BorderFilter::restoreFilter(QString description) {
	throw "Not yet implemented";
}

QString Model::BorderFilter::getSaveString() {

}
