#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void cup();
void cube1();
void cube2();
void liquid();
void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Old Fashioned");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	cup();
	liquid();
	cube1();
	cube2();
	
	glFlush();
}

void cup(){
	glColor4ub(212,197,165,255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-.3f,-.6f);
	glVertex2f(.3f,-.6f);
	glVertex2f(-0.45f,0.2f);
	glVertex2f(0.45f,0.2f);
	glEnd();
}

void liquid(){
	glColor4ub(184,12,20,255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-.25f,-.5f);
	glVertex2f(.25f,-.5f);
	glVertex2f(-0.35f,0.05f);
	glVertex2f(0.35f,0.05f);
	glEnd();
}

void cube1(){ //lower
	glColor4ub(208,62,53,255);
	glBegin(GL_QUADS);
	glVertex2f(-0.0f, -0.25f); // left corner
	glVertex2f(0.2f, -0.25f); // right corner
	glVertex2f(0.2f, -0.45f); // bottom right corner
	glVertex2f(-0.0f, -0.45f); // bottom left corner
	glEnd();
}

void cube2(){ //upper
	glColor4ub(208,62,53,255);
	glBegin(GL_QUADS);
	glVertex2f(-0.26f, 0.0f); // left corner
	glVertex2f(-0.06f, 0.0f); // right corner
	glVertex2f(-0.06f, -0.2f); // bottom right corner
	glVertex2f(-0.26f, -0.2f); // bottom left corner
	glEnd();
}
