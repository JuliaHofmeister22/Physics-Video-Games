//do physics
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <unordered_map>
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
template <typename T>
bool collision(T obj1,T obj2,float changeT){
	bool collision = false;
	if (obj1["shape"] == 1.0 and obj2["shape"] == 1.0){
		float dist = sqrt((obj1["x"] - obj2["x"])^2 +
				(obj1["y"] - obj2["y"])^2);
		if (dist<=obj1["radius"]+obj2["radius"]){
			collision = true;
			//force direction??
			//f_dir =(obj1.getPosition()-obj2.getPosition())/dist;
			//obj1_dir = f_dir;
			//obj2_dir = -f_dir;
		}
	}
	else if (obj1["shape"] == 2.0 and obj2["shape"]==2.0){
                Vector2f dist = (abs(obj1["x"]-obj2["x"]),
					abs(obj2["y"]-obj2["y"]));
                if (dist.x<=(obj1["width"]/2)+(obj2["width"]/2) and 
				dist.y<=(obj1["height"]/2) + (obj2["height"]/2)){
                        collision = true;
                }
        }
	else if (obj1["shape"] == 2.0 and obj2["shape"]==1.0){
                Vector2f dist = (abs(obj1["x"]-obj2["x"]),
                                        abs(obj2["y"]-obj2["y"]));
                if (dist.x<=(obj1["width"]/2)+obj2["radius"] and 
				dist <= (obj1["height"]/2 + obj2["radius"])){
                        collision = true;
                }
        }
	else if (obj1["shape"] == 1.0 and obj2["shape"]==2.0){
                Vector2f dist = (abs(obj1["x"]-obj2["x"]),
                                        abs(obj2["y"]-obj2["y"]));
                if (dist.x<=(obj2["width"]/2)+obj1["radius"] and
                                dist <= (obj2["height"]/2 + obj1["radius"])){
                        collision = true;
                }
        }
	return collision;
	//probably eventually return force and direction
}
