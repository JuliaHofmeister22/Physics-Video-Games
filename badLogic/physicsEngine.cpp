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

float mid(float a, float b, float c){
	float re=0;
	if(a>b){
		if(a<c){
			return a;
		}
		if(a>c){
			if(b>c){
				return b;
			}
			else{
				return c;
			}
		}
	}
	else{
		if(a>c){
			return a;
		}
		else{
			if(c<b){
				return c;
			}
			else{
				return b;
			}
		}
	}
}

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
                Vector2f dist(abs((obj2.radius/2 + obj2.x)-(obj1.radius/2+obj1.x)),abs((obj2.radius2/2 + obj2.y)-(obj1.y+obj1.radius2/2)));
                if (dist.x<=(obj1.radius/2)+(obj2.radius/2) and 
				dist.y<=(obj1.radius2/2) + (obj2.radius2/2)){
                        collision = true;
                }
        }
	else if (obj1.shape == 1 and obj2.shape==0){
				float px= mid(obj2.x, obj1.x,obj1.x+obj1.radius);
				float py= mid(obj2.y+obj2.radius, obj1.y,obj1.y+obj1.radius2);
				float dist = sqrt(pow(obj2.x - px,2) +
				pow((obj2.y+obj2.radius) - py,2));
                //float dist=(sqrt(pow(abs(obj2.x-px),2)),sqrt(pow(abs(obj2.y-py),2)));
                if (dist<=obj2.radius and dist <= (obj2.radius)){
                        collision = true;
                }
        }
	else if (obj1.shape == 0 and obj2.shape==1){
				float px= mid(obj1.x, obj2.x,obj2.x+obj2.radius);
				float py= mid(obj1.y+obj1.radius, obj2.y,obj2.y+obj2.radius2);
				float dist = sqrt(pow(obj1.x-px,2) +
				pow((obj1.y+obj1.radius)-py,2));
                /*Vector2f dist(sqrt(pow(abs(obj1.x-px),2)),
                                        sqrt(pow(abs(obj1.y-py),2)));*/
                if (dist<=obj1.radius and dist<= obj1.radius){
                        collision = true;
                }
        }
	return collision;
	//probably eventually return force and direction
}
