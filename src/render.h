#ifndef _RENDER_H_
#define _RENDER_H_

#include <GL/glut.h>
#include <GL/glu.h>
#include "person.h"
#include "controller.h"
#include "math.h"

class Render {
private:
	Person person;

public:
	Render();
	Render(Person p);
	~Render();

	void start(int* argc, char **argv);
};

#endif
