#include "Floor.h"

Floor::Floor(uint32_t id, uint32_t width, uint32_t height) : id(id), width(width), height(height) {
	this->tileMap.resize(width);
	for (vector<Tile>& col : this->tileMap) {
		col.resize(height);
	}
}

bool Floor::addGoodsCollection(uint32_t xPos, uint32_t yPos) {
	this->goodsCollections.push_back(GoodsCollection(goodsCollectionIdCounter++));
}

bool Floor::addShelf(uint32_t xPos, uint32_t yPos) {
	if (this->tileMap[xPos][yPos] == NoShelf) {
		tileMap[xPos][yPos] = Tile::EmptyShelf;
	}

	return tileMap[xPos][yPos] == Tile::EmptyShelf;;
}

bool Floor::removeShelf(uint32_t xPos, uint32_t yPos) {
	if (this->tileMap[xPos][yPos] == EmptyShelf) {
		tileMap[xPos][yPos] = Tile::NoShelf;
	}

	return tileMap[xPos][yPos] == Tile::NoShelf;
}
