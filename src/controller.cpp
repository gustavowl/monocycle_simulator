#include "controller.h"

void controllerReadCommands(unsigned char key, int x, int y) {
	Person* p = Person::getInstance();
	//TODO: switch case?
	//TODO: detect multiple key pressing
	if (key == 'q')
		exit(-1);
	if (key == 'd') {
		//printf("Move forward\n");
		p->updatePosition(-10);
	}
	if (key == 'a') {
		//printf("Move backwards\n");
		p->updatePosition(10);
	}
	if (key == 'l') {
		//printf("Balance forward\n");
		p->updateBodyAngle(-5);
	}
	if (key == 'j') {
		//printf("Balance backwards\n");
		p->updateBodyAngle(5);
	}
	if (key == 'r') {
		//restart game
		p->restart();
	}
	//printf("=========================\n");
	glutPostRedisplay();	
}
