#ifndef _PERSON_H_
#define _PERSON_H_

#include <string.h>

#define LEFT 0
#define RIGHT 1

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
