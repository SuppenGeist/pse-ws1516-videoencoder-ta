#ifndef __AddVideo_h__
#define __AddVideo_h__

#include <QUndoCommand>
#include <QString>

namespace GUI {
class AnalysisBoxContainer;
}

namespace UndoRedo {
/**
 * This class is the undo command for adding a encoded video on the analysis tab.
*/
class AddVideo: public QUndoCommand {

  public:
    /**
     * @brief AddVideo Constuctor.
     * @param analysisBoxContainer The AnalysisBoxContainer to operate on.
     * @param filename The video on which the action is performed.
     */
    AddVideo(GUI::AnalysisBoxContainer *analysisBoxContainer,QString filename);

    /**
     * @brief undo Removes the added video from the analysis tab.
     */
	void undo();

    /**
     * @brief redo Adds a video to the Analysis tab.
     */
	void redo();

  private:
    GUI::AnalysisBoxContainer*      anaBoxContainer_;
    QString                         filename_;
};
}

#endif
