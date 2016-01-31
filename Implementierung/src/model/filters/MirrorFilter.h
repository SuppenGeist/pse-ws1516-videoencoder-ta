#include <exception>
#include <string>


#ifndef __MirrorFilter_h__
#define __MirrorFilter_h__

#include "../MirrorMode.h"
#include "Filter.h"

namespace Model {
// enum MirrorMode;
// class Filter;
class MirrorFilter;
}

<<<<<<< HEAD
namespace Model
{
	/**
	 * Mirrors the video horizontally or vertically.
    */
	class MirrorFilter: public Model::Filter
	{
		private: Model::MirrorMode* mode;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: MirrorFilter();

        public: std::string getFilterDescription();

        public: std::string getName();

		/// <summary>
		/// Returns the MirrorMode.
		/// </summary>
		/// <returns>The MirrorMode.</returns>
		public: Model::MirrorMode getMode();

		/// <summary>
		/// Sets the MirrorMode.
		/// </summary>
		/// <param name="mode">The MirrorMode.</param>
		public: void setMode(Model::MirrorMode mode);

        public: void restoreFilter(QString description);

        public: QString getSaveString();
	};
=======
namespace Model {
/**
 * Mirrors the video horizontally or vertically.
*/
class MirrorFilter: public Model::Filter {
  private:
	Model::MirrorMode* mode;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	MirrorFilter();

  public:
	string getFilterDescription();

  public:
	string getName();

	/// <summary>
	/// Returns the MirrorMode.
	/// </summary>
	/// <returns>The MirrorMode.</returns>
  public:
	Model::MirrorMode getMode();

	/// <summary>
	/// Sets the MirrorMode.
	/// </summary>
	/// <param name="mode">The MirrorMode.</param>
  public:
	void setMode(Model::MirrorMode mode);

  public:
	void restoreFilter(QString description);

  public:
	QString getSaveString();
};
>>>>>>> origin/master
}

#endif


