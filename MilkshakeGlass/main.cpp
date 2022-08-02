#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void cup1();
void cup2();
void liquid();
void cube1();
void cube2();
void cube3();
void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Milkshake Glass");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4ub(170,126,78,255);
	circle(0.45f, 0.45f, .25f);
	glColor4ub(183,146,99,255);
	circle(0.45f, 0.45f, .2f);
	
	
	cup1();
	cup2();
	liquid();
	cube1();
	cube2();
	cube3();
	
	glColor4ub(199,167,134,255);
	circle(0.0f, -0.6f, .05f);
	
	glFlush();
}

void cup1(){
	glColor4ub(212,197,165,255);
	glBegin(GL_TRIANGLES);
	glVertex2f(-.45f,0.45f); //left
	glVertex2f(.45f,0.45f); //right
	glVertex2f(0.0f,-0.6f); //center
	glEnd();
}

void cup2(){
	glColor4ub(212,197,165,255);
	glBegin(GL_TRIANGLES);
	glVertex2f(-.25f,-0.75f); //left
	glVertex2f(.25f,-0.75f); //right
	glVertex2f(0.0f,-0.6f); //center
	glEnd();
}

void liquid(){
	glColor4ub(190,68,108,255);
	glBegin(GL_TRIANGLES);
	glVertex2f(-.35f,0.35f); //left
	glVertex2f(.35f,0.35f); //right
	glVertex2f(0.0f,-0.5f); //center
	glEnd();
}

void cube1(){
	glColor4ub(136,177,176,255);
	glBegin(GL_QUADS);
	glVertex2f(-0.2f, 0.3f); // left corner
	glVertex2f(0.0f, 0.3f); // right corner
	glVertex2f(0.0f, 0.1f); // bottom right corner
	glVertex2f(-0.2f, 0.1f); // bottom left corner
	glEnd();
}

void cube2(){
	glColor4ub(136,177,176,255);
	glBegin(GL_QUADS);
	glVertex2f(0.03f, 0.0f); // left corner
	glVertex2f(0.13f, 0.0f); // right corner
	glVertex2f(0.13f, -0.1f); // bottom right corner
	glVertex2f(0.03f, -0.1f); // bottom left corner
	glEnd();
}

void cube3(){
	glColor4ub(136,177,176,255);
	glBegin(GL_QUADS);
	glVertex2f(0.1f, 0.25f); // left corner
	glVertex2f(0.2f, 0.25f); // right corner
	glVertex2f(0.2f, 0.15f); // bottom right corner
	glVertex2f(0.1f, 0.15f); // bottom left corner
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

