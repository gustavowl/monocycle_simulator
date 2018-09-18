#include <stdio.h>

#define LEFT 0
#define BHEIGHT 1
#define BACK 2
#define RIGHT 3
#define FHEIGHT 4
#define FRONT 5

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
inline void drawParallelepiped(float* sqrBot, float* sqrTop) {
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

inline void drawFoot(float* pos, int size) {
	glColor3f(0.4, 0.2, 0);
	glPushMatrix();

	float bot[6] = {pos[ANKLEX], pos[ANKLEY], pos[ANKLEZ] - FOOT_DEPTH,
		pos[TIPTOEX], pos[TIPTOEY], pos[TIPTOEZ]};
	
	float top[6] = {pos[ANKLEX], pos[ANKLEY] + FOOT_HEIGHT,
		pos[ANKLEZ] - FOOT_DEPTH,
		pos[TIPTOEX], pos[TIPTOEY] + FOOT_HEIGHT, pos[TIPTOEZ]};

	drawParallelepiped(bot, top);
	
	glPopMatrix();
}

inline void drawCalf(float* pos, int size) {
	glColor3f(1, 0.5, 0);
	glPushMatrix();

	float bot[6] = {pos[ANKLEX], pos[ANKLEY], pos[ANKLEZ] - CALF_DEPTH,
		pos[ANKLEX] + CALF_WIDTH, pos[ANKLEY], pos[ANKLEZ]};

	float top[6] = {pos[KNEEX] - CALF_WIDTH, pos[KNEEY],
		pos[KNEEZ] - CALF_DEPTH,
		pos[KNEEX], pos[KNEEY], pos[KNEEZ]};

	drawParallelepiped(bot, top);

	glPopMatrix();
}

inline void drawThigh(float* pos, int size) {
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

inline void drawTorso(float* pos, int size) {
	glColor3f(1, 0, 0);
	glPushMatrix();

	float bot[6] = {pos[SHOULDERX], pos[HIPY], pos[HIPZ] -
		TORSO_DEPTH,
		pos[HIPX], pos[HIPY], pos[KNEEZ]};
	float top[6] = {pos[SHOULDERX], pos[SHOULDERY], pos[SHOULDERZ] -
		TORSO_DEPTH,
		pos[HIPX], pos[SHOULDERY], pos[SHOULDERZ]};

	drawParallelepiped(bot, top);

	glPopMatrix();
}

inline void drawLeftArm(float* pos, int size) {
	glColor3f(1, 0.5, 0);
	glPushMatrix();
	float bot[6] = {pos[LARMX], pos[LARMY], pos[LARMZ],
		pos[LARMX] + ARM_WIDTH, pos[LARMY], pos[SHOULDERZ]};
	float top[6] = {pos[LARMX], pos[LARMY] + ARM_HEIGHT, pos[LARMZ],
		pos[LARMX] + ARM_WIDTH, pos[LARMY] + ARM_HEIGHT, pos[SHOULDERZ]};

	drawParallelepiped(bot, top);
	glPopMatrix();
}

inline void drawRightArm(float* pos, int size) {
	glColor3f(1, 0.5, 0);
	glPushMatrix();
	float bot[6] = {pos[RARMX], pos[RARMY], pos[SHOULDERZ],
		pos[RARMX] + ARM_WIDTH, pos[RARMY], pos[RARMZ]};
	float top[6] = {pos[RARMX], pos[RARMY] + ARM_HEIGHT, pos[SHOULDERZ],
		pos[RARMX] + ARM_WIDTH, pos[RARMY] + ARM_HEIGHT, pos[RARMZ]};

	drawParallelepiped(bot, top);
	glPopMatrix();
}

inline void drawHead(float* pos, int size) {
	glColor3f(1, 0.5, 0);
	glPushMatrix();
	float bot[6] = {pos[HEADX], pos[NECKY], pos[HEADZ],
		pos[NECKX], pos[NECKY], pos[NECKZ]};
	float top[6] = {pos[HEADX], pos[HEADY], pos[HEADZ],
		pos[NECKX], pos[HEADY], pos[NECKZ]};

	drawParallelepiped(bot, top);
	glPopMatrix();
}

inline void renderMono(Person* p){
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluQuadricNormals(quadratic, GLU_SMOOTH);
	// Rodinha
	float sz = 2.6;
	glPushMatrix();
		glTranslatef(-0.7, -0.6, 0);
		glColor3f(0.7f, 0.7f, 0.7f);
		gluDisk(quadratic,sz, sz+0.1, 32, 32);
		for (int i=0; i<12; ++i){
			glBegin(GL_LINES);
				glVertex3f (0, 0, 0);
		      	glVertex3f (sin(i+p->getFootAngle())*sz, cos(i+p->getFootAngle())*sz, 0);
			glEnd();
		}
	glPopMatrix();
}

inline void renderPerson() {
	int size;
	Person* p = Person::getInstance();
	float* vec = p->getArticulations(&size);

	
	
	//glPushMatrix();
	glTranslatef(1, -5, -5);
	glRotatef(p->getBodyAngle() - 90, 0, 0, 1);
	
	drawCalf(vec, size);
	drawFoot(vec, size);
	drawThigh(vec, size);
	drawLeftArm(vec, size);
	drawTorso(vec, size);
	drawHead(vec, size);
	drawRightArm(vec, size);
	//glPopMatrix();

	glRotatef((-1)*(p->getBodyAngle() - 90), 0, 0, 1);
	renderMono(p);	// Rodinha
	glRotatef(p->getBodyAngle() - 90, 0, 0, 1);
	// glPushMatrix();
	// glTranslatef(1, -5, -5);
	//glRotatef(p->getBodyAngle() - 90, 0, 0, 1);
	p->calculateSecondLegPos(vec);
	drawCalf(vec, size);
	drawFoot(vec, size);
	drawThigh(vec, size);
	//glPopMatrix();
	
	delete vec;
}


