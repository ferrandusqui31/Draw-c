#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class ColorRect{
private:
    sf::RectangleShape rectangle;

    void initRectangle();

public:
    // Public variables
    sf::Color color;
    sf::Vector2f size;
    sf::Vector2f position;

    // Constructor
    ColorRect(sf::Color colorSet, sf::Vector2f sizeSet, sf::Vector2f positionSet);

    // Public functions
    void render(sf::RenderWindow window);
};