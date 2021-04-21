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
    float velocity;
    float acceleration;
    float mass;
};

bool collision(Collider obj1,Collider obj2, float changeT);
Vector2f direction(Collider obj1,Collider obj2,float changeT);

float mid(float a, float b, float c);

inline float gravity = -9.8;


