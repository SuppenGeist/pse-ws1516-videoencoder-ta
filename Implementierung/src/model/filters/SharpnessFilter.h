#include <exception>
#include <string>


#ifndef __SharpnessFilter_h__
#define __SharpnessFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class SharpnessFilter;
}

<<<<<<< HEAD
namespace Model
{
	/**
	 * Sharpens the video.
    */
	class SharpnessFilter: public Model::Filter
	{
		private: int intensity;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: SharpnessFilter();

        public: std::string getFilterDescription();

		/// <summary>
		/// Returns the intensity of the sharpness.
		/// </summary>
		/// <returns>The intensity.</returns>
		public: int getIntensity();

        public: std::string getName();

		/// <summary>
		/// Sets the intensity of the sharpness.
		/// </summary>
		/// <param name="intensity">The new intensity.</param>
		public: void setIntensity(int intensity);

        public: void restoreFilter(QString description);

        public: QString getSaveString();
	};
=======
namespace Model {
/**
 * Sharpens the video.
*/
class SharpnessFilter: public Model::Filter {
  private:
	int intensity;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	SharpnessFilter();

  public:
	string getFilterDescription();

	/// <summary>
	/// Returns the intensity of the sharpness.
	/// </summary>
	/// <returns>The intensity.</returns>
  public:
	int getIntensity();

  public:
	string getName();

	/// <summary>
	/// Sets the intensity of the sharpness.
	/// </summary>
	/// <param name="intensity">The new intensity.</param>
  public:
	void setIntensity(int intensity);

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
>>>>>>> origin/master
}

#endif


