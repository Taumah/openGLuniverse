openGL:
	@g++ src/*/*.cpp src/*.cpp  header/*/*.h header/*.h -lglut -lGL -lGLU -o bin/programme.out 

launch:	
	@./bin/programme.out

all: openGL launch