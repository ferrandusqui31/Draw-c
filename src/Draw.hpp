#pragma once

#include "Color.hpp"

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

    // Color rectangles
    ColorRect* colorRectangleRed;
    ColorRect* colorRectangleOrange;
    ColorRect* colorRectangleYellow;
    ColorRect* colorRectangleGreen;
    ColorRect* colorRectangleCyan;
    ColorRect* colorRectangleBlue;
    ColorRect* colorRectanglePurple;
    ColorRect* colorRectangleMagenta;
    ColorRect* colorRectangleWhite;
    ColorRect* colorRectangleLightGray;
    ColorRect* colorRectangleDarkGray;
    ColorRect* colorRectangleBlack;
    ColorRect* colorPreview;

    // Functionalities (no se como llamarlo)
    sf::Color color = sf::Color(0, 0, 0);
    int radius;
    std::vector<sf::CircleShape> circles;

    // Drawable things
    sf::Text textTitle;
    sf::Text textRadius;
    sf::RectangleShape canvasRect;
    sf::CircleShape preview;
    sf::RectangleShape whiteRectangleUp;
    sf::RectangleShape whiteRectangleDown;
    sf::RectangleShape whiteRectangleRight;
    sf::RectangleShape whiteRectangleLeft;

    // Private functions
    void initVariables();
    void initWindow();
    void reInitWindow();
    void initTextTitle();
    void initTextRadius();
    void initCanvasRect();
    void initPreviewCircle();
    void initColorRectangles();
    void initWhiteRectangles();

public:

    // Constructor / Destructor
    Draw();
    ~Draw();

    // Accessors (no se que es xd)
    const bool running() const;     //(no entiendo nada pero va)

    // Funciones
    void checkWindowSize();

    // Event functions
    void keyEvent(sf::Event event);
    void changeRadius(int delta);
    void pushCircle();
    void checkIfColorRectangleClicked();

    // Update functions
    void updateRadius();
    void updatePreviewCircle();

    // Render functions
    void renderCircles();
    void renderColorRectangles();

    void events();
    void update();
    void render();
};