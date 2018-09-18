#include <GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int initial_time = time(NULL), final_time, frame_count;

void init() {
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-10, 10, -15, 10);
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
	}
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
float _angle = 90.0f;
float _cameraAngle = 0.0f;

void cube()
{

	//front side
	glColor3f(0.169f, 0.169f, 0.169f);//Dark grey
	glBegin(GL_POLYGON);
	glVertex3f(0.2f, 0.1f, 0.0f);
	glVertex3f(0.9f, 0.1f, 0.0f);
	glVertex3f(0.9f, 0.5f, 0.0f);
	glVertex3f(0.2f, 0.5f, 0.0f);
	glEnd();

	//back side
	glColor3f(0.169f, 0.169f, 0.169f);//Dark grey
	glBegin(GL_POLYGON);
	glVertex3f(0.2f, 0.1f, 0.5f);
	glVertex3f(0.9f, 0.1f, 0.5f);
	glVertex3f(0.9f, 0.5f, 0.5f);
	glVertex3f(0.2f, 0.5f, 0.5f);
	glEnd();

	//left side
	glColor3f(0.169f, 0.169f, 0.169f);//Dark grey
	glBegin(GL_POLYGON);
	glVertex3f(0.2f, 0.1f, 0.5f);
	glVertex3f(0.2f, 0.1f, 0.0f);
	glVertex3f(0.2f, 0.5f, 0.0f);
	glVertex3f(0.2f, 0.5f, 0.5f);
	glEnd();

	//right side
	glColor3f(0.211f, 0.211f, 0.211f);//Lighter grey
	glBegin(GL_POLYGON);
	glVertex3f(0.9f, 0.1f, 0.5f);
	glVertex3f(0.9f, 0.1f, 0.0f);
	glVertex3f(0.9f, 0.5f, 0.0f);
	glVertex3f(0.9f, 0.5f, 0.5f);
	glEnd();


}
void drawCube() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
	glTranslatef(-1.0f, -1.5f, -2.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRotatef(_angle, 0.0f, 0.1f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glColor3f(1.0, 0.25, 1.0);
	glColor3f(.5, 0.5, .25);

	glClear(GL_COLOR_BUFFER_BIT);
	
	cube();

	frame_count++;
	final_time = time(NULL);
	if (final_time - initial_time > 0)
	{
		cout << "FPS: " << frame_count / (final_time - initial_time) << "\n";
		frame_count = 0;
		initial_time = final_time;
	}

	glFlush();
	glPopMatrix();
	glutSwapBuffers();
}

void update(int value) {
	_angle += 0.5f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(20, update, 0);
}

int main(int argc, char * * argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 720);
	glutCreateWindow("Cube");
	init();
	glutDisplayFunc(drawCube);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(1000, update, 0);
	glutMainLoop();
	return 0;
}

