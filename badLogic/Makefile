INCLUDE_SFML = -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/
INCLUDE_SFML_EXTRAS = -lsfml-audio -lsfml-network
INCLUDE_GL = -lGL -lGLU -lglut -I/usr/include/GL/

.PHONY: all clean

logic: logic.cpp
	g++ -o logic logic.cpp $(INCLUDE_SFML)

advanced: advanced.cpp
	g++ -o advanced advanced.cpp $(INCLUDE_SFML) $(INCLUDE_SFML_EXTRAS)

opengl: opengl.cpp
	g++ -o opengl opengl.cpp $(INCLUDE_SFML) $(INCLUDE_GL)

all: helloworld advanced opengl

clean :
	rm -rf logic advanced opengl *.o
