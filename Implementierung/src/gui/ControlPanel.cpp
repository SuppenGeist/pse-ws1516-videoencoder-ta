#include "ControlPanel.h"

#include <vector>
#include <algorithm>

#include "Player.h"

GUI::ControlPanel::ControlPanel() noexcept:
masterPlayer_(nullptr) {

}

void GUI::ControlPanel::setMasterVideoPlayer(GUI::Player& player) noexcept {
	masterPlayer_=&player;
	updateUi();
}

void GUI::ControlPanel::addVideoPlayer(GUI::Player* player) {
	players_.push_back(player);
    if(masterPlayer_) {
        player->setPosition(masterPlayer_->getPosition());
    }
}


void GUI::ControlPanel::removeVideoPlayer(GUI::Player& player) {
	std::size_t pos = std::find(players_.begin(), players_.end(), &player) - players_.begin();
	if(pos<players_.size()) {
		players_.erase(players_.begin()+pos);
	}
}

