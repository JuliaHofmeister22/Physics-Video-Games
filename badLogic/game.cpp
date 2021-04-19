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

    /*Collider ball2;
    ball2.shape=0;
    ball2.x=200.0;
    ball2.y=250.0;
    ball2.radius=20.0;
    ball2.radius2=0.0; 
    ball2.isStatic=true;*/

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

    /*CircleShape player2;
    player2.setPosition(ball2.x, ball2.y);
    player2.setRadius(ball2.radius); 
    player2.setFillColor(Color::Blue);*/

    float ballGravity = gravity;//multiply gravity by time1??

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
        };

        ball.y-=ballGravity;
	player.setPosition(ball.x, ball.y);
	window.clear();
        window.draw(player);
        //window.draw(player2);
	window.draw(ground_1);
        window.display();
    }

    return 0;
}
           

