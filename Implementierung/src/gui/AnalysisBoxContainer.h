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

#include "../memento/AnalysisBoxContainerMemento.h"

namespace GUI {
class AnalysisTab;
class Timer;
class GlobalControlPanel;
enum class AnalysisGraph;
enum class AnalysisVideo;
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

    std::unique_ptr<Memento::AnalysisBoxContainerMemento> getMemento();

    void restore(Memento::AnalysisBoxContainerMemento* memento);

	void setParentTab(AnalysisTab* parent);

    AnalysisTab* getParentTab();

    AnalysisBox* appendBox(AnalysisBox* box);

    int removeBox(AnalysisBox* box);

	void clear();

	void setTimer(std::shared_ptr<Timer> timer);

    void setControlPanel(std::shared_ptr<GlobalControlPanel> controlpanel);

	void showGraph(AnalysisGraph graph);

    void showAnalysisVideo(AnalysisVideo video);

    void showAttributes();

    AnalysisBox* getAnalysisBox(int index);

    int getIndex(AnalysisBox* box);

    AnalysisGraph getShownGraph();

    AnalysisVideo getShownVideo();

    AnalysisBox* insertBox(AnalysisBox* box,int index);

  private slots:
	void addVideo();

  private:
	QVBoxLayout*                v_boxes_;
	QSpacerItem*                spacer_;
	QPushButton*                button_addVideo_;

	AnalysisTab*                parent_;
	std::shared_ptr<Timer>      timer_;
    std::shared_ptr<GlobalControlPanel>         controlPanel_;

	std::vector<AnalysisBox*>   boxes_;

	AnalysisGraph               currentGraph_;
    AnalysisVideo               currentVideo_;

	void createUi();

	void updateUi();
};
}

#endif
