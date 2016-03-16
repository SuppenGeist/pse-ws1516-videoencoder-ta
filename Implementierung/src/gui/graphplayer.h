#ifndef GRAPHPLAYER_H
#define GRAPHPLAYER_H

#include <memory>

#include "Player.h"
#include "graphplayer.h"
#include "GraphWidget.h"
#include "Timer.h"

#include "../model/graphvideo.h"

namespace GUI {

class GraphPlayer:public Player {
  public:
	GraphPlayer();

	/**
	 * @brief play Plays the video.
	 */
	void play();

	/**
	 * @brief pause Pauses the video.
	 */
	void pause();

	/**
	 * @brief stop Stops the video.
	 */
	void stop();

	/**
	 * @brief nextFrame Shows the next frame.
	 */
	void nextFrame();

	/**
	 * @brief previousFrame Shows the previous frame.
	 */
	void previousFrame();

	/**
	 * @brief setSpeed Sets the speed.
	 * @param speed The new speed.
	 */
	void setSpeed(float speed);

	/**
	 * @brief setPosition Sets the position in the video.
	 * @param position The new position.
	 */
	void setPosition(std::size_t position);

	/**
	 * @brief getPosition Returns the position in the video.
	 * @return The current position.
	 */
	std::size_t getPosition() const;

	/**
	 * @brief getSpeed Returns the speed.
	 * @return The current speed.
	 */
	float getSpeed() const;

	/**
	 * @brief isPlaying Whether the player is currently playing.
	 * @return True if the player is playing.
	 */
	bool isPlaying() const;

	/**
	 * @brief isStopped Whether the player is stopped.
	 * @return True if the player is stopped.
	 */
	bool isStopped() const;

	/**
	 * @brief reset Resets the player.
	 */
	void reset();

	/**
	 * @brief getNumberOfFrames Returns the maximum number of frames.
	 * @return The number of frames.
	 */
	std::size_t getNumberOfFrames() const;

	void setGraphVideo(Model::GraphVideo* video);

	void setView(GraphWidget* view);

	void setTimer(std::shared_ptr<Timer> timer);

	void clearTimer();

  private:
	std::size_t             position_;
	Model::GraphVideo*      video_;
	GraphWidget*            view_;
	std::shared_ptr<Timer>  timer_;

	void updateView();
};

}

#endif // GRAPHPLAYER_H
