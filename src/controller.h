#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <GL/glut.h>

//FIXME: REMOVE STD OUTPUT
#include <stdio.h>

class Controller {
public:
	Controller();
	~Controller();

	void readCommands(unsigned char key, int x, int y);
};

#endif
