#ifndef __AnalysisBoxContainer_h__
#define __AnalysisBoxContainer_h__


#include <vector>
#include <memory>

#include <QWidget>
#include <QFrame>

#include "Timer.h"

namespace Ui {
class AnalysisBoxContainer;
}
namespace GUI {
class AnalysisTab;
class AnalysisBox;
class GlobalControlPanel;
}
namespace Memento {
class AnalysisBoxContainerMemento;
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
	void setTimer(std::shared_ptr<GUI::Timer> timer);

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
	 * @return Index where box was removed.
	 */
	int removeBox(GUI::AnalysisBox* box);
	/**
	 * @brief addBox Adds a box at specific postion.
	 * @param index Where to add the box.
	 * @param boxMemo The Memento of the Box.
	 * @return The created Box.
	 */
	GUI::AnalysisBox* addBox(int index, Memento::AnalysisBoxMemento boxMemo);

	/**
	 * @brief addVideo Adds the given video to the container.
	 * @param video The video to add.
	 * @return The box in which the video is presented.
	 */
	GUI::AnalysisBox* addVideo(Model::EncodedVideo video);

  private:
	int anaTypShown_;
	Model::Video* rawVideo_;
	std::shared_ptr<GUI::Timer> timer_;
    GUI::GlobalControlPanel* controlPanel_;
	std::vector<GUI::AnalysisBox*> boxes_;
	Ui::AnalysisBoxContainer* ui_;
};
}

#endif
