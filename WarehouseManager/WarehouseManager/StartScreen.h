#pragma once
#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\widgets.hpp>
#include "Warehouse.h"

using namespace std;

class StartScreen {
private:
	shared_ptr<sfg::Box> box;
	shared_ptr<sfg::Entry> ipEntry;
	shared_ptr<sfg::Button> connectButton;
	shared_ptr<sfg::Button> hostButton;
	bool active = true;
public:
	StartScreen();
	void handleEvent(sf::Event& e);
	void update(float seconds);
	bool isActive() const;
};
