#include <exception>
#include <string>


#ifndef __NegativeFilter_h__
#define __NegativeFilter_h__

#include "Filter.h"



namespace Model {
/**
 * Converts the video into it's negative.
*/
class NegativeFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief BorderFilter Constructor.
	 */
	NegativeFilter();


	std::string getFilterDescription();

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
};
}

#endif
