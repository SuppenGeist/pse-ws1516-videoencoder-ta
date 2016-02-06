#include "BlendingFilter.h"

#include <QString>
#include <QStringList>

const QString Model::BlendingFilter::FILTERNAME="Blending";

Model::BlendingFilter::BlendingFilter():inBlend_(true),startFrame_(0),endFrame_(1) {

}

bool Model::BlendingFilter::getInBlend() {
    return inBlend_;
}

void Model::BlendingFilter::setInBlend(bool inBlend) {
    inBlend_ = inBlend;
}

int Model::BlendingFilter::getStartFrame() {
    return startFrame_;
}

void Model::BlendingFilter::setStartFrame(int startFrame) {
    if(startFrame<0||startFrame>=endFrame_)
        return;
    startFrame_ = startFrame;
}

int Model::BlendingFilter::getEndFrame() {
    return endFrame_;
}

void Model::BlendingFilter::setEndFrame(int endFrame) {
    if(endFrame<0||endFrame-startFrame_<=0)
        return;
    endFrame_ = endFrame;
}

QString Model::BlendingFilter::getName() {
    return FILTERNAME;
}

std::string Model::BlendingFilter::getFilterDescription() {
    std::string str("fade=");
    if(inBlend_) {
        str+="in:";
    }else {
        str+="out:";
    }
    str+=std::to_string(startFrame_)+":";
    str+=std::to_string(endFrame_-startFrame_);

    return str;
}


void Model::BlendingFilter::restoreFilter(QString description) {
    QStringList list  = description.split(";");
    if(list.size()!=3)
        return;
    setInBlend(list[0].toInt());
    setStartFrame(list[1].toInt());
    setEndFrame(list[2].toInt());
}

QString Model::BlendingFilter::getSaveString() {
    QString str = QString::number(inBlend_);
    str+=";";
    str+=QString::number(startFrame_);
    str+=";";
    str+=QString::number(endFrame_);

    return str;
}
