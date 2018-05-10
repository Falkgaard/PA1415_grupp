#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>
#include <iostream>
#include "Warehouse.h"
#include "WarehouseView.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Warehouse Manager");
	
	Warehouse warehouse;
	WarehouseView warehouseView;
	uint32_t currentFloor = warehouse.addFloor(20, 20);
	
	warehouse.addShelf(currentFloor, 1, 1);
	warehouse.addShelf(currentFloor, 1, 2);
	warehouse.addShelf(currentFloor, 1, 3);
	warehouse.addShelf(currentFloor, 1, 4);
	
	warehouse.addGoodsCollection(currentFloor, 1, 1);
	warehouse.addGoodsCollection(currentFloor, 1, 2);
	warehouse.addGoodsCollection(currentFloor, 1, 4);
	
	warehouseView.setWarehouse(&warehouse);
	warehouseView.setCurrentlyDisplayedFloor(0);

	sf::Event event;
	try {
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
