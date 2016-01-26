
#include <exception>
using namespace std;

#ifndef __LoadAnalysisVideo_h__
#define __LoadAnalysisVideo_h__

// #include "AnalysisTab.h"
// #include "AnalysisTabMemento.h"
#include "YuvVideo.h"
#include "QUndoCommand.h"

namespace GUI
{
	class AnalysisTab;
}
namespace Memento
{
	class AnalysisTabMemento;
}
namespace Model
{
	class YuvVideo;
}
namespace UndoRedo
{
	// class QUndoCommand;
	class LoadAnalysisVideo;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for loading the raw video on the analysis tab.
	 */
	class LoadAnalysisVideo: public UndoRedo::QUndoCommand
	{
		public: Memento::AnalysisTabMemento* memento;
		private: GUI::AnalysisTab* anaTab;
		private: Model::YuvVideo* video;

		/// <summary>
		/// Constructor..
		/// </summary>
		/// <param name="anaTab">The AnalyseTab to operate on.</param>
		/// <param name="anaTabMem">The memento of the analyse tab before the raw video is loaded.</param>
		/// <param name="video">The new raw video.</param>
		public: LoadAnalysisVideo(GUI::AnalysisTab* anaTab, AnalyseTabMemento anaTabMem, Model::YuvVideo video);

		/// <summary>
		/// Restores the anlysis tab to the state before the new video was loaded.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Loads anew raw video in the analysis tab.
		/// </summary>
		public: void redo();
	};
}

#endif
