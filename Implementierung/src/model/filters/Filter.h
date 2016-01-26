/*/*
#include <exception>
#include <string>
using namespace std;

#ifndef __Filter_h__
#define __Filter_h__

// #include "RemoveFilter.h"

namespace Model
{
	class Filter;
}
namespace UndoRedo
{
	class RemoveFilter;
}

namespace Model
{
	/**
	 * Baseclass for Filters.

	__abstract class Filter
	{
		public: UndoRedo::RemoveFilter* filter;

		/// <summary>
		/// Returns the string that the ffmpeg library needs to apply the filter to a video.
		/// </summary>
		/// <returns>The string for the ffmpeg library.</returns>
		public: virtual string getFilterDescription() = 0;

		/// <summary>
		/// Returns the name of the filter.
		/// </summary>
		/// <returns>The filtername.</returns>
		public: virtual string getName() = 0;
	};
}

#endif
*/

