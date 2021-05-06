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
        buttons?
        wind?
*/
void resetLevel1(Collider &ball, Collider &ball2, Collider &ball3, Collider &ball4, Collider &wall1, Collider &wall2, Collider &wall3, Collider &wall4, Collider &wall5, Collider &wall6, Collider &wall7, Collider &wall8, Collider &ground, Collider &wall_ground, Collider &platform1, Collider &platform2, Collider &platform3);

using namespace sf;

//change this to your directory?
std::string resources(){
        return "/home/CS/users/cwhite/.linux/COS370/370Final/badLogic/resources/";
}

int main()
{   
    Clock clock;

    int window_width = 800;

    int window_height = 800;

    Texture texture1;
    Texture texture2;

    if(!texture1.loadFromFile(resources() + "GeoBackground.jpg")){
            std::cout<<"Error"<<std::endl;
    }
    texture1.loadFromFile(resources() + "GeoBackground.jpg");
    Sprite background;
    Vector2u size = texture1.getSize();
    background.setTexture(texture1);
    background.setOrigin(size.x/2, size.y/2-300);
    

    if(!texture2.loadFromFile(resources() + "GeoMenu.jpg")){
            std::cout<<"Error"<<std::endl;
    }
    texture2.loadFromFile(resources() + "GeoMenu.jpg");
    Sprite menuBackground;
    Vector2u size2 = texture2.getSize();
    menuBackground.setTexture(texture2);
    menuBackground.setOrigin(size2.x/2-150, size2.y/2-400);



    Collider ball;
    ball.shape=0;
    ball.x=40.0;
    ball.y=350.0;
    ball.radius=20.0;
    ball.radius2=0.0; 
    ball.isStatic=false;
    ball.tempStatic=false;
    ball.velocity_y = -10.0;
    ball.velocity_x = 1.0;
    ball.acceleration_y = 0.0;
    ball.acceleration_x = 0.0;
    ball.mass = 5.0;
    ball.material = "rubber";

    Collider wall1;
    wall1.shape=0;
    wall1.x=600.0;
    wall1.y=window_height-116;
    wall1.radius=20.0;
    wall1.radius2=20.0;
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
    wall2.x=600.0;
    wall2.y=window_height-73;
    wall2.radius=20.0;
    wall2.radius2=20.0;
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
    wall3.x=641.0;
    wall3.y=window_height-116;
    wall3.radius=20.0;
    wall3.radius2=20.0;
    wall3.isStatic=false;
    wall3.tempStatic=false;
    wall3.velocity_y = 0.0;
    wall3.velocity_x = 0.0;
    wall3.acceleration_y = 0;
    wall3.acceleration_x = 0.0;
    wall3.mass = 4.0;
    wall3.material = "plastic";

    Collider wall4;
    wall4.shape=0;
    wall4.x=558.0;
    wall4.y=window_height-116;
    wall4.radius=20.0;
    wall4.radius2=20.0;
    wall4.isStatic=false;
    wall4.tempStatic=false;
    wall4.velocity_y = 0.0;
    wall4.velocity_x = 0.0;
    wall4.acceleration_y = 0;
    wall4.acceleration_x = 0.0;
    wall4.mass = 4.0;
    wall4.material = "plastic";

    Collider wall5;
    wall5.shape=0;
    wall5.x=517.0;
    wall5.y=window_height-116;
    wall5.radius=20.0;
    wall5.radius2=20.0;
    wall5.isStatic=false;
    wall5.tempStatic=false;
    wall5.velocity_y = 0.0;
    wall5.velocity_x = 0.0;
    wall5.acceleration_y = 0;
    wall5.acceleration_x = 0.0;
    wall5.mass = 4.0;
    wall5.material = "plastic";

    Collider wall6;
    wall6.shape=0;
    wall6.x=675.0;
    wall6.y=window_height-250;
    wall6.radius=20.0;
    wall6.radius2=20.0;
    wall6.isStatic=false;
    wall6.tempStatic=false;
    wall6.velocity_y = 0.0;
    wall6.velocity_x = 0.0;
    wall6.acceleration_y = 0;
    wall6.acceleration_x = 0.0;
    wall6.mass = 4.0;
    wall6.material = "plastic";

    Collider wall7;
    wall7.shape=0;
    wall7.x=600.0;
    wall7.y=window_height-240;
    wall7.radius=20.0;
    wall7.radius2=20.0;
    wall7.isStatic=false;
    wall7.tempStatic=false;
    wall7.velocity_y = 0.0;
    wall7.velocity_x = 0.0;
    wall7.acceleration_y = 0;
    wall7.acceleration_x = 0.0;
    wall7.mass = 4.0;
    wall7.material = "plastic";

    Collider wall8;
    wall8.shape=0;
    wall8.x=600.0;
    wall8.y=window_height-195;
    wall8.radius=20.0;
    wall8.radius2=20.0;
    wall8.isStatic=false;
    wall8.tempStatic=false;
    wall8.velocity_y = 0.0;
    wall8.velocity_x = 0.0;
    wall8.acceleration_y = 0;
    wall8.acceleration_x = 0.0;
    wall8.mass = 4.0;
    wall8.material = "plastic";


    Collider ball2;
    ball2.shape=0;
    ball2.x=675.0;
    ball2.y=window_height-73;
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
    ball2.hit = 0;

    Collider ball3;
    ball3.shape=0;
    ball3.x=475.0;
    ball3.y=window_height-73;
    ball3.radius=20.0;
    ball3.radius2=0.0; 
    ball3.isStatic=false;
    ball3.tempStatic=false;
    ball3.velocity_y = 0.0;
    ball3.velocity_x = 0.0;
    ball3.acceleration_y = 0;
    ball3.acceleration_x = 0.0;
    ball3.mass = 6.0;
    ball3.material = "rubber";
    ball3.hit = 0;

    Collider ball4;
    ball4.shape=0;
    ball4.x=675.0;
    ball4.y=600;
    ball4.radius=20.0;
    ball4.radius2=0.0; 
    ball4.isStatic=false;
    ball4.tempStatic=false;
    ball4.velocity_y = 0.0;
    ball4.velocity_x = 0.0;
    ball4.acceleration_y = 0;
    ball4.acceleration_x = 0.0;
    ball4.mass = 6.0;
    ball4.material = "rubber";
    ball4.hit = 0;

    Collider ground;
    ground.shape=1;
    ground.x=0.0;
    ground.y=window_height-30;
    ground.radius=window_width;
    ground.radius2=30.0;
    ground.isStatic=true;
    ground.mass = 50.0;
    ground.material = "hard";

    Collider wall_ground;
    wall_ground.shape=1;
    wall_ground.x=window_width-30;
    wall_ground.y=0;
    wall_ground.radius=30.0;
    wall_ground.radius2=window_height;
    wall_ground.isStatic=true;
    wall_ground.mass = 50.0;
    wall_ground.material = "hard";

    Collider platform1;
    platform1.shape=1;
    platform1.x=350.0;
    platform1.y=650.0;
    platform1.radius=50;
    platform1.radius2=15.0;
    platform1.isStatic=true;
    platform1.tempStatic=true;
    platform1.mass = 500.0;
    platform1.material = "hard";

    Collider platform2;
    platform2.shape=1;
    platform2.x=350.0;
    platform2.y=650.0;
    platform2.radius=50;
    platform2.radius2=15.0;
    platform2.isStatic=true;
    platform2.tempStatic=true;
    platform2.mass = 500.0;
    platform2.material = "hard";

    Collider platform3;
    platform3.shape=1;
    platform3.x=350.0;
    platform3.y=650.0;
    platform3.radius=50;
    platform3.radius2=15.0;
    platform3.isStatic=true;
    platform3.tempStatic=true;
    platform3.mass = 500.0;
    platform3.material = "hard";


    Collider box;
    box.shape=1;
    box.x=150;
    box.y=150;
    box.radius=100;
    box.radius2=100;
    box.isStatic=true;
    box.mass=50;
    box.material="hard";

    
    
    RenderWindow window(VideoMode(window_width, window_height), "Geometry Crash");

    Font font;
    if(!font.loadFromFile(resources() + "ubuntu.ttf")){
            std::cout<<"Error"<<std::endl;
    }

    font.loadFromFile(resources() + "ubuntu.ttf");

    Text finished_text;

    finished_text.setFont(font);
    finished_text.setCharacterSize(40);
    finished_text.setPosition(window_width-550, window_height/2-100);
    finished_text.setFillColor(Color::White);

    finished_text.setString("Winner!\nPress Enter for level 1,\nRight arrow for level 2");

    Text menu_text;

    menu_text.setFont(font);
    menu_text.setCharacterSize(40);
    menu_text.setPosition(window_width-550, (window_height/2)-100);
    menu_text.setFillColor(Color::White);

    menu_text.setString(" Geometry Crash\nPress Enter for level 1!\nRight arrow for level 2");

    Text lives_text;
    lives_text.setFont(font);
    lives_text.setCharacterSize(20);
    lives_text.setPosition(50, 50);
    lives_text.setFillColor(Color::White);

    Text restart_life_text;
    restart_life_text.setFont(font);
    restart_life_text.setCharacterSize(20);
    restart_life_text.setPosition(100, 50);
    restart_life_text.setFillColor(Color::White);

    restart_life_text.setString("Press E to kill the ball if stuck\nPress space to launch the ball");
    

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

    CircleShape enemy2;
    enemy2.setPosition(ball3.x, ball3.y);
    enemy2.setRadius(ball3.radius); 
    enemy2.setFillColor(orange);

    CircleShape enemy3;
    enemy3.setPosition(ball4.x, ball4.y);
    enemy3.setRadius(ball4.radius); 
    enemy3.setFillColor(orange);

    RectangleShape barrier1;
    barrier1.setPosition(wall1.x, wall1.y);
    barrier1.setSize(Vector2f(wall1.radius*2,wall1.radius2*2)); 
    barrier1.setFillColor(Color::Red);

    RectangleShape barrier2;
    barrier2.setPosition(wall2.x, wall2.y);
    barrier2.setSize(Vector2f(wall2.radius*2,wall2.radius2*2)); 
    barrier2.setFillColor(Color::Red);


    RectangleShape barrier3;
    barrier3.setPosition(wall3.x, wall3.y);
    barrier3.setSize(Vector2f(wall3.radius*2,wall3.radius2*2)); 
    barrier3.setFillColor(Color::Red);

    RectangleShape barrier4;
    barrier4.setPosition(wall4.x, wall4.y);
    barrier4.setSize(Vector2f(wall4.radius*2,wall4.radius2*2)); 
    barrier4.setFillColor(Color::Red);


    RectangleShape barrier5;
    barrier5.setPosition(wall5.x, wall5.y);
    barrier5.setSize(Vector2f(wall5.radius*2,wall5.radius2*2)); 
    barrier5.setFillColor(Color::Red);

    RectangleShape barrier6;
    barrier6.setPosition(wall6.x, wall6.y);
    barrier6.setSize(Vector2f(wall6.radius*2,wall6.radius2*2)); 
    barrier6.setFillColor(Color::Red);

    RectangleShape barrier7;
    barrier7.setPosition(wall7.x, wall7.y);
    barrier7.setSize(Vector2f(wall7.radius*2,wall7.radius2*2)); 
    barrier7.setFillColor(Color::Red);


    RectangleShape barrier8;
    barrier8.setPosition(wall8.x, wall8.y);
    barrier8.setSize(Vector2f(wall8.radius*2,wall8.radius2*2)); 
    barrier8.setFillColor(Color::Red);



    RectangleShape ground_1;
    ground_1.setPosition(ground.x, ground.y);
    ground_1.setSize(Vector2f(ground.radius,ground.radius2)); 
    ground_1.setFillColor(gray);

    RectangleShape ground_2;
    ground_2.setPosition(wall_ground.x, wall_ground.y);
    ground_2.setSize(Vector2f(wall_ground.radius,wall_ground.radius2)); 
    ground_2.setFillColor(gray);

    RectangleShape ground_3;
    ground_3.setPosition(platform1.x, platform1.y);
    ground_3.setSize(Vector2f(platform1.radius*2,platform1.radius2*2)); 
    ground_3.setFillColor(gray);

    RectangleShape ground_4;
    ground_4.setPosition(platform2.x, platform2.y);
    ground_4.setSize(Vector2f(platform2.radius*2,platform2.radius2*2)); 
    ground_4.setFillColor(gray);

    RectangleShape ground_5;
    ground_5.setPosition(platform3.x, platform3.y);
    ground_5.setSize(Vector2f(platform3.radius*2,platform3.radius2*2)); 
    ground_5.setFillColor(gray);

    
    RectangleShape box_1;
    box_1.setPosition(box.x, box.y);
    box_1.setSize(Vector2f(box.radius,box.radius2)); 
    box_1.setFillColor(orange);

    CircleShape point;
    point.setPosition(ball4.x, ball4.y);
    point.setRadius(1);
    point.setFillColor(Color::Green);

    Collider* colliders[] = {&ball, &ball2, &ball3, &ball4, &wall1, &wall2, &wall3, &wall4, &wall5, &wall6, &wall7, &wall8, &ground, &wall_ground, &platform1, &platform2, &platform3};
    

    int scene = 2;

    int hit = 0;

    int player_hit = 0;

    int player_lives = 5;
    
    int enemies_alive = 3;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        float DT=clock.getElapsedTime().asSeconds()*4;
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
                        window.close();
                }
        if(scene==0){
                
                lives_text.setString(std::to_string(player_lives));

                if(Keyboard::isKeyPressed(Keyboard::Space)){
                    ball.acceleration_y = gravity;
                    ball.acceleration_x = 50.0;
                }
                
                //slingshot rotation
                if(ball.y > 600 && ball.x <=50){
                        ball.velocity_y = -10;
                }
                else if(ball.y < 400 && ball.x <=50){
                        ball.velocity_y = 10;
                }
                
                
                //out of bounds kill
                if(ball.tempStatic == 1 || ball.x <0){
                        player_hit+=1;
                }

                if(player_hit >2000){
                    player_lives-=1;
                    player_hit=0;
                    ball.x=40.0;
                    ball.y=350.0;
                    ball.radius=20.0;
                    ball.radius2=0.0; 
                    ball.isStatic=false;
                    ball.tempStatic=false;
                    ball.velocity_y = -10.0;
                    ball.velocity_x = 1.0;
                    ball.acceleration_y = 0.0;
                    ball.acceleration_x = 0.0;
                }
                if(Keyboard::isKeyPressed(Keyboard::E) && ball.x >50){
                    player_lives-=1;
                    player_hit=0;
                    ball.x=40.0;
                    ball.y=350.0;
                    ball.radius=20.0;
                    ball.radius2=0.0; 
                    ball.isStatic=false;
                    ball.tempStatic=false;
                    ball.velocity_y = -10.0;
                    ball.velocity_x = 1.0;
                    ball.acceleration_y = 0.0;
                    ball.acceleration_x = 0.0;
                }

                if(player_lives < 1){
                    finished_text.setString("Loser!\nPress Enter for level 1,\nRight arrow for level 2");
                    scene=1;
                }
        
                do_collisions(colliders, 17, hit);

                velocityUpdate(&ball, DT);
                velocityUpdate(&wall1, DT);
                velocityUpdate(&wall2, DT);
                velocityUpdate(&wall3, DT);
                velocityUpdate(&wall4, DT);
                velocityUpdate(&wall5, DT);
                velocityUpdate(&wall6, DT);
                velocityUpdate(&wall7, DT);
                velocityUpdate(&wall8, DT);

                if(ball2.hit >= 1000 && ball2.hit < 2000){
                    enemies_alive-=1;
                    ball2.hit=2001;
                }
                else{
                    velocityUpdate(&ball2, DT);
                    enemy.setPosition(ball2.x, ball2.y);
                }

                if(ball3.hit >= 1000 && ball3.hit < 2000){
                    enemies_alive-=1;
                    ball3.hit=2001;
                }
                else{
                    velocityUpdate(&ball3, DT);
                    enemy2.setPosition(ball3.x, ball3.y);
                }
                if(ball4.hit >= 1000 && ball4.hit < 2000){
                    enemies_alive-=1;
                    ball4.hit=2001;
                }
                else{
                    velocityUpdate(&ball4, DT);
                    enemy3.setPosition(ball4.x, ball4.y);
                }

                if(enemies_alive <= 0){
                    scene=1;
                }
                
        }
        if(scene==1){
                player_lives = 1;
                if(Keyboard::isKeyPressed(Keyboard::Enter)){
                        resetLevel1(ball, ball2, ball3, ball4, wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8, ground, wall_ground, platform1, platform2, platform3);
                        ground_3.setPosition(platform1.x,platform1.y);
                        ground_3.setSize(Vector2f(platform1.radius*2,platform1.radius2*2));
                        ground_4.setPosition(platform2.x,platform2.y);
                        ground_4.setSize(Vector2f(platform2.radius*2,platform2.radius2*2));
                        ground_5.setPosition(platform3.x,platform3.y);
                        ground_5.setSize(Vector2f(platform3.radius*2,platform3.radius2*2));
                        player_lives = 5;
                        enemies_alive=3;
                        ball2.hit=0;
                        ball3.hit=0;
                        ball4.hit=0;
                        scene=0;
                }
                if(Keyboard::isKeyPressed(Keyboard::Right)){
                        player_lives = 5;
                        enemies_alive=3;
                        ball2.hit=0;
                        ball3.hit=0;
                        ball4.hit=0;
                        resetLevel1(ball, ball2, ball3, ball4, wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8, ground, wall_ground, platform1, platform2, platform3);
                        
                        //level 2 
                    wall1.x=400.0;
                    wall1.x=600.0;
                    wall1.y=window_height-400;

                    wall2.x=650.0;
                    wall2.y=window_height-350;

                    wall3.x=600.0;
                    wall3.y=window_height-300;

                    wall4.x=550.0;
                    wall4.y=window_height-250;

                    wall5.x=600.0;
                    wall5.y=window_height-200;

                    wall6.x=550.0;
                    wall6.y=window_height-150;

                    wall7.x=475.0;
                    wall7.y=window_height-100;

                    wall8.x=450.0;
                    wall8.y=window_height-200;

                    ball2.x=675.0;
                    ball2.y=500;

                    ball3.x=700.0;
                    ball3.y=700;

                    ball4.x=675.0;
                    ball4.y=600;

                    platform1.radius=30.0;
                    platform1.radius2=15.0;
                    platform1.x=350.0;
                    platform1.y=600.0;

                    ground_3.setPosition(platform1.x,platform1.y);
                    ground_3.setSize(Vector2f(platform1.radius*2,platform1.radius2*2));

                    platform2.radius=30.0;
                    platform2.radius2=15.0;
                    platform2.x=350.0;
                    platform2.y=500.0;

                    ground_4.setPosition(platform2.x,platform2.y);
                    ground_4.setSize(Vector2f(platform2.radius*2,platform2.radius2*2));

                    platform3.radius=30.0;
                    platform3.radius2=15.0;
                    platform3.x=350.0;
                    platform3.y=700.0;

                    ground_5.setPosition(platform3.x,platform3.y);
                    ground_5.setSize(Vector2f(platform3.radius*2,platform3.radius2*2));

                        

                        scene=3;
                }
        }

        if(scene==2){
                if(Keyboard::isKeyPressed(Keyboard::Enter)){
                        scene=0;
                }
                if(Keyboard::isKeyPressed(Keyboard::Right)){
                    resetLevel1(ball, ball2, ball3, ball4, wall1, wall2, wall3, wall4, wall5, wall6, wall7, wall8, ground, wall_ground, platform1, platform2, platform3);
                        
                        //level 2 
                    wall1.x=600.0;
                    wall1.y=window_height-400;

                    wall2.x=650.0;
                    wall2.y=window_height-350;

                    wall3.x=600.0;
                    wall3.y=window_height-300;

                    wall4.x=550.0;
                    wall4.y=window_height-250;

                    wall5.x=600.0;
                    wall5.y=window_height-200;

                    wall6.x=550.0;
                    wall6.y=window_height-150;

                    wall7.x=475.0;
                    wall7.y=window_height-100;

                    wall8.x=450.0;
                    wall8.y=window_height-200;

                    ball2.x=675.0;
                    ball2.y=500;

                    ball3.x=700.0;
                    ball3.y=700;

                    ball4.x=675.0;
                    ball4.y=600;

                    platform1.radius=30.0;
                    platform1.radius2=15.0;
                    platform1.x=350.0;
                    platform1.y=600.0;

                    ground_3.setPosition(platform1.x,platform1.y);
                    ground_3.setSize(Vector2f(platform1.radius*2,platform1.radius2*2));

                    platform2.radius=30.0;
                    platform2.radius2=15.0;
                    platform2.x=350.0;
                    platform2.y=500.0;

                    ground_4.setPosition(platform2.x,platform2.y);
                    ground_4.setSize(Vector2f(platform2.radius*2,platform2.radius2*2));

                    platform3.radius=30.0;
                    platform3.radius2=15.0;
                    platform3.x=350.0;
                    platform3.y=700.0;

                    ground_5.setPosition(platform3.x,platform3.y);
                    ground_5.setSize(Vector2f(platform3.radius*2,platform3.radius2*2));



                    scene=3;
                }
        }
        //level 2
        if(scene==3){
                lives_text.setString(std::to_string(player_lives));

                if(Keyboard::isKeyPressed(Keyboard::Space)){
                    ball.acceleration_y = gravity;
                    ball.acceleration_x = 50.0;
                }
                
                //slingshot rotation
                if(ball.y > 600 && ball.x <=50){
                        ball.velocity_y = -10;
                }
                else if(ball.y < 400 && ball.x <=50){
                        ball.velocity_y = 10;
                }
                
                
                //out of bounds kill
                if(ball.tempStatic == 1 || ball.x <0){
                        player_hit+=1;
                }

                if(player_hit >2000){
                    player_lives-=1;
                    player_hit=0;
                    ball.x=40.0;
                    ball.y=350.0;
                    ball.radius=20.0;
                    ball.radius2=0.0; 
                    ball.isStatic=false;
                    ball.tempStatic=false;
                    ball.velocity_y = -10.0;
                    ball.velocity_x = 1.0;
                    ball.acceleration_y = 0.0;
                    ball.acceleration_x = 0.0;
                }
                if(Keyboard::isKeyPressed(Keyboard::E) && ball.x >50){
                    player_lives-=1;
                    player_hit=0;
                    ball.x=40.0;
                    ball.y=350.0;
                    ball.radius=20.0;
                    ball.radius2=0.0; 
                    ball.isStatic=false;
                    ball.tempStatic=false;
                    ball.velocity_y = -10.0;
                    ball.velocity_x = 1.0;
                    ball.acceleration_y = 0.0;
                    ball.acceleration_x = 0.0;
                }

                if(player_lives < 1){
                    finished_text.setString("Loser!\nPress Enter for level 1,\nRight arrow for level 2");
                    scene=1;
                }
        
                do_collisions(colliders, 15, hit);

                velocityUpdate(&ball, DT);
                velocityUpdate(&wall1, DT);
                velocityUpdate(&wall2, DT);
                velocityUpdate(&wall3, DT);
                velocityUpdate(&wall4, DT);
                velocityUpdate(&wall5, DT);
                velocityUpdate(&wall6, DT);
                velocityUpdate(&wall7, DT);
                velocityUpdate(&wall8, DT);

                if(ball2.hit >= 1000 && ball2.hit < 2000){
                    enemies_alive-=1;
                    ball2.hit=2001;
                }
                else{
                    velocityUpdate(&ball2, DT);
                    enemy.setPosition(ball2.x, ball2.y);
                }

                if(ball3.hit >= 1000 && ball3.hit < 2000){
                    enemies_alive-=1;
                    ball3.hit=2001;
                }
                else{
                    velocityUpdate(&ball3, DT);
                    enemy2.setPosition(ball3.x, ball3.y);
                }
                if(ball4.hit >= 1000 && ball4.hit < 2000){
                    enemies_alive-=1;
                    ball4.hit=2001;
                }
                else{
                    velocityUpdate(&ball4, DT);
                    enemy3.setPosition(ball4.x, ball4.y);
                }

                if(enemies_alive <= 0){
                    scene=1;
                }

        }
	
       
        clock.restart();

        
        //level 1 scene
        if(scene==0 || scene==3){
                player.setPosition(ball.x, ball.y);
                barrier1.setPosition(wall1.x,wall1.y);
                barrier2.setPosition(wall2.x,wall2.y);
                barrier3.setPosition(wall3.x,wall3.y);
                barrier4.setPosition(wall4.x,wall4.y);
                barrier5.setPosition(wall5.x,wall5.y);
                barrier6.setPosition(wall6.x,wall6.y);
                barrier7.setPosition(wall7.x,wall7.y);
                barrier8.setPosition(wall8.x,wall8.y);
                
                window.clear();
                window.draw(background);
                window.draw(player);
                if(ball2.hit <=1000){
                    window.draw(enemy);
                }
                if(ball3. hit<=1000){
                    window.draw(enemy2);
                }
                if(ball4. hit<=1000){
                    window.draw(enemy3);
                }
                
                window.draw(barrier1);
                window.draw(barrier2);
                window.draw(barrier3);
                window.draw(barrier4);
                window.draw(barrier5);
                window.draw(barrier6);
                window.draw(barrier7);
                window.draw(barrier8);
                window.draw(ground_1);
                window.draw(ground_2);
                window.draw(ground_3);
                if(scene==3){
                    window.draw(ground_4);
                    window.draw(ground_5);
                }
                window.draw(lives_text);
                window.draw(restart_life_text);
                
                window.display();
        }
        //ending scene
        if(scene==1){
                window.clear();
                window.draw(menuBackground);
                window.draw(finished_text);
                window.display();
        } 

        //menu scene
        if(scene==2){
                window.clear();
                window.draw(menuBackground);
                window.draw(menu_text);
                window.display();
        } 
	
    }

    return 0;
}



void resetLevel1(Collider &ball, Collider &ball2, Collider &ball3, Collider &ball4, Collider &wall1, Collider &wall2, Collider &wall3, Collider &wall4, Collider &wall5, Collider &wall6, Collider &wall7, Collider &wall8, Collider &ground, Collider &wall_ground, Collider &platform1, Collider &platform2, Collider &platform3){
    int window_width = 800;
    int window_height = 800;
    ball.shape=0;
    ball.x=40.0;
    ball.y=350.0;
    ball.radius=20.0;
    ball.radius2=0.0; 
    ball.isStatic=false;
    ball.tempStatic=false;
    ball.velocity_y = -10.0;
    ball.velocity_x = 1.0;
    ball.acceleration_y = 0.0;
    ball.acceleration_x = 0.0;
    ball.mass = 5.0;
    ball.material = "rubber";

    wall1.shape=0;
    wall1.x=600.0;
    wall1.y=window_height-116;
    wall1.radius=20.0;
    wall1.radius2=20.0;
    wall1.isStatic=false;
    wall1.tempStatic=false;
    wall1.velocity_y = 0.0;
    wall1.velocity_x = 0.0;
    wall1.acceleration_y = 0;
    wall1.acceleration_x = 0.0;
    wall1.mass = 4.0;
    wall1.material = "plastic";


    wall2.shape=0;
    wall2.x=600.0;
    wall2.y=window_height-73;
    wall2.radius=20.0;
    wall2.radius2=20.0;
    wall2.isStatic=false;
    wall2.tempStatic=false;
    wall2.velocity_y = 0.0;
    wall2.velocity_x = 0.0;
    wall2.acceleration_y = 0;
    wall2.acceleration_x = 0.0;
    wall2.mass = 4.0;
    wall2.material = "plastic";

    wall3.shape=0;
    wall3.x=641.0;
    wall3.y=window_height-116;
    wall3.radius=20.0;
    wall3.radius2=20.0;
    wall3.isStatic=false;
    wall3.tempStatic=false;
    wall3.velocity_y = 0.0;
    wall3.velocity_x = 0.0;
    wall3.acceleration_y = 0;
    wall3.acceleration_x = 0.0;
    wall3.mass = 4.0;
    wall3.material = "plastic";


    wall4.shape=0;
    wall4.x=558.0;
    wall4.y=window_height-116;
    wall4.radius=20.0;
    wall4.radius2=20.0;
    wall4.isStatic=false;
    wall4.tempStatic=false;
    wall4.velocity_y = 0.0;
    wall4.velocity_x = 0.0;
    wall4.acceleration_y = 0;
    wall4.acceleration_x = 0.0;
    wall4.mass = 4.0;
    wall4.material = "plastic";


    wall5.shape=0;
    wall5.x=517.0;
    wall5.y=window_height-116;
    wall5.radius=20.0;
    wall5.radius2=20.0;
    wall5.isStatic=false;
    wall5.tempStatic=false;
    wall5.velocity_y = 0.0;
    wall5.velocity_x = 0.0;
    wall5.acceleration_y = 0;
    wall5.acceleration_x = 0.0;
    wall5.mass = 4.0;
    wall5.material = "plastic";

    wall6.shape=0;
    wall6.x=675.0;
    wall6.y=window_height-250;
    wall6.radius=20.0;
    wall6.radius2=20.0;
    wall6.isStatic=false;
    wall6.tempStatic=false;
    wall6.velocity_y = 0.0;
    wall6.velocity_x = 0.0;
    wall6.acceleration_y = 0;
    wall6.acceleration_x = 0.0;
    wall6.mass = 4.0;
    wall6.material = "plastic";

    wall7.shape=0;
    wall7.x=600.0;
    wall7.y=window_height-240;
    wall7.radius=20.0;
    wall7.radius2=20.0;
    wall7.isStatic=false;
    wall7.tempStatic=false;
    wall7.velocity_y = 0.0;
    wall7.velocity_x = 0.0;
    wall7.acceleration_y = 0;
    wall7.acceleration_x = 0.0;
    wall7.mass = 4.0;
    wall7.material = "plastic";

  
    wall8.shape=0;
    wall8.x=600.0;
    wall8.y=window_height-195;
    wall8.radius=20.0;
    wall8.radius2=20.0;
    wall8.isStatic=false;
    wall8.tempStatic=false;
    wall8.velocity_y = 0.0;
    wall8.velocity_x = 0.0;
    wall8.acceleration_y = 0;
    wall8.acceleration_x = 0.0;
    wall8.mass = 4.0;
    wall8.material = "plastic";


   
    ball2.shape=0;
    ball2.x=675.0;
    ball2.y=window_height-73;
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
    ball2.hit = 0;

   
    ball3.shape=0;
    ball3.x=475.0;
    ball3.y=window_height-73;
    ball3.radius=20.0;
    ball3.radius2=0.0; 
    ball3.isStatic=false;
    ball3.tempStatic=false;
    ball3.velocity_y = 0.0;
    ball3.velocity_x = 0.0;
    ball3.acceleration_y = 0;
    ball3.acceleration_x = 0.0;
    ball3.mass = 6.0;
    ball3.material = "rubber";
    ball3.hit = 0;

    
    ball4.shape=0;
    ball4.x=675.0;
    ball4.y=600;
    ball4.radius=20.0;
    ball4.radius2=0.0; 
    ball4.isStatic=false;
    ball4.tempStatic=false;
    ball4.velocity_y = 0.0;
    ball4.velocity_x = 0.0;
    ball4.acceleration_y = 0;
    ball4.acceleration_x = 0.0;
    ball4.mass = 6.0;
    ball4.material = "rubber";
    ball4.hit = 0;

    ground.shape=1;
    ground.x=0.0;
    ground.y=window_height-30;
    ground.radius=window_width;
    ground.radius2=30.0;
    ground.isStatic=true;
    ground.mass = 50.0;
    ground.material = "hard";

    wall_ground.shape=1;
    wall_ground.x=window_width-30;
    wall_ground.y=0;
    wall_ground.radius=30.0;
    wall_ground.radius2=window_height;
    wall_ground.isStatic=true;
    wall_ground.mass = 50.0;
    wall_ground.material = "hard";

    platform1.shape=1;
    platform1.x=350.0;
    platform1.y=650.0;
    platform1.radius=250;
    platform1.radius2=15.0;
    platform1.isStatic=true;
    platform1.mass = 50.0;
    platform1.material = "hard";

    platform2.shape=1;
    platform2.x=0.0;
    platform2.y=0.0;
    platform2.radius=0;
    platform2.radius2=0.0;
    platform2.isStatic=true;
    platform2.tempStatic=true;
    platform2.mass = 500.0;
    platform2.material = "hard";

    platform3.shape=1;
    platform3.x=0.0;
    platform3.y=0.0;
    platform3.radius=50;
    platform3.radius2=15.0;
    platform3.isStatic=true;
    platform3.tempStatic=true;
    platform3.mass = 500.0;
    platform3.material = "hard";

}

