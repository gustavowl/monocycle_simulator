#ifndef _PERSON_H_
#define _PERSON_H_

#include <string.h>
#include <math.h>
#define PI 3.1415926535897932

#define PERSON_LEFT 0
#define PERSON_RIGHT 1

#define FOOT_DEPTH 1.0f
#define FOOT_HEIGHT 0.5f
#define CALF_DEPTH 1.0f
#define CALF_WIDTH 1.0f
#define THIGH_DEPTH 1.2f
#define THIGH_HEIGHT 1.2f
#define TORSO_DEPTH 2.5f
#define ARM_WIDTH 0.5f
#define ARM_HEIGHT 0.5f

#define TIPTOEX 0
#define TIPTOEY 1
#define TIPTOEZ 2
#define ANKLEX 3
#define ANKLEY 4
#define ANKLEZ 5
#define KNEEX 6
#define KNEEY 7
#define KNEEZ 8
#define HIPX 9
#define HIPY 10
#define HIPZ 11
#define SHOULDERX 12
#define SHOULDERY 13
#define SHOULDERZ 14
#define RARMX 15
#define RARMY 16
#define RARMZ 17
#define LARMX 18
#define LARMY 19
#define LARMZ 20


class Person {
private:
	static Person* instance;

	struct articulations {
		//store positions of articulations
		float tiptoe[3];
		float ankle[3];
		float knee[3];
		float hip[3];
		float shoulder[3];
		float rarm[3];
		float larm[3];
	} initial, actual;

	int foot_angle = 0;
	float body_angle = 90;
	bool game_over = false;

	float cosDegrees(float degrees);
	float sinDegrees(float degrees);

	int distance = 0;
	
	Person();

public:
	//do not forget to delete array
	float* getArticulations(int *size);

	void updatePosition(int angle_increase);
	void updateBodyAngle(float angle_increase);

	//will be used for rotation
	//returns body angle with respect to y-axis
	float getBodyAngle();

	//this should be called every "frame" when
	//gravity should act
	void gravity();

	void checkGameOver();
	void restart();

	static Person* getInstance();

	int getDistance();

	void calculateSecondLegPos(float* vec);

};

#endif
