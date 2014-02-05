all:
	g++ -lglut -lGL -lGLU -Wall -W fpsTest.cpp -o fpsTest
clean:
	rm -rf *o fpsTest
