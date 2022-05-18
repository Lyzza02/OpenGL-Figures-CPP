#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void cup();
void lid();
void straw();
void liquid();
void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Milktea");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	cup();
	liquid();
	straw();
	lid();
	
	//pearls
	glColor3ub(122,63,2);
	circle(-0.2f, -0.63f, .05f);
	circle(-0.17f, -0.5f, .065f);
	circle(-0.1f, -0.62f, .05f);
	
	circle(0.2f, -0.6f, .065f);
	circle(0.1f, -0.5f, .065f);
	circle(0.2f, -0.4f, .065f);
	circle(0.05f, -0.63f, .05f);
	glFlush();
}

void cup(){
	glColor3ub(255,245,227);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-.27f,-.7f);
	glVertex2f(.27f,-.7f);
	glVertex2f(-0.4f,0.2f);
	glVertex2f(0.4f,0.2f);
	glEnd();
}

void lid(){
	glColor3ub(196, 221, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.5f, 0.3f); // left corner
	glVertex2f(0.5f, 0.3f); // right corner
	glVertex2f(0.5f, 0.2f); // bottom right corner
	glVertex2f(-0.5f, 0.2f); // bottom left corner
	glEnd();
}

void straw(){
	glColor3ub(249,227,208);
	glBegin(GL_QUADS);
	glVertex2f(-0.05f, 0.6f); // left corner
	glVertex2f(0.05f, 0.6f); // right corner
	glVertex2f(0.05f, -0.6f); // bottom right corner
	glVertex2f(-0.05f, -0.6f); // bottom left corner
	glEnd();
}

void liquid(){
	glColor3ub(240,200,140);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-.27f,-.7f);
	glVertex2f(.27f,-.7f);
	glVertex2f(-0.372f,0.0f);
	glVertex2f(0.372f,0.0f);
	glEnd();
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

