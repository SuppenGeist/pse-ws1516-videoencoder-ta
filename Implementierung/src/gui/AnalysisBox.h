#ifndef __AnalysisBox_h__
#define __AnalysisBox_h__

#include <QFrame>
#include <QTabWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
// #include "Video.h"
// #include "AnalysisBoxContainer.h"
// #include "VideoPlayer.h"
// #include "GraphWidget.h"
#include "Timer.h"
namespace Ui {
class AnalysisBox;
}
namespace GUI {
class AnalysisBoxContainer;
class VideoPlayer;
class Timer;
class GlobalControlPanel;
class GraphWidget;
}
namespace Memento {
class AnalysisBoxMemento;
}
namespace Model {
class Video;
class EncodedVideo;
}
namespace UndoRedo {
class RemoveVideo;
}

namespace GUI {
/**
 * Shows the Analysis of a single encoded video.
*/
class AnalysisBox: public QFrame {


  public:

	/**
	 * @brief AnalysisBox Constructor
	 * @param parent The parent of this Object
	 */
	AnalysisBox(QWidget* parent);

	/**
	* @brief getMemento Creates a memento which contains the state of the box.
	* @return The created memento.
	*/
	Memento::AnalysisBoxMemento getMemento();

	/**
	 * @brief restore Restores the box based on the memento.
	 * @param memento The memento which contains the state of the box.
	 */
	void restore(Memento::AnalysisBoxMemento memento);

	/// <summary>
	/// Sets the timer for the videoplayer.
	/// </summary>
	/// <param name="timer:std:">The timer for the videoplayer.</param>
	//void setTimer(shared_ptr<GUI::Timer> timer:std:);

	/// <summary>
	///
	/// </summary>
	/// <param name="video">.</param>
	/**
	 * @brief setRawVideo Sets the rawvideo the encoded video is compared to.
	 * @param video The rawvideo
	 */
	void setRawVideo(Model::Video* video);

	/**
	 * @brief setControlPanel Sets the GlobalControlPanel.
	 * @param panel The GlobalControlPanel.
	 */
	void setControlPanel(GUI::GlobalControlPanel* panel);

	/**
	 * @brief showMacroBlockVideo Shows the macroblock video. The rgb difference video is no longer shown.
	 */
	void showMacroBlockVideo();

	/**
	 * @brief showRGBDifferenceVideo Shows the rgb difference video. The macroblock video is no longer shown.
	 */
	void showRGBDifferenceVideo();

	/**
	 * @brief close removes this box from AnalysisBoxContainer
	 */
	void close();

	/**
	 * @brief textChanged updates QUndoStack
	 */
	void textChanged();

	/**
	 * @brief setAnalyseVideo Sets the video this box shall present.
	 * @param video The video to present.
	 */
	void setAnalyseVideo(Model::EncodedVideo video);



  public:
	UndoRedo::RemoveVideo* anaBox;
  private:
	Model::Video* rawVideo;
	int currentlyPlayedVideo;
	QTabWidget* tabs;
	QPushButton* button_close;
	QTextEdit* textEdit_comment;
	GlobalControlPanel* controlPanel;
	GUI::AnalysisBoxContainer* boxes;
	GUI::VideoPlayer* plainVideoPlayer;
	GUI::VideoPlayer* analysisVideoPlayer;
	GUI::GraphWidget* psnrGraph;
	GUI::GraphWidget* bitrateGraph;
	GUI::GraphWidget* redHistogramm;
	GUI::GraphWidget* blueHistogramm;
	GUI::GraphWidget* greenHistogramm;
	Model::EncodedVideo* video;
	Ui::AnalysisBox* ui;
};
}

#endif
