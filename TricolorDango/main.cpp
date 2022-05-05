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
   glutCreateWindow("Tricolor Dango");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	stick();
	
	//center
	glColor3ub(255,255,241);
	circle(0.0f, 0.2f, .15f);
	
	//lower
	glColor3ub	(149,180,126);
	circle(0.0f, -0.1f, .15f);
	
	//upper
	glColor3ub(255,217,211);
	circle(0.0f, 0.5f, .15f);
	
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
	glLineWidth(3);
	glColor3ub(226, 159, 97);
	glBegin(GL_LINES);
	glVertex3f(0.0, -0.1, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glEnd();
}

