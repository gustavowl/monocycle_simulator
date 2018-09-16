#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <GL/glut.h>

//FIXME: REMOVE STD OUTPUT
#include <stdio.h>
#include "person.h"

extern Person* gambiarra;

void controllerReadCommands(unsigned char key, int x, int y);

#endif
