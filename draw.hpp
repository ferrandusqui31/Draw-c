#pragma once

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Draw
{
private:
    sf::VideoMode toGetWindowSize;
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event event;
    //sf::Font fontAntonio;

    // Drawable things
    //sf::Text textTitle;
    //sf::Text textRadius;
    //sf::RectangleShape canvasRect;

    // Private functions
    void initVariables();
    void initWindow();
    //void initTextTitle();
    //void initTextRadius();
    //void initCanvasRect();

public:
    // Public variables
    //int radius;

    // Constructor / Destructor
    Draw();
    ~Draw();

    // Accessors (no se que es xd)
    const bool running() const;     //(no entiendo nada pero va)

    // Funciones

    void keyEvent(sf::Event event);
    //void updateRadius();

    void events();
    void update();
    void render();
};