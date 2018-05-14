#pragma once
#include <cstdint>
#include <vector>
#include "GoodInformation.h"

using namespace std;

class Good {
private:
	GoodInformation goodInfo;
	uint32_t quantity;
public:
	Good(GoodInformation goodInfo, uint32_t quantity);
	void setQuantity(uint32_t newQuantity);
	string getName() const;
	float getWeight() const;
	uint32_t getQuantity() const;
};
