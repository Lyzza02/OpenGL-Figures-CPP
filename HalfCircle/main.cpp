#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define PI 3.141592653589793238462643383279502884197

using namespace std;

void display();
void drawLeftCircle();
void drawRightHalfCircle();


int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Half Circle");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
	drawLeftCircle();
	drawRightHalfCircle();
}

void drawLeftCircle()   // the filled one
{
	glColor3ub(249,227,208);
    float radius = 0.7;
    float twoPI = 2 * PI;

    glBegin(GL_TRIANGLE_FAN);

    for (float i = PI; i <= twoPI; i += 0.001)
        glVertex2f((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glFlush();
}


void drawRightHalfCircle()  // the empty one
{
	glColor3ub(240,200,140);
    float radius = 0.7;
    float twoPI = 2 * PI;

    glBegin(GL_POINTS);

    for (float i = 0.0; i <= twoPI / 2; i += 0.001)
        glVertex2f((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glFlush();
}
