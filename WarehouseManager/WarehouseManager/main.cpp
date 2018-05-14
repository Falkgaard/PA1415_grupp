#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <iostream>
#include "Warehouse.h"
#include "WarehouseView.h"
#include "StartScreen.h"

void setupMockWarehouse(Warehouse& warehouse);

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Warehouse Manager");
	window.resetGLStates();
	sfg::SFGUI sfgui;
	StartScreen startScreen;
	
	Warehouse warehouse;
	setupMockWarehouse(warehouse);
	WarehouseView warehouseView;

	warehouseView.setWarehouse(&warehouse);
	warehouseView.setCurrentlyDisplayedFloor(0);

	sf::Event event;

	try {
		while (startScreen.isActive()) {
			while (window.pollEvent(event)) {
				startScreen.handleEvent(event);
				
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.clear();
			startScreen.update(0.05);
			sfgui.Display(window);
			window.display();
		}

		while (window.isOpen()) {
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.clear();
			window.draw(warehouseView);
			window.display();
		}
	}
	catch (const char* e) {
		cout << "Exception: " << e << endl;
		system("pause");
	}

	return 0;
}

void setupMockWarehouse(Warehouse& warehouse) {
	uint32_t currentFloor = warehouse.addFloor(20, 20);

	warehouse.addShelf(currentFloor, 1, 1);
	warehouse.addShelf(currentFloor, 1, 2);
	warehouse.addShelf(currentFloor, 1, 3);
	warehouse.addShelf(currentFloor, 1, 4);

	warehouse.addGoodsCollection(currentFloor, 1, 1);
	warehouse.addGoodsCollection(currentFloor, 1, 2);
	warehouse.addGoodsCollection(currentFloor, 1, 4);
}