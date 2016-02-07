#ifndef __AnalysisBoxContainer_h__
#define __AnalysisBoxContainer_h__


#include <vector>


#include <QWidget>
#include <QFrame>

namespace Ui {
class AnalysisBoxContainer;
}
namespace GUI {
class Timer;
class AnalysisTab;
class AnalysisBox;
class GlobalControlPanel;
}
namespace Memento {
class AnalysisBoxContainerMemento;
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
 * Contains and manages the AnalysisBoxes.
*/
class AnalysisBoxContainer: public QFrame {
  public:

	/**
	* @brief AnalysisBoxContainer Constructor
	* @param parent parent of this object
	*/
	AnalysisBoxContainer(QWidget* parent);

	/**
	     * @brief getMemento Creates a memento which contains the state of the container.
	     * @return The created memento
	     */
	Memento::AnalysisBoxContainerMemento getMemento();

	/**
	 * @brief restore Restores the container based on the memento.
	 * @param memento The memento which contains the state to restore.
	 */
	void restore(Memento::AnalysisBoxContainerMemento memento);

	/**
	 * @brief addVideo Creates The path of the video to analyse.a Analysis box and shows it.
	 * @param path
	 */
	void addVideo(QString path);

	/**
	 * @brief setRawVideo Sets the rawVideo the encoded videos are compared to.

	 * @param video The raw video.
	 */
	void setRawVideo(Model::Video* video);



	/**
	 * @brief setTimer Sets the timer for the videoplayers.
	 * @param timer The timer for the videoplayers.
	 */
	//void setTimer(shared_ptr<GUI::Timer> timer:std:);

	/**
	 * @brief setControlPanel Sets the GlobalControlPanel.
	 * @param panel The panel.
	 */
	void setControlPanel(GUI::GlobalControlPanel* panel);

	/**
	 * @brief showMacroBlockVideos Tells all AnalysisBoxes to show the macro block video.
	 */
	void showMacroBlockVideos();

	/**
	 * @brief showRGBDifferenceVideos Tells all AnalysisBoxes to show the RGBDiff video.
	 */
	void showRGBDifferenceVideos();

	/**
	 * @brief removeBox Removes a box from the list.
	 * @param box The box to remove.
	 */
	void removeBox(GUI::AnalysisBox& box);

	/**
	 * @brief addVideo Adds the given video to the container.
	 * @param video The video to add.
	 * @return The box in which the video is presented.
	 */
	GUI::AnalysisBox* addVideo(Model::EncodedVideo video);
  public:
	UndoRedo::RemoveVideo* anaBoxContainer;
  private:

	Model::Video* rawVideo;
	//private: shared_ptr<GUI::Timer> timer:std:;
	GUI::GlobalControlPanel* controlPanel;
	GUI::AnalysisTab* analysisBoxContainer;
	std::vector<GUI::AnalysisBox*> boxes;
	Ui::AnalysisBoxContainer* ui;
};
}

#endif
