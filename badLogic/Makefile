INCLUDE_SFML = -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/
INCLUDE_SFML_EXTRAS = -lsfml-audio -lsfml-network
INCLUDE_GL = -lGL -lGLU -lglut -I/usr/include/GL/
COMPLIER_ARGS = -std=c++17
.PHONY: all clean


game: game.cpp
	g++ -o game game.cpp physicsEngine.cpp $(INCLUDE_SFML) $(COMPLIER_ARGS)


all: game

clean :
	rm -rf game *.o
