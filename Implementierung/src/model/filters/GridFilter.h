#ifndef __GridFilter_h__
#define __GridFilter_h__

#include <QColor>



#include "Filter.h"


namespace Model {
/**
 * Inserts a grid into the video as an overlay.
*/
class GridFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief BorderFilter Constructor.
	 */
	GridFilter();


	std::string getFilterDescription();

	/**
	* @brief Returns the horizontal number cells.
	* @return horizontal Number of cells
	*/
	int getHorizontalCells();

	/**
	* @brief Sets the horizontal number of cells.
	* @param horizontal Number of cells
	*/
	void setHorizontalCells(int horizontalCells);

	/**
	* @brief Returns the vertical number of cells.
	* @return vertical Number of cells
	*/
	int getVerticalCells();

	/**
	* @brief Sets the vertical number of cells.
	* @param vertical Number of cells
	*/
	void setVerticalCells(int verticalCells);

	/**
	 *@brief Returns the color of the grid.
	 *@return The gridcolor
	 */
	QColor getColor();

	/**
	 *@brief Sets the color of the grid.
	 *@param The gridcolor
	 */
	void setColor(QColor color);

	/**
	 *@brief Returns the thickness of the drawn lines.
	 *@return The line thickness.
	 */
	int getThickness();

	/**
	 *@brief Sets the thickness of the drawn lines.
	 *@param The line thickness.
	 */
	void setThickness(int thickness);

	/**
	 *@brief Returns the opacity of the grid.
	 *@return The grids opacity.
	 */
	int getOpacity();

	/**
	 *@brief Sets the opacity of the grid.
	 *@param The grids opacity.
	 */
	void setOpacity(int opacity);

	/**
	 * @brief getName
	 * @return
	 */
	QString getName();

	/**
	 * @brief restoreFilter
	 * @param description
	 */
	void restore(QString description);

	/**
	 * @brief getSaveString
	 * @return
	 */
	QString getSaveString();
  private:
	int    horizontalCells_;
	int    verticalCells_;
	int    opacity_;
	int     thickness_;
	QColor    color_;
};
}

#endif


