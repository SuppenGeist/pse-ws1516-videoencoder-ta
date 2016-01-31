#include <exception>
#include <string>


#ifndef __ContrastFilter_h__
#define __ContrastFilter_h__

#include "Filter.h"

namespace Model {
// class Filter;
class ContrastFilter;
}

<<<<<<< HEAD
namespace Model
{
	/**
	 * Adjusts the contrast of the video.
    */
	class ContrastFilter: public Model::Filter
	{
		private: int intensity;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: ContrastFilter();

		/// <summary>
		/// Sets the intensity of the contrast.
		/// </summary>
		/// <param name="intensity">The new intensity.</param>
		public: void setIntensity(int intensity);

		/// <summary>
		/// Returns the intensity of the contrast.
		/// </summary>
		/// <returns>The intensity.</returns>
		public: int getIntensity();

        public: std::string getName();

        public: std::string getFilterDescription();

        public: void restoreFilter(QString description);

        public: QString getSaveString();
	};
=======
namespace Model {
/**
 * Adjusts the contrast of the video.
*/
class ContrastFilter: public Model::Filter {
  private:
	int intensity;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	ContrastFilter();

	/// <summary>
	/// Sets the intensity of the contrast.
	/// </summary>
	/// <param name="intensity">The new intensity.</param>
  public:
	void setIntensity(int intensity);

	/// <summary>
	/// Returns the intensity of the contrast.
	/// </summary>
	/// <returns>The intensity.</returns>
  public:
	int getIntensity();

  public:
	string getName();

  public:
	string getFilterDescription();

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
>>>>>>> origin/master
}

#endif


