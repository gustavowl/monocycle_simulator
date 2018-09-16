#include "render.h"
#include <stdio.h>
#define PI 3.1415926535897932

#define LEFT 0
#define BHEIGHT 1
#define BACK 2
#define RIGHT 3
#define FHEIGHT 4
#define FRONT 5

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

//xyz = width, height, depth
//lbb = leftBottomBack
//rtf = rightTopFront
//
//CURRENT IMPLEMENTATION:
//Uses two rectangles: bottom and top
//each rectangle has two points: (left, back) and (right, front)
//expected format:
//bottom(point1, point2) => {x1, y1, z1, x2, y2 ,z2}
//i.e. sqrBottom[6] = {LEFT, LBHEIGHT, BACK, RIGHT, RFHEIGHT, FRONT}
void drawParallelepiped(float* sqrBot, float* sqrTop) {
	glBegin(GL_QUADS);
		//draw back clockwise: lbb, ltb, rtb, rbb
		/*glColor3f(1, 0, 0); //red
		glVertex3f(sqrBot[LEFT], sqrBot[BHEIGHT], sqrBot[BACK]);
		glVertex3f(sqrTop[LEFT], sqrTop[BHEIGHT], sqrTop[BACK]);
		glVertex3f(sqrTop[RIGHT], sqrTop[BHEIGHT], sqrTop[BACK]);
		glVertex3f(sqrBot[RIGHT], sqrBot[BHEIGHT], sqrBot[BACK]);*/

		//draw bottom clockwise: rbb, rbf, lbf, lbb
		//glColor3f(1, 1, 0); //yellow
		glVertex3f(sqrBot[RIGHT], sqrBot[FHEIGHT], sqrBot[BACK]);
		glVertex3f(sqrBot[RIGHT], sqrBot[FHEIGHT], sqrBot[FRONT]);
		glVertex3f(sqrBot[LEFT], sqrBot[BHEIGHT], sqrBot[FRONT]);
		glVertex3f(sqrBot[LEFT], sqrBot[BHEIGHT], sqrBot[BACK]);

		//draw left clockwise: lbb, lbf, ltf, ltb
		//glColor3f(0, 1, 0); //green
		glVertex3f(sqrBot[LEFT], sqrBot[BHEIGHT], sqrBot[BACK]);
		glVertex3f(sqrBot[LEFT], sqrBot[BHEIGHT], sqrBot[FRONT]);
		glVertex3f(sqrTop[LEFT], sqrTop[BHEIGHT], sqrTop[FRONT]);
		glVertex3f(sqrTop[LEFT], sqrTop[BHEIGHT], sqrTop[BACK]);

		//draw right: rtf, rtb, rbb, rbf
		//glColor3f(1, 1, 1); //white
		glVertex3f(sqrTop[RIGHT], sqrTop[FHEIGHT], sqrTop[FRONT]);
		glVertex3f(sqrTop[RIGHT], sqrTop[FHEIGHT], sqrTop[BACK]);
		glVertex3f(sqrBot[RIGHT], sqrBot[FHEIGHT], sqrBot[BACK]);
		glVertex3f(sqrBot[RIGHT], sqrBot[FHEIGHT], sqrBot[FRONT]);

		//draw top clockwise: ltb, rtb, rtf, ltf
		//glColor3f(0, 1, 1); //cyan
		glVertex3f(sqrTop[LEFT], sqrTop[BHEIGHT], sqrTop[BACK]);
		glVertex3f(sqrTop[RIGHT], sqrTop[FHEIGHT], sqrTop[BACK]);
		glVertex3f(sqrTop[RIGHT], sqrTop[FHEIGHT], sqrTop[FRONT]);
		glVertex3f(sqrTop[LEFT], sqrTop[BHEIGHT], sqrTop[FRONT]);

		//draw front anti-clockwise: ltf, lbf, rbf, rtf
		//glColor3f(0, 0, 1); //blue
		glVertex3f(sqrTop[LEFT], sqrTop[BHEIGHT], sqrTop[FRONT]);
		glVertex3f(sqrBot[LEFT], sqrBot[BHEIGHT], sqrBot[FRONT]);
		glVertex3f(sqrBot[RIGHT], sqrBot[FHEIGHT], sqrBot[FRONT]);
		glVertex3f(sqrTop[RIGHT], sqrTop[FHEIGHT], sqrTop[FRONT]);

	glEnd();
}

void drawFoot(float* pos, int size) {
	glColor3f(1, 0, 0);
	glPushMatrix();

	float bot[6] = {pos[ANKLEX], pos[ANKLEY], pos[ANKLEZ] - FOOT_DEPTH,
		pos[TIPTOEX], pos[TIPTOEY], pos[TIPTOEZ]};
	
	float top[6] = {pos[ANKLEX], pos[ANKLEY] + FOOT_HEIGHT,
		pos[ANKLEZ] - FOOT_DEPTH,
		pos[TIPTOEX], pos[TIPTOEY] + FOOT_HEIGHT, pos[TIPTOEZ]};

	drawParallelepiped(bot, top);
	
	glPopMatrix();
}

void drawCalf(float* pos, int size) {
	glColor3f(0, 1, 0);
	glPushMatrix();

	float bot[6] = {pos[ANKLEX], pos[ANKLEY], pos[ANKLEZ] - CALF_DEPTH,
		pos[ANKLEX] + CALF_WIDTH, pos[ANKLEY], pos[ANKLEZ]};

	float top[6] = {pos[KNEEX] - CALF_WIDTH, pos[KNEEY],
		pos[KNEEZ] - CALF_DEPTH,
		pos[KNEEX], pos[KNEEY], pos[KNEEZ]};

	drawParallelepiped(bot, top);

	glPopMatrix();
}

void drawThigh(float* pos, int size) {
	glColor3f(0, 0, 1);
	glPushMatrix();

	float bot[6] = {pos[HIPX], pos[HIPY], pos[HIPZ] - THIGH_DEPTH,
		pos[KNEEX], pos[KNEEY], pos[KNEEZ]};
	
	float top[6] = {pos[HIPX], pos[HIPY] + THIGH_HEIGHT,
		pos[HIPZ] - THIGH_DEPTH,
		pos[KNEEX], pos[KNEEY] + THIGH_HEIGHT, pos[KNEEZ]};

	drawParallelepiped(bot, top);

	glPopMatrix();
}

void renderPerson() {
	int size;
	float* vec = gambiarra.getArticulations(&size);
	/*for (int i = 0; i < size; i++) {
		printf("%f, ", vec[i]);
	}
	printf("\n");*/

	glTranslatef(1, -1, 1);
	drawFoot(vec, size);
	drawCalf(vec, size);
	drawThigh(vec, size);
	
	delete vec;
}

void renderDisplay() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 2.0, 5.0, 
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

int time = 0;
void timer() {
	if (++time == 2112 * 73) {
		gambiarra.updatePosition(-15);

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
