#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <vector>
using namespace std;



void drawCube(double height, double width, double depth, double xOff, double yOff, double zOff){
	// WireFrame Cube
  // GL_LINES
  glBegin(GL_LINES);
	// front of cube
	//glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
	glVertex3f( width + xOff, height + yOff, depth + zOff);		// Top Right Of The Quad (Front)
	glVertex3f(0 + xOff, height + yOff, depth + zOff);		// Top Left Of The Quad (Front)
	
	glVertex3f(0 + xOff, height + yOff, depth + zOff);	
	glVertex3f(0 + xOff, 0 + yOff, depth + zOff);
	
	glVertex3f(width + xOff, height + yOff, depth + zOff);	
	glVertex3f(width + xOff, 0 + yOff, depth + zOff);
		
	glVertex3f(width + xOff,0 + yOff, depth + zOff);		// Bottom Left Of The Quad (Front)
	glVertex3f(0 + xOff,0 + yOff, depth + zOff);		// Bottom Right Of The Quad (Front)
	
	// Left side of cube
	
	glVertex3f(0 + xOff, height + yOff, depth + zOff);		// Top Right Of The Quad (Left)
	glVertex3f(-0 + xOff, height + yOff,-0 + zOff);		// Top Left Of The Quad (Left)
	glVertex3f(-0 + xOff,-0 + yOff,-0 + zOff);		// Bottom Left Of The Quad (Left)
	glVertex3f(-0 + xOff,-0 + yOff, depth + zOff);
	
	// Right side of cube
	
	glVertex3f( width + xOff, height + yOff,-0 + zOff);	        // Top Right Of The Quad (Right)
	glVertex3f( width + xOff, height + yOff, depth + zOff);		// Top Left Of The Quad (Right)
	glVertex3f( width + xOff,-0 + yOff, depth + zOff);		// Bottom Left Of The Quad (Right)
	glVertex3f( width + xOff,-0 + yOff,-0 + zOff);
	
	// Back of Cube
	
	glVertex3f( width + xOff, height + yOff, -0 + zOff);		// Top Right Of The Quad (Front)
	glVertex3f(-0 + xOff, height + yOff, -0 + zOff);		// Top Left Of The Quad (Front)
	
	glVertex3f(-0 + xOff, height + yOff, -0 + zOff);	
	glVertex3f(-0 + xOff, -0 + yOff, -0 + zOff);
	
	glVertex3f(width + xOff, height + yOff, -0 + zOff);	
	glVertex3f(width + xOff, -0 + yOff, -0 + zOff);
		
	glVertex3f(-0 + xOff,-0 + yOff, -0 + zOff);		// Bottom Left Of The Quad (Front)
	glVertex3f( width + xOff,-0 + yOff, -0 + zOff);	
	
    glEnd();

}

//ToDo: make doors work
void makeRoom(double width, double height, double depth, double xMiddle, double yMiddle, double zMiddle, bool north, bool south, bool west, bool east){
	double xStart = xMiddle - width/2;
	double yStart = yMiddle - height/2;
	double zStart = zMiddle - depth/2;

	for (int i = 0; i < depth; i++){
		// Draw the front and back wall of the room
		if (i == 0 || i == depth - 1){
			for (int j = 0; j < height; j++){
				for (int k = 0; k< width; k++){
					if ((j == 0 || j == 1) && k == width/2 && north && i == depth -1){
						cout << "This happened \n";
					}
					else if ((j == 0 || j == 1) && k == width/2 && south && i == 0){
						cout << "This happened \n";
					}
					else{
						drawCube(1,1,1,xStart + k, yStart + j, zStart + i);
					}
				}
			}
		}
		else{
			for (int k = 0; k< width; k++){
				//Draw the side walls of the room
				if (k == 0 || k == width - 1){
					for (int j = 0; j < height; j++){
						drawCube(1,1,1,xStart+k,yStart+j,zStart+i);
					}
				}
				//Else draw floor and roof
				else{
					drawCube(1,1,1,xStart + k, yStart, zStart + i);
					drawCube(1,1,1,xStart + k, yStart + height - 1, zStart + i);
				}
			}
		}
	}

}

void makeHall(double width, double height, double depth, double xMiddle, double yMiddle, double zMiddle){
	double xStart = xMiddle - width/2;
	double yStart = yMiddle - height/2;
	double zStart = zMiddle - depth/2;

	for (int i = 0; i < depth; i++){
		if (i == 0 || i == depth - 1){
			for (int j = 0; j < height; j++){
				for (int k = 0; k< width; k++){
					drawCube(1,1,1,xStart + k, yStart + j, zStart + i);
				}
			}
		}
		else{
			for (int k = 0; k< width; k++){
				drawCube(1,1,1,xStart + k, yStart, zStart + i);
				drawCube(1,1,1,xStart + k, yStart + height - 1, zStart + i);
			}
		}
	}

}


void drawGround(double xStart, double zStart){
	// First take the ceiling of the inputs
	xStart = ceil(xStart);
	zStart = ceil(zStart);
	cout << xStart << " " << zStart << "\n";
	glBegin(GL_LINES);
	// Will draw a 50 by 50 area of squares as the ground
	for (int i = -25; i < 25; i++){
		for (int j = -25; j < 25; j++){
			// Draw half of each square in order to not repeat vertices
			glVertex3f( i - xStart, 0,j - zStart);
			glVertex3f( i - xStart + 1, 0,j - zStart);
			glVertex3f( i - xStart, 0,j - zStart);
			glVertex3f( i - xStart, 0,j - zStart - 1);
		}
	}
	glEnd();

}


