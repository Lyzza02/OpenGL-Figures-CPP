#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void dots();
void circle(GLfloat x, GLfloat y, GLfloat radius);

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Cookie");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//center base -- back
	glColor3ub (39, 13, 11);
	circle(0.0f, 0.0f, .763f);
	
	//center base -- front
	glColor3ub(243, 179, 102);
	circle(0.0f, 0.0f, .75f);
	
	//chocolate
	glColor3ub(132, 86, 60);
	circle(-0.22f, 0.45f, .1f);
	circle(0.22f, 0.45f, .1f);
	
	circle(-0.5f, 0.0f, .1f);	
	circle(0.01f, 0.0f, .1f);
	circle(0.5f, 0.0f, .1f);
	
	circle(-0.22f, -0.4f, .1f);
	circle(0.22f, -0.4f, .1f);
	
	//dots
	dots();
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

void dots(){ 
	glLoadIdentity();
	glPointSize(4);
	glColor3ub(189, 140, 97);
	
	//Using Vertex Array
	GLfloat dot[] = {
		0.5f,0.3f,0.0f,
		0.22f,0.2f,0.0f,
		0.0f,0.3f,0.0f,
		0.0f,0.6f,0.0f,
		-0.22f,0.2f,0.0f,
		-0.5f,0.33f,0.0f,
		
		
		0.5f,-0.3f,0.0f,
		0.22f,-0.15f,0.0,
		0.0f,-0.3f,0.0f,
		0.0f,-0.6f,0.0f,
		-0.22f,-0.15f,0.0f,
		-0.5f,-0.33f,0.0f
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, dot);
	glDrawArrays(GL_POINTS,0.5,12);
	glDisableClientState(GL_VERTEX_ARRAY);
}
