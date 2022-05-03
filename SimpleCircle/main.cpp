#include<GL/glut.h>
#include<iostream>

using namespace std;

void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Simple Circle");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
}

