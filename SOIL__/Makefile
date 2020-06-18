dir := /home/thomas/CLionProjects/openGLuniverse/SOIL__/src

compil:
	@g++ -o "bin/Debug/Implémentation SOIL" obj/Debug/src/*.o \
	lib/glut32.lib lib/libSOIL.a -lglut -lGL -lGLU -lSOIL

main:
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(dir)/main.cpp -o obj/Debug/src/main.o

block:
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(dir)/Block.cpp -o obj/Debug/src/Block.o


camera:
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(dir)/Camera.cpp -o obj/Debug/src/Camera.o

map:
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(dir)/Map.cpp -o obj/Debug/src/Map.o

robot:
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(dir)/Robot.cpp -o obj/Debug/src/Robot.o 

tree:
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(dir)/Tree.cpp -o obj/Debug/src/Tree.o 

launch:
	@./"bin/Debug/Implémentation SOIL"

all:
	@echo "Compiling"
	@make main block camera map robot tree compil launch
