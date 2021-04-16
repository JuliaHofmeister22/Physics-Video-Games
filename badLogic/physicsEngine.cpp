//do physics
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
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
bool collision(obj1,obj2,changeT){
	collision = false;
	if (obj1.shape == "circle" and obj2.shape=="circle"){
		dist = sqrt((obj1.getPosition().x - obj2.getPosition().x)^2 +
				(obj1.getPosition().y - obj2.getPosition().y)^2)
		if (dist<=obj1.getRadius()+obj2.getRadius()){
			collision = true;
			//force direction??
			//f_dir =(obj1.getPosition()-obj2.getPosition())/dist;
			//obj1_dir = f_dir;
			//obj2_dir = -f_dir;
		}
	}
	else if (obj1.shape == "rect" and obj2.shape=="rect"){
                Vector2f dist = (abs(obj1.getPosition().x-obj2.getPosition().x),
					abs(obj2.getPosition().y-obj2.getPosition().y))
                if (dist.x<=(obj1.width/2)+(obj2.width/2) and 
				dist.y<=(obj1.height/2) + (obj2.height/2)){
                        collision = true;
                }
        }
	else if (obj1.shape == "rect" and obj2.shape=="circle"){
                Vector2f dist = (abs(obj1.getPosition().x-obj2.getPosition().x),
                                        abs(obj2.getPosition().y-obj2.getPosition().y))
                if (dist.x<=(obj1.width/2)+obj2.getRadius() and 
				dist <= (obj1.height/2 + obj2.getRadius())){
                        collision = true;
                }
        }
	else if (obj1.shape == "circle" and obj2.shape=="rect"){
                Vector2f dist = (abs(obj1.getPosition().x-obj2.getPosition().x),
                                        abs(obj2.getPosition().y-obj2.getPosition().y))
                if (dist.x<=(obj2.width/2)+obj1.getRadius() and
                                dist <= (obj2.height/2 + obj1.getRadius())){
                        collision = true;
                }
        }
	return collision;
	//probably eventually return force and direction
}
