#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();
void circle(GLfloat x, GLfloat y, GLfloat radius);
void windowSquares();
void doors();
void windowRectangle();
void buildings();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Building");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	buildings();
	doors();
	windowSquares();
	windowRectangle();
	glFlush();
}

void buildings(){
	glBegin(GL_QUADS);
	//left building
	glColor3ub(165,165,165);
	glVertex2f(-0.6f, 0.1f); // left corner
	glVertex2f(0.0f, 0.1f); // right corner
	glVertex2f(0.0f, -0.7f); // bottom right corner
	glVertex2f(-0.6f, -0.7f); // bottom left corner
	
	//right building
	glColor3ub(85, 132, 172);
	glVertex2f(0.0f, 0.7f); // left corner
	glVertex2f(0.6f, 0.7f); // right corner
	glVertex2f(0.6f, -0.7f); // bottom right corner
	glVertex2f(0.0f, -0.7f); // bottom left corner
	glEnd();
}

void doors(){
	glBegin(GL_QUADS);
	//door -- smaller building
	glColor3ub(127, 181, 255);
	glVertex2f(-0.5f, -0.55f); // left corner
	glVertex2f(-0.1f, -0.55f); // right corner
	glVertex2f(-0.1f, -0.7f); // bottom right corner
	glVertex2f(-0.5f, -0.7f); // bottom left corner
	
	//door -- taller building
	glColor3ub(149, 209, 204);
	glVertex2f(0.15f, -0.45f); // left corner
	glVertex2f(0.45f, -0.45f); // right corner
	glVertex2f(0.45f, -0.7f); // bottom right corner
	glVertex2f(0.15f, -0.7f); // bottom left corner
	
	glEnd();
}
void windowSquares(){
	glColor3ub(196, 221, 255);
	GLfloat winSquare[] = {
		//windows upper part
		-0.55f, 0.05f, 0.0f,
		-0.35f, 0.05f, 0.0f,
		-0.35f, -0.15f, 0.0f,
		-0.55f, -0.15f, 0.0f,
		
		-0.25f, 0.05f, 0.0f,
		-0.05f, 0.05f, 0.0f,
		-0.05f, -0.15f, 0.0f,
		-0.25f, -0.15f, 0.0f,
		
		//window lower part
		-0.55f, -0.25f, 0.0f,
		-0.35f, -0.25f, 0.0f,
		-0.35f, -0.45f, 0.0f,
		-0.55f, -0.45f, 0.0f,
		
		-0.25f, -0.25f, 0.0f,
		-0.05f, -0.25f, 0.0f,
		-0.05f, -0.45f, 0.0f,
		-0.25f, -0.45f, 0.0f
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, winSquare);
	glDrawArrays(GL_QUADS,-0.55,16);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void windowRectangle(){
	glColor3ub(250, 255, 175);
	
	GLfloat winRectangle[] = {
		0.05f, 0.65f, 0.0f,
		0.55f, 0.65f, 0.0f,
		0.55f, 0.5f, 0.0f,
		0.05f, 0.5f, 0.0f,
		
		0.05f, 0.45f, 0.0f,
		0.55f, 0.45f, 0.0f,
		0.55f, 0.3f, 0.0f,
		0.05f, 0.3f, 0.0f,
		
		0.05f, 0.25f, 0.0f,
		0.55f, 0.25f, 0.0f,
		0.55f, 0.1f, 0.0f,
		0.05f, 0.1f, 0.0f,
		
		0.05f, 0.05f, 0.0f,
		0.55f, 0.05f, 0.0f,
		0.55f, -0.1f, 0.0f,
		0.05f, -0.1f, 0.0f,
		
		0.05f, -0.15f, 0.0f,
		0.55f, -0.15f, 0.0f,
		0.55f, -0.3f, 0.0f,
		0.05f, -0.3f, 0.0f
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, winRectangle);
	glDrawArrays(GL_QUADS,0.05,20);
	glDisableClientState(GL_VERTEX_ARRAY);
}
