DIR := ./src

compil:
	@g++ -o "bin/Debug/Implémentation SOIL" obj/Debug/src/*.o \
	-lglut -lGL -lGLU -lSOIL

main: $(DIR)/main.cpp
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(DIR)/main.cpp -o obj/Debug/src/main.o

block: $(DIR)/Block.cpp
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(DIR)/Block.cpp -o obj/Debug/src/Block.o


camera: $(DIR)/Camera.cpp
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(DIR)/Camera.cpp -o obj/Debug/src/Camera.o

map: $(DIR)/Map.cpp
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(DIR)/Map.cpp -o obj/Debug/src/Map.o

robot: $(DIR)/Robot.cpp
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(DIR)/Robot.cpp -o obj/Debug/src/Robot.o 

tree: $(DIR)/Tree.cpp
	@g++ -Wall -Wextra -fexceptions -g -Iinclude -Iinclude -c $(DIR)/Tree.cpp -o obj/Debug/src/Tree.o 

launch:
	@./"bin/Debug/Implémentation SOIL"

all:
	@echo "Compiling"
	@make main block camera map robot tree compil launch
