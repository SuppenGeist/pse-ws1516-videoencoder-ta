#ifndef CHANGEFILTER_H
#define CHANGEFILTER_H

#include <QString>
#include <QUndoCommand>

#include "../gui/FilterTab.h"

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
};

}
#endif // CHANGEFILTE_H
