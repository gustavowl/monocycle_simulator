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
	this->hip[0] = -3.0;
	this->hip[1] = 2.0;
	this->hip[2] = -1.5;
}

Person::~Person() {}

float* Person::getArticulations(int *size) {
	*size = 12;
	float* ret = new float[*size];
	
	for (int i = 0; i < *size / 3; i++) {
		ret[i] = this->tiptoe[i];
		ret[i + 3] = this->ankle[i];
		ret[i + 6] = this->knee[i];
		ret[i + 9] = this->hip[i];
	}

	return ret;
}

