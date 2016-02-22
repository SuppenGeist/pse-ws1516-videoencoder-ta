#ifndef __AnalysisTab_h__
#define __AnalysisTab_h__

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QComboBox>
#include <QTabWidget>
#include <QScrollArea>

#include "PlayerControlPanel.h"
#include "GraphWidget.h"
#include "AnalysisBoxContainer.h"
#include "ForwardPlayer.h"
#include "VideoPlayer.h"
#include "Timer.h"
#include "FrameView.h"
#include "GlobalControlPanel.h"
#include "graphplayer.h"
#include "graphcalculator.h"

#include "../model/YuvVideo.h"

#include "../memento/AnalysisTabMemento.h"

#include "../utility/resultsaver.h"

namespace GUI {
class MainWindow;
}

namespace GUI {
enum class AnalysisGraph {
    BITRATE,
    RED_HISTOGRAM,
    BLUE_HISTOGRAM,
    GREEN_HISTOGRAM,
    PSNR
};

enum class AnalysisVideo {
    MACROBLOCK,
    RGB_DIFFERENCE
};

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
	AnalysisTab(QWidget* parent=0);

	std::unique_ptr<Memento::AnalysisTabMemento> getMemento();

	void restore(Memento::AnalysisTabMemento* memento);

	void setRawVideo(Model::YuvVideo* rawVideo);

	Model::YuvVideo* getRawVideo();

	bool isRawVideoLoaded();

	void setParentWindow(MainWindow* window);

	MainWindow* getParentWindow();

  protected:
	void resizeEvent(QResizeEvent * event);

signals:
    void resultsSaved();

  private slots:
	void loadRawVideo();
	void showBitrate();
        void showRedHistogram();
        void showBlueHistogram();
        void showGreenHistogram();
	void showPsnr();
	void showAttributes();
	void analysisVideoChanged(int index);
	void updateLabels();
    void resultSavingFinished();
    void saveResults();

  private:
	QPushButton*            button_saveResults_;
	QPushButton*            button_addRawVideo_;
	QPushButton*            button_attributes_;
        QPushButton*            button_redHistogram_;
        QPushButton*            button_blueHistogram_;
        QPushButton*            button_greenHistogram_;
	QPushButton*            button_bitrate_;
	QPushButton*            button_psnr_;
	PlayerControlPanel*     playerControlPanel_;
	QTabWidget*             tabs_graphattrs;
	QComboBox*              combobbox_anaVideo_;
	QVBoxLayout*            v_rawVideo_;
	GraphWidget*            graphWidget_;
	AnalysisBoxContainer*   analysisBoxContainer_;
	QScrollArea*            scroll_anaBoxes_;
	QString                 stylesheet_buttons_;
	QString                 stylesheet_buttonsSelected_;
	QLabel*                 label_filename_;
	QLabel*                 label_filesize_;
	QLabel*                 label_resolution_;
	QLabel*                 label_framesize_;
	QPushButton*            button_loadnewvideo_;

	Model::YuvVideo*        rawVideo_;

	std::unique_ptr<ForwardPlayer>      forwardPlayer_;
	std::unique_ptr<GraphPlayer>        graphPlayer_;
	std::shared_ptr<Timer>              timer_;
	std::shared_ptr<GlobalControlPanel> globalControlPanel_;
	std::unique_ptr<VideoPlayer>        videoPlayer_;
    std::unique_ptr<GraphCalculator>    calculator_;
	FrameView*                          rawVideoView_;

    std::unique_ptr<Utility::ResultSaver> resultsSaver_;

    QTimer                  timer_labelUpdater_;

	MainWindow*             parentWindow_;

	void createUi();
	void connectActions();
};
}

#endif

