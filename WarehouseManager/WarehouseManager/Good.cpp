#include "Good.h"

Good::Good(GoodInformation goodInfo, uint32_t quantity) : goodInfo(goodInfo), quantity(quantity) {

}

void Good::setQuantity(uint32_t newQuantity) {
	this->quantity = newQuantity;
}

string Good::getName() const {
	return goodInfo.getName();
}

float Good::getWeight() const {
	return goodInfo.getWeight();
}

uint32_t Good::getQuantity() const {
	return quantity;
}
