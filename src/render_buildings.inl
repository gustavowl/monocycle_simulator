inline void renderBuildings(int traveled_distance) {
	float heights[] = {4, 2.5, 4, 1, 2, 4, 1.5, 2, 3.5, 2.5,
		1, 1.5, 4, 2};

	glColor3f(0.55, 0.55, 0.55);
	for (int i = 0; i < 14; i++) {
		glPushMatrix();
		glScalef(1, heights[i], 1);
		//[-14, 14]
		float shiftx = i*2 - traveled_distance / 20.0;
		while(shiftx < -14)
			shiftx += 28;
		while(shiftx > 14)
			shiftx -= 28;

		glTranslatef(shiftx, 0.5, -5);
		glutSolidCube(1);
		glPopMatrix();
	}
}


