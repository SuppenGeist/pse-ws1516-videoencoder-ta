#include "RotationFilter.h"

#include <QString>
#include <QStringList>
#include <cmath>

#include "Filter.h"

const QString Model::RotationFilter::FILTERNAME="Rotation";

Model::RotationFilter::RotationFilter():angle_(90) {
}

std::string Model::RotationFilter::getFilterDescription() {
    std::string str = std::string("rotate="+std::to_string(angle_)+"*PI/180");
    return str;
}

int Model::RotationFilter::getAngle() {
    return angle_;
}

QString Model::RotationFilter::getName() {
	return FILTERNAME;
}

void Model::RotationFilter::setAngle(int angle) {
    angle_ = angle;
}

void Model::RotationFilter::restore(QString description) {
	QStringList list  = description.split(";");
    if(list.size()!=1)
        return;
	setAngle(list[0].QString::toInt());
}

QString Model::RotationFilter::getSaveString() {
    QString str = QString::number(angle_);
	return str;
}
