#include "GoodInformation.h"

GoodInformation::GoodInformation(string name) : name(name) {
	this->weight = 0;
}

GoodInformation::GoodInformation(string name, float weight) : name(name), weight(weight) {

}

void GoodInformation::setWeight(float newWeight) {
	this->weight = newWeight;
}

string GoodInformation::getName() const {
	return name;
}

float GoodInformation::getWeight() const {
	return weight;
}
