#ifndef _RENDER_H_
#define _RENDER_H_

#include <GL/glut.h>
#include <GL/glu.h>
#include "controller.h"
#include "math.h"
#include "render_person.h"
#include "render_buildings.h"

class Render {

public:
	Render();
	~Render();

	void start(int* argc, char **argv);
};

#endif
