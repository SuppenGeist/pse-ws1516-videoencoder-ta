/*
#include <exception>
using namespace std;

#ifndef __WriteComment_h__
#define __WriteComment_h__

#include "QUndoCommand.h"

namespace UndoRedo
{
	// class QUndoCommand;
	class WriteComment;
}

namespace UndoRedo
{
	class WriteComment: public UndoRedo::QUndoCommand
	{

		/// <summary>
		/// Constuctor
		/// </summary>
		public: WriteComment();

		/// <summary>
		/// attempts to merge this command with command if they have the same id, and the id is not -1
		/// </summary>
		public: void mergeWith(UndoRedo::QUndoCommand command);

		/// <summary>
		/// reverts changes to the textbox
		/// </summary>
		public: void undo();

		/// <summary>
		/// applies changes to the textbox
		/// </summary>
		public: void redo();

		/// <summary>
		/// returns id of this command
		/// </summary>
		public: void id();
	};
}

#endif
*/
