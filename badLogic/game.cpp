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
    ball.x=200.0;
    ball.y=200.0;
    ball.radius=20.0;
    ball.radius2=0.0; 
    ball.isStatic=false;
    ball.velocity = 1.0;
    ball.acceleration = gravity;
    ball.mass = 15.0;

    Collider ball2;
    ball2.shape=1;
    ball2.x=200.0;
    ball2.y=100.0;
    ball2.radius=20.0;
    ball2.acceleration = gravity;
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

    RectangleShape player2;
    player2.setPosition(ball2.x, ball2.y);
    player2.setSize(Vector2f(ball2.radius,ball2.radius2));
    player2.setFillColor(Color::Red);

    //float ballGravity = gravity;//multiply gravity by time1??
    float boxGravity = gravity;

    RectangleShape ground_1;
    ground_1.setPosition(ground.x, ground.y);
    ground_1.setSize(Vector2f(ground.radius,ground.radius2));
    ground_1.setFillColor(Color::Blue);
 
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
        
	if (collision(ball, ground, DT)){
                ball.acceleration= -ball.acceleration;
                std::cout<<ball.velocity;
                std::cout<<" ";
                ball.y-=1;
                //ball.velocity = -ball.velocity;
                ball.velocity = ((ball.mass-ground.mass)/(ball.mass+ground.mass))*ball.velocity;
                std::cout<<ball.velocity;
                //ball_dir = force_direction(ball, ground, pin);

        }

        /*if(collision(ball2, ball, DT)){
                ball2.acceleration= -ball2.acceleration;
                ball.velocity = 0;
                ball.acceleration=0;
                //std::cout<<ball2.velocity;
                //std::cout<<" ";
                ball2.y-=1;
                ball2.velocity= ((ball2.mass-ball.mass)/(ball2.mass+ball.mass))*ball2.velocity + (2*ball2.mass/(ball2.mass+ball.mass))*ball.velocity;
                //std::cout<<ball2.velocity;
        }*/
        if(ball.acceleration>gravity){
                ball.acceleration+=(gravity*DT);
        }
        if(ball2.acceleration>gravity){
                ball2.acceleration+=(gravity*DT);
        }
        ball.velocity = ball.velocity+(ball.acceleration*DT);
        ball2.velocity = ball2.velocity+(ball2.acceleration*DT);
        ball2.y-=ball2.velocity*(DT);
        ball.y-=ball.velocity*(DT);
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
           

