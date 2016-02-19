#ifndef __Timer_h__
#define __Timer_h__

#include <vector>

#include <QTimer>
#include <QObject>

namespace GUI {
class Player;
}

namespace GUI {
/**
 * This class is the timer for the video player.
 * It handles the switching of the frames according to fps and speed.
 */
class Timer : QObject {
	Q_OBJECT
  public:
	/**
	 * @brief Timer Constructor.
	 * @param fps The fps to play at.
	 */
	Timer(QObject *parent=0);

	virtual ~Timer() {}

	/**
	 * If fps is < 1 nothing happens.
	 * @brief setFps Sets the fps for the timer.
	 * @param fps The new fps.
	 */
	void setFps(int fps) noexcept;

	/**
	 * If the speed <= 0 nothing happens.
	 *
	 * @brief setSpeed Sets the speed to play at.
	 * @param speed The new speed.
	 */
	void setSpeed(float speed) noexcept;

	/**
	 * @brief getSpeed Returns the current speed the timer plays at.
	 * @return The current speed.
	 */
	float getSpeed() const noexcept;

	/**
	 * @brief getFps Returns the current fps the timer plays at.
	 * @return The current fps.
	 */
	int getFps() const noexcept;

	/**
	 * @brief pause Stops the timer from switching frames.
	 */
	void pause();

	/**
	 * @brief start Tells the timer to start switching frames.
	 */
	void start();

	/**
	 * If the player is already in the list nothing happens.
	 *
	 * @brief addPlayer Adds a player.
	 * @param player The player to add.
	 */
	void addPlayer(Player& player);

	/**
	 * @brief isPlaying Whether the timer currently switches frames.
	 * @return true if the timer currently switches frames.
	 */
	bool isPlaying();

	/**
	 * If the player is not in the list nothing happens.
	 *
	 * @brief removePlayer Removes a player from the list.
	 * @param player The player to remove.
	 */
	void removePlayer(Player& player);

  private slots:
	/**
	 * @brief update This method switched the frames in all players.
	 */
	void update();

  private:
	QTimer                      timer_;
	float                       speed_;
	int                         fps_;
	std::vector<Player*>   players_;


};
}

#endif
