
#include <exception>
#include <vector>
using namespace std;

#ifndef __ControlPanel_h__
#define __ControlPanel_h__

// #include "ForwardPlayer.h"
#include "VideoPlayer.h"
#include "Player.h"

namespace GUI
{
	class ForwardPlayer;
	class VideoPlayer;
	class Player;
	class ControlPanel;
}

namespace GUI
{
	/**
	 * This class is the base class for control panels.
	 * Control panels control videoplayers,
	 */
	__abstract class ControlPanel
	{
		public: GUI::ForwardPlayer* forwardPanel;
		public: GUI::VideoPlayer* masterPanel;
		protected: std::vector<GUI::VideoPlayer*> players;
		private: GUI::Player* masterPlayer;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: ControlPanel();

		/// <summary>
		/// Sets the master video player.
		/// The master video player is the reference to where to set the position of the slider, if the video is played paused or stopped.
		/// </summary>
		/// <param name="player">The master video player.</param>
		public: void setMasterVideoPlayer(Player::Player& player);

		/// <summary>
		/// Adds the video player the list of players to notify.
		/// </summary>
		/// <param name="player">The player to add to the list.</param>
		public: void addVideoPlayer(GUI::Player& player);

		/// <summary>
		/// Updates the ui of the control panel.
		/// </summary>
		public: virtual void updateUi() = 0;

		/// <summary>
		/// Removes the video player from the list of the players to notify.
		/// </summary>
		/// <param name="player">The player to remove.</param>
		public: void removeVideoPlayer(Player::Player& player);
	};
}

#endif
