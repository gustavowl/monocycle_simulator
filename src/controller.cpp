#include "controller.h"

Controller::Controller() {
}

Controller::~Controller() {
}

void Controller::readCommands(unsigned char key, int x, int y) {
	//TODO: switch case?
	if (key == 'q')
		exit(-1);
	if (key == 'd')
		printf("Move forward\n");
	if (key == 'a')
		printf("Move backwards\n");
	if (key == 'l')
		printf("Balance forward\n");
	if (key == 'j')
		printf("Balance backwards\n");
	printf("=========================");
	glutPostRedisplay();	
}