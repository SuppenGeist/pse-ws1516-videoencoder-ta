#include "ColorbalanceFilter.h"

#include <QString>
#include <QStringList>

#include <string>
#include <stdexcept>

#include "../../utility/BasicColor.h"
#include "Filter.h"

const QString Model::ColorbalanceFilter::FILTERNAME="Colorbalance";

Model::ColorbalanceFilter::ColorbalanceFilter():intensity_(20),brightPixels_(true),
	mediumPixels_(true),darkPixels_(true),color_(BasicColor::RED) {

}

Model::BasicColor Model::ColorbalanceFilter::getColor() {
	return color_;
}

void Model::ColorbalanceFilter::setColor(BasicColor color) {
	color_=color;
}

int Model::ColorbalanceFilter::getIntensity() {
	return intensity_;
}

void Model::ColorbalanceFilter::setIntensity(int intensity) {
	if(intensity<-100||intensity>100)
		return;
	intensity_ = intensity;
}

bool Model::ColorbalanceFilter::getBrightPixels() {
	return brightPixels_;
}

void Model::ColorbalanceFilter::setBrightPixels(bool brightPixels) {
	brightPixels_ = brightPixels;
}

bool Model::ColorbalanceFilter::getMediumPixels() {
	return mediumPixels_;
}

void Model::ColorbalanceFilter::setMediumPixels(bool mediumPixels) {
	mediumPixels_ = mediumPixels;
}

std::string Model::ColorbalanceFilter::getFilterDescription() {
	std::string str("colorbalance=");
	std::string range("'");
	range+=std::to_string((double)intensity_/100)+"'";

	if(color_==BasicColor::RED) {
		if(darkPixels_) {
			str+="rs="+range+":";
		}
		if(mediumPixels_) {
			str+="rm="+range+":";
		}
		if(brightPixels_) {
			str+="rh="+range+":";
		}
	} else if(color_==BasicColor::GREEN) {
		if(darkPixels_) {
			str+="gs="+range+":";
		}
		if(mediumPixels_) {
			str+="gm="+range+":";
		}
		if(brightPixels_) {
			str+="gh="+range+":";
		}
	} else if(color_==BasicColor::BLUE) {
		if(darkPixels_) {
			str+="bs="+range+":";
		}
		if(mediumPixels_) {
			str+="bm="+range+":";
		}
		if(brightPixels_) {
			str+="bh="+range+":";
		}
	} else {
		throw std::logic_error("Should not get here");
	}

	if(str=="colorbalance=") {
		str="null";
	}/*else {
        str=str.substr(0,str.size()-1);
    }*/

	return str;
}

QString Model::ColorbalanceFilter::getName() const {
	return FILTERNAME;
}

bool Model::ColorbalanceFilter::getDarkPixels() {
	return darkPixels_;
}

void Model::ColorbalanceFilter::setDarkPixels(bool darkPixels) {
	darkPixels_ = darkPixels;
}

void Model::ColorbalanceFilter::restore(QString description) {
	QStringList list  = description.split(";");
	if(list.size()!=5)
		return;
	setIntensity(list[0].QString::toInt());
	setDarkPixels(list[1].QString::toInt());
	setMediumPixels(list[2].QString::toInt());
	setBrightPixels(list[3].QString::toInt());
	setColor(static_cast<BasicColor>(list[4].QString::toInt()));
}

QString Model::ColorbalanceFilter::getSaveString() const {
	QString str =QString::number(intensity_);
	str+=";";
	str+=QString::number(darkPixels_);
	str+=";";
	str+=QString::number(mediumPixels_);
	str+=";";
	str+=QString::number(brightPixels_);
	str+=";";
	str+=QString::number(color_);

	return str;
}
