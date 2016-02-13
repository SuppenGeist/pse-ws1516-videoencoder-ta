#ifndef __AnalysisBoxContainer_h__
#define __AnalysisBoxContainer_h__

#include <vector>

#include <QWidget>
#include <QFrame>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "AnalysisBox.h"

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
    AnalysisBoxContainer(QWidget* parent=0);

    void addVideo(QString path);

    void clear();

  private:
    QVBoxLayout*                v_boxes_;
    QSpacerItem*                spacer_;
    QPushButton*                button_addVideo_;

    std::vector<AnalysisBox*>   boxes_;

    void createUi();
};
}

#endif
