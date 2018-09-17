inline void renderBuildings(int traveled_distance) {
	glColor3f(1, 1, 0);
	for (int i = 0; i < 3; i++) {
		glPushMatrix();
		glScalef(1, 3, 1);
		glTranslatef(i + 0.25 - traveled_distance / 20.0,
				0.25, -2);
		glutSolidCube(0.5);
		glPopMatrix();
	}
}


