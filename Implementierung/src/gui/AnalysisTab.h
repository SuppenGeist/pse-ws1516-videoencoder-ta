#ifndef __AnalysisTab_h__
#define __AnalysisTab_h__


#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QScrollArea>

namespace Ui {
class AnalysisTab;
}
namespace GUI {
class VideoPlayer;
class FrameView;
class PlayerControlPanel;
class Timer;
class AnalysisBoxContainer;
class GlobalControlPanel;
}
namespace Memento {
class AnalysisTabMemento;
}
namespace Model {
class YuvVideo;
}
namespace UndoRedo {
class LoadAnalysisVideo;
}

namespace GUI {
/**
 * The tab that shows videos and analyses them.
*/
class AnalysisTab: public QFrame {

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	AnalysisTab(QWidget* parent);

	/// <summary>
	/// Creates a memento which contains the state of this tab.
	/// </summary>
	/// <returns>The created memento.</returns>
  public:
	Memento::AnalysisTabMemento getMemento();

	/// <summary>
	/// Restores the tab based on the memento.
	/// </summary>
	/// <param name="memento">The memento which contains the state of the tab.</param>
  public:
	void restore(Memento::AnalysisTabMemento memento);

	/// <summary>
	/// Slot: connected to comboBox_analyseTyp.currentIndexChanged(index : int)
	/// tells AnalysisBox to showMacroBlocks() or showRGBDiff()
	/// </summary>
	/// <param name="index">The new type.</param>
  private:
	void analyseTypChanged(int index);

	/// <summary>
	/// Slot: connected to button_addVideo.pressed()
	/// opens QFIleDialog, and gives string to AnalysisBoxContainer
	/// </summary>
  private:
	void addVideo();

	/// <summary>
	/// Slot: connected to button_addRawVideo.pressed()
	/// opens YuvFileOpenDialog and gives the video to AnalysisBoxContainer
	/// </summary>
  private:
	void loadRawVideo();

	/// <summary>
	/// Opens QFIleDialog and saves relevant data in the path.
	/// </summary>
  private:
	void saveResults();

	/// <summary>
	/// Sets the raw video for the analysis. This operation resets the tab completely.
	/// </summary>
	/// <param name="video">The new raw video.</param>
  public:
	void setRawVideo(Model::YuvVideo video);

  public:
	GUI::FrameView* rawVideoView;
	UndoRedo::LoadAnalysisVideo* anaTab;

  private:
	QPushButton* button_save;
	QComboBox* comboBox_analyseTyp;
	QScrollArea* scrollArea_analyseVideos;
	QLabel* label_rawVideo;
	QPushButton* button_addRawVideo;
	QTabWidget* tab_properties;
	QPushButton* button_addVideo;
	GUI::VideoPlayer* player;
	GUI::PlayerControlPanel* controlPanel;
	GUI::Timer* playerTimer;
	GUI::AnalysisBoxContainer* analysisBoxContainer;
	Model::YuvVideo* rawVideo;
	GUI::GlobalControlPanel* globalControlPanel;
	Ui::AnalysisTab* ui;
};
}

#endif

