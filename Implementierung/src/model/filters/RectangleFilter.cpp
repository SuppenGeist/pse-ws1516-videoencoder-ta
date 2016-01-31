#include <exception>
#include <string>
#include <QColor>
#include "RectangleFilter.h"
#include "Filter.h"

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

<<<<<<< HEAD
std::string Model::RectangleFilter::getName() {
    return "Rectangle";
=======
string Model::RectangleFilter::getName() {
	return "Rectangle";
>>>>>>> origin/master
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
	throw "Not yet implemented";
}

QString Model::RectangleFilter::getSaveString() {

}
