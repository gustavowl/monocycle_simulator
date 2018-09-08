#include <stdio.h>
#include "person.h"
#include "render.h"

int main(int argc, char **argv) {
	Person* p = new Person();
	int size;
	float* vec = p->getArticulations(&size);
	//delete[] vec;
	printf("%f\n", vec[2]);
	printf("%f\n", ++vec[2]);
	printf("%f\n", vec[2]);
	
	delete vec;
	
	vec = p->getArticulations(&size);
	
	printf("------------\n%f\n", vec[2]);
	printf("%f\n", ++vec[2]);
	printf("%f\n", vec[2]);
	printf("size: %i\n", size);

	Render *r = new Render(*p);
	r->start(&argc, argv);
	
	return 0;
}
