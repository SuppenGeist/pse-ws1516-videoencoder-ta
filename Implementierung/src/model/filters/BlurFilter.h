#ifndef __BlurFilter_h__
#define __BlurFilter_h__

#include <QString>

#include <string>

#include "Filter.h"

namespace Model {
/**
 * Blurs the video.
*/
class BlurFilter: public Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief BlurFilter Constructor.
	 */
	BlurFilter();

	/**
	  *@brief getIntensity.
	  *@return
	  */
	int getIntensity();

	/**
	* @brief setIntensity;
	* @param intensity of the blurring.
	*/
	void setIntensity(int intensity);

	/**
	 * @brief getFilterDescription
	 * @return
	 */
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
	void restoreFilter(QString description);

	/**
	 * @brief getSaveString
	 * @return
	 */
	QString getSaveString();

  private:
	int     intensity_;
};
}

#endif


