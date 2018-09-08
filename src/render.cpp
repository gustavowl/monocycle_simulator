#include "render.h"

Render::Render() {
	//TODO
}

Render::Render(Person p) {
	this->person = p;
}

void a(unsigned char key, int x, int y){
}

void Render::start(int* argc, char **argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Monocycle Simulator");
	glutKeyboardFunc(controllerReadCommands);
	//glutKeyboardFunc(a);
}
