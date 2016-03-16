#ifndef __GraphWidget_h__
#define __GraphWidget_h__

#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QPen>
#include <QBrush>
#include <QImage>
#include <QFont>
#include <QGraphicsScene>
#include <QTimer>

#include "graphcalculator.h"

namespace GUI {
class GlobalControlPanel;
}
namespace Model {
class Graph;
}

namespace GUI {
/**
 * This class is a widget to draw graphs.
 */
class GraphWidget:public QGraphicsView {
	Q_OBJECT
  public:
	/**
	 * @brief GraphWidget Constructor.
	 */
	GraphWidget(QWidget* parent=0);

	/**
	 * @brief drawGraph Draws a graph to the widget.
	 * @param graph The graph to draw.
	 * @param filled Whether the area under the graph is filled.
	 */
	void drawGraph(Model::Graph *graph);

	Model::Graph* getGraph();

	void setGraphCalculator(GraphCalculator* calculator);

	/**
	     * @brief setControlPanel Sets the GlobalControlPanel to notify, if a click on the graph was performed.
	 * @param panel The panel to notify.
	 */
	void setControlPanel(GlobalControlPanel* panel);

	/**
	 * @brief buildScene Creates the GraphicsScene.
	 */
	void buildScene();

  protected:
	/**
	 * @brief mouseReleaseEvent This method is called if the was a click on the widget.
	 * @param event
	 */
	void mouseReleaseEvent(QMouseEvent* event);

	void resizeEvent(QResizeEvent* event);

  private slots:
	void updateView();

  private:
	GlobalControlPanel*         controlPanel_;
	Model::Graph*               graph_;
	QGraphicsScene*             scene_;
	QTimer                      updater_;
	GraphCalculator*            calculator_;
};
}

#endif
