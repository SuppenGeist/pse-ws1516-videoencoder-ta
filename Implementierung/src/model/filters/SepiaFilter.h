#include <exception>
#include <string>


#ifndef __SepiaFilter_h__
#define __SepiaFilter_h__

#include "Filter.h"


namespace Model {
/**
 * Converts the video into sepia.
*/
class SepiaFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;
	/**
	 * @brief SepiaFilter Constructor.
	 */
	SepiaFilter();

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
	void restore(QString);

	/**
	 * @brief getSaveString
	 * @return
	 */
	QString getSaveString() const;
};
}

#endif


