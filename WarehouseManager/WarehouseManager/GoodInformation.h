#pragma once
#include <cstdint>
#include <vector>
#include <string>

using namespace std;

class GoodInformation {
private:
	string name;
	float weight;
public:
	GoodInformation(string name);
	GoodInformation(string name, float weight);
	void setWeight(float newWeight);
};
