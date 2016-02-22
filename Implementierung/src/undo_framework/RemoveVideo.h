#ifndef __RemoveVideo_h__
#define __RemoveVideo_h__

#include <memory>
#include <QUndoCommand>

#include "../memento/AnalysisBoxMemento.h"

namespace GUI {
class AnalysisBox;
class AnalysisBoxContainer;
}

namespace UndoRedo {
/**
 * This class is the undo command for removing an encoded video from the analysis tab.
*/
class RemoveVideo: public QUndoCommand {
  public:

	/**
	 * @brief RemoveVideo The AnalysisBoxContainer to operate on.
	 * @param container The video to remove.
	 */
	RemoveVideo(GUI::AnalysisBoxContainer* boxContainer, GUI::AnalysisBox* box);

	/**
         * @brief undo Readds the removed video to the analysis tab.
	 */
	void undo();

	/**
	 * @brief redo Removes a video from the analysis tab.
	 */
	void redo();

  private:
	std::unique_ptr<Memento::AnalysisBoxMemento>  boxMemento_;
	GUI::AnalysisBox*           anaBox_;
	GUI::AnalysisBoxContainer*  container_;
	int                         index_;
};
}

#endif
