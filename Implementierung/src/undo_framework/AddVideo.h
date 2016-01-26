/*
#include <exception>
using namespace std;

#ifndef __AddVideo_h__
#define __AddVideo_h__

// #include "AnalysisBox.h"
// #include "AnalysisBoxContainer.h"
#include "EncodedVideo.h"
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
	class AddVideo;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for adding a encoded video on the analysis tab.

	class AddVideo: public UndoRedo::QUndoCommand
	{
		private: GUI::AnalysisBox* anaBox;
		private: GUI::AnalysisBoxContainer* anaBoxContainer;
		private: Model::EncodedVideo* video;

		/// <summary>
		/// Constuctor.
		/// </summary>
		/// <param name="analysisBoxContainer">The AnalysisBoxContainer to operate on.</param>
		/// <param name="video">The video on which the action is performed.</param>
		public: AddVideo(GUI::AnalysisBoxContainer* analysisBoxContainer, Model::EncodedVideo video);

		/// <summary>
		/// Removes the added video from the analysis tab.
		/// </summary>
		public: void undo();

		/// <summary>
		/// Adds a video to the Analysis tab.
		/// </summary>
		public: void redo();
	};
}

#endif
*/
