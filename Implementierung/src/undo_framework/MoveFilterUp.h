
#include <exception>
using namespace std;

#ifndef __MoveFilterUp_h__
#define __MoveFilterUp_h__

// #include "FilterTab.h"
#include "QUndoCommand.h"

namespace GUI
{
	class FilterTab;
}
namespace UndoRedo
{
	// class QUndoCommand;
	class MoveFilterUp;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for moving a filter up in the filterlist.
	 */
	class MoveFilterUp: public UndoRedo::QUndoCommand
	{
		private: int oldIndex;
		private: int newIndex;
		private: GUI::FilterTab* filterTab;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="filterTab">The filtertab to operate on.</param>
		/// <param name="old">Old index of the filter.</param>
		/// <param name="new">New index of the filter.</param>
		public: MoveFilterUp(GUI::FilterTab* filterTab, int old, int new_1);

		/// <summary>
		/// Moves the filter one position back down in the filterlist.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Moves selected filter one position up in the filterlist.
		/// </summary>
		public: void redo();
	};
}

#endif
