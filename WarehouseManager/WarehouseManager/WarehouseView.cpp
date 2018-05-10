#include "WarehouseView.h"

WarehouseView::WarehouseView() {
	currentWarehouse = nullptr;
	sf::Image img;
	img.create(32, 32, sf::Color::White);
	whiteTexture.loadFromImage(img);
	whiteSquare.setTexture(whiteTexture);
}

WarehouseView::WarehouseView(const Warehouse* warehousePtr) : currentWarehouse(warehousePtr) {
	sf::Image img;
	img.create(32, 32, sf::Color::White);
	whiteTexture.loadFromImage(img);
	whiteSquare.setTexture(whiteTexture);
}

void WarehouseView::setWarehouse(const Warehouse* warehousePtr) {
	this->currentWarehouse = warehousePtr;
}

void WarehouseView::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}
