#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <ctime>
#include <string>
#include <iostream>
#include <queue>
#include "physicsEngine.h"

/*things to do still
        fix corner collisions
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
    ball.x=90.0;
    ball.y=100.0;
    ball.radius=20.0;
    ball.radius2=0.0; 
    ball.isStatic=false;
    ball.tempStatic=false;
    ball.velocity_y = 1.0;
    ball.velocity_x = 0.5;
    ball.acceleration_y = gravity;
    ball.acceleration_x = 3.0;
    ball.mass = 5.0;
    ball.material = "rubber";

    Collider ball2;
    ball2.shape=0;
    ball2.x=200.0;
    ball2.y=100.0;
    ball2.radius=20.0;
    ball2.isStatic=false;
    ball.tempStatic=false;
    ball2.velocity_y = 1.0;
    ball2.velocity_x = -1.0;
    ball2.acceleration_y = gravity;
    ball2.acceleration_x = -5.0;
    ball2.mass = 6.0;
    ball2.material = "plastic";

    Collider ball3;
    ball3.shape=0;
    ball3.x=100.0;
    ball3.y=150.0;
    ball3.radius=10.0;
    ball3.isStatic=false;
    ball.tempStatic=false;
    ball3.velocity_y = 1.0;
    ball3.velocity_x = -1.0;
    ball3.acceleration_y = gravity;
    ball3.acceleration_x = -1.0;
    ball3.mass = 6.0;
    ball3.material = "plastic";

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

    Collider ball4;
    ball4.shape=0;
    ball4.x=0.0;
    ball4.y=0.0;
    ball4.radius=20.0;
    ball4.radius2=0.0; 
    ball4.isStatic=false;
    ball.tempStatic=false;
    ball4.velocity_y = 40.0;
    ball4.velocity_x = 60.0;
    ball4.acceleration_y = gravity;
    ball4.acceleration_x = 5.0;
    ball4.mass = 5.0;
    ball4.material = "rubber";

    Collider box;
    box.shape=1;
    box.x=150;
    box.y=150;
    box.radius=100;
    box.radius2=100;
    box.isStatic=true;
    box.mass=50;
    box.material="hard";
    
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

    CircleShape player4;
    player4.setPosition(ball4.x, ball4.y);
    player4.setRadius(ball4.radius);
    player4.setFillColor(Color::Blue);


    RectangleShape ground_1;
    ground_1.setPosition(ground.x, ground.y);
    ground_1.setSize(Vector2f(ground.radius,ground.radius2)); 
    ground_1.setFillColor(gray);

    RectangleShape ledge_1;
    ledge_1.setPosition(ledge.x, ledge.y);
    ledge_1.setSize(Vector2f(ledge.radius,ledge.radius2)); 
    ledge_1.setFillColor(orange);

    RectangleShape box_1;
    box_1.setPosition(box.x, box.y);
    box_1.setSize(Vector2f(box.radius,box.radius2)); 
    box_1.setFillColor(orange);

    CircleShape point;
    point.setPosition(ball4.x, ball4.y);
    point.setRadius(1);
    point.setFillColor(Color::Green);

    Collider* colliders[] = {&ball, &ball2, &ball3, &ledge, &ground};
    

    int scene = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        float DT=clock.getElapsedTime().asSeconds();
        if(scene==0){
            
        
                do_collisions(colliders, 5);

                /*if (collision(ball, ground)){
                        collisions(ball,ground);
                        velocity_cutoff(ball);
                }
                if (collision(ball2, ground)){
                        collisions(ball2, ground);
                        velocity_cutoff(ball2);
                }
                if (collision(ball3, ground)){
                        collisions(ball3, ground);
                        velocity_cutoff(ball3);
                }
                if (collision(ball2, ledge)){
                        collisions(ball2, ledge);
                        velocity_cutoff(ball2);
                }
                if(collision(ball2, ball)){
                        collisions(ball2,ball);
                        velocity_cutoff(ball2);
                        velocity_cutoff(ball);
                           
                }
                if(collision(ball, ball3)){
                        collisions(ball,ball3);
                        velocity_cutoff(ball3);
                        velocity_cutoff(ball);
                }*/
                velocityUpdate(&ball, DT);
                velocityUpdate(&ball2, DT);
                velocityUpdate(&ball3, DT);
        }
        if(scene==1){
                if(collision(&ball4,&box)){
                        collisions(&ball4,&box);
                       
                }
                velocityUpdate(&ball4, DT); 
        }
	
       
        clock.restart();

        if(scene==0){
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
        if(scene==1){
                player4.setPosition(ball4.x,ball4.y);
                point.setPosition(ball4.x+(ball4.radius), ball4.y+ball4.radius);
                window.clear();
                window.draw(player4);
                window.draw(box_1);
                window.draw(point);
                window.display();
        } 
	
    }

    return 0;
}
           

