
#include <exception>
using namespace std;

#ifndef __LoadFilterVideo_h__
#define __LoadFilterVideo_h__

// #include "FilterTab.h"
#include "FilterTabMemento.h"
#include "YuvVideo.h"
#include "QUndoCommand.h"

namespace GUI
{
	class FilterTab;
}
namespace Memento
{
	class FilterTabMemento;
}
namespace Model
{
	class YuvVideo;
}
namespace UndoRedo
{
	// class QUndoCommand;
	class LoadFilterVideo;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for loading a raw video in the filtertab.
	 */
	class LoadFilterVideo: public UndoRedo::QUndoCommand
	{
		private: Memento::FilterTabMemento* memento;
		private: GUI::FilterTab* filterTab;
		private: Model::YuvVideo* video;

		/// <summary>
		/// Constuctor.
		/// </summary>
		/// <param name="filterTab">The filtertab to operate on.</param>
		/// <param name="video">The video to use.</param>
		/// <param name="memento">The memento before the new video is loaded.</param>
		public: LoadFilterVideo(GUI::FilterTab* filterTab, Model::YuvVideo video, Memento::FilterTabMemento memento);

		/// <summary>
		/// Removes current video to which filters can be applied and loads previous video.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Loads video to which filter can be applied.
		/// </summary>
		public: void redo();
	};
}

#endif
