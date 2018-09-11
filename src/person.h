#ifndef _PERSON_H_
#define _PERSON_H_

#include <string.h>

#define PERSON_LEFT 0
#define PERSON_RIGHT 1

#define FOOT_DEPTH 1.0f
#define FOOT_HEIGHT 0.5f
#define CALF_DEPTH 1.0f
#define CALF_WIDTH 1.0f
#define THIGH_DEPTH 1.2f
#define THIGH_HEIGHT 1.2f

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

class Person {
private:
	//store positions of articulations
	float tiptoe[3];
	float ankle[3];
	float knee[3];
	float hip[3];
	float shoulder[3];

public:
	Person();
	//todo: copy constructor? (contrutor de copia)
	~Person();

	//do not forget to delete array
	float* getArticulations(int *size);

};

#endif
