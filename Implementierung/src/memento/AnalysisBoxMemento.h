#ifndef __AnalysisBoxMemento_h__
#define __AnalysisBoxMemento_h__

#include <QString>

namespace Memento {
/**
 * This class is the memento for the AnalysisBox.
 */
class AnalysisBoxMemento {

public:
    /**
     * @brief AnalysisBoxMemento Constructor.
     */
    AnalysisBoxMemento();

    QString getPath();

    void setPath(QString path);

    QString getComment();

    void setComment(QString comment);

private:
    QString path_;
    QString comment_;
};
}

#endif
