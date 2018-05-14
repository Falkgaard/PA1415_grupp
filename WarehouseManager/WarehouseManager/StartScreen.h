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
public:
	StartScreen();
	void handleEvent(sf::Event& e);
	void connectConnectButton(function<void()> delegate);
	void connectHostButton(function<void()> delegate);
	void update(float seconds);
};
