#include <exception>
#include <string>


#ifndef __BlurFilter_h__
#define __BlurFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class BlurFilter;
}

namespace Model {
/**
 * Blurs the video.
*/
class BlurFilter: public Model::Filter {
  public:
    static const QString FILTERNAME;
  private:
	bool preserveEdges;
  private:
	int intensity;

    /**
     * @brief BlurFilter Constructor.
     */
  public:
	BlurFilter();

    /**
    * Whether edges shall be preserved when blurring.
    */
  public:
	bool getPreserveEdges();

    /**
    * Sets whether the edges shall be preserved when blurring.
    *
    * @param preserveEdges.
    */
  public:
	void setPreserveEdges(bool preserveEdges);

    /**
      *@brief getIntensity.
      *@return
      */
  public:
	int getIntensity();

    /**
    * @brief setIntensity;
    * @param intensity of the blurring.
    */
  public:
	void setIntensity(int intensity);

  public:
	std::string getFilterDescription();

  public:
    QString getName();

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
}

#endif


