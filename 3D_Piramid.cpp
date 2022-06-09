#include <stdlib.h>
#include <glut.h>

GLfloat R=0;
void spin(){
	R=R+0.005;
	if(R>360)
		R=0;
	glutPostRedisplay();
}

void pyramid(void){
	//Bagian Alas
	glBegin(GL_POLYGON);
	  glColor3f(1,1,1);   
      glVertex3f(0.5f, -0.5f, -0.5f);
      glVertex3f(-0.5f, -0.5f, -0.5f);
      glVertex3f(-0.5f, -0.5f, 0.5f);
	  glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd;

	//Bagian sisi
	glBegin(GL_TRIANGLES);
	  //Bagian depan
      glColor3f(1,1,0);   
      glVertex3f(0.0f, 0.5f, 0.0f);
      glVertex3f(-0.5f, -0.5f, 0.5f);
      glVertex3f(0.5f, -0.5f, 0.5f);

	  //Bagian Kanan
	  glColor3f(1,0,1);   
      glVertex3f(0.0f, 0.5f, 0.0f);
      glVertex3f(0.5f, -0.5f, 0.5f);
      glVertex3f(0.5f, -0.5f, -0.5f);

	  //Bagian Belakang
	  glColor3f(0,1,1);   
      glVertex3f(0.0f, 0.5f, 0.0f);
      glVertex3f(0.5f, -0.5f, -0.5f);
      glVertex3f(0.5f, -0.5f, -0.5f);

	  //Bagian Kiri
	  glColor3f(1,0,1);   
      glVertex3f(0.0f, 0.5f, 0.0f);
      glVertex3f(-0.5f, -0.5f, -0.5f);
      glVertex3f(0.5f, -0.5f, 0.5f);

	glEnd();
	glFlush();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   glRotated(R,1,1,0);
   pyramid();
   glutSwapBuffers();
}

void main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Fikri|3D Pyramid");
   glutIdleFunc(spin);
   glEnable(GL_DEPTH_TEST);
   glutDisplayFunc(display);
   glutMainLoop();
}