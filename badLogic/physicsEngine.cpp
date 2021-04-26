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

float material_velocity_x(Collider c){
	if (c.material == "rubber"){
		return 0.9;
	}
	else if (c.material == "plastic"){
		return 0.7;
	}
	else if (c.material == "metal"){
		return 0.3;
	}
}

float material_velocity_y(Collider c){
	if (c.material == "rubber"){
		return 0.5;
	}
	else if (c.material == "plastic"){
		return 0.3;
	}
	else if (c.material == "metal"){
		return 0.1;
	}
}

float static_absorb(Collider c){
	if (c.material == "hard"){
		return 0.9;
	}
	else if (c.material == "soft"){
		return 0.5;
	}
	else if (c.material == "sticky"){
		return 0.0;
	}
	else return 1.0;
}

void collisions(Collider &c1, Collider &c2){
	if(c1.isStatic){
		std::cout<<c2.x;
		float absorb = static_absorb(c1);
		if(c1.x<c2.x+c2.radius && c2.y+c2.radius<c1.y){							
			c2.y-=1;
			c2.velocity_y = -c2.velocity_y * material_velocity_y(c2)*absorb;
			c2.velocity_x = c2.velocity_x * material_velocity_x(c2);
		}
		else if(c1.x<c2.x+c2.radius && c2.y+c2.radius>c1.y && abs(c2.x-(c1.x+c1.radius))<1){							
			c2.x+=2;
			c2.velocity_y = c2.velocity_y * material_velocity_y(c2)*absorb;
			c2.velocity_x = -c2.velocity_x * material_velocity_x(c2);
			c2.acceleration_x = -c2.acceleration_x;
		}
		else if(c1.x<c2.x+c2.radius && c2.y+c2.radius>c1.y && c2.x+c2.radius<c1.x+c1.radius){							
			c2.y+=1;
			c2.velocity_y = -c2.velocity_y * material_velocity_y(c2)*absorb;
			c2.velocity_x = c2.velocity_x * material_velocity_x(c2);
		}
		else if(c1.x>c2.x+c2.radius && c2.y+c2.radius>c1.y){							
			c2.x-=1;
			c2.velocity_y = c2.velocity_y * material_velocity_y(c2)*absorb;
			c2.velocity_x = -c2.velocity_x * material_velocity_x(c2);
			c2.acceleration_x = -c2.acceleration_x; //because we don't want it going back that way
		}
		
	}
	else if(c2.isStatic){
		std::cout<<c1.x;
		float absorb = static_absorb(c2);
		if(c2.x<c1.x+c1.radius && c1.y+c1.radius<c2.y){							
			c1.y-=1;
			c1.velocity_y = -c1.velocity_y * material_velocity_y(c1)*absorb;
			c1.velocity_x = c1.velocity_x * material_velocity_x(c1);
		}
		else if(c2.x<c1.x+c1.radius && c1.y+c1.radius>c2.y && abs(c1.x-(c2.x+c2.radius))<1){							
			c1.x+=2;
			c1.velocity_y = c1.velocity_y * material_velocity_y(c1)*absorb;
			c1.velocity_x = -c1.velocity_x * material_velocity_x(c1);
			c1.acceleration_x = -c1.acceleration_x;
		}
		else if(c2.x<c1.x+c1.radius && c1.y+c1.radius>c2.y && c1.x+c1.radius<c2.x+c2.radius){							
			c1.y+=1;
			c1.velocity_y = -c1.velocity_y * material_velocity_y(c1)*absorb;
			c1.velocity_x = c1.velocity_x * material_velocity_x(c1);
		}
		else if(c2.x>c1.x+c1.radius && c1.y+c1.radius>c2.y){							
			c1.x-=1;
			c1.velocity_y = c1.velocity_y * material_velocity_y(c1)*absorb;
			c1.velocity_x = -c1.velocity_x * material_velocity_x(c1);
			c1.acceleration_x = -c1.acceleration_x; //because we don't want it going back that way
		}
		
	}
	else if(c1.shape==0 && c2.shape==0){
		if (c1.velocity_y == 0.0 && c1.velocity_x == 0.0){
			c1.velocity_y = c2.velocity_y*0.9;
			c1.velocity_x = c2.velocity_x*0.9;
			c1.acceleration_y = gravity;
			c1.acceleration_x = c2.acceleration_x*0.9;
			c2.velocity_y = 0.0;
			c2.velocity_x = 0.0;
			c2.acceleration_x = 0.0;
			c2.acceleration_y = 0.0;
		}
		else if (c2.velocity_y == 0.0 && c2.velocity_x == 0.0){
			c2.velocity_y = c1.velocity_y*0.9;
			c2.velocity_x = c1.velocity_x*0.9;
			c2.acceleration_y = gravity;
			c2.acceleration_x = c1.acceleration_x*0.9;
			c1.velocity_y = 0.0;
			c1.velocity_x = 0.0;
			c1.acceleration_x = 0.0;
			c1.acceleration_y = 0.0;
		}
		else{
			if(c1.y<c2.y){
				c1.y-=1;
			}else{
				c2.y-=1;
			}
			c1.velocity_y = -c1.velocity_y * 0.8;
			c1.velocity_x = c1.velocity_x * 0.5;
			c2.velocity_y = -c2.velocity_y * 0.8;
			c2.velocity_x = c2.velocity_x * 0.5;
		}
	}
	
}

bool collision(Collider obj1,Collider obj2){
	bool collision = false;
	if (obj1.shape== 0 and obj2.shape == 0){
		float dist = sqrt(pow((obj2.x+obj2.radius) - (obj1.x+obj1.radius),2) +
				pow((obj2.y+obj2.radius) - (obj1.y+obj1.radius),2));
		//std::cout << dist;
		if (dist<=obj1.radius+obj2.radius){
			collision = true;
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
				float px= mid(obj2.x+obj2.radius, obj1.x,obj1.x+obj1.radius);
				float py= mid(obj2.y+obj2.radius, obj1.y,obj1.y+obj1.radius2);
				float dist = sqrt(pow((obj2.x+obj2.radius) - px,2) +
				pow((obj2.y+obj2.radius) - py,2));
				/*std::cout<<px;
				std::cout<<" ";*/
                //float dist=(sqrt(pow(abs(obj2.x-px),2)),sqrt(pow(abs(obj2.y-py),2)));
				if (dist<=obj2.radius){
                        collision = true;
                }
        }
	else if (obj1.shape == 0 and obj2.shape==1){
				float px= mid(obj1.x+obj1.radius, obj2.x,obj2.x+obj2.radius);
				float py= mid(obj1.y+obj1.radius, obj2.y,obj2.y+obj2.radius2);
				float dist = sqrt(pow((obj1.x+obj1.radius)-px,2) +
				pow((obj1.y+obj1.radius)-py,2));
                /*Vector2f dist(sqrt(pow(abs(obj1.x-px),2)),
                                        sqrt(pow(abs(obj1.y-py),2)));*/
                if (dist<=obj1.radius){
                        collision = true;
                }
        }
	return collision;
	//probably eventually return force and direction
}

void velocityUpdate(Collider &c1, float DT){
	c1.velocity_y = c1.velocity_y+(-c1.acceleration_y*DT);
	c1.velocity_x = c1.velocity_x+(c1.acceleration_x*DT);
	c1.y+=c1.velocity_y*(DT);
	c1.x+=c1.velocity_x*(DT);
	if(c1.velocity_y==0 && c1.acceleration_y==0){
		c1.velocity_x*=0.95;
	}
}

void velocity_cutoff(Collider &c1){
	if(c1.velocity_y <10 && c1.velocity_y > -10){
		c1.velocity_y = 0;
		c1.acceleration_y =0;
		c1.y-=0.5;
	}
}
