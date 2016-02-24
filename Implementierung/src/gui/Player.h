#ifndef __Player_h__
#define __Player_h__

#include <cstddef>

namespace GUI {
/**
 * This class is the base class for players.
 * It specifies the basic interface that a player has to provide.
 */
class Player {
  public:
	/**
	 * @brief ~Player Destructor.
	 */
	virtual ~Player() {}

	/**
	 * @brief play Plays the video.
	 */
	virtual void play() = 0;

	/**
	 * @brief pause Pauses the video.
	 */
	virtual void pause() = 0;

	/**
	 * @brief stop Stops the video.
	 */
	virtual void stop() = 0;

	/**
	 * @brief nextFrame Shows the next frame.
	 */
	virtual void nextFrame() = 0;

	/**
	 * @brief previousFrame Shows the previous frame.
	 */
	virtual void previousFrame() = 0;

	/**
	 * @brief setSpeed Sets the speed.
	 * @param speed The new speed.
	 */
	virtual void setSpeed(float speed) = 0;

	/**
	 * @brief setPosition Sets the position in the video.
	 * @param position The new position.
	 */
	virtual void setPosition(std::size_t position) = 0;

	/**
	 * @brief getPosition Returns the position in the video.
	 * @return The current position.
	 */
	virtual std::size_t getPosition() const = 0;

	/**
	 * @brief getSpeed Returns the speed.
	 * @return The current speed.
	 */
	virtual float getSpeed() const = 0;

	/**
	 * @brief isPlaying Whether the player is currently playing.
	 * @return True if the player is playing.
	 */
	virtual bool isPlaying() const = 0;

	/**
	 * @brief isStopped Whether the player is stopped.
	 * @return True if the player is stopped.
	 */
	virtual bool isStopped() const = 0;

	/**
	 * @brief reset Resets the player.
	 */
	virtual void reset() = 0;

	/**
	 * @brief getNumberOfFrames Returns the maximum number of frames.
	 * @return The number of frames.
	 */
    virtual std::size_t getNumberOfFrames() const = 0;
};
}

#endif

