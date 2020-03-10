openGL:
	g++ src/*.cpp  header/*.h -lglut -lGL -lGLU -o bin/programme.out 

launch:	
	./bin/programme.out