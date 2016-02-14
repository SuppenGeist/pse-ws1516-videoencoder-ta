#ifndef __AnalysisBox_h__
#define __AnalysisBox_h__

#include <memory>

#include <QFrame>
#include <QTabWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>

#include "FrameView.h"
#include "GraphWidget.h"
#include "VideoPlayer.h"
#include "Timer.h"
#include "GlobalControlPanel.h"

#include "../model/EncodedVideo.h"

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

    void setFile(QString filename);

    void setTimer(std::shared_ptr<Timer> timer);

    void setControlPanel(GlobalControlPanel* controlPanel);

private slots:
    void closeBox();

  private:
    FrameView*      origView_;
    FrameView*      anaView_;
    QTabWidget*     tabs_graphs_;
    QPushButton*    button_close_;
    GraphWidget*    graphWidget_;
    QLabel*         label_title_;

    std::unique_ptr<VideoPlayer>              origVidPlayer_;
    std::unique_ptr<VideoPlayer>              anaVidPlayer_;
    GlobalControlPanel*                       globalControlPanel_;

    QString         filename_;
    std::unique_ptr<Model::EncodedVideo>      origVideo_;

    void createUi();

};
}

#endif
