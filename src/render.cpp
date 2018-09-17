#include "render.h"
#include <stdio.h>
#define PI 3.1415926535897932

Render::Render() {
	//TODO
}

Render::~Render() {
}

void renderDisplay() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 2.0, 5.0,
			0, 0, 0, 0, 1, 0);

	glColor3f(0.7f, 0.7f, 0.7f);

	Person* p = Person::getInstance();
	renderBuildings(p->getDistance());
	renderPerson();

	glFlush();
	glutSwapBuffers();
}

int time = 0;
void timer() {
	if (++time == 2112 * 3) {
		//printf("Body angle = %f\n", gambiarra->getBodyAngle());
		Person* p = Person::getInstance();
		p->gravity();
		glutPostRedisplay();
		time = 0;
	}
}

void Render::start(int* argc, char **argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Monocycle Simulator");
	glutKeyboardFunc(controllerReadCommands);
	glutDisplayFunc(renderDisplay);
	glutIdleFunc(timer);

	/*GLfloat lightPos[4] = {0.0, 50.0, 50.0, 1.0};
	glShadeModel(GL_FLAT);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);*/
	//background color
	glClearColor(0.53, 0.8, 1.0, 0.0);
	
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1, 1, -1, 1, 1.5, 20.0);

	glutMainLoop();
}
