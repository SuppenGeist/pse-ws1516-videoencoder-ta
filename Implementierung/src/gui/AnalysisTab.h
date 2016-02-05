#ifndef __AnalysisTab_h__
#define __AnalysisTab_h__

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QScrollArea>

#include "../model/YuvVideo.h"
#include "VideoPlayer.h"

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
    Q_OBJECT

  public:
    /**
     * @brief AnalysisTab Contructor.
     * @param parent Parent of this Object.
     */
    AnalysisTab(QWidget* parent);

    /**
     * @brief getMemento Creates a memento which contains the state of this tab.
     * @return The created memento.
     */
    Memento::AnalysisTabMemento getMemento();


    /**
     * @brief restore Restores the tab based on the memento.
     * @param memento The memento which contains the state of the tab.
     */
	void restore(Memento::AnalysisTabMemento memento);

     /**
     * @brief setRawVideo Sets the raw video for the analysis. This operation resets the tab completely.
     * @param video The new raw video.
     */
    void setRawVideo(std::unique_ptr<Model::YuvVideo> video);

private slots:

    /**
     * @brief loadRawVideo opens YuvFileOpenDialog and gives the video to AnalysisBoxContainer
     */
	void loadRawVideo();

    /**
     * @brief addVideo opens QFIleDialog, and gives string to AnalysisBoxContainer
     */
    void addVideo();

    /**
     * @brief analyseTypChanged tells AnalysisBox to showMacroBlocks() or showRGBDiff()
     * @param index The new type.
     */
    void analyseTypChanged(int index);

    /**
    * @brief saveResults Opens QFIleDialog and saves relevant data in the path.
    */
   void saveResults();

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
    GUI::PlayerControlPanel* playerPanel_;
	GUI::Timer* playerTimer;
    GUI::AnalysisBoxContainer* analysisBoxContainer;
	GUI::GlobalControlPanel* globalControlPanel;
	Ui::AnalysisTab* ui;

    std::unique_ptr<Model::YuvVideo>    rawVideo_;
    std::unique_ptr<VideoPlayer>        player_;
};
}

#endif

