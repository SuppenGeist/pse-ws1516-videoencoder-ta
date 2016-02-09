#ifndef __ColorbalanceFilter_h__
#define __ColorbalanceFilter_h__

#include <string>

#include <QString>

#include "../../utility/BasicColor.h"
#include "Filter.h"


namespace Model {
/**
 * Adjusts the colorbalance of the video for the 3 basic colors.
*/
class ColorbalanceFilter: public Filter {
  public:
	static const QString FILTERNAME;

	/**
	 * @brief ColorbalanceFilter Constructor.
	 */
	ColorbalanceFilter();

	/**
	 * @brief getColor Returns the color whose balance is to be changed.
	 * @return The color to change.
	 */
	Model::BasicColor getColor();

	/**
	 * @brief setColor Sets the color whose balance shall be changed.
	 * @param color The color to change.
	 */
	void setColor(Model::BasicColor color);

	/**
	 * @brief getIntensity Returns the intensity of the change.
	 * @return The intensity.
	 */
	int getIntensity();

	/**
	 * @brief setIntensity Sets the intensity of the change.
	 * @param intensity The intensity.
	 */
	void setIntensity(int intensity);

	/**
	 * @brief getBrightPixels Whether the bright pixels shall be changed.
	 * @return True if the bright pixels are changed.
	 */
	bool getBrightPixels();

	/**
	 * @brief setBrightPixels Sets whether the bright pixels shall be changed.
	 * @param brightPixels True if the bright pixels shall be changed.
	 */
	void setBrightPixels(bool brightPixels);

	/**
	 * @brief getMediumPixels Whether the medium pixels shall be changed.
	 * @return True if the medium pixels are changed.
	 */
	bool getMediumPixels();

	/**
	 * @brief setMediumPixels Sets whether the medium pixels shall be changed.
	 * @param mediumPixels True if the medium pixels are changed.
	 */
	void setMediumPixels(bool mediumPixels);

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
	 * @brief getDarkPixels Whether the drak pixels shall be changed.
	 * @return True if the dark pixels are changed.
	 */
	bool getDarkPixels();

	/**
	 * @brief setDarkPixels Sets whether the dark pixels shall be changed.
	 * @param darkPixels True if the dark pixels are changed.
	 */
	void setDarkPixels(bool darkPixels);

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
	int         intensity_;
	bool        brightPixels_;
	bool        mediumPixels_;
	bool        darkPixels_;
	BasicColor  color_;
};
}

#endif


