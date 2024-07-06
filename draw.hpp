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
    sf::Font fontAntonio;
    sf::Cursor cursorCross;

    int radius;
    std::vector<sf::CircleShape> circles;

    // Drawable things
    sf::Text textTitle;
    sf::Text textRadius;
    sf::RectangleShape canvasRect;
    sf::CircleShape preview;

    // Private functions
    void initVariables();
    void initWindow();
    void reInitWindow();
    void initTextTitle();
    void initTextRadius();
    void initCanvasRect();
    void initPreviewCircle();

public:

    // Constructor / Destructor
    Draw();
    ~Draw();

    // Accessors (no se que es xd)
    const bool running() const;     //(no entiendo nada pero va)

    // Funciones
    void checkWindowSize();

    // Event functions
    void pushCircle();
    void keyEvent(sf::Event event);

    // Update functions
    void updateRadius();
    void updatePreviewCircle();

    // Render functions
    void renderCircles();

    void events();
    void update();
    void render();
};