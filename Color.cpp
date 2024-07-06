#include "Color.hpp"

void ColorRect::initRectangle()
{
    this->rectangle.setFillColor(this->color);
    this->rectangle.setPosition(this->position);
    this->rectangle.setSize(this->size);
    this->rectangle.setOutlineColor(sf::Color::Black);
    this->rectangle.setOutlineThickness(2);
}

ColorRect::ColorRect(sf::Color colorSet, sf::Vector2f sizeSet, sf::Vector2f positionSet)
{
    this->color = colorSet;
    this->size = sizeSet;
    this->position = positionSet;

    this->initRectangle();
}

void ColorRect::render(sf::RenderWindow window)
{
    window.draw(rectangle);
}
