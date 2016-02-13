#ifndef __AnalysisBox_h__
#define __AnalysisBox_h__

#include <QFrame>
#include <QTabWidget>

#include "FrameView.h"
#include "GraphWidget.h"

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

  private:
    FrameView*      origView_;
    FrameView*      anaView_;
    QTabWidget*     tabs_graphs_;
    GraphWidget*    graphWidget_;

    void createUi();

};
}

#endif
