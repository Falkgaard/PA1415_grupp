#include "Warehouse.h"

uint32_t Warehouse::idCounter = 0;

Warehouse::Warehouse() : id(idCounter++) {

}

void Warehouse::addFloor() {
	this->floors.push_back(Floor(floorIdCounter++));
}

void Warehouse::addGoodsCollection(uint32_t floorNr) {
	this->floors[floorNr].addGoodsCollection();
}

void Warehouse::setIdCounter(uint32_t value) {
	Warehouse::idCounter = value;
}

uint32_t Warehouse::getId() const {
	return this->id;
}
