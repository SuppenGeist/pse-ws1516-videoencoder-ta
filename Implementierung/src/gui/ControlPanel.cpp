#include <exception>
#include <vector>

#include "ControlPanel.h"
#include "ForwardPlayer.h"
#include "VideoPlayer.h"
#include "Player.h"
#include <QApplication>

GUI::ControlPanel::ControlPanel() {
}

void GUI::ControlPanel::setMasterVideoPlayer(GUI::Player& player) {
    Q_UNUSED(player);
	throw "Not yet implemented";
}

void GUI::ControlPanel::addVideoPlayer(GUI::Player& player) {
    Q_UNUSED(player);
	throw "Not yet implemented";
}


void GUI::ControlPanel::removeVideoPlayer(GUI::Player& player) {
    Q_UNUSED(player);
	throw "Not yet implemented";
}

