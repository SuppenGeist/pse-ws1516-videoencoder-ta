
#include <exception>
using namespace std;

#ifndef __AddFilter_h__
#define __AddFilter_h__

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
	class AddFilter;
}

namespace UndoRedo
{
	/**
	 * This is the undo command for adding a filter to the filterlist on the filtertab.
	 */
	class AddFilter: public UndoRedo::QUndoCommand
	{
		private: GUI::FilterTab* filterTab;
		private: Model::Filter* filter;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filterTab">The filtertab to operate on.</param>
		/// <param name="filter">The filter on which the operation is performed on.</param>
		public: AddFilter(Model::Filter::FilterTab* filterTab, Model::Filter filter);

		/// <summary>
		/// Removes the added filter from the filterlist.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Adds a filter to the filterlist.
		/// </summary>
		public: void redo();
	};
}

#endif
