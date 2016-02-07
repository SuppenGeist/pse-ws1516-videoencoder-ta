#include "RGBFilter.h"

#include <QString>
#include <QStringList>

#include "../../utility/BasicColor.h"
#include "Filter.h"

const QString Model::RGBFilter::FILTERNAME="RGB";

Model::RGBFilter::RGBFilter():color_(BasicColor::RED) {
}

std::string Model::RGBFilter::getFilterDescription() {
std::string str = std::string("colorchannelmixer=");
    if(color_ == BasicColor::RED){
        str+= "1:0:0:0:0:0:0:0:0:0:0:0";
    } else if (color_ == BasicColor::GREEN){
        str+= "0:0:0:0:0:1:0:0:0:0:0:0";
    } else if (color_ == BasicColor::BLUE){
        str+= "0:0:0:0:0:0:0:0:0:0:1:0";
    }
    return str;
}

Model::BasicColor Model::RGBFilter::getColor() {
    return color_;
}

void Model::RGBFilter::setColor(BasicColor color) {
    color_=color;
}

QString Model::RGBFilter::getName() {
	return FILTERNAME;
}

void Model::RGBFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    if(list.size()!=1)
        return;
    setColor(static_cast<BasicColor>(list[0].QString::toInt()));
}

QString Model::RGBFilter::getSaveString() {
    QString str = QString::number(color_);
    return str;
}

