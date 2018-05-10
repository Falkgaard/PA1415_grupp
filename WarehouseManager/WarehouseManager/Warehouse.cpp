#include "Warehouse.h"

uint32_t Warehouse::idCounter = 0;

Warehouse::Warehouse() : id(idCounter++) {

}

uint32_t Warehouse::addFloor(uint32_t width, uint32_t height) {
	this->floors.push_back(Floor(floors.size(), width, height));
	return floors.size() - 1;
}

bool Warehouse::addShelf(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) {
	return floors[floorIndex].addShelf(xPos, yPos);
}

bool Warehouse::addGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos) {
	return this->floors[floorIndex].addGoodsCollection(xPos, yPos);
}

void Warehouse::setIdCounter(uint32_t value) {
	Warehouse::idCounter = value;
}

uint32_t Warehouse::getId() const {
	return this->id;
}

const Floor* Warehouse::getFloor(uint32_t floorIndex) const {
	return &floors[floorIndex];
}
