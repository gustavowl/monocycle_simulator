#include "person.h"

Person::Person() {
	this->tiptoe[0] = 1.0;
	this->tiptoe[1] = 0.0;
	this->tiptoe[2] = 1.0;
}

Person::~Person() {}

float* Person::getArticulations(int *size) {
	*size = 3;
	float* ret = new float[3];
	int i = 0;
	for (i = 0; i < *size; i++) {
		ret[i] = this->tiptoe[i];
	}
	return ret;
}

