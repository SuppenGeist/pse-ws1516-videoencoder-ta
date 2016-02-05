#include "PosterFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::PosterFilter::FILTERNAME="Poster";

Model::PosterFilter::PosterFilter() {
}

std::string Model::PosterFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::PosterFilter::getNumberOfColors() {
	return this->numberOfColors;
}

QString Model::PosterFilter::getName() {
    return FILTERNAME;
}

void Model::PosterFilter::setNumberOfColors(int numberOfColors) {
	this->numberOfColors = numberOfColors;
}

void Model::PosterFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setNumberOfColors(list[1].QString::toInt());
}

QString Model::PosterFilter::getSaveString() {
    QString str(getName());
    str+=";";
    str+=QString::number(numberOfColors);
    return str;
}
