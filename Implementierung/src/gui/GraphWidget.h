#ifndef __GraphWidget_h__
#define __GraphWidget_h__

#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QGraphicsScene>

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

	/**
	 * @brief setLineColor Sets the pen which is used to draw the graph line.
	 * @param color The pen to use.
	 */
	void setLinePen(QPen linePen);

	/**
	 * @brief setFillPen Sets the pen which is used to draw the polygon lines which fill the graph.
	 * @param fillPen The pen to use.
	 */
	void setFillPen(QPen fillPen);

	/**
	 * @brief setFillBrush The brish which is used to fill the graph.
	 * @param fillBrush The brush to use.
	 */
	void setFillBrush(QBrush fillBrush);

	/**
	 * @brief setControlPanel Sets the GlobalControlPanel to notify if a click on the graph was performed.
	 * @param panel The panel to notify.
	 */
    void setControlPanel(GlobalControlPanel* panel);

	/**
	 * @brief setAchsisLabels Sets the labels of the achsis.
	 * @param xLabel x-achsis label.
	 * @param yLabel y-achsis label;
	 */
	void setAxisLabels(QString xLabel,QString yLabel);

	/**
	 * @brief setIsFilles Sets if the grah gets filled.
	 * @param isFilled true if the graph gets filled
	 */
	void setIsFilled(bool isFilled);

	/**
	 * @brief setMargin Sets the margin for the scene.
	 * @param marginX The margin on the x axis.
	 * @param marginY The margin on the y axis.
	 */
	void setMargin(int marginX,int marginY);

	/**
	 * @brief setShowLabels Sets whether the axis labels are shown or not.
	 * @param showLabels true if the labels are shown.
	 */
	void setShowLabels(bool showLabels);

	/**
	 * @brief setMarkLength Sets the length of the marks.
	 * @param xMarkLen Marks on the x axis.
	 * @param yMarkLen Marks on the y axis.
	 */
	void setMarkLength(int xMarkLen,int yMarkLen);

	/**
	 * @brief setBackgroundColot Sets the backgroundcolor of the widget.
	 * @param bColor The backgroundcolor.
	 */
	void setBackgroundColor(QColor bColor);

	/**
	 * @brief setMarkDistance Sets the distance between the marks.
	 * @param disX Distance on the x axis.
	 * @param disY Distance on the y axis.
	 */
	void setMarkDistance(int disX,int disY);

	/**
	 * @brief setLabelFont Sets the font for the axis labels.
	 * @param labelFont The font to use.
	 */
	void setLabelFont(QFont labelFont);

	/**
	 * @brief setMarkFont Sets the font for the marks.
	 * @param markFont The font to use.
	 */
	void setMarkFont(QFont markFont);

    void setFixedMaxYValue(double maxYVal);

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

  private:
	QPen                        linePen_;
	QPen                        fillPen_;
	QBrush                      fillBrush_;
	GlobalControlPanel*         controlPanel_;
	Model::Graph*               graph_;
	QGraphicsScene*             scene_;
	QFont                       axisLabelFont_;
	QString                     xLabel_;
	QString                     yLabel_;
	QFont                       labelFont_;
	QFont                       markFont_;
	bool                        isFilled_;
	int                         marginWidth_;
    int                         marginHeight_;
	int                         markLenX_;
	int                         markLenY_;
	int                         xLabelHeight_;
	int                         yLabelWidth_;
	bool                        showLabels_;
	int                         markDistanceX_;
	int                         markDistanceY_;
    double                      fixedMaxYVal_;

	/**
	 * @brief clamp Clamps the value to the given index.
	 * @param val The value to clamp.
	 * @param max Maxvalue.
	 * @param min Minvalue.
	 * @return  The clamped value.
	 */
	int clamp(int val,int max,int min);

	/**
	 * @brief updateLabelSizes Updates the sizes of the labels.
	 */
	void updateLabelSizes();
};
}

#endif
