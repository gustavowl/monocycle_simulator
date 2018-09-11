#include "person.h"

Person::Person() {
	this->tiptoe[0] = 0.0;
	this->tiptoe[1] = -2.0;
	this->tiptoe[2] = -1.0;
	this->ankle[0] = -2.0;
	this->ankle[1] = -2.0;
	this->ankle[2] = -1.0;
	this->knee[0] = 0.0;
	this->knee[1] = 2.0;
	this->knee[2] = -1.0;
}

Person::~Person() {}

float* Person::getArticulations(int *size) {
	*size = 9;
	float* ret = new float[9];
	int i = 0;
	for (i = 0; i < *size / 3; i++) {
		ret[i] = this->tiptoe[i];
		ret[i + 3] = this->ankle[i];
		ret[i + 6] = this->knee[i];
	}
	return ret;
}

