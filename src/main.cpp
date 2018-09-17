#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include "person.h"
#include "render.h"

int main(int argc, char **argv) {
	Render *r = new Render();
	r->start(&argc, argv);

	return 0;
}

#endif
