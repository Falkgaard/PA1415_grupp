#pragma once
#include <cstdint>
#include <vector>
#include "Floor.h"

using namespace std;

class Warehouse {
private:
	static uint32_t idCounter;
	const uint32_t id;
	vector<Floor> floors;
public:
	explicit Warehouse();
	
	uint32_t addFloor(uint32_t width, uint32_t height);
	/*Requires the position to have no shelf*/
	bool addShelf(uint32_t floorIndex, uint32_t xPos, uint32_t yPos);
	/*Requires a shelf at the position*/
	bool addGoodsCollection(uint32_t floorIndex, uint32_t xPos, uint32_t yPos);
	static void setIdCounter(uint32_t value);
	const Floor* getFloor(uint32_t floorIndex) const;
	uint32_t getId() const;
};
