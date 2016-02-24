#include <exception>
#include <string>


#ifndef __NoiseFilter_h__
#define __NoiseFilter_h__

#include "../NoiseMode.h"
#include "Filter.h"



namespace Model {
/**
 * Inserts noise into the video.
*/
class NoiseFilter: public Model::Filter {
  public:
	static const QString FILTERNAME;


	/**
	 * @brief NoiseFilter Constructor.
	 */
	NoiseFilter();


	/**
	 * @brief Returns the NoiseMode.
	 * @return The new NoiseMode.
	 */
	Model::NoiseMode getMode();

	/**
	 * @brief Sets the NoiseMode.
	 * @param The new NoiseMode.
	 */
	void setMode(Model::NoiseMode mode);

	/**
	 * @brief Returns the intensity of the noise.
	     * @return The intensity of the noise.
	 */
	int getIntensity();

	/**
	 * @brief Sets the intensity of the noise.
	 * @param The new intensity of the noise.
	 */
	void setIntensity(int intensity);

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
	Model::NoiseMode mode_;
	int intensity_;

};
}

#endif


