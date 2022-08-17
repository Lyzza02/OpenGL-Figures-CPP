#include<GL/glut.h>
#include<GL/freeglut_ext.h>
#include<iostream>

using namespace std;

void display();
void container();
void lid();
void text1();
void text2();
void label();

void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Jar");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	container();
	lid();
	label();
	text1();
	text2();
	
	glFlush();
}

void container(){
	glColor3ub(168,41,83);
	glBegin(GL_QUADS);
	
	//main body
	glVertex2f(-0.4f, 0.2f); // left corner
	glVertex2f(0.4f, 0.2f); // right corner
	glVertex2f(0.4f, -0.5f); // bottom right corner
	glVertex2f(-0.4f, -0.5f); // bottom left corner
	
	//lower
	glVertex2f(-0.4f, -0.5f); // left corner
	glVertex2f(0.4f, -0.5f); // right corner
	glVertex2f(0.3f, -0.6f); // bottom right corner
	glVertex2f(-0.3f, -0.6f); // bottom left corner
	
	//upper
	glVertex2f(-0.3f, 0.3f); // left corner
	glVertex2f(0.3f, 0.3f); // right corner
	glVertex2f(0.4f, 0.2f); // bottom right corner
	glVertex2f(-0.4f, 0.2f); // bottom left corner
	
	glEnd();
}

void lid(){
	glColor3ub(228, 187, 151);
	glBegin(GL_QUADS);
	glVertex2f(-0.4f, 0.4f); // left corner
	glVertex2f(0.4f, 0.4f); // right corner
	glVertex2f(0.4f, 0.3f); // bottom right corner
	glVertex2f(-0.4f, 0.3f); // bottom left corner
	glEnd();
}

void text1(){
	const unsigned char str[100] = "Strawberry";
	glColor3ub(255, 255, 255);
	glRasterPos2f(-0.3, -0.1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, str);
}

void text2(){
	const unsigned char str[100] = "Jam";
	glColor3ub(255, 255, 255);
	glRasterPos2f(-0.07, -0.23);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, str);
}

void label(){
	glColor3ub(211, 167, 108);
	glBegin(GL_QUADS);
	glVertex2f(-0.35f, 0.05f); // left corner
	glVertex2f(0.35f, 0.05f); // right corner
	glVertex2f(0.35f, -0.3f); // bottom right corner
	glVertex2f(-0.35f, -0.3f); // bottom left corner	
	glEnd();
}

