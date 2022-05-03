#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Arrow Target Board");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//target board
	glColor3ub(211,211,211);
	circle(0.0f, 0.0f, .75f);
	
	glColor3ub(0,0,0);
	circle(0.0f, 0.0f, .60f);
	
	glColor3ub	(0,4,255);
	circle(0.0f, 0.0f, .45f);
	
	glColor3ub(255,0,0);
	circle(0.0f, 0.0f, .30f);
	
	glColor3ub(255,255,0);
	circle(0.0f, 0.0f, .15f);

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

void line(){
	glLineWidth(10);
	
	glColor3ub(0, 29, 110);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.8, 0.8, 0.0);
	glEnd();
}
