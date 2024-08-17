#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

namespace fn{
class HelpWindow{
private:
    // Private variables
    sf::RenderWindow* window;
    sf::Event event;

    // Private functions
    void initWindow();

public:
    // Constructor / Destructor
    HelpWindow();
    ~HelpWindow();

    // Accessors (again, I don't know what they are, but work)
    const bool running() const;

    void events();
    void update();
    void render();

};
}