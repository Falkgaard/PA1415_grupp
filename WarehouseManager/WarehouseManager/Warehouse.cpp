#include "Warehouse.h"

uint32_t Warehouse::idCounter = 0;

Warehouse::Warehouse() : id(idCounter++) {

}

void Warehouse::addFloor(uint32_t width, uint32_t height) {
	this->floors.push_back(Floor(floorIdCounter++, width, height));
}

void Warehouse::addGoodsCollection(uint32_t floorNr, uint32_t xPos, uint32_t yPos) {
	this->floors[floorNr].addGoodsCollection(xPos, yPos);
}

void Warehouse::setIdCounter(uint32_t value) {
	Warehouse::idCounter = value;
}

uint32_t Warehouse::getId() const {
	return this->id;
}
