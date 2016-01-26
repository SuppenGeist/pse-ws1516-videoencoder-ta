/*
#include <exception>
using namespace std;

#ifndef __RemoveVideo_h__
#define __RemoveVideo_h__

// #include "AnalysisBox.h"
// #include "AnalysisBoxContainer.h"
// #include "EncodedVideo.h"
#include "QUndoCommand.h"

namespace GUI
{
	class AnalysisBox;
	class AnalysisBoxContainer;
}
namespace Model
{
	class EncodedVideo;
}
namespace UndoRedo
{
	// class QUndoCommand;
	class RemoveVideo;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for removing a encoded video in the analysis tab.

	class RemoveVideo: public UndoRedo::QUndoCommand
	{
		private: GUI::AnalysisBox* anaBox;
		private: GUI::AnalysisBoxContainer* anaBoxContainer;
		private: Model::EncodedVideo* video;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="container">The AnalysisBoxContainer to operate on.</param>
		/// <param name="video">The video to remove.</param>
		public: RemoveVideo(GUI::AnalysisBoxContainer* container, encodedVideo video);

		/// <summary>
		/// Re adds the removed video to the analysis tab.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Removes a video from the analysis tab.
		/// </summary>
		public: void redo();
	};
}

#endif
*/
