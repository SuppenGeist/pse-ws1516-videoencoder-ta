
#include <exception>
using namespace std;

#ifndef __ForwardPlayer_h__
#define __ForwardPlayer_h__

#include "ControlPanel.h"
#include "Player.h"

namespace GUI
{
	class ControlPanel;
	// class Player;
	class ForwardPlayer;
}

namespace GUI
{
	/**
	 * This player forwards its input to a ControlPanel.
	 */
	class ForwardPlayer: public GUI::Player
	{
		private: GUI::ControlPanel* controlPanel;
		private: GUI::ControlPanel* forwardPanel;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: ForwardPlayer();

		/// <summary>
		/// Sets the control panel that the player forwards its input to.
		/// </summary>
		/// <param name="panel">The player to forward to.</param>
		public: void setForwardControlPanel(GUI::ControlPanel panel);

		/// <summary>
		/// Plays the video.
		/// </summary>
		public: void play();

		/// <summary>
		/// Pauses the video.
		/// </summary>
		public: void pause();

		/// <summary>
		/// Stops the video.
		/// </summary>
		public: void stop();

		/// <summary>
		/// Shows the next frame.
		/// </summary>
		public: void nextFrame();

		/// <summary>
		/// Shows the previous frame.
		/// </summary>
		public: void previousFrame();

		/// <summary>
		/// Sets the speed.
		/// </summary>
		/// <param name="speed">The new speed.</param>
		public: void setSpeed(float speed);

		/// <summary>
		/// Sets the position in the video.
		/// </summary>
		/// <param name="position">The new position.</param>
		public: void setPosition(int position);

		/// <summary>
		/// Returns the position in the video.
		/// </summary>
		/// <returns>The current position.</returns>
		public: int getPosition();

		/// <summary>
		/// Returns the speed.
		/// </summary>
		/// <returns>The current speed.</returns>
		public: float getSpeed();

		/// <summary>
		/// Whether the player is currently playing.
		/// </summary>
		/// <returns>True if the player is playing.</returns>
		public: bool isPlaying();

		/// <summary>
		/// Whether the player is stopped.
		/// </summary>
		/// <returns>True if the player is stopped.</returns>
		public: bool isStopped();

		/// <summary>
		/// Resets the player.
		/// </summary>
		public: void reset();
	};
}

#endif
