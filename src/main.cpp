#include <stdio.h>
#include "person.h"
#include "render.h"

int main(int argc, char **argv) {
	Person *p = new Person();
	Render *r = new Render(*p);

	r->start(&argc, argv);

	delete p;
	return 0;
}
