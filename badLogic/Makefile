INCLUDE_SFML = -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/
INCLUDE_SFML_EXTRAS = -lsfml-audio -lsfml-network
INCLUDE_GL = -lGL -lGLU -lglut -I/usr/include/GL/
INCLUDE_PHYSICS = -I/usr/include/physicsEngine.h/
.PHONY: all clean


game: game.cpp
	g++ -o game game.cpp physicsEngine.cpp $(INCLUDE_SFML) $(INCLUDE_PHYSICS)


all: game

clean :
	rm -rf game *.o
