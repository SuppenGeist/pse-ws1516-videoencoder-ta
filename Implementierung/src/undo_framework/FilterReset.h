
#include <exception>
using namespace std;

#ifndef __FilterReset_h__
#define __FilterReset_h__

// #include "FilterTab.h"
#include "FilterList.h"
#include "QUndoCommand.h"

namespace GUI
{
	class FilterTab;
}
namespace Model
{
	class FilterList;
}
namespace UndoRedo
{
	// class QUndoCommand;
	class FilterReset;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for resting the filterlist in the filter tab.
	 */
	class FilterReset: public UndoRedo::QUndoCommand
	{
		private: GUI::FilterTab* filterTab;
		private: Model::FilterList* filterList;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filterTab">The filtertab to operate on.</param>
		/// <param name="filterList">The filterlist the action to perform on.</param>
		public: FilterReset(GUI::FilterTab* filterTab, Model::FilterList filterList);

		/// <summary>
		/// Loads the filterlist and filter configuration to the state it was before the reset.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Clears the filter configurations and the filter list.
		/// </summary>
		public: void redo();
	};
}

#endif
