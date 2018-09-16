#include "controller.h"

void controllerReadCommands(unsigned char key, int x, int y) {
	//TODO: switch case?
	//TODO: detect multiple key pressing
	if (key == 'q')
		exit(-1);
	if (key == 'd') {
		//printf("Move forward\n");
		gambiarra->updatePosition(-10);
		printf("Body angle: %i\n", gambiarra->getBodyAngle());
	}
	if (key == 'a') {
		//printf("Move backwards\n");
		gambiarra->updatePosition(10);
		printf("Body angle: %i\n", gambiarra->getBodyAngle());
	}
	if (key == 'l')
		printf("Balance forward\n");
	if (key == 'j')
		printf("Balance backwards\n");
	//printf("=========================\n");
	glutPostRedisplay();	
}
