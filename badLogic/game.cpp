#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <ctime>
#include <string>
#include <iostream>
#include "physicsEngine.h"

/*things to do still
        finish velocity cut off
        check for side and bottom collisions
        force transfer between objects
        check all collisions through a list
        buttons?
        wind?
*/

using namespace sf;

int main()
{
    
    Clock clock;

    Collider ball;
    ball.shape=0;
    ball.x=10.0;
    ball.y=100.0;
    ball.radius=20.0;
    ball.radius2=0.0; 
    ball.isStatic=false;
    ball.velocity_y = 1.0;
    ball.velocity_x = 0.5;
    ball.acceleration_y = gravity;
    ball.acceleration_x = 5.0;
    ball.mass = 5.0;
    ball.material = "rubber";

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
    ball2.material = "plastic";

    Collider ball3;
    ball3.shape=0;
    ball3.x=300.0;
    ball3.y=100.0;
    ball3.radius=10.0;
    ball3.isStatic=false;
    ball3.velocity_y = 1.0;
    ball3.velocity_x = -1.0;
    ball3.acceleration_y = gravity;
    ball3.acceleration_x = -1.0;
    ball3.mass = 6.0;
    ball3.material = "metal";

    Collider ground;
    ground.shape=1;
    ground.x=0.0;
    ground.y=370.0;
    ground.radius=400.0;
    ground.radius2=30.0;
    ground.isStatic=true;
    ground.mass = 50.0;
    ground.material = "hard";

    Collider ledge;
    ledge.shape=1;
    ledge.x=160.0;
    ledge.y=300.0;
    ledge.radius=80.0;
    ledge.radius2=10.0;
    ledge.isStatic=true;
    ledge.mass = 20.0;
    ledge.material = "sticky";
    
    RenderWindow window(VideoMode(400, 400), "Gravity Demo");

    //Colors: gray=metal; green=rubber; red=plastic; orange=sticky
    Color gray(100,100,100);
    Color orange(255,165,100);

    CircleShape player;
    player.setPosition(ball.x, ball.y);
    player.setRadius(ball.radius); 
    player.setFillColor(Color::Green);

    CircleShape player2;
    player2.setPosition(ball2.x, ball2.y);
    player2.setRadius(ball2.radius);
    player2.setFillColor(Color::Red);

    CircleShape player3;
    player3.setPosition(ball3.x, ball3.y);
    player3.setRadius(ball3.radius);
    player3.setFillColor(gray);


    RectangleShape ground_1;
    ground_1.setPosition(ground.x, ground.y);
    ground_1.setSize(Vector2f(ground.radius,ground.radius2)); 
    ground_1.setFillColor(gray);

    RectangleShape ledge_1;
    ledge_1.setPosition(ledge.x, ledge.y);
    ledge_1.setSize(Vector2f(ledge.radius,ledge.radius2)); 
    ledge_1.setFillColor(orange);



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
                if(ball.velocity_y <15 && ball.velocity_y > -15){
                        ball.velocity_y = 0;
                        ball.acceleration_y =0;
                        ball.y-=0.5;
                        std::cout<<ball.velocity_x<<std::endl;
                        //std::cout<<ball.y+ball.radius*2<<std::endl;
                }
        }
        if (collision(ball2, ground)){
                collisions(ball2, ground);
                if(ball2.velocity_y <10 && ball2.velocity_y > -10){
                        ball2.velocity_y = 0;
                        ball2.acceleration_y =0;
                        ball2.y+=1;
                        //std::cout<<ball2.velocity_y<<std::endl;
                }
                //ball.velocity_x = ball.velocity_x * 0.3;
                //ball.velocity = ((ball.mass-ground.mass)/(ball.mass+ground.mass))*ball.velocity;
        }
        if (collision(ball3, ground)){
                collisions(ball3, ground);
                if(ball3.velocity_y <10 && ball3.velocity_y > -10){
                        ball3.velocity_y = 0;
                        ball3.acceleration_y =0;
                        ball3.y+=1;
                        //std::cout<<ball3.velocity_y<<std::endl;
                }
                //ball.velocity_x = ball.velocity_x * 0.3;
                //ball.velocity = ((ball.mass-ground.mass)/(ball.mass+ground.mass))*ball.velocity;
        }
        if (collision(ball2, ledge)){
                collisions(ball2, ledge);
                if(ball2.velocity_y <10 && ball2.velocity_y > -10){
                        ball2.velocity_y = 0;
                        ball2.acceleration_y =0;
                        ball2.y+=1;
                }
        }
        if(collision(ball2, ball)){
                collisions(ball2,ball);
                //ball2.velocity= ((ball2.mass-ball.mass)/(ball2.mass+ball.mass))*ball2.velocity + (2*ball2.mass/(ball2.mass+ball.mass))*ball.velocity;     
        }
        velocityUpdate(ball, DT);
        velocityUpdate(ball2, DT);
        velocityUpdate(ball3, DT);
       
        clock.restart();
	player.setPosition(ball.x, ball.y);
        player2.setPosition(ball2.x,ball2.y);
        player3.setPosition(ball3.x,ball3.y);
	window.clear();
        window.draw(player);
        window.draw(player2);
        window.draw(player3);
	window.draw(ground_1);
        window.draw(ledge_1);
        window.display();
    }

    return 0;
}
           

