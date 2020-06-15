compil:
	g++ -o "bin/Debug/Implémentation SOIL" obj/Debug/src/Block.o obj/Debug/src/Camera.o obj/Debug/src/main.o obj/Debug/src/Map.o \
	lib/glut32.lib lib/libSOIL.a -lglut -lGL -lGLU -lSOIL

main:
	g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c "/home/thomas/Bureau/ImplВmentation SOIL/src/main.cpp" -o obj/Debug/src/main.o

block:
	g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c "/home/thomas/Bureau/ImplВmentation SOIL/src/Block.cpp" -o obj/Debug/src/Block.o


camera:
	g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c "/home/thomas/Bureau/ImplВmentation SOIL/src/Camera.cpp" -o obj/Debug/src/Camera.o

map:
	g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c "/home/thomas/Bureau/ImplВmentation SOIL/src/Map.cpp" -o obj/Debug/src/Map.o

launch:
	./"bin/Debug/Implémentation SOIL"
