#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <string>



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
    std::string material;
};

bool collision(Collider obj1,Collider obj2);

float mid(float a, float b, float c);

void collisions(Collider &c1, Collider &c2);

float material_velocity_y(Collider c);

float material_velocity_x(Collider c);

float static_absorb(Collider c);

void velocityUpdate(Collider &c1, float DT);

void velocity_cutoff(Collider &c1);

inline float gravity = -30;


