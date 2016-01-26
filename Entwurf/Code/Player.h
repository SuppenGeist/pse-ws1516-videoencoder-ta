
#include <exception>
using namespace std;

#ifndef __Player_h__
#define __Player_h__

// #include "ControlPanel.h"

namespace GUI
{
	class ControlPanel;
	class Player;
}

namespace GUI
{
	/**
	 * This class is the base class for players.
	 */
	__abstract class Player
	{
		public: GUI::ControlPanel* players;
		public: GUI::ControlPanel* masterPlayer;

		/// <summary>
		/// Plays the video.
		/// </summary>
		public: virtual void play() = 0;

		/// <summary>
		/// Pauses the video.
		/// </summary>
		public: virtual void pause() = 0;

		/// <summary>
		/// Stops the video.
		/// </summary>
		public: virtual void stop() = 0;

		/// <summary>
		/// Shows the next frame.
		/// </summary>
		public: virtual void nextFrame() = 0;

		/// <summary>
		/// Shows the previous frame.
		/// </summary>
		public: virtual void previousFrame() = 0;

		/// <summary>
		/// Sets the speed.
		/// </summary>
		/// <param name="speed">The new speed.</param>
		public: virtual void setSpeed(float speed) = 0;

		/// <summary>
		/// Sets the position in the video.
		/// </summary>
		/// <param name="position">The new position.</param>
		public: virtual void setPosition(int position) = 0;

		/// <summary>
		/// Returns the position in the video.
		/// </summary>
		/// <returns>The current position.</returns>
		public: virtual int getPosition() = 0;

		/// <summary>
		/// Returns the speed.
		/// </summary>
		/// <returns>The current speed.</returns>
		public: virtual float getSpeed() = 0;

		/// <summary>
		/// Whether the player is currently playing.
		/// </summary>
		/// <returns>True if the player is playing.</returns>
		public: virtual bool isPlaying() = 0;

		/// <summary>
		/// Whether the player is stopped.
		/// </summary>
		/// <returns>True if the player is stopped.</returns>
		public: virtual bool isStopped() = 0;

		/// <summary>
		/// Resets the player.
		/// </summary>
		public: virtual void reset() = 0;
	};
}

#endif
