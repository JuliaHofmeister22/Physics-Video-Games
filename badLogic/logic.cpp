#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>


std::string resources(){
        //change to your resource file
        return "/home/CS/users/cwhite/.linux/COS370/projects/logic/resources/";
}
int main()
{


    sf::Font font;
    font.loadFromFile(resources() + "ubuntu.ttf");



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
    }
}

