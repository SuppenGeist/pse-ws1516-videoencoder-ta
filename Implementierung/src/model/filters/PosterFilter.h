#include <exception>
#include <string>


#ifndef __PosterFilter_h__
#define __PosterFilter_h__

#include "Filter.h"


namespace Model {
/**
 * Reduces the maximum number of colors in the video.
*/
class PosterFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;


	/**
	 * @brief PosterFilter Constructor.
	 */
	PosterFilter();

	/**
	 * @brief getFilterDescription
	 * @return
	 */
	std::string getFilterDescription();

	/**
	     * @brief Returns the maximum number of colors.
	 * @return The maximum number of colors.
	 */
	int getNumberOfColors();


	/**
	 * @brief Sets the maximum number of colors.
	 * @param The maximum number of colors.
	 */
	void setNumberOfColors(int numberOfColors);

	/**
	 * @brief getName
	 * @return
	 */
	QString getName() const;

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
	int numberOfColors_;
};
}

#endif


