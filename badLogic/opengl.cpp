#include <iostream>
#include <GL/glut.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

// modified from: https://www.sfml-dev.org/documentation/2.5.1/

using namespace std;

void printout_fullscreenmodes() {
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    for(std::size_t i = 0; i < modes.size(); ++i) {
        sf::VideoMode mode = modes[i];
        cout << "Mode #" << i << ": "
             << mode.width << "x" << mode.height << " - "
             << mode.bitsPerPixel << " bpp" << std::endl;
    }
}

int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 4;
    settings.minorVersion = 6;

    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL Example", sf::Style::Fullscreen, settings);
    window.setVerticalSyncEnabled(true);
    window.setActive(true);

    bool running = true;
    while(running && window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();    // Close window: exit
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) running = false;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(1, 0, 0); glVertex2f(-1, -1);
        glColor3f(0, 1, 0); glVertex2f( 1, -1);
        glColor3f(1, 1, 1); glVertex2f( 1,  1);
        glColor3f(0, 0, 1); glVertex2f(-1,  1);
        glEnd();
        window.display();
    }

    return EXIT_SUCCESS;
}