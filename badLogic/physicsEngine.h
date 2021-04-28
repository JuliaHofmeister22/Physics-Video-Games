#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <string>
#include <ctime>



using namespace sf;

struct Collider {
    int shape;
    float x;
    float y;
    float radius;
    float radius2;
    bool isStatic;
    bool tempStatic;
    float velocity_y = 0;
    float velocity_x = 0;
    float acceleration_y;
    float acceleration_x;
    float mass;
    std::string material;
};
void do_collisions(std::queue<Collider> colliders, int size);

float mid(float a, float b, float c);

float material_velocity_y(Collider c);

float material_velocity_x(Collider c);

float static_absorb(Collider c);

void collisions(Collider &c1, Collider &c2);

bool collision(Collider obj1,Collider obj2);

void velocityUpdate(Collider &c1, float DT);

void velocity_cutoff(Collider &c1);

inline float gravity = -30;


