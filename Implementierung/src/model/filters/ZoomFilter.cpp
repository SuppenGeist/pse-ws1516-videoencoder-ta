#include "ZoomFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::ZoomFilter::FILTERNAME="Zoom";

Model::ZoomFilter::ZoomFilter():intensity_(100) {
}

QString Model::ZoomFilter::getName() {
	return FILTERNAME;
}

std::string Model::ZoomFilter::getFilterDescription() {
	std::string str = std::string("zoompan=z=min'(zoom+0,0015,"+std::to_string((
	                                  double)intensity_/10)+")':d=100:x='iw/2-(iw/zoom/2)':y='ih/2-(ih/zoom/2)'");
	return str;
}

int Model::ZoomFilter::getIntensity() {
	return intensity_;
}

void Model::ZoomFilter::setIntensity(int intensity) {
	intensity_ = intensity;
}

void Model::ZoomFilter::restoreFilter(QString description) {
	QStringList list  = description.split(";");
    if(list.size()!=1)
        return;
	setIntensity(list[0].QString::toInt());
}

QString Model::ZoomFilter::getSaveString() {
	QString str = QString::number(intensity_);
	return str;
}
