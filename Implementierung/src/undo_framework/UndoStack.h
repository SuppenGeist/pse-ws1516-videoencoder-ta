
#include <exception>
using namespace std;

#ifndef __UndoStack_h__
#define __UndoStack_h__

namespace UndoRedo
{
	class UndoStack;
}

namespace UndoRedo
{
	/**
	 * This class holds the stack that all undo commands are stacked on as a singleton.
    */
	class UndoStack
	{
		private: static QUndoStack undoStack;

		/// <summary>
		/// Constructor.
		/// </summary>
		private: UndoStack();

		/// <summary>
		/// Returns the undo stack to operate on.
		/// </summary>
		/// <returns>The undo stack.</returns>
		public: static QUndoStack& getUndoStack() {
			throw "Not yet implemented";
		}
	};
}

#endif

