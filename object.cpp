#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>

// TODO: Make this an interface and create classes for each object type
class Object{
	private:
		string type;
		double xPosition;
		double zPosition;
	public:
		Object(string typeInput, double xInput, double zInput){
			type = typeInput;
			// For some reason the camera coordinates and the object coordinates are opposites, so just flip the sign
			xPosition = -xInput;
			zPosition = -zInput;
		}
		Object(){
		
		}
		~Object(){}
		
		string getType(){return type;}
		double getXPos(){return xPosition;}
		double getZPos(){return zPosition;}
		
		void draw(){
			//glBegin(GL_LINES);
			
			if (type == "Tree"){
				// Draw the trunk of the tree
				drawCube(1,1,1,xPosition,0,zPosition);
				drawCube(1,1,1,xPosition,1,zPosition);
				drawCube(1,1,1,xPosition,2,zPosition);
				// Draw the "leaves" of the tree, adjusting because the cube is drawn from its back-left corner (depending how you look at it)
				drawCube(1.5,2,2,xPosition - .5,3,zPosition - .5);
			}
			else{}
			
			
			//glEnd();
		}

};
