#include <exception>
#include <string>
#include <QColor>

#ifndef __RectangleFilter_h__
#define __RectangleFilter_h__

#include "Filter.h"


namespace Model {
/**
 * Inserts a filled rectangle with a given color into the video
*/
class RectangleFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;


	/**
	 * @brief RectangleFilter Constructor.
	 */
	RectangleFilter();


	/**
	* @brief Returns the color of the rectangle.
	* @return The new color of the rectangle.
	*/
	QColor getColor();

	/**
	* @brief Sets the color of the rectangle.
	* @param The new color of the rectangle.
	*/
	void setColor(QColor color);

	/**
	* @brief Returns the width of the rectangle.
	* @return The width of the rectangle.
	*/
	int getWidth();

	/**
	* @brief Sets the width of the rectangle.
	* @param The new width of the rectangle.
	*/
	void setWidth(int width);

	/**
	* @brief Returns the height of the rectangle.
	* @return The height of the rectangle.
	*/
	int getHeight();

	/**
	* @brief Sets the height of the rectangle.
	* @param The new height of the rectangle.
	*/
	void setHeight(int height);

	/**
	* @brief Returns the start position on the x axis.
	* @return The start position on the x axis.
	*/
	int getX();

	/**
	* @brief Sets the start position on the x axis.
	* @param The new start position on the x axis.
	*/
	void setX(int x);

	/**
	* @brief Returns the start position on the y axis.
	* @return The start position on the y axis.
	*/
	int getY();

	/**
	* @brief Sets the start position on the y axis.
	* @param The new start position on the y axis.
	*/
	void setY(int y);

	/**
	* @brief Returns the opacity of the rectangle.
	* @return The opacity of the rectangle.
	*/
	int getOpacity();

	/**
	* @brief Sets the opacity of the rectangle.
	* @param The new opacity of the rectangle.
	*/
	void setOpacity(int opacity);

	/**
	 * @brief getName
	 * @return
	 */
	QString getName() const;

	/**
	 * @brief getFilterDescription
	 * @return
	 */
	std::string getFilterDescription();

	/**
	 * @brief restoreFilter
	 * @param description
	 */
	void restore(QString description);

	/**
	 * @brief getSaveString
	 * @return
	 */
	QString getSaveString() const;

  private:
    int x_;
    int y_;
	int width_;
	int height_;
    QColor color_;
	int opacity_;
};
}

#endif


