#pragma once
#include <cstdint>
#include <vector>
#include "Floor.h"

using namespace std;

class Warehouse {
private:
	static uint32_t idCounter;
	const uint32_t id;
	uint32_t floorIdCounter = 0;
	vector<Floor> floors;
public:
	explicit Warehouse();
	
	void addFloor(uint32_t width, uint32_t height);
	void addGoodsCollection(uint32_t floorNr);
	static void setIdCounter(uint32_t value);
	uint32_t getId() const;
};
