#include "GoodsCollection.h"

GoodsCollection::GoodsCollection(uint32_t id) : id(id) {

}

void GoodsCollection::addGood(Good good) {
	this->goods.push_back(good);
}
