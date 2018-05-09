#include "Warehouse.h"

Warehouse::Warehouse() : id(idCounter++) {

}

size_t Warehouse::addFloor() {
	this->floors.push_back(Floor(floorIdCounter++));
}

void Warehouse::addGoodsCollection(uint32_t floorNr, GoodsCollection goodsCollection) {
	this->floors[floorNr].addGoodsCollection(goodsCollection);
}

void Warehouse::setIdCounter(uint32_t value) {
	Warehouse::idCounter = value;
}




Floor::Floor(uint32_t id) : id(id) {

}

void Floor::addGoodsCollection(GoodsCollection goodsCollection) { 
	this->goodsCollections.push_back(goodsCollection);
}




GoodsCollection::GoodsCollection(uint32_t id) : id(id) {

}

void GoodsCollection::addGood(Good good) {
	this->goods.push_back(good);
}




Good::Good(GoodInformation goodInfo, uint32_t quantity) : goodInfo(goodInfo), quantity(quantity) {

}

void Good::setQuantity(uint32_t newQuantity) {
	this->quantity = newQuantity;
}




GoodInformation::GoodInformation(string name) : name(name) {
	this->weight = 0;
}

GoodInformation::GoodInformation(string name, float weight) : name(name), weight(weight) {

}

void GoodInformation::setWeight(float newWeight) {
	this->weight = newWeight;
}
