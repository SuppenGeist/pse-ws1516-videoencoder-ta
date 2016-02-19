#include "AnalysisBoxMemento.h"

#include <QString>

Memento::AnalysisBoxMemento::AnalysisBoxMemento():path_(""),comment_("") {

}

QString Memento::AnalysisBoxMemento::getPath() {
	return path_;
}

void Memento::AnalysisBoxMemento::setPath(QString path) {
	path_=path;
}

QString Memento::AnalysisBoxMemento::getComment() {
	return comment_;
}

void Memento::AnalysisBoxMemento::setComment(QString comment) {
	comment_=comment;
}
