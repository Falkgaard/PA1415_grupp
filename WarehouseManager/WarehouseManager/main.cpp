#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <iostream>
#include "Warehouse.h"
#include "WarehouseView.h"
#include "StartScreen.h"

void setupMockWarehouse(Warehouse& warehouse);

int main() {
	sf::RenderWindow scrolledWindow(sf::VideoMode(800, 800), "Warehouse Manager");
	scrolledWindow.resetGLStates();
	sfg::SFGUI sfgui;
	StartScreen startScreen;
	Warehouse warehouse;
	setupMockWarehouse(warehouse);
	WarehouseView warehouseView;

	warehouseView.setWarehouse(&warehouse);
	warehouseView.setCurrentlyDisplayedFloor(0);
	startScreen.connectConnectButton([&warehouseView] {warehouseView.setVisible(true); });
	sf::Event event;

	try {
		while (scrolledWindow.isOpen()) {
			while (scrolledWindow.pollEvent(event)) {
				startScreen.handleEvent(event);
				warehouseView.handleEvent(event);

				if (event.type == sf::Event::Closed) {
					scrolledWindow.close();
				}
				if (event.type == sf::Event::MouseButtonReleased) {
					if (event.mouseButton.button == sf::Mouse::Left) {
						cout << event.mouseButton.x << ", " << event.mouseButton.y << endl;
					}
				}
			}
			
			startScreen.update(0.05);
			warehouseView.update(0.05);

			scrolledWindow.clear();
			scrolledWindow.draw(warehouseView);
			sfgui.Display(scrolledWindow);
			scrolledWindow.display();
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
	warehouse.addGood(currentFloor, 1, 1, Good(GoodInformation("TestGood", 0.999), 11));
	warehouse.addGoodsCollection(currentFloor, 1, 2);
	warehouse.addGoodsCollection(currentFloor, 1, 4);
}