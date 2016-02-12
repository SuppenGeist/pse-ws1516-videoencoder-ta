#ifndef CHANGEFILTER_H
#define CHANGEFILTER_H

#include <QString>
#include <QUndoCommand>

#include <memory>

#include "../gui/FilterTab.h"
#include "../memento/FilterTabMemento.h"

namespace UndoRedo {

class ChangeFilter:public QUndoCommand
{
public:
    ChangeFilter(GUI::FilterTab& filtertab,int index,QString oldState,QString newState);

    void undo();

    void redo();

private:
    QString         newState_;
    QString         oldState_;
    int             index_;
    GUI::FilterTab* filtertab_;
    std::unique_ptr<Memento::FilterTabMemento>  memento_;
};

}
#endif // CHANGEFILTE_H
