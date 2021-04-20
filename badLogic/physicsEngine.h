#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>



using namespace sf;

struct Collider {
    int shape;
    float x;
    float y;
    float radius;
    float radius2;
    bool isStatic;
};

bool collision(Collider obj1,Collider obj2, float changeT);

float mid(float a, float b, float c);

inline float gravity = -.0098;


