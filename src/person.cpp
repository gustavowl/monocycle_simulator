#include "person.h"

Person::Person() {
	//this->initial.tiptoe[0] = 0.0;
	this->initial.tiptoe[0] = 1.0;
	this->initial.tiptoe[1] = -2.0;
	this->initial.tiptoe[2] = -1.0;
	//this->initial.ankle[0] = -2.0;
	this->initial.ankle[0] = -1.0;
	this->initial.ankle[1] = -2.0;
	this->initial.ankle[2] = -1.0;
	this->initial.knee[0] = 0.0;
	this->initial.knee[1] = 2.0;
	this->initial.knee[2] = -1.0;
	this->initial.hip[0] = -3.0;
	this->initial.hip[1] = 2.0;
	this->initial.hip[2] = -1.5;

	updatePosition(0);
}

Person::~Person() {}

float* Person::getArticulations(int *size) {
	*size = 12;
	float* ret = new float[*size];
	
	for (int i = 0; i < *size / 3; i++) {
		ret[i] = this->actual.tiptoe[i];
		ret[i + 3] = this->actual.ankle[i];
		ret[i + 6] = this->actual.knee[i];
		ret[i + 9] = this->actual.hip[i];
	}

	return ret;
}

float Person::cosDegrees(int degrees) {
	return cos(degrees * PI / 180);
}

float Person::sinDegrees(int degrees) {
	return sin(degrees * PI / 180);
}

void Person::updatePosition(int angle_increase) {
	//updates foot angle relatively to pedal
	this->foot_angle += angle_increase;
	//may be moving forward or backward
	while (this->foot_angle < 0)
		this->foot_angle += 360;
	this->foot_angle = this->foot_angle % 360;

	//updates body angle simulating inertia.
	//If person moves forward the angle increases.
	//The angle decreases otherwise.
	//2 indicates the "speed proportion"
	this->body_angle -= angle_increase / 2;
	this->body_angle = this->body_angle % 360;

	this->actual = this->initial;

	this->actual.tiptoe[0] += cosDegrees(this->foot_angle);
	this->actual.tiptoe[1] += sinDegrees(this->foot_angle);
	
	this->actual.ankle[0] += cosDegrees(this->foot_angle);
	this->actual.ankle[1] += sinDegrees(this->foot_angle);
	
	//calculate calf height using Pythagoras
	float calf_height = sqrt(pow(this->initial.ankle[0] -
					this->initial.knee[0], 2) +
				pow(this->initial.ankle[1] -
					this->initial.knee[1], 2)
			);
	//calculate knee height using Pythagoras
	this->actual.knee[1] = sqrt(pow(calf_height,2) - pow(
				this->actual.ankle[0] - this->actual.knee[0] ,2)) +
				this->actual.ankle[1];
}

int Person::getBodyAngle() {
	return this->body_angle;
}
