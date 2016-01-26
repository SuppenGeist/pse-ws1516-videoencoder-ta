/*
#include <exception>
using namespace std;

#ifndef __AnalysisTabMemento_h__
#define __AnalysisTabMemento_h__

#include "AnalysisBoxContainerMemento.h"
// #include "LoadAnalysisVideo.h"

namespace Memento
{
	class AnalysisBoxContainerMemento;
	class AnalysisTabMemento;
}
namespace UndoRedo
{
	class LoadAnalysisVideo;
}

namespace Memento
{
	/**
	 * This class is the memento for the analysis tab.

	class AnalysisTabMemento
	{
		private: int currentVideoPosition;
		private: int currentlyShownAnalyseVideo;
		private: float currentSpeed;
		public: UndoRedo::LoadAnalysisVideo* memento;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: AnalysisTabMemento();

		/// <summary>
		/// Returns the current position the player is at.
		/// </summary>
		/// <returns>The current position of the player.</returns>
		public: int getCurrentVideoPosition();

		/// <summary>
		/// Sets the current position of the player.
		/// </summary>
		/// <param name="currentVideoPosition">The current position of the player.</param>
		public: void setCurrentVideoPosition(int currentVideoPosition);

		/// <summary>
		/// Returns what analysis video is currently shown.
		/// 0 means rgb difference.
		/// non zero means macroblocks.
		/// </summary>
		/// <returns>The currently shown analysis video.</returns>
		public: int getCurrentlyShownAnalysisVideo();

		/// <summary>
		/// Sets the currently shown analysis video.
		/// 0 means rgb difference.
		/// non 0 means macroblocks.
		/// </summary>
		/// <param name="currentlyShownAnalysisVideo">The currrently shown analysis video.</param>
		public: void setCurrentlyShownAnalysisVideo(int currentlyShownAnalysisVideo);

		/// <summary>
		/// Returns the current speed of the player.
		/// </summary>
		/// <returns>The current speed of the player.</returns>
		public: float getCurrentSpeed();

		/// <summary>
		/// Sets the current speed of the player.
		/// </summary>
		/// <param name="currentSpeed">The current speed of the player.</param>
		public: void setCurrentSpeed(float currentSpeed);

		/// <summary>
		/// Returns the memento of the AnalysisBoxContainer.
		/// </summary>
		/// <returns>The memento of the AnalysisBoxContainer.</returns>
		public: Memento::AnalysisBoxContainerMemento getAnalysisBoxContainerMemento();

		/// <summary>
		/// Sets the memento of the AnalysisBoxContainer.
		/// </summary>
		/// <param name="analysisBoxContainerMemento">The memento of the AnalysisBoxContainer.</param>
		public: void setAnalysisBoxContainerMemento(Memento::AnalysisBoxContainerMemento analysisBoxContainerMemento);
	};
}

#endif
*/
