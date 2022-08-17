#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void tape();
void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Video Tape");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	tape();
	
	//center base -- front
	glColor3ub(255, 255, 255);
	circle(-0.1f, 0.0f, .65f);
	
	glColor3ub(0,0,0);
	circle(-0.1f, 0.35f, .2f); // top
	circle(-0.1f, -0.35f, .2f); //bottom
	circle(-0.45f, 0.0f, .2f); //left
	circle(0.25f, 0.0f, .2f); //right
	circle(-0.1f, 0.0f, .05f); //center
	
	glFlush();
}

void tape(){
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2f(-0.15f, -0.53f); // left corner
	glVertex2f(0.73f, -0.53f); // right corner
	glVertex2f(0.73f, -0.649f); // bottom right corner
	glVertex2f(-0.15f, -0.649f); // bottom left corner
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
