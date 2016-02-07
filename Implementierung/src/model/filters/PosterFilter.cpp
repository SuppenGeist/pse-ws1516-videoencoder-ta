#include "PosterFilter.h"

#include <QString>
#include <QStringList>

#include "Filter.h"

const QString Model::PosterFilter::FILTERNAME="Poster";

Model::PosterFilter::PosterFilter():numberOfColors_(12) {
}

std::string Model::PosterFilter::getFilterDescription() {
	std::string str = std::string("elbg=codebook_length='"+std::to_string(numberOfColors_));

	return str;
}

int Model::PosterFilter::getNumberOfColors() {
	return numberOfColors_;
}

QString Model::PosterFilter::getName() {
	return FILTERNAME;
}

void Model::PosterFilter::setNumberOfColors(int numberOfColors) {
	numberOfColors_ = numberOfColors;
}

void Model::PosterFilter::restoreFilter(QString description) {
	QStringList list  = description.split(";");
	setNumberOfColors(list[0].QString::toInt());
}

QString Model::PosterFilter::getSaveString() {
	QString str = QString::number(numberOfColors_);
	return str;
}
