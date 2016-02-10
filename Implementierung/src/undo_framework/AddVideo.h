#ifndef __AddVideo_h__
#define __AddVideo_h__

// #include "AnalysisBox.h"
// #include "AnalysisBoxContainer.h"
#include <QUndoCommand>

namespace GUI {
class AnalysisBox;
class AnalysisBoxContainer;
}
namespace Model {
class EncodedVideo;
}

namespace UndoRedo {
/**
 * This class is the undo command for adding a encoded video on the analysis tab.
*/
class AddVideo: public QUndoCommand {


	/// <summary>
	/// Constuctor.
	/// </summary>
	/// <param name="analysisBoxContainer">The AnalysisBoxContainer to operate on.</param>
	/// <param name="video">The video on which the action is performed.</param>
  public:
	AddVideo(GUI::AnalysisBox *analysisBoxContainer);

	/// <summary>
	/// Removes the added video from the analysis tab.
	/// </summary>
  public:
	void undo();

	/// <summary>
	/// Adds a video to the Analysis tab.
	/// </summary>
  public:
	void redo();

  private:
	GUI::AnalysisBox* anaBox;
};
}

#endif
