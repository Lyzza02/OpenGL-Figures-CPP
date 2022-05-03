#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();
void x_Axis();
void y_Axis();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Simple Circle");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	x_Axis();
	y_Axis();
	
	glFlush();
}

void x_Axis(){
	glColor3ub(254, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glEnd();
}

void y_Axis(){
	glColor3ub(31, 255, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glEnd();
}

