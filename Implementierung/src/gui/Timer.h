#ifndef __Timer_h__
#define __Timer_h__

#include "VideoPlayer.h"

#include <QTimer>

namespace GUI
{
	class VideoPlayer;
	class Timer;
}

namespace GUI
{
	/**
	 * This class is the timer for the video player.
	 * It handles the switching of the frames according to fps and speed.
     */
	class Timer
	{
		private: QTimer timer;
		private: float speed;
		private: int fps;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="fps">The fps to play at.</param>
		public: Timer(int fps);

		/// <summary>
		/// Sets the fps for the timer.
		/// </summary>
		/// <param name="fps">The new fps.</param>
		public: void setFps(int fps);

		/// <summary>
		/// Sets the speed to play at.
		/// The default value is 1.0.
		/// </summary>
		/// <param name="speed">The new speed.</param>
		public: void setSpeed(float speed);

		/// <summary>
		/// Returns the current speed the timer plays at.
		/// </summary>
		/// <returns>The current speed.</returns>
		public: float getSpeed();

		/// <summary>
		/// Returns the current fps the timer plays at.
		/// </summary>
		/// <returns>The current fps.</returns>
		public: int getFps();

		/// <summary>
		/// Stops the timer from switching frames.
		/// </summary>
		public: void pause();

		/// <summary>
		/// Tells the timer to start switching frames.
		/// </summary>
		public: void start();

		/// <summary>
		/// Adds a player.
		/// </summary>
		/// <param name="player">The player to add.</param>
		public: void addPlayer(GUI::VideoPlayer& player);

		/// <summary>
		/// Whether the timer currently switches frames.
		/// </summary>
		/// <returns>true if the timer currently switches frames.</returns>
		public: bool isPlaying();

		/// <summary>
		/// This method switched the frames in all players.
		/// </summary>
		private: void update();

		/// <summary>
		/// Removes a player from the list.
		/// </summary>
		/// <param name="player">The player to remove.</param>
		public: void removePlayer(GUI::VideoPlayer& player);
	};
}

#endif
