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
    

    Collider ball;
    ball.shape=0;
    ball.x=200.0;
    ball.y=200.0;
    ball.radius=20.0;
    ball.radius2=0.0; 
    ball.isStatic=false;

    Collider ball2;
    ball2.shape=1;
    ball2.x=200.0;
    ball2.y=100.0;
    ball2.radius=20.0;
    ball2.radius2=20.0; 
    ball2.isStatic=false;

    Collider ground;
    ground.shape=1;
    ground.x=0.0;
    ground.y=370.0;
    ground.radius=400.0;
    ground.radius2=30.0;
    ground.isStatic=true;
    
    float pin = clock();
    RenderWindow window(VideoMode(400, 400), "Gravity Demo");

    CircleShape player;
    player.setPosition(ball.x, ball.y);
    player.setRadius(ball.radius); 
    player.setFillColor(Color::Green);

    RectangleShape player2;
    player2.setPosition(ball2.x, ball2.y);
    player2.setSize(Vector2f(ball2.radius,ball2.radius2));
    player2.setFillColor(Color::Red);

    float ballGravity = gravity;//multiply gravity by time1??
    float boxGravity = gravity;

    RectangleShape ground_1;
    ground_1.setPosition(ground.x, ground.y);
    ground_1.setSize(Vector2f(ground.radius,ground.radius2));
    ground_1.setFillColor(Color::Blue);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

	if (collision(ball, ground, pin)){
                ballGravity = 0.0;
        }

        if(collision(ball2, ball, pin)){
                boxGravity = 0.0;
        }
        ball2.y-=boxGravity;
        ball.y-=ballGravity;
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
           

