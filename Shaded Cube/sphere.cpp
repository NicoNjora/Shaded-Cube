#include<GL/glut.h>
#include<math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


GLfloat xRotated, yRotated, zRotated;
GLdouble size = 1.0;
GLdouble width = 1.0;
GLdouble radius=1;


GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 0.0 }; //Black Color
GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 }; //green Color
GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 }; //White Color
GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 }; //White Color

										  // Set lighting intensity and color
GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat emitLight[] = { 0.9, 0.9, 0.9, 0.01 };
GLfloat Noemit[] = { 0.0, 0.0, 0.0, 1.0 };
// Light source position
GLfloat qaLightPosition[] = { 10, 10, 3.5, 1 };

void display(void);
void reshape(int x, int y);

void idleFunc(void)
{

	zRotated += 0.02;

	display();
}
void initLighting()
{

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Solid Cube");
	initLighting();
	xRotated = yRotated = zRotated = 0.0;

	glutIdleFunc(idleFunc);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

void display(void)
{


	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// clear the identity matrix.
	glLoadIdentity();


	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glTranslatef(0.0, 0.0, -9.0);


	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// Set material properties
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);

	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);

	// built-in (glut library) function , draw you a cube.
	glutSolidSphere(radius, 15, 15);

	
	// Flush buffers to screen
	

	glFlush();
	glutSwapBuffers();
	// sawp buffers called because we are using double buffering 
	// glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
	
		//  Right arrow - increase rotation by 5 degree
		if (key == GLUT_KEY_RIGHT)
			yRotated += 5;
	
		//  Left arrow - decrease rotation by 5 degree
		else if (key == GLUT_KEY_LEFT)
			yRotated -= 5;
	
		else if (key == GLUT_KEY_UP)
			xRotated += 5;
	
		else if (key == GLUT_KEY_DOWN)
			xRotated -= 5;
	
		//  Request display update
		glutPostRedisplay();
	
	}

void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(39.0, (GLdouble)x / (GLdouble)y, 0.6, 21.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
}


//#include <GL/freeglut.h>
//#include <time.h>
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//int initial_time = time(NULL), final_time, frame_count;
//double rotate_y = 0;
//double rotate_x = 0;
//double rotate_z;
//
//void init() {
//	glEnable(GL_DEPTH_TEST);
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	gluOrtho2D(-10, 10, -15, 10);
//}
//
//
//
//void handleResize(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
//}
//float _angle = 90.0f;
//float _cameraAngle = 0.0f;
//
//void cube()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
//
//
//	glRotatef(rotate_x, 1.0, 0.0, 0.0);
//	glRotatef(rotate_y, 0.0, 1.0, 0.0);
//
//	
//
//	//front side
//	glColor3f(0.169f, 0.169f, 0.169f);//Dark grey
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex3f(0.2f, 0.1f, 0.0f);
//	glVertex3f(0.6f, 0.1f, 0.0f);
//	glColor3f(0.6, 0.6, 0.6);
//	glVertex3f(0.6f, 0.5f, 0.0f);
//	glVertex3f(0.2f, 0.5f, 0.0f);
//	glEnd();
//
//	//back side
//	glColor3f(0.169f, 0.169f, 0.169f);//Dark grey
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex3f(0.2f, 0.1f, 0.5f);
//	glVertex3f(0.6f, 0.1f, 0.5f);
//	glColor3f(0.6, 0.6, 0.6);
//	glVertex3f(0.6f, 0.5f, 0.5f);
//	glVertex3f(0.2f, 0.5f, 0.5f);
//	glEnd();
//
//	//left side
//	glColor3f(0.169f, 0.169f, 0.169f);//Dark grey
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex3f(0.2f, 0.1f, 0.5f);
//	glVertex3f(0.2f, 0.1f, 0.0f);
//	glColor3f(0.6, 0.6, 0.6);
//	glVertex3f(0.2f, 0.5f, 0.0f);
//	glVertex3f(0.2f, 0.5f, 0.5f);
//	glEnd();
//
//	//right side
//	glColor3f(0.211f, 0.211f, 0.211f);//Lighter grey
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex3f(0.6f, 0.1f, 0.5f);
//	glVertex3f(0.6f, 0.1f, 0.0f);
//	glColor3f(0.6, 0.6, 0.6);
//	glVertex3f(0.6f, 0.5f, 0.0f);
//	glVertex3f(0.6f, 0.5f, 0.5f);
//	glEnd();
//
//	//top side
//	glColor3f(0.211f, 0.211f, 0.211f);//Lighter grey
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex3f(0.2f, 0.5f, 0.0f);
//	glVertex3f(0.6f, 0.5f, 0.0f);
//	glColor3f(0.6, 0.6, 0.6);
//	glVertex3f(0.6f, 0.5f, 0.5f);
//	glVertex3f(0.2f, 0.5f, 0.5f);
//	glEnd();
//
//	//bottom side
//	glColor3f(0.169f, 0.169f, 0.169f);//Dark grey
//	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex3f(0.2f, 0.1f, 0.0f);
//	glVertex3f(0.6f, 0.1f, 0.0f);
//	glColor3f(0.6, 0.6, 0.6);
//	glVertex3f(0.6f, 0.1f, 0.5f);
//	glVertex3f(0.2f, 0.1f, 0.5f);
//	glEnd();
//
//
//}
//void drawCube() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
//	glTranslatef(-1.0f, -1.5f, -2.0f);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslatef(1.0f, 1.0f, 0.0f);
//	glRotatef(_angle, 0.0f, 0.1f, 0.0f);
//	glScalef(1.0f, 1.0f, 1.0f);
//	glColor3f(1.0, 0.25, 1.0);
//	glColor3f(.5, 0.5, .25);
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	cube();
//
//
//
//	glFlush();
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//
//
//void specialKeys(int key, int x, int y) {
//
//	//  Right arrow - increase rotation by 5 degree
//	if (key == GLUT_KEY_RIGHT)
//		rotate_y += 5;
//
//	//  Left arrow - decrease rotation by 5 degree
//	else if (key == GLUT_KEY_LEFT)
//		rotate_y -= 5;
//
//	else if (key == GLUT_KEY_UP)
//		rotate_x += 5;
//
//	else if (key == GLUT_KEY_DOWN)
//		rotate_x -= 5;
//
//	//  Request display update
//	glutPostRedisplay();
//
//}
//
//
//int main(int argc, char * * argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(1200, 720);
//	glutCreateWindow("Cube");
//	init();
//	glutDisplayFunc(drawCube);
//
//	glutReshapeFunc(handleResize);
//
//	glutSpecialFunc(specialKeys);
//	glutMainLoop();
//	return 0;
//}
