#include "Floor.h"

Floor::Floor(uint32_t id) : id(id) {

}

void Floor::addGoodsCollection() {
	this->goodsCollections.push_back(GoodsCollection(goodsCollectionIdCounter++));
}
