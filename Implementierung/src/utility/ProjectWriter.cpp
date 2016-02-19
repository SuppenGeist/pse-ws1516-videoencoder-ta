#include "ProjectWriter.h"

#include <QDataStream>

#include "../model/Project.h"

#include "../memento/MainWindowMemento.h"

Utility::ProjectWriter::ProjectWriter(Model::Project *project):project_(project) {
    if(project) {
        file_=std::make_unique<QFile>(project->getPath());
        file_->open(QIODevice::WriteOnly);
        dataStream_.setDevice(file_.get());
    }
}

Utility::ProjectWriter::~ProjectWriter()
{
    file_->flush();
    file_->close();
}

void Utility::ProjectWriter::saveProject() {
    if(!project_)
        return;

    auto& memento=project_->getMemento();
    dataStream_<<memento.getSelectedTab()<<";";
}

void Utility::ProjectWriter::saveResults() {
}
