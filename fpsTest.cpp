//#include <GLUT/glut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include "makeGeometry.cpp"
#include "object.cpp"

//#include "Project.h"
using namespace std;


#define checkImageWidth 64
#define checkImageHeight 64



static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;

// Movement constants
double xMove;
double yMove;
double zMove;
double xRotate;
double yRotate;
vector<Object> objects;


void init(void)
{
    //glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    
    
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImage);
                 
    // Initialize objects
    Object* tree1 = new Object("Tree",10,10);
    objects.push_back(*tree1);
                 
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(.5,.5,.5);
	//glLoadIdentity();
	/*
  drawCube(1,1,1,0,0,0);
  drawCube(1,1,1,0,0,1);
  drawCube(1,1,1,0,1,0);
	drawCube(1,1,1,1,0,0);
	*/
	makeRoom(5,5,5,0,0,0, true, true, false, false);
	makeHall(5,6,6,5,0,0);
	makeHall(10,6,6,10,0,0);
	
	// Function to draw the (flat) ground layer of cubes
	drawGround(xMove,zMove);
	
	// Now draw all objects in the scene
	for (int i = 0; i < objects.size(); i++){
		cout << objects[i].getType() << "\n";
		objects[i].draw();
	}
	/*
	glBegin(GL_LINES);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0,0,0);
	glVertex3f(-1,0,0);
	*/
	//glEnd();
  glFlush();

	glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
	glRotatef(yRotate,0,1,0);   
	glRotatef(xRotate,1,0,0); 
// 0 0 -3.6
	
  glTranslatef(xMove, yMove, zMove);

	//glRotatef(yRotate,0,1,0);   
	//glRotatef(xRotate,1,0,0);
	
    //glDisable(GL_TEXTURE_2D);

	//glFlush();
}


void reshape(int w, int h)
{
    glViewport(0.0, 0.0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	// 1, 30
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 200.0);
   
    
}

void keyboard (unsigned char key, int x, int y)
{	
	// Dummy stuff
	x = y;
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'w':
        	zMove = zMove + .1;
        	//cout << "Ymove: " << yMove << "\n";
        	glutPostRedisplay();
        	break;
        case 's':
        	zMove = zMove - .1;
        	//cout << "Ymove: " << yMove << "\n";
        	glutPostRedisplay();
        	break;
        case 'a':
        	xMove = xMove + .1;
        	//cout << "Xmove: " << xMove << "\n";
        	glutPostRedisplay();
        	break;
        case 'd':
        	xMove = xMove - .1;
        	//cout << "Xmove: " << xMove << "\n";
        	glutPostRedisplay();
        	break;
				case 'm':
        	yMove = yMove + .1;
        	//cout << "Ymove: " << yMove << "\n";
        	glutPostRedisplay();
        	break;
				case 'n':
        	yMove = yMove - .1;
        	//cout << "Ymove: " << yMove << "\n";
        	glutPostRedisplay();
        	break;

        case 'i':
        	xRotate = xRotate - 5;
        	glutPostRedisplay();
        	break;
        case 'j':
        	yRotate = yRotate - 5;
        	glutPostRedisplay();
        	break;
				case 'k':
        	xRotate = xRotate + 5;
        	glutPostRedisplay();
        	break;
				case 'l':
        	yRotate = yRotate + 5;
        	glutPostRedisplay();
        	break;
        default:
            break;
    }
}



int main(int argc, char** argv)
{
	// Initialize movement variables
	xMove = 0;
	yMove = -1;
	zMove = -1;
	yRotate = 0;
	xRotate = 0;
	
	
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(150, 150);
	glutCreateWindow(argv[0]);
	// Load 3D Texture
	//glGenTextures(1, &texture3D);	


	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0; 
}
