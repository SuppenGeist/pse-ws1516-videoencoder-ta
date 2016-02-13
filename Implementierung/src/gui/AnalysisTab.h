#ifndef __AnalysisTab_h__
#define __AnalysisTab_h__

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QTabWidget>
#include <QScrollArea>

#include "PlayerControlPanel.h"
#include "GraphWidget.h"
#include "AnalysisBoxContainer.h"

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
    AnalysisTab(QWidget* parent=0);

protected:
    void resizeEvent(QResizeEvent * event);

  private:
    QPushButton*            button_saveResults_;
    QPushButton*            button_addRawVideo_;
    QPushButton*            button_attributes_;
    QPushButton*            button_redHistogramm_;
    QPushButton*            button_blueHistogramm_;
    QPushButton*            button_greenHistogramm_;
    QPushButton*            button_bitrate_;
    QPushButton*            button_psnr_;
    QPushButton*            button_addencodedvideo;
    PlayerControlPanel*     playerControlPanel_;
    QTabWidget*             tabs_graphattrs;
    QComboBox*              combobbox_anaVideo_;
    QVBoxLayout*            v_rawVideo_;
    GraphWidget*            graphWidget_;
    AnalysisBoxContainer*   analysisBoxContainer_;
    QScrollArea*            scroll_anaBoxes_;

    void createUi();
    void connectActions();
};
}

#endif

