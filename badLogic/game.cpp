#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <ctime>
#include <string>
#include <unordered_map>
#include "physicsEngine.h"
#include <iostream>
using namespace sf;

int main()
{

std::unordered_map<std::string, float> ball = {
        {"shape", 1.0},
        {"x", 200},
        {"y", 200},
        {"radius", 20.0},
        {"static", 0.0}
};

std::unordered_map<std::string, float> ground = {
        {"shape", 2.0},
        {"x", 0.0},
        {"y", 370.0},
        {"width", 400.0},
        {"height", 30.0},
        {"static", 1.0}
};
    float pin = clock();
    RenderWindow window(VideoMode(400, 400), "Gravity Demo");
    CircleShape player;
    player.setPosition(ball["x"], ball["y"]);
    player.setRadius(ball["radius"]); 
    player.setFillColor(Color::Green);

    float ballGravity = gravity;//multiply gravity by time1??

    RectangleShape ground_1;
    ground_1.setPosition(ground["x"], ground["y"]);
    ground_1.setSize(Vector2f(ground["width"],ground["height"]));
    ground_1.setFillColor(Color::Blue);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

	collision(ball, ground, pin);

	//if (ball.getPosition().y+(ball.getRadius()*2) >= ground.getPosition().y) {
	//	ballGravity = 0.0;
	//}
	player.setPosition(player.getPosition().x, player.getPosition().y-ballGravity);
	window.clear();
        window.draw(player);
	window.draw(ground_1);
        window.display();
    }

    return 0;
}
           

