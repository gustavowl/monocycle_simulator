#include "render.h"
#include "math.h"
#include <stdio.h>
#define PI 3.1415926535897932

Person gambiarra;

Render::Render() {
	//TODO
}

Render::Render(Person p) {
	this->person = p;
	gambiarra = p;
}

Render::~Render() {
}

void drawFoot(float* pos, int size) {
	int dim = 1;
	glColor3f(1, 0, 0);

	glPushMatrix();
	//glTranslatef(pos[0], pos[1], pos[2]);
	glRotatef(45, 0, 1, 0);
	
	int i = 0;
	glBegin(GL_QUADS);
	for (; i < 4; i++) {
		glVertex3f(dim * cos(i*PI/2),
				0, dim * sin(i*PI/2));

	}

	glColor3f(0, 1, 0);
	i = 0;
	for (; i < 4; i++) {
		glVertex3f(dim * cos(i*PI/2),
				dim * sin(i*PI/2), 0);

	}
	glEnd();
	glPopMatrix();
		/*glVertex3f(pos[0] + ((i+1)/2)%2 * dim,
				pos[1], pos[2] + i/2 * dim);*/

	/*glVertex3f(pos[0], pos[1], pos[2]);
	glVertex3f(pos[0] + dim, pos[1], pos[2]);
	glVertex3f(pos[0] + dim, pos[1], pos[2] + dim);
	glVertex3f(pos[0], pos[1], pos[2] + dim);*/

	//((i + 1)/2) % 2
}

void renderPerson() {
	int size;
	float* vec = gambiarra.getArticulations(&size);

	drawFoot(vec, size);
	delete vec;
}

void renderDisplay() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(5.0, 2.0, 0.0, 
			0, 0, 0, 0, 1, 0);

	glColor3f(0.7f, 0.7f, 0.7f);

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

	renderPerson();

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
