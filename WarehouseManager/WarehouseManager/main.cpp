#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Warehouse Manager");
	
	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		

		window.display();
	}

	return 0;
}
