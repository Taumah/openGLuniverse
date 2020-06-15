compil:
	g++ -o "bin/Debug/Implémentation SOIL" obj/Debug/src/Block.o obj/Debug/src/Camera.o obj/Debug/src/main.o obj/Debug/src/Map.o \
	lib/glut32.lib lib/libSOIL.a -lglut -lGL -lGLU -lSOIL

main:
	g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c "/home/thomas/CLionProjects/openGLuniverse/SOIL__/CLionProjects/openGLuniverse/SOIL__/src/main.cpp" -o obj/Debug/src/main.o

block:
	g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c "/home/thomas/CLionProjects/openGLuniverse/SOIL__/src/Block.cpp" -o obj/Debug/src/Block.o


camera:
	g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c "/home/thomas/CLionProjects/openGLuniverse/SOIL__/src/Camera.cpp" -o obj/Debug/src/Camera.o

map:
	g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c "/home/thomas/CLionProjects/openGLuniverse/SOIL__/src/Map.cpp" -o obj/Debug/src/Map.o

launch:
	./"bin/Debug/Implémentation SOIL"

all:
	make main block camera map compil launch