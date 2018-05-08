#pragma once
#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\widgets.hpp>
#include "Warehouse.h"

using namespace std;

class GUI {
private:
	sf::RenderWindow* window;
	sfg::SFGUI sfgui;

	shared_ptr<sfg::Window> goodCollectionWindow;
public:
	GUI(sf::RenderWindow* window) {
		this->window = window;
		window->resetGLStates();
		sfg::SFGUI sfgui;

		goodCollectionWindow = sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
	};
};