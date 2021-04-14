//do physics
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>

using namespace sf;

//gravity
Vector2 gravity=Vector2(0,-9.8);

//position
verlet(obj){
	obj.position = obj.position+obj.velocity*changeT+
		0.5*obj.acceleration*changeT^2;
	halfV = obj.velocity+0.5*obj.acceleration*changeT;
	//change acceleration??
	obj.velocity = halfV+0.5*obj.acceleration*changeT;
}

//applying forces and pulses-spring mass
//collision
//direction

