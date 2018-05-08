#pragma once
#include <cstdint>
#include <vector>
#include <string>

using namespace std;

class GoodInformation {
private:
	string name;
	float weight;
public:
	GoodInformation(string name) : name(name) {};
	GoodInformation(string name, float weight) : name(name), weight(weight) {};
	void setWeight(float newWeight) { this->weight = newWeight; };
};

class Good {
private:
	GoodInformation info;
	uint32_t quantity;
public:
	Good(GoodInformation goodInfo, uint32_t quantity) : info(goodInfo), quantity(quantity) {};
	void setQuantity(uint32_t newQuantity) { this->quantity = newQuantity; };
};

class GoodsCollection {
private:
	uint32_t id;
	vector<Good> goods;
public:
	GoodsCollection(uint32_t id) : id(id) {};
	void addGood(Good good) { goods.push_back(good); };
};

class Floor {
private:
	uint32_t id;
	vector<GoodsCollection> goodsCollections;
public:
	Floor(uint32_t id) : id(id) {};
	void addGoodsCollection(GoodsCollection goodsCollection) {  };
};

class Warehouse {
private:
	static uint32_t idCounter;
	const uint32_t id;

	vector<Floor> floors;
public:
	Warehouse() : id(idCounter++) {};
	
	size_t addFloor() { 
		Floor floor(floors.size());
		floors.push_back(floor);
	};

	void addGoodsCollection(uint32_t floorNr, GoodsCollection goodsCollection) { floors[floorNr].addGoodsCollection(goodsCollection); };
};
