#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();
void plate();
void rice();
void seaweed();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Onigiri");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	plate();
	rice();
	seaweed();
	
	glFlush();
}

void plate(){
	glColor3ub(8, 129, 163);
	GLfloat plate_1 [] = {
		-0.7f, 0.0f, 0.0f,
		0.7f, 0.0f, 0.0f,
		0.7f, -0.1f, 0.0f,
		-0.7f, -0.1f, 0.0f,
		
		-0.6f, -0.12f, 0.0f,
		0.6f, -0.12f, 0.0f,
		0.6f, -0.2f, 0.0f,
		-0.6f, -0.2f, 0.0f,
		
		//leg of the plate
		0.4f, -0.2f, 0.0f,
		0.3f, -0.2f, 0.0f,
		0.3f, -0.35f, 0.0f,
		0.4f, -0.35f, 0.0f,
		
		-0.4f, -0.2f, 0.0f,
		-0.3f, -0.2f, 0.0f,
		-0.3f, -0.35f, 0.0f,
		-0.4f, -0.35f, 0.0f
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, plate_1);
	glDrawArrays(GL_QUADS,-0.7,16);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void rice(){
	glColor3ub(244, 231, 211);
	GLfloat triangle [] = {
		0.6f,0.0f, 0.0f,
		0.15f,0.0f, 0.0f,
		0.38f,.45f, 0.0f,
		
		-.25f,0.0f, 0.0f,
		.25f,0.0f, 0.0f,
		0.0f,.45f, 0.0f,
		
		-.6f,0.0f, 0.0f,
		-0.15f,0.0f, 0.0f,
		-0.38f,.45f, 0.0f
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangle);
	glDrawArrays(GL_TRIANGLES,0.6,9);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void seaweed(){
	glColor3ub(52, 100, 84);
	GLfloat rect_seaweed [] = {
		-0.1f, 0.1f, 0.0f,
		0.1f, 0.1f, 0.0f,
		0.1f, 0.0f, 0.0f,
		-0.1f, 0.0f, 0.0f,
		
		0.47f, 0.1f, 0.0f,
		0.28f, 0.1f, 0.0f,
		0.28f, 0.0f, 0.0f,
		0.47f, 0.0f, 0.0f,
		
		-0.47f, 0.1f, 0.0f,
		-0.28f, 0.1f, 0.0f,
		-0.28f, 0.0f, 0.0f,
		-0.47f, 0.0f, 0.0f
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, rect_seaweed);
	glDrawArrays(GL_QUADS,-0.1,12);
	glDisableClientState(GL_VERTEX_ARRAY);
}
