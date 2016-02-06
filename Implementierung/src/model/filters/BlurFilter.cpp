#include "BlurFilter.h"

#include <string>
#include <stdexcept>

#include <QString>
#include <QStringList>

const QString Model::BlurFilter::FILTERNAME="Blur";

Model::BlurFilter::BlurFilter():intensity_(20) {

}
int Model::BlurFilter::getIntensity() {
    return intensity_;
}

void Model::BlurFilter::setIntensity(int intensity) {
    if(intensity<0||intensity>100)
        return;
    intensity_ = intensity;
}

std::string Model::BlurFilter::getFilterDescription() {
    std::string str= "boxblur="+std::to_string((int)((double)intensity_/100*20))+":1";

	return str;
}

QString Model::BlurFilter::getName() {
    return FILTERNAME;
}

void Model::BlurFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    if(list.size()!=1)
        return;
    setIntensity(list[1].QString::toInt());
}

QString Model::BlurFilter::getSaveString() {
    QString str = QString::number(intensity_);

    return str;
}
