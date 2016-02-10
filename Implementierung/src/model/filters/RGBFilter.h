
#include <exception>
#include <string>


#ifndef __RGBFilter_h__
#define __RGBFilter_h__

#include "../../utility/BasicColor.h"
#include "Filter.h"


namespace Model {
/**
 * Filters the video by a given channel (red, green or blue).
*/
class RGBFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;


	/**
	 * @brief RGBFilter Constructor.
	 */
  public:
	RGBFilter();


	/**
	 * @brief Returns the preserved color.
	 * @return The preserved color.
	 */
	Model::BasicColor getColor();

	/**
	 * @brief Sets the preserved color.
	 * @param The preserved color.
	 */
	void setColor(Model::BasicColor color);

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
	Model::BasicColor color_;
};
}

#endif

