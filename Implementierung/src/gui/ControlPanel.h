#ifndef __ControlPanel_h__
#define __ControlPanel_h__

#include <vector>

namespace GUI {
class Player;
}

namespace GUI {
/**
 * This class is the base class for control panels.
 * Control panels control videoplayers,
 */
class ControlPanel {

  public:
	/**
	 * @brief ControlPanel Constructor.
	 */
	ControlPanel() noexcept;

	/**
	 * @brief ~ControlPanel Destructor.
	 */
	virtual ~ControlPanel() {}

	/**
	 * This player must not be added with addVideoPlayer() again.
	 *
	 * @brief setMasterVideoPlayer Sets the master video player.
	 * @param player The master video player.
	 */
	void setMasterVideoPlayer(Player& player) noexcept;

	/**
	     * If the player is already in the list, nothing happens.
	 *
	     * @brief addVideoPlayer Adds the video player to the list of players to notify.
	 * @param player The player to add to the list.
	 */
	void addVideoPlayer(Player *player);

	/**
	 * @brief updateUi Updates the ui of the control panel.
	 */
	virtual void updateUi() = 0;

	/**
	     * If the player is not in the list nothing happens.
	 *
	 * @brief removeVideoPlayer Removes the video player from the list of the players to notify.
	 * @param player The player to remove.
	 */
	void removeVideoPlayer(Player& player);

  protected:
	std::vector<Player*>  players_;
	Player*               masterPlayer_;
};
}

#endif

