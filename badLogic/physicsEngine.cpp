//do physics
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <cmath>
#include "physicsEngine.h"
using namespace sf;

//position
//verlet(obj,changeT){
//	obj.position = obj.position+obj.velocity*changeT+
//		0.5*obj.acceleration*changeT^2;
//	halfV = obj.velocity+0.5*obj.acceleration*changeT;
//	//change acceleration??
//	obj.velocity = halfV+0.5*obj.acceleration*changeT;
//}

//still need to do direction and force based on collision
//do we multiply changeT by this at all?
bool collision(Collider obj1,Collider obj2,float changeT){
	bool collision = false;
	if (obj1.shape== 0 and obj2.shape == 0){
		float dist = sqrt(pow(obj2.x - obj1.x,2) +
				pow(obj2.y - obj1.y,2));
		//std::cout << dist;
		if (dist<=obj1.radius+obj2.radius){
			collision = true;
			//force direction??
			//f_dir =(obj1.getPosition()-obj2.getPosition())/dist;
			//obj1_dir = f_dir;
			//obj2_dir = -f_dir;
		}
	}
	else if (obj1.shape == 1 and obj2.shape==1){
                Vector2f dist(abs(obj2.x-obj1.x),abs(obj2.y-obj1.y));
                if (dist.x<=(obj1.radius/2)+(obj2.radius/2) and 
				dist.y<=(obj1.radius2/2) + (obj2.radius2/2)){
                        collision = true;
                }
        }
	else if (obj1.shape == 1 and obj2.shape==0){
                Vector2f dist(abs(obj2.x-obj1.x),
                                        abs(obj2.y-obj1.y));
                if (dist.x<=(obj1.radius/2)+obj2.radius and dist.y <= (obj1.radius2/2 + obj2.radius)){
                        collision = true;
                }
        }
	else if (obj1.shape == 0 and obj2.shape==1){
                Vector2f dist(sqrt(pow(abs(obj2.x-obj1.x),2)),
                                        sqrt(pow(abs(obj2.y-obj1.y),2)));
                if (dist.x<=(obj2.radius/2)+obj1.radius and dist.y <= (obj2.radius2/2) + obj1.radius){
                        collision = true;
                }
        }
	return collision;
	//probably eventually return force and direction
}
