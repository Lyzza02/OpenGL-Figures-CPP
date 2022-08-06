#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void cup_bg();
void cup();
void liquid();
void stand();
void stick();
void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Elegant Martini Glass");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	stand();
	cup_bg();
	cup();
	liquid();
	stick();
	
	glColor3ub(0, 0, 0);
	circle(0.01f, 0.2f, .04f); // for the stick
	
	//bubbles
	glColor3ub(255,201,33);
	circle(0.15f, 0.35f, .03f);
	circle(0.25f, 0.4f, .03f);
	circle(0.22f, 0.33f, .02f);
	circle(0.2f, 0.5f, .03f);
	circle(0.3f, 0.55f, .03f);
	
	glFlush();
}

void cup_bg(){
	glColor3ub(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-.375f,0.41f); //left
	glVertex2f(.375f,0.41f); //right
	glVertex2f(0.0f,-0.02f); //center
	glEnd();
}

void cup(){
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLES);
	glVertex2f(-.35f,0.4f); //left
	glVertex2f(.35f,0.4f); //right
	glVertex2f(0.0f,0.0f); //center
	glEnd();
}

void liquid(){
	glColor3ub(255,201,33);
	glBegin(GL_TRIANGLES);
	glVertex2f(-.25f,0.3f); //left
	glVertex2f(.25f,0.3f); //right
	glVertex2f(0.0f,0.05f); //center
	glEnd();
}

void stand(){
	glColor3ub(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.0f,0.1f); //upper
	glVertex2f(0.0f,-0.5f); //lower
	
	glVertex2f(.13f,-0.5f); //left
	glVertex2f(-.13f,-0.5f); //right
	glEnd();
}

void stick(){
	glColor3ub(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-.25f,0.5f); //upper
	glVertex2f(0.05f,0.15f); //lower
	
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

