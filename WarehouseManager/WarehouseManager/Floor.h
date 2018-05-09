#pragma once
#include <cstdint>
#include <vector>
#include "GoodsCollection.h"

using namespace std;

class Floor {
private:
	const uint32_t id;
	uint32_t goodsCollectionIdCounter = 0;
	vector<GoodsCollection> goodsCollections;
public:
	Floor(uint32_t id);
	void addGoodsCollection();

};
