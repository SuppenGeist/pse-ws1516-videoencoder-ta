
#include <exception>
using namespace std;

#ifndef __MoveFilterDown_h__
#define __MoveFilterDown_h__

// #include "FilterTab.h"
#include "QUndoCommand.h"

namespace GUI
{
	class FilterTab;
}
namespace UndoRedo
{
	// class QUndoCommand;
	class MoveFilterDown;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for moving a filter down in the filterlist.
	 */
	class MoveFilterDown: public UndoRedo::QUndoCommand
	{
		private: int oldIndex;
		private: int newIndex;
		private: GUI::FilterTab* filterTab;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filterTab">The filtertab to operate on.</param>
		/// <param name="old">The old index of the filter.</param>
		/// <param name="new">The new index of the filter.</param>
		public: MoveFilterDown(GUI::FilterTab* filterTab, int old, int new_2);

		/// <summary>
		/// Moves the filter one position back up in the filterlist.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Moves selected filter one position down in the filterlist.
		/// </summary>
		public: void redo();
	};
}

#endif
