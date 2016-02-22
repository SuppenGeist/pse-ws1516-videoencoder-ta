#ifndef __AnalysisBox_h__
#define __AnalysisBox_h__

#include <memory>

#include <QFrame>
#include <QTabWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QTimer>

#include "FrameView.h"
#include "GraphWidget.h"
#include "VideoPlayer.h"
#include "Timer.h"
#include "GlobalControlPanel.h"
#include "graphplayer.h"

#include "../model/EncodedVideo.h"

#include "../memento/AnalysisBoxMemento.h"

namespace GUI {
class AnalysisBoxContainer;
enum class AnalysisGraph;
enum class AnalysisVideo;
}

namespace GUI {
/**
 * Shows the Analysis of a single encoded video.
*/
class AnalysisBox: public QFrame {

	Q_OBJECT
  public:

	/**
	 * @brief AnalysisBox Constructor
	 * @param parent The parent of this Object
	 */
	AnalysisBox(QWidget* parent=0);

	~AnalysisBox();

    std::unique_ptr<Memento::AnalysisBoxMemento> getMemento(bool calculateImages=false);

	void restore(Memento::AnalysisBoxMemento* memento);

	void setParentContainer(AnalysisBoxContainer* container);

	void setFile(QString filename);

	void setTimer(std::shared_ptr<Timer> timer);

	void setControlPanel(std::shared_ptr<GlobalControlPanel> controlPanel);

	void showGraph(AnalysisGraph graph);

	void showAnalysisVideo(AnalysisVideo video);

	void showAttributes();

    QString getPath();

	QPlainTextEdit* getCommentBox();

    void lockUi();

    void unlockUi();

  private slots:
	void closeBox();
	void updateLabels();
	void commentChanged();

  private:
	FrameView*      origView_;
	FrameView*      anaView_;
	QTabWidget*     tabs_graphs_;
	QPushButton*    button_close_;
	GraphWidget*    graphWidget_;
	QLabel*         label_title_;
	QPlainTextEdit* texteEdit_comment_;
	QLabel*         label_filename_;
	QLabel*         label_filesize_;
	QLabel*         label_codec_;
	QLabel*         label_averageBitrate_;

	AnalysisBoxContainer*                   parentContainer_;

	std::unique_ptr<VideoPlayer>              origVidPlayer_;
	std::unique_ptr<VideoPlayer>              anaVidPlayer_;
	std::shared_ptr<GlobalControlPanel>     globalControlPanel_;
	std::unique_ptr<GraphPlayer>            graphPlayer_;

	QString         filename_;
	std::unique_ptr<Model::EncodedVideo>      origVideo_;
	QTimer          timer_updateLabels_;
	QString currentComment_;

	void createUi();


};
}

#endif
