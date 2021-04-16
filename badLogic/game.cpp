#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include "physicsEngine.h"

using namespace sf;

Clock clock;
Time time1 = clock.restart();

time1 = clock.restart();

//create ball object with shape, position, radius, static, color, mass attributes
//create rect object with shape, position, width, height, static, color, mass attributes

int main()
{
    RenderWindow window(VideoMode(400, 400), "Gravity Demo");
    CircleShape ball;
    ball.setPosition(200, 200);
    ball.setRadius(20.0); 
    ball.setFillColor(Color::Green);

    float ballGravity = gravity;//multiply gravity by time1??

    RectangleShape ground;
    ground.setPosition(0,370);
    ground.setSize(Vector2f(400,30));
    ground.setFillColor(Color::Blue);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

	//call collision(ball, ground, time1) from engine

	//if (ball.getPosition().y+(ball.getRadius()*2) >= ground.getPosition().y) {
	//	ballGravity = 0.0;
	//}
	ball.setPosition(ball.getPosition().x, ball.getPosition().y-ballGravity);
	window.clear();
        window.draw(ball);
	window.draw(ground);
        window.display();
    }

    return 0;
}
           

