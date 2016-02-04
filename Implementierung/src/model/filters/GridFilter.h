#ifndef __GridFilter_h__
#define __GridFilter_h__

#include <QColor>



#include "Filter.h"

namespace Model {
// class Filter;
class GridFilter;
}

namespace Model {
/**
 * Inserts a grid into the video as an overlay.
*/
class GridFilter: public Model::Filter {
  private:
	int horizontalLines;
  private:
	int verticalLines;
  private:
	QRgb color;
  private:
	int thickness;
  private:
	int opacity;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	GridFilter();

  public:
	std::string getFilterDescription();

	/// <summary>
	/// Returns the number of horizontal drawn lines.
	/// </summary>
	/// <returns>Number of horizontal lines.</returns>
  public:
	int getHorizontalLines();

	/// <summary>
	/// Sets the number of horizontal drawn lines.
	/// </summary>
	/// <param name="horizontalLines">Number of horizontal lines.</param>
  public:
	void setHorizontalLines(int horizontalLines);

	/// <summary>
	/// Returns the number of vertical drawn lines.
	/// </summary>
	/// <returns>Number of vertical lines.</returns>
  public:
	int getVerticalLines();

	/// <summary>
	/// Sets the number of vertical drawn lines.
	/// </summary>
	/// <param name="verticalLines">Number of vertical drawn lines.</param>
  public:
	void setVerticalLines(int verticalLines);

	/// <summary>
	/// Returns the color of the grid.
	/// </summary>
	/// <returns>The gridcolor.</returns>
  public:
	QRgb getColor();

	/// <summary>
	/// Sets the color of the grid.
	/// </summary>
	/// <param name="color">The gridcolor.</param>
  public:
	void setColor(QRgb color);

	/// <summary>
	/// Returns the thickness of the drawn lines.
	/// </summary>
	/// <returns>The line thickness.</returns>
  public:
	int getThickness();

	/// <summary>
	/// Sets the thickness of the drawn lines.
	/// </summary>
	/// <param name="thickness">The thickness of the drawn lines.</param>
  public:
	void setThickness(int thickness);

	/// <summary>
	/// Returns the opacity of the grid.
	/// </summary>
	/// <returns>The grids opacity.</returns>
  public:
	int getOpacity();

	/// <summary>
	/// Sets the opacity of the grid.
	/// </summary>
	/// <param name="opacity">The grids opacity.</param>
  public:
	void setOpacity(int opacity);

  public:
	std::string getName();

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


