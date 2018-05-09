#include "Good.h"

Good::Good(GoodInformation goodInfo, uint32_t quantity) : goodInfo(goodInfo), quantity(quantity) {

}

void Good::setQuantity(uint32_t newQuantity) {
	this->quantity = newQuantity;
}
