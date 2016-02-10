#include "PosterFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::PosterFilter::FILTERNAME="Poster";

Model::PosterFilter::PosterFilter():numberOfColors_(12) {
}

std::string Model::PosterFilter::getFilterDescription() {

	std::string str = std::string("elbg=codebook_length="+std::to_string(numberOfColors_));

	return str;
}

int Model::PosterFilter::getNumberOfColors() {
	return numberOfColors_;
}

QString Model::PosterFilter::getName() const {
	return FILTERNAME;
}

void Model::PosterFilter::setNumberOfColors(int numberOfColors) {
	if(numberOfColors<-0||numberOfColors>16777216)
		return;
	numberOfColors_ = numberOfColors;
}

void Model::PosterFilter::restore(QString description) {
	QStringList list  = description.split(";");
	if(list.size()!=1)
		return;
	setNumberOfColors(list[0].QString::toInt());
}

QString Model::PosterFilter::getSaveString() const {
	QString str = QString::number(numberOfColors_);
	return str;
}
