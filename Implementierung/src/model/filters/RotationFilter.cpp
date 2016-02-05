#include "RotationFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::RotationFilter::FILTERNAME="Rotation";

Model::RotationFilter::RotationFilter() {
}

std::string Model::RotationFilter::getFilterDescription() {
	throw "Not yet implemented";
}

int Model::RotationFilter::getAngle() {
	return this->angle;
}

QString Model::RotationFilter::getName() {
    return FILTERNAME;
}

void Model::RotationFilter::setAngle(int angle) {
	this->angle = angle;
}

void Model::RotationFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    setAngle(list[0].QString::toInt());
}

QString Model::RotationFilter::getSaveString() {
    QString str = QString::number(angle);
    return str;
}
