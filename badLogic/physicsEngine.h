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
    float velocity_y;
    float velocity_x;
    float acceleration_y;
    float acceleration_x;
    float mass;
};

bool collision(Collider obj1,Collider obj2);
Vector2f direction(Collider obj1,Collider obj2,float changeT);

float mid(float a, float b, float c);

void collisions(Collider &c1, Collider &c2);

inline float gravity = -30;


