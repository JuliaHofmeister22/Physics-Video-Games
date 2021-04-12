#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// modified from: https://www.sfml-dev.org/documentation/2.5.1/

// resource locations
#define RES_IMAGE   "resources/cute_image.jpg"
#define RES_FONT    "resources/ubuntu.ttf"
#define RES_MUSIC   "resources/nice_music.ogg"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Advanced");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(RES_IMAGE)) return EXIT_FAILURE;      // could not load image
    sf::Sprite sprite(texture);                                     // turn image into a sprite

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(RES_FONT)) return EXIT_FAILURE;          // could not load font
    sf::Text text("Hello, World!", font, 50);                       // create a friendly message

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(RES_MUSIC)) return EXIT_FAILURE;        // could not load music
    music.setLoop(true);                                            // make it loop forever!
    music.play();                                                   // Play the music

    // the main game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();    // Close window: exit
        }

        window.clear();         // Clear screen
        window.draw(sprite);    // Draw the sprite
        window.draw(text);      // Draw the string
        window.display();       // Update the window
    }

    return EXIT_SUCCESS;
}