openGL:
	@g++ src/*/*.cpp src/*.cpp  header/*/*.hpp header/*.hpp -lglut -lGL -lGLU -o bin/programme.out 

launch:	
	@./bin/programme.out

robot:
	@g++ src/*/*.cpp -Wall -Wextra -fexceptions -g -Iinclude -Iinclude src/robot.cpp  src/body.cpp src/head.cpp src/bodysides.cpp src/leftArm.cpp src/rightArm.cpp src/lowerBody.cpp src/leftLeg.cpp src/rightLeg.cpp src/hand.cpp \
	-lglut -lGL -lGLU -o SOIL__/obj/Debug/src/Robot.o

	
all: openGL launch