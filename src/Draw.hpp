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
    fn::ColorRect* colorRectangleRed;
    fn::ColorRect* colorRectangleOrange;
    fn::ColorRect* colorRectangleYellow;
    fn::ColorRect* colorRectangleGreen;
    fn::ColorRect* colorRectangleCyan;
    fn::ColorRect* colorRectangleBlue;
    fn::ColorRect* colorRectanglePurple;
    fn::ColorRect* colorRectangleMagenta;
    fn::ColorRect* colorRectangleWhite;
    fn::ColorRect* colorRectangleLightGray;
    fn::ColorRect* colorRectangleDarkGray;
    fn::ColorRect* colorRectangleBlack;
    fn::ColorRect* colorPreview;

    // Functionalities (no se como llamarlo)
    sf::Color color = sf::Color(0, 0, 0);
    sf::Vector2i mousePos;

    int radius;
    sf::CircleShape previewCircle;
    std::vector<sf::CircleShape> circles;

    bool rectMode;
    sf::Vector2f previewRectangleOrigin;

    sf::RectangleShape previewRectangle;
    std::vector<sf::RectangleShape> rectangles;

    std::vector<int> objectsIndex;

    // Drawable things
    sf::Text textTitle;
    sf::Text textRadius;
    sf::RectangleShape canvasRect;
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
    void mouseButtonPressedEvent(sf::Event event);
    void changeRadius(int delta);
    void pushCircle();
    void checkIfColorRectangleClicked();
    void startPreviewRectangle();
    void endPreviewRectangle();
    void undo();

    // Update functions
    void updateRadius();
    void updatePreviewCircle();
    void updatePreviewRectangle();

    // Render functions
    void renderObjects();
    void renderColorRectangles();

    void events();
    void update();
    void render();
};