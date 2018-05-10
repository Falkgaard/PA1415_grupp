#pragma once
#include <cstdint>
#include <vector>
#include "GoodsCollection.h"

using namespace std;



class Floor {
public:
	enum Tile {
		NoShelf,
		EmptyShelf,
		OccupiedShelf
	};
private:
	uint32_t width;
	uint32_t height;
	const uint32_t id;
	uint32_t goodsCollectionIdCounter = 0;
	vector<vector<Tile>> tileMap;
	vector<GoodsCollection> goodsCollections;
public:
	Floor(uint32_t id, uint32_t width, uint32_t height);
	bool addGoodsCollection(uint32_t xPos, uint32_t yPos);
	bool addShelf(uint32_t xPos, uint32_t yPos);
	bool removeShelf(uint32_t xPos, uint32_t yPos);
};
