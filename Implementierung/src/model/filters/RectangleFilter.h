#include <exception>
#include <string>
#include <QColor>

#ifndef __RectangleFilter_h__
#define __RectangleFilter_h__

#include "Filter.h"
//NOT FINISHED
namespace Model {
// class Filter;
class RectangleFilter;
}

namespace Model {
/**
 * Inserts a filled rectangle with a given color into the video
*/
class RectangleFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;


	/// <summary>
	/// Constructor.
	/// </summary>
	RectangleFilter();

	std::string getFilterDescription();

	/// <summary>
	/// Returns the color of the rectangle.
	/// </summary>
	/// <returns>The color of the rectangle.</returns>  
    QColor getColor();

	/// <summary>
	/// Sets the color of the rectangle.
	/// </summary>
	/// <param name="color">The new color of the rectangle.</param>
    void setColor(QColor color_);

	/// <summary>
	/// Returns the width of the rectangle.
	/// </summary>
	/// <returns>The width of the rectangle.</returns>
	int getWidth();

	/// <summary>
	/// Sets the width of the rectangle.
	/// </summary>
	/// <param name="width">The new width of the rectangle.</param>
    void setWidth(int width_);

	/// <summary>
	/// Returns the height of the rectangle.
	/// </summary>
	/// <returns>The height of the rectangle.</returns>
	int getHeight();

	/// <summary>
	/// Sets the height of the rectangle.
	/// </summary>
	/// <param name="height">The new height of the rectangle.</param>
    void setHeight(int height_);

	/// <summary>
	/// Returns the start position on the x axis.
	/// </summary>
	/// <returns>The start position on the x axis.</returns>
	int getX();

    QString getName();

	/// <summary>
	/// Sets the start position on the x axis.
	/// </summary>
	/// <param name="x">The new start position on the x axis.</param>
    void setX(int x_);

	/// <summary>
	/// Returns the start position on the y axis.
	/// </summary>
	/// <returns>The start position on the y axis.</returns>
	int getY();

	/// <summary>
	/// Sets the start position on the y axis.
	/// </summary>
	/// <param name="y">The new start position on the y axis.</param>
    void setY(int y_);

	/// <summary>
	/// Returns the opacity of the rectangle.
	/// </summary>
	/// <returns>The opacity of the rectangle.</returns>
	int getOpacity();

	/// <summary>
	/// Sets the opacity of the rectangle.
	/// </summary>
	/// <param name="opacity">The new opacity of the rectangle.</param>
    void setOpacity(int opacity_);

	void restoreFilter(QString description);

	QString getSaveString();

private:
  QColor color_;
  int width_;
  int height_;
  int x_;
  int y_;
  int opacity_;
};
}

#endif


