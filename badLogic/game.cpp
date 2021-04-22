#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <ctime>
#include <string>
#include <iostream>
#include "physicsEngine.h"

using namespace sf;

int main()
{
    
    Clock clock;

    Collider ball;
    ball.shape=0;
    ball.x=10.0;
    ball.y=200.0;
    ball.radius=20.0;
    ball.radius2=0.0; 
    ball.isStatic=false;
    ball.velocity_y = 1.0;
    ball.velocity_x = 1.0;
    ball.acceleration_y = gravity;
    ball.acceleration_x = 5.0;
    ball.mass = 5.0;

    Collider ball2;
    ball2.shape=0;
    ball2.x=200.0;
    ball2.y=100.0;
    ball2.radius=20.0;
    ball2.isStatic=false;
    ball2.velocity_y = 1.0;
    ball2.velocity_x = -1.0;
    ball2.acceleration_y = gravity;
    ball2.acceleration_x = -1.0;
    ball2.mass = 6.0;

    Collider ground;
    ground.shape=1;
    ground.x=0.0;
    ground.y=370.0;
    ground.radius=400.0;
    ground.radius2=30.0;
    ground.isStatic=true;
    ground.mass = 50.0;
    
    
    RenderWindow window(VideoMode(400, 400), "Gravity Demo");

    CircleShape player;
    player.setPosition(ball.x, ball.y);
    player.setRadius(ball.radius); 
    player.setFillColor(Color::Green);

    CircleShape player2;
    player2.setPosition(ball2.x, ball2.y);
    player2.setRadius(ball2.radius);
    player2.setFillColor(Color::Red);

    //float ballGravity = gravity;//multiply gravity by time1??
    float boxGravity = gravity;

    RectangleShape ground_1;
    ground_1.setPosition(ground.x, ground.y);
    ground_1.setSize(Vector2f(ground.radius,ground.radius2));
    ground_1.setFillColor(Color::Blue);

    //Collider colliders[3] = {ball, ball2, ground};
    /*colliders.push(ball);
    colliders.push(ball2);
    colliders.push(ground);*/
 
    //std::cout<<clock.getElapsedTime().asSeconds();
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        float DT=clock.getElapsedTime().asSeconds();
        
	if (collision(ball, ground)){
                collisions(ball,ground);
                //ball.velocity = ((ball.mass-ground.mass)/(ball.mass+ground.mass))*ball.velocity;

        }

        if (collision(ball2, ground)){
                collisions(ball2, ground);
                //ball.velocity_x = ball.velocity_x * 0.3;
                //ball.velocity = ((ball.mass-ground.mass)/(ball.mass+ground.mass))*ball.velocity;

        }

        if(collision(ball2, ball)){
                collisions(ball2,ball);
                //ball2.velocity= ((ball2.mass-ball.mass)/(ball2.mass+ball.mass))*ball2.velocity + (2*ball2.mass/(ball2.mass+ball.mass))*ball.velocity;
                
        }
        //collisions(colliders);
        if(ball.acceleration_y>gravity){
                ball.acceleration_y+=(gravity*DT);
        }
        if(ball2.acceleration_y>gravity){
                ball2.acceleration_y+=(gravity*DT);
        }
        ball.velocity_y = ball.velocity_y+(ball.acceleration_y*DT);
        ball.velocity_x = ball.velocity_x+(ball.acceleration_x*DT);
        ball.y-=ball.velocity_y*(DT);
        ball.x+=ball.velocity_x*(DT);
        ball2.velocity_y = ball2.velocity_y+(ball2.acceleration_y*DT);
        ball2.velocity_x = ball2.velocity_x+(ball2.acceleration_x*DT);
        ball2.y-=ball2.velocity_y*(DT);
        ball2.x+=ball2.velocity_x*(DT);
        clock.restart();
	player.setPosition(ball.x, ball.y);
        player2.setPosition(ball2.x,ball2.y);
	window.clear();
        window.draw(player);
        window.draw(player2);
	window.draw(ground_1);
        window.display();
    }

    return 0;
}
           

