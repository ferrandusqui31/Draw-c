#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class ColorRect{
private:
    void initRectangle();

public:
    // Public variables
    sf::RectangleShape rectangle;
    sf::Color color;
    sf::Vector2f size;
    sf::Vector2f position;

    // Constructor
    ColorRect(sf::Color colorSet, sf::Vector2f positionSet, sf::Vector2f sizeSet);

    // Public functions
};