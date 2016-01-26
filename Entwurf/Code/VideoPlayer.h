
#include <exception>
#include <vector>
using namespace std;

#ifndef __VideoPlayer_h__
#define __VideoPlayer_h__

#include "ControlPanel.h"
#include "Video.h"
#include "FrameView.h"
#include "Timer.h"
#include "Player.h"

namespace GUI
{
	class ControlPanel;
	class Video;
	class FrameView;
	class Timer;
	// class Player;
	class VideoPlayer;
}

namespace GUI
{
	/**
	 * This class is a video player.
	 * It provides a basic interface for handling playback of videos.
	 */
	class VideoPlayer: public GUI::Player
	{
		private: int position;
		private: GUI::ControlPanel* players;
		private: GUI::Video* video;
		public: std::vector<GUI::FrameView*> views;
		private: GUI::Timer* timer;
		private: GUI::ControlPanel* masterPanel;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: VideoPlayer();

		/// <summary>
		/// Adds a view.
		/// Multiple views can be added.
		/// </summary>
		/// <param name="view">The view to add.</param>
		public: void addView(GUI::FrameView& view);

		/// <summary>
		/// Removes a view.
		/// </summary>
		/// <param name="view">The view to remove.</param>
		public: void removeView(GUI::FrameView& view);

		/// <summary>
		/// Sets the video.
		/// If a video was previously set the old video gets deleted,
		/// </summary>
		/// <param name="video">The video to play.</param>
		public: void setVideo(GUI::Video& video);

		/// <summary>
		/// Returns a pointer to the currently played video.
		/// If no video is set nullptr is returned.
		/// </summary>
		/// <returns>Pointer to the current video.</returns>
		public: GUI::Video* getVideo();

		/// <summary>
		/// Sets the timer for the player.
		/// This method has to be called in order to be able to play the video.
		/// </summary>
		/// <param name="timer">The timer for the player.</param>
		public: void setTimer(shared_ptr<GUI::Timer> timer);

		/// <summary>
		/// Clears the timer.
		/// </summary>
		public: void clearTimer();

		/// <summary>
		/// Returns the fps the player is currently playing at.
		/// </summary>
		/// <returns>The current fps of the player.</returns>
		public: int getFps();

		/// <summary>
		/// Sets the MasterControlPanel. This panel is the reference for video position and speed.
		/// </summary>
		public: void setMasterControlPanel(GUI::ControlPanel& controlPanel);

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
