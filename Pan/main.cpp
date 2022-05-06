#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void circle(GLfloat x, GLfloat y, GLfloat radius);
void stick();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Pan");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3ub(84, 84, 84);
	circle(-0.2f, 0.2f, .5f);
	
	glColor3ub(127, 127, 127);
	circle(-0.2f, 0.2f, .4f);
	
	stick();
	
	glFlush();
}

void circle(GLfloat x, GLfloat y, GLfloat radius){
	int triangleAmount = 40;
	
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	
	for (int i = 0; i<=triangleAmount ; i++){
		glVertex2f(
			x + (radius * cos(i*twicePi / triangleAmount)),
			y + (radius * sin(i*twicePi / triangleAmount))
		);
	}
	
	glEnd();
}

void stick(){
	glColor3ub(84, 84, 84);
	glBegin(GL_QUADS);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.2, -0.1);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.4, -0.6);
	glEnd();
}
