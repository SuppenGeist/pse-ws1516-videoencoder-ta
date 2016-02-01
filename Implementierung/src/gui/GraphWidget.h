#ifndef __GraphWidget_h__
#define __GraphWidget_h__

#include <QRgb>
#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QGraphicsScene>

#include "../model/Graph.h"

namespace GUI {
    class GlobalControlPanel;
}

namespace GUI
{
	/**
	 * This class is a widget to draw graphs.
     */
    class GraphWidget:public QGraphicsView
	{

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
        void drawGraph(Model::Graph graph, bool filled);

        /**
         * @brief setLineColor Determines the color of the graph line.
         * @param color The color in which the line is shown.
         */
        void setLineColor(QRgb color);

        /**
         * @brief setFillColor Determines the color of the area beneath the graph line.
         * @param color The color in which the area beneath the graph line is filled.
         */
        void setFillColor(QRgb color);

        /**
         * @brief setControlPanel Sets the GlobalControlPanel to notify if a click on the graph was performed.
         * @param panel The panel to notify.
         */
        void setControlPanel(GlobalControlPanel* panel);

        protected:
        /**
         * @brief mouseReleaseEvent This method is called if the was a click on the widget.
         * @param event
         */
        void mouseReleaseEvent(QMouseEvent* event);

        /**
         * @brief resizeEvent This methods reacts to the change of the size.
         * @param event
         */
        void resizeEvent(QResizeEvent* event);

    private:
        QRgb                        lineColor_;
        QRgb                        fillColor_;
        GlobalControlPanel*         controlPanel_;
        Model::Graph                graph_;
        QGraphicsScene*             scene_;
        bool                        isFilled_;

        /**
         * @brief buildScene Creates the GrpahicsScene.
         */
        void buildScene();
	};
}

#endif
