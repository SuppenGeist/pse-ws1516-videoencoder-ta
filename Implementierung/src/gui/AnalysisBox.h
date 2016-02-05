#ifndef __AnalysisBox_h__
#define __AnalysisBox_h__

#include <QFrame>
#include <QTabWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <memory>
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

    /**
     * @brief setTimer Sets the timer for the videoplayer.
     * @param timer The timer for the videoplayer.
     */
    void setTimer(std::shared_ptr<GUI::Timer> timer);


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
    void setAnalyseVideo(std::unique_ptr<Model::EncodedVideo> video);



  public:
    UndoRedo::RemoveVideo* anaBox_;
  private:
    Model::Video* rawVideo_;
    int currentlyPlayedVideo_;
    QTabWidget* tabs_;
    QPushButton* button_close_;
    QTextEdit* textEdit_comment_;
    GlobalControlPanel* playerPanel_;
    GUI::AnalysisBoxContainer* boxes_;
    std::unique_ptr<VideoPlayer> plainVideoPlayer_;
    std::unique_ptr<VideoPlayer> analysisVideoPlayer_;
    GUI::GraphWidget* psnrGraph_;
    GUI::GraphWidget* bitrateGraph_;
    GUI::GraphWidget* redHistogramm_;
    GUI::GraphWidget* blueHistogramm_;
    GUI::GraphWidget* greenHistogramm_;
    std::unique_ptr<Model::EncodedVideo> video_;
    Ui::AnalysisBox* ui_;
};
}

#endif
