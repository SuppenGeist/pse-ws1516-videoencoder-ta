
#include <exception>
using namespace std;

#ifndef __GlobalControlPanel_h__
#define __GlobalControlPanel_h__

// #include "AnalysisTab.h"
#include "ControlPanel.h"

namespace GUI
{
	class AnalysisTab;
	// class ControlPanel;
	class GlobalControlPanel;
}

namespace GUI
{
	/**
	 * This control panel has no gui. Instead it has functions to control the video.
	 */
	class GlobalControlPanel: public GUI::ControlPanel
	{
		public: GUI::AnalysisTab* globalControlPanel;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: GlobalControlPanel();

		/// <summary>
		/// Updates the ui of the control panel.
		/// </summary>
		public: void updateUi();

		/// <summary>
		/// Sends a play signal to the players.
		/// </summary>
		public: void play();

		/// <summary>
		/// Sends a pause signal to the players.
		/// </summary>
		public: void pause();

		/// <summary>
		/// Sends a stop signal to the players.
		/// </summary>
		public: void stop();

		/// <summary>
		/// Sends a nextFrame signal to the players.
		/// </summary>
		public: void nextFrame();

		/// <summary>
		/// Sends a previousFrame signal to the players.
		/// </summary>
		public: void previousFrame();

		/// <summary>
		/// Sends a setPosition signal to the players.
		/// </summary>
		/// <param name="position">The position to show.</param>
		public: void setPosition(int position);
	};
}

#endif
