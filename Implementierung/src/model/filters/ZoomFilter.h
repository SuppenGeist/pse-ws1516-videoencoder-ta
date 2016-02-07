#include <exception>
#include <string>


#ifndef __ZoomFilter_h__
#define __ZoomFilter_h__

#include "Filter.h"

namespace Model {
/**
 * Zooms into the center of the video.
*/
class ZoomFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;


    /**
     * @brief ZoomFilter Constructor.
     */
	ZoomFilter();

    /**
     * @brief Returns the intensity of the Zoom.
     * @return The intensity.
     */
  public:
	int getIntensity();

    /**
     * @brief Sets the intensity of the Zoom.
     * @param The intensity.
     */
	void setIntensity(int intensity);

    /**
     * @brief getName
     * @return
     */
    QString getName();

    /**
     * @brief getFilterDescription
     * @return
     */
    std::string getFilterDescription();

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
  int intensity_;
};
}

#endif


