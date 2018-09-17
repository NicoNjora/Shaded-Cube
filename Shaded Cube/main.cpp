#include <GL/glut.h>;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);

	gluOrtho2D(-10, 10, -15, 10);


}
void drawCube() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);


	glColor3f(0.75f, 0.75f, 0.75f);//Lighter grey

	glVertex2i(0, -2);
	glVertex2i(3, -3);

	glVertex2i(3, -3);
	glVertex2i(0, -4);

	glColor3f(0.75f, 0.75f, 0.75f);//Lighter grey

	glVertex2i(0, -4);
	glVertex2i(-3, -3);

	glColor3f(0.75f, 0.75f, 0.75f);//Lighter grey

	glVertex2i(-3, -3);
	glVertex2i(0, -2);

	glColor3f(0.75f, 0.75f, 0.75f);//Lighter grey

	glVertex2i(3, -3);
	glVertex2i(3, -5);


	glVertex2i(3, -5);
	glVertex2i(0, -7);

	glColor3f(0.1f, 0.1f, 0.1f);//Dark grey


	glVertex2i(0, -7);
	glVertex2i(-0, -4);

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex2i(-3, -3);
	glVertex2i(0, -2);


	glVertex2i(0, -4);
	glVertex2i(0, -7);

	glColor3f(0.1f, 0.1f, 0.1f);//Dark grey

	glVertex2i(-3, -5);
	glVertex2i(-3, -3);

	glVertex2i(-3, -3);
	glVertex2i(0, -4);

	glVertex2i(-3, -5);
	glVertex2i(0, -7);

	glEnd();




	glFlush();


}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(drawCube);
	glutMainLoop();
	return 0;
}

