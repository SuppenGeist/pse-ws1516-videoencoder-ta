
#include <exception>
using namespace std;

#ifndef __LoadFilterconfig_h__
#define __LoadFilterconfig_h__

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
	class LoadFilterconfig;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for loading a filter config on the filter tab.
	 */
	class LoadFilterconfig: public UndoRedo::QUndoCommand
	{
		private: GUI::FilterTab* filterTab;
		private: Model::FilterList* oldList;
		private: Model::FilterList* newList;

		/// <summary>
		/// Constuctor.
		/// </summary>
		/// <param name="filterTab">The filtertab to operate on.</param>
		/// <param name="oldList">The filterlist before the config is loaded.</param>
		/// <param name="list">The new filter configuration.</param>
		public: LoadFilterconfig(GUI::FilterTab* filterTab, Model::FilterList oldList, Model::FilterList list);

		/// <summary>
		/// Loads the filter configuration present before external configuration was loaded.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Loads a filter configuration from a external file.
		/// </summary>
		public: void redo();
	};
}

#endif
