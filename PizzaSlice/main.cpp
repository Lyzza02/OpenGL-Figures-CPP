#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void crust();
void cheese();
void shadowCircle();
void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Slice of Pizza");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	crust();
	cheese();
	
	//peperoni
	shadowCircle();
	glColor3ub(188, 45, 47);
	circle(0.2f, 0.2f, .08f);
	circle(-0.2f, 0.2f, .08f);
	circle(0.0f, -0.03f, .08f);
	circle(-0.03f, -0.3f, .07f);
	
	glFlush();
}

void crust(){
	glBegin(GL_TRIANGLES);
	
	//back
	glColor3ub(0,0,0);
	glVertex2f(-.48f,0.47f); //left
	glVertex2f(.48f,0.47f); //right
	glVertex2f(0.0f,-0.65f); //center
	
	
	//front
	glColor3ub(252, 212, 100);
	glVertex2f(-.45f,0.45f); //left
	glVertex2f(.45f,0.45f); //right
	glVertex2f(0.0f,-0.6f); //center
	glEnd();
}

void cheese(){
	glBegin(GL_TRIANGLES);
	
	//back
	glColor3ub(0,0,0);
	glVertex2f(-.43f,0.37f); //left
	glVertex2f(.43f,0.37f); //right
	glVertex2f(0.0f,-0.6f); //center
	
	//front
	glColor3ub(250, 176, 5);
	glVertex2f(-.41f,0.35f); //left
	glVertex2f(.41f,0.35f); //right
	glVertex2f(0.0f,-0.6f); //center
	glEnd();
}

void shadowCircle(){
	glColor3ub(0,0,0);
	circle(0.2f, 0.2f, .1f);
	circle(-0.2f, 0.2f, .1f);
	circle(0.0f, -0.03f, .1f);
	circle(-0.03f, -0.3f, .09f);
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

