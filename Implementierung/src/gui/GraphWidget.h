/*
#include <exception>
using namespace std;

#ifndef __GraphWidget_h__
#define __GraphWidget_h__

// #include "AnalysisBox.h"
// #include "GlobalControlPanel.h"
#include "Graph.h"

namespace GUI
{
	class AnalysisBox;
	class GlobalControlPanel;
	class GraphWidget;
}
namespace Model
{
	class Graph;
}

namespace GUI
{
	/**
	 * This class is a widget to draw graphs.

	class GraphWidget
	{
		private: QRgb lineColor;
		private: QRgb fillColor;
		private: GloablControlPanel* controlPanel;
		public: GUI::AnalysisBox* psnrGraph;
		public: GUI::AnalysisBox* bitrateGraph;
		public: GUI::AnalysisBox* redHistogramm;
		public: GUI::AnalysisBox* blueHistogramm;
		public: GUI::AnalysisBox* greenHistogramm;
		public: Model::Graph* graph;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: GraphWidget();

		/// <summary>
		/// Draws a graph to the widget.
		/// </summary>
		/// <param name="graph">The graph to draw.</param>
		/// <param name="filled">Whether the area under the graph is filled.</param>
		public: void drawGraph(Model::Graph graph, bool filled);

		/// <summary>
		/// Determines the color of the graph line.
		/// </summary>
		/// <param name="color">The color in which the line is shown.</param>
		public: void setLineColor(QRgb color);

		/// <summary>
		/// Determines the color of the area beneath the graph line.
		/// </summary>
		/// <param name="color">The color in which the area beneath the graph line is filled.</param>
		public: void setFillColor(QRgb color);

		/// <summary>
		/// Sets the GlobalControlPanel to notify if a click on the graph was performed.
		/// </summary>
		/// <param name="panel">The panel to notify.</param>
		public: void setControlPanel(GUI::GlobalControlPanel* panel);

		/// <summary>
		/// This method is called if the was a click on the widget.
		/// </summary>
		protected: void mouseReleaseEvent(QMouseEvent* event);
	};
}

#endif
*/
