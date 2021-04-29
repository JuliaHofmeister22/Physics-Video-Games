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
        check all collisions through a list
        buttons?
        wind?
*/

using namespace sf;

std::string resources(){
        return "/home/CS/users/cwhite/.linux/COS370/370Final/badLogic/resources/";
}

int main()
{   
    Clock clock;

    

    Collider ball;
    ball.shape=0;
    ball.x=40.0;
    ball.y=250.0;
    ball.radius=20.0;
    ball.radius2=0.0; 
    ball.isStatic=false;
    ball.tempStatic=false;
    ball.velocity_y = 1.0;
    ball.velocity_x = 1.0;
    ball.acceleration_y = gravity;
    ball.acceleration_x = 50.0;
    ball.mass = 5.0;
    ball.material = "rubber";

    Collider wall1;
    wall1.shape=0;
    wall1.x=200.0;
    wall1.y=289.0;
    wall1.radius=20.0;
    wall1.radius2=40.0;
    wall1.isStatic=false;
    wall1.tempStatic=false;
    wall1.velocity_y = 0.0;
    wall1.velocity_x = 0.0;
    wall1.acceleration_y = 0;
    wall1.acceleration_x = 0.0;
    wall1.mass = 4.0;
    wall1.material = "plastic";

    Collider wall2;
    wall2.shape=0;
    wall2.x=200.0;
    wall2.y=331.0;
    wall2.radius=20.0;
    wall2.radius2=40.0;
    wall2.isStatic=false;
    wall2.tempStatic=false;
    wall2.velocity_y = 0.0;
    wall2.velocity_x = 0.0;
    wall2.acceleration_y = 0;
    wall2.acceleration_x = 0.0;
    wall2.mass = 4.0;
    wall2.material = "plastic";

    Collider wall3;
    wall3.shape=0;
    wall3.x=241.0;
    wall3.y=289.0;
    wall3.radius=20.0;
    wall3.radius2=40.0;
    wall3.isStatic=false;
    wall3.tempStatic=false;
    wall3.velocity_y = 0.0;
    wall3.velocity_x = 0.0;
    wall3.acceleration_y = 0;
    wall3.acceleration_x = 0.0;
    wall3.mass = 4.0;
    wall3.material = "plastic";


    Collider ball2;
    ball2.shape=0;
    ball2.x=275.0;
    ball2.y=325.0;
    ball2.radius=20.0;
    ball2.radius2=0.0; 
    ball2.isStatic=false;
    ball2.tempStatic=false;
    ball2.velocity_y = 0.0;
    ball2.velocity_x = 0.0;
    ball2.acceleration_y = 0;
    ball2.acceleration_x = 0.0;
    ball2.mass = 6.0;
    ball2.material = "rubber";

    Collider ground;
    ground.shape=1;
    ground.x=0.0;
    ground.y=370.0;
    ground.radius=400.0;
    ground.radius2=30.0;
    ground.isStatic=true;
    ground.mass = 50.0;
    ground.material = "hard";

    Collider ball4;
    ball4.shape=0;
    ball4.x=0.0;
    ball4.y=0.0;
    ball4.radius=20.0;
    ball4.radius2=0.0; 
    ball4.isStatic=false;
    ball4.tempStatic=false;
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
    
    RenderWindow window(VideoMode(400, 400), "Geometry Crash");

    Font font;
    if(!font.loadFromFile(resources() + "ubuntu.ttf")){
            std::cout<<"Error"<<std::endl;
    }

    font.loadFromFile(resources() + "ubuntu.ttf");

    Text menuText;

    menuText.setFont(font);
    menuText.setCharacterSize(40);
    menuText.setPosition(100.f, 200.f);
    menuText.setFillColor(Color::White);

    menuText.setString("Winner!");
    

    //Colors: gray=metal; green=rubber; red=plastic; orange=sticky
    Color gray(100,100,100);
    Color orange(255,165,100);

    CircleShape player;
    player.setPosition(ball.x, ball.y);
    player.setRadius(ball.radius); 
    player.setFillColor(Color::Green);

    CircleShape enemy;
    enemy.setPosition(ball2.x, ball2.y);
    enemy.setRadius(ball2.radius); 
    enemy.setFillColor(orange);

    RectangleShape barrier1;
    barrier1.setPosition(wall1.x, wall1.y);
    barrier1.setSize(Vector2f(wall1.radius,wall1.radius2)); 
    barrier1.setFillColor(Color::Red);

    RectangleShape barrier2;
    barrier2.setPosition(wall2.x, wall2.y);
    barrier2.setSize(Vector2f(wall2.radius,wall2.radius2)); 
    barrier2.setFillColor(Color::Red);

    RectangleShape barrier3;
    barrier3.setPosition(wall3.x, wall3.y);
    barrier3.setSize(Vector2f(wall3.radius,wall3.radius2)); 
    barrier3.setFillColor(Color::Red);


    RectangleShape ground_1;
    ground_1.setPosition(ground.x, ground.y);
    ground_1.setSize(Vector2f(ground.radius,ground.radius2)); 
    ground_1.setFillColor(gray);

    
    RectangleShape box_1;
    box_1.setPosition(box.x, box.y);
    box_1.setSize(Vector2f(box.radius,box.radius2)); 
    box_1.setFillColor(orange);

    CircleShape point;
    point.setPosition(ball4.x, ball4.y);
    point.setRadius(1);
    point.setFillColor(Color::Green);

    Collider* colliders[] = {&ball, &ball2, &wall1, &wall2, &wall3, &ground};
    

    int scene = 0;

    int hit = 0;

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
            
        
                do_collisions(colliders, 6, hit);

                velocityUpdate(&ball, DT);
                velocityUpdate(&ball2, DT);
                velocityUpdate(&wall1, DT);
                velocityUpdate(&wall2, DT);
                velocityUpdate(&wall3, DT);

                if(hit > 2100){
                        scene=1;
                }
                
        }
        if(scene==1){
        }
	
       
        clock.restart();

        if(scene==0){
                player.setPosition(ball.x, ball.y);
                enemy.setPosition(ball2.x, ball2.y);
                barrier1.setPosition(wall1.x,wall1.y);
                barrier2.setPosition(wall2.x,wall2.y);
                barrier3.setPosition(wall3.x,wall3.y);
                
                window.clear();
                window.draw(player);
                window.draw(enemy);
                window.draw(barrier1);
                window.draw(barrier2);
                window.draw(barrier3);
                window.draw(ground_1);
                window.display();
        }
        if(scene==1){
                window.clear();
                window.draw(menuText);
                window.display();
        } 
	
    }

    return 0;
}
           

