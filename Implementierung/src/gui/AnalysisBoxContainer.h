#ifndef __AnalysisBoxContainer_h__
#define __AnalysisBoxContainer_h__

#include <vector>
#include <memory>

#include <QWidget>
#include <QFrame>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "AnalysisBox.h"

namespace GUI {
    class AnalysisTab;
    class Timer;
    class GlobalControlPanel;
}

namespace GUI {
/**
 * Contains and manages the AnalysisBoxes.
*/
class AnalysisBoxContainer: public QFrame {
    Q_OBJECT
  public:

	/**
	* @brief AnalysisBoxContainer Constructor
	* @param parent parent of this object
	*/
    AnalysisBoxContainer(QWidget* parent=0);

    void setParentTab(AnalysisTab* parent);

    void appendVideo(QString path);

    void removeLastVideo();

    void clear();

    void setTimer(std::shared_ptr<Timer> timer);

    void setControlPanel(GlobalControlPanel* controlpanel);

private slots:
    void addVideo();

  private:
    QVBoxLayout*                v_boxes_;
    QSpacerItem*                spacer_;
    QPushButton*                button_addVideo_;

    AnalysisTab*                parent_;
    std::shared_ptr<Timer>      timer_;
    GlobalControlPanel*         controlPanel_;

    std::vector<AnalysisBox*>   boxes_;

    void createUi();
};
}

#endif
