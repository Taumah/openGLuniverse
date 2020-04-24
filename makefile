openGL:
	@g++ src/*/*.cpp src/*.cpp  header/*/*.hpp header/*.hpp -lglut -lGL -lGLU -o bin/programme.out 

launch:	
	@./bin/programme.out

all: openGL launch