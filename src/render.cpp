#include "render.h"

Render::Render() {
	//TODO
}

Render::Render(Person p) {
	this->person = p;
}

void renderDisplay() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(5.0, 0.0, 0.0, 
			0, 0, 0, 0, 1, 0);

	glColor3f(0, 0, 0);

	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			glPushMatrix();
			//glScalef(1.0, i+3.0, 1.0);
			//glScalef(1.0, random_scale_matrix[i+2][j+2], 1.0);
			glTranslatef((double)i, 0.25, (double)j);
			//glutWireCube(0.5);
			glutSolidCube(0.5);
			glPopMatrix();
		}
	}

	glFlush();
	glutSwapBuffers();
}

void Render::start(int* argc, char **argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Monocycle Simulator");
	glutKeyboardFunc(controllerReadCommands);
	glutDisplayFunc(renderDisplay);

	GLfloat lightPos[4] = {0.0, 50.0, 50.0, 1.0};
	glShadeModel(GL_FLAT);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	//background color
	glClearColor(0.53, 0.8, 1.0, 0.0);
	
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1, 1, -1, 1, 1.5, 20.0);

	glutMainLoop();
}
