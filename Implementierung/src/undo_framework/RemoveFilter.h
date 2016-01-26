
#include <exception>
using namespace std;

#ifndef __RemoveFilter_h__
#define __RemoveFilter_h__

// #include "FilterTab.h"
#include "Filter.h"
#include "QUndoCommand.h"

namespace GUI
{
	class FilterTab;
}
namespace Model
{
	class Filter;
}
namespace UndoRedo
{
	// class QUndoCommand;
	class RemoveFilter;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for removing a filter in the filterlist on the filtertab.
	 */
	class RemoveFilter: public UndoRedo::QUndoCommand
	{
		private: int index;
		private: GUI::FilterTab* filterTab;
		private: Model::Filter* filter;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filterTab">The filtertab to operate on.</param>
		/// <param name="filter">The filter to remove.</param>
		/// <param name="index">The current index of the filter to remove.</param>
		public: RemoveFilter(GUI::FilterTab* filterTab, Model::Filter filter, int index);

		/// <summary>
		/// Adds the removed filter back into the filterlist.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Removes a filter from the filterlist.
		/// </summary>
		public: void redo();
	};
}

#endif
