#include "Draw.hpp"

void Draw::initVariables()
{
    this->videoMode = toGetWindowSize.getDesktopMode();
    this->window = nullptr;
    this->fontAntonio.loadFromFile("../fonts/Antonio.ttf");
    this->cursorCross.loadFromSystem(sf::Cursor::Cross);

    this->radius = 30;
    this->rectMode = false;
    this->objectsIndex.push_back(0);
}

// Funciones privadas
void Draw::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, "Draw");
    this->window->setFramerateLimit(30);
    this->window->setMouseCursor(this->cursorCross);
}

void Draw::reInitWindow()
{
    this->window->close();
    this->window->create(this->videoMode, "Draw");

    this->window->setFramerateLimit(30);
    this->window->setMouseCursor(this->cursorCross);
}

void Draw::initTextTitle()
{
    // Style
    this->textTitle.setFont(fontAntonio);
    this->textTitle.setStyle(sf::Text::Bold | sf::Text::Italic);
    this->textTitle.setCharacterSize(55);
    this->textTitle.setString("DRAW!");
    this->textTitle.setFillColor(sf::Color::Black);

    // Position
    sf::Vector2f pos;
    pos.x = videoMode.width / 2;
    pos.x -= 64.5;     // Half of text's width
    pos.y = 10;
    this->textTitle.setPosition(pos);
}

void Draw::initTextRadius()
{
    // Style
    this->textRadius.setFont(fontAntonio);
    this->textRadius.setCharacterSize(33);
    this->textRadius.setFillColor(sf::Color::Black);
    this->textRadius.setPosition(sf::Vector2f(15,65));

    std::string str = "Radius: " + std::to_string(radius);
    this->textRadius.setString(str);
}

void Draw::initCanvasRect()
{
    // Style
    this->canvasRect.setFillColor(sf::Color::Transparent);
    this->canvasRect.setOutlineColor(sf::Color::Black);
    this->canvasRect.setOutlineThickness(4);

    // Size and position
    sf::Vector2f size;
    size.x = videoMode.width * .68;
    size.y = size.x * .45;

    sf::Vector2f pos;
    pos.x = videoMode.width / 2;
    pos.x -= size.x / 2;
    pos.y = 85;

    this->canvasRect.setSize(size);
    this->canvasRect.setPosition(pos);
}

void Draw::initPreviewCircle()
{
    this->previewCircle.setFillColor(sf::Color::Black);
    this->previewCircle.setRadius(this->radius);
    this->previewCircle.setOrigin(this->radius, this->radius);
}

void Draw::initColorRectangles()
{
    sf::Vector2f initSize(70,70);
    sf::Vector2f initPos;

    initPos.x = this->videoMode.width / 2;
    initPos.x -= 360;

    initPos.y = 85;
    initPos.y += this->canvasRect.getSize().y;
    initPos.y += 20;

    this->colorRectangleRed = new fn::ColorRect(sf::Color(255,0,0), initPos, initSize);
    this->colorRectangleOrange = new fn::ColorRect(sf::Color(255, 162, 0), sf::Vector2f(initPos.x+80, initPos.y), initSize);
    this->colorRectangleYellow = new fn::ColorRect(sf::Color(255, 255, 0), sf::Vector2f(initPos.x+160, initPos.y), initSize);
    this->colorRectangleGreen = new fn::ColorRect(sf::Color(0, 255, 0), sf::Vector2f(initPos.x+240, initPos.y), initSize);
    this->colorRectangleCyan = new fn::ColorRect(sf::Color(0, 255, 255), sf::Vector2f(initPos.x+320, initPos.y), initSize);
    this->colorRectangleBlue = new fn::ColorRect(sf::Color(0, 0, 255), sf::Vector2f(initPos.x+400, initPos.y), initSize);
    this->colorRectanglePurple = new fn::ColorRect(sf::Color(150, 0, 255), sf::Vector2f(initPos.x+480, initPos.y), initSize);
    this->colorRectangleMagenta = new fn::ColorRect(sf::Color(255, 0, 255), sf::Vector2f(initPos.x+560, initPos.y), initSize);
    this->colorRectangleWhite = new fn::ColorRect(sf::Color(255, 255, 255), sf::Vector2f(initPos.x, initPos.y+80), sf::Vector2f(150, initSize.y));
    this->colorRectangleLightGray = new fn::ColorRect(sf::Color(170, 170, 170), sf::Vector2f(initPos.x+160, initPos.y+80), sf::Vector2f(150, initSize.y));
    this->colorRectangleDarkGray = new fn::ColorRect(sf::Color(85, 85, 85), sf::Vector2f(initPos.x+320, initPos.y+80), sf::Vector2f(150, initSize.y));
    this->colorRectangleBlack = new fn::ColorRect(sf::Color(0, 0, 0), sf::Vector2f(initPos.x+480, initPos.y+80), sf::Vector2f(150, initSize.y));
    this->colorPreview = new fn::ColorRect(this->color, sf::Vector2f(initPos.x+650, initPos.y), sf::Vector2f(initSize.x, 150));
}

void Draw::initWhiteRectangles()
{
    float op1;
    float op2;
    this->whiteRectangleUp.setFillColor(sf::Color::White);
    this->whiteRectangleDown.setFillColor(sf::Color::White);
    this->whiteRectangleRight.setFillColor(sf::Color::White);
    this->whiteRectangleLeft.setFillColor(sf::Color::White);

    this->whiteRectangleUp.setPosition(sf::Vector2f(0, 0));
    this->whiteRectangleUp.setSize(sf::Vector2f(videoMode.width, 85));

    op1 = videoMode.width * .68;
    op1 *= .45;
    op1 += 85;
    this->whiteRectangleDown.setPosition(sf::Vector2f(0, op1));
    
    op1 = videoMode.height - op1;
    this->whiteRectangleDown.setSize(sf::Vector2f(videoMode.width, op1));

    op1 = videoMode.width * .68;
    op2 = videoMode.width / 2;
    op2 -= op1 / 2;
    op1 += op2;
    this->whiteRectangleRight.setPosition(sf::Vector2f(op1, 0));

    op2 = videoMode.width - op1;
    this->whiteRectangleRight.setSize(sf::Vector2f(op2, videoMode.height));

    this->whiteRectangleLeft.setPosition(sf::Vector2f(0, 0));

    op1 = videoMode.width * .68;
    op2 = videoMode.width / 2;
    op2 -= op1 / 2;
    this->whiteRectangleLeft.setSize(sf::Vector2f(op2, videoMode.height));
}

// Constructor / Destructor
Draw::Draw()
{
    this->initVariables();
    this->initWindow();
    this->initTextTitle();
    this->initTextRadius();
    this->initCanvasRect();
    this->initPreviewCircle();
    this->initColorRectangles();
    this->initWhiteRectangles();
}

Draw::~Draw()
{
    delete this->window;
}

// Accessors
const bool Draw::running() const
{
    return this->window->isOpen();
}

void Draw::checkWindowSize()
{
    sf::Vector2u windowSize = window->getSize();
    if(windowSize.x != videoMode.width or windowSize.y != videoMode.height)
    {
        videoMode.width = windowSize.x;
        videoMode.height = windowSize.y;
        reInitWindow();
    }
}

// Event Functions
void Draw::keyEvent(sf::Event event)
{
    switch(event.key.code)
    {
        case sf::Keyboard::Escape:
            this->window->close();
        break;

        case sf::Keyboard::Z:
            this->undo();
        break;

        case sf::Keyboard::Y:
            this->redo();
        break;

        case sf::Keyboard::C:
            this->clean();
        break;

        case sf::Keyboard::H:
            this->openHelpWindow();
        break;
    }
}

void Draw::mouseButtonPressedEvent(sf::Event event)
{
   switch (event.mouseButton.button)
   {
    case sf::Mouse::Button::Left:
        if(this->canvasRect.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y) and this->rectMode == false)
            this->pushCircle();
        else
            this->checkIfColorRectangleClicked();
    break;

    case sf::Mouse::Button::Right:
        if(this->rectMode == false)
            this->startPreviewRectangle();
    break;
    }
}

void Draw::changeRadius(int delta)
{
    this->radius += delta;
    if(this->radius < 1)
        this->radius = 1;
    this->previewCircle.setRadius(this->radius);
    this->previewCircle.setOrigin(sf::Vector2f(this->radius, this->radius));
}

void Draw::pushCircle()
{
    if(this->canvasRect.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y)){

        this->circles.push_back(this->previewCircle);
        this->objectsIndex.push_back(2);
    }
}

void Draw::checkIfColorRectangleClicked()
{
    if(this->colorRectangleRed->checkIfClicked(this->window))
        this->color = colorRectangleRed->color;
    else if(this->colorRectangleOrange->checkIfClicked(this->window))
        this->color = colorRectangleOrange->color;
    else if(this->colorRectangleYellow->checkIfClicked(this->window))
        this->color = colorRectangleYellow->color;
    else if(this->colorRectangleGreen->checkIfClicked(this->window))
        this->color = colorRectangleGreen->color;
    else if(this->colorRectangleCyan->checkIfClicked(this->window))
        this->color = colorRectangleCyan->color;
    else if(this->colorRectangleBlue->checkIfClicked(this->window))
        this->color = colorRectangleBlue->color;
    else if(this->colorRectanglePurple->checkIfClicked(this->window))
        this->color = colorRectanglePurple->color;
    else if(this->colorRectangleMagenta->checkIfClicked(this->window))
        this->color = colorRectangleMagenta->color;
    else if(this->colorRectangleWhite->checkIfClicked(this->window))
        this->color = colorRectangleWhite->color;
    else if(this->colorRectangleLightGray->checkIfClicked(this->window))
        this->color = colorRectangleLightGray->color;
    else if(this->colorRectangleDarkGray->checkIfClicked(this->window))
        this->color = colorRectangleDarkGray->color;
    else if(this->colorRectangleBlack->checkIfClicked(this->window))
        this->color = colorRectangleBlack->color;

    this->colorPreview->updateColor(this->color);
    this->previewCircle.setFillColor(this->color);
}

void Draw::startPreviewRectangle()
{
    if(this->canvasRect.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y))
    {
        this->rectMode = true;

        this->previewRectangleOrigin.x = this->mousePos.x;
        this->previewRectangleOrigin.y = this->mousePos.y;

        this->previewRectangle.setPosition(this->previewRectangleOrigin);
        this->previewRectangle.setFillColor(this->color);
        this->previewRectangle.setSize(sf::Vector2f(0, 0));
    }
}

void Draw::endPreviewRectangle()
{
    this->rectMode = false;

    if(this->canvasRect.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y))
    {
        this->rectangles.push_back(this->previewRectangle);
        this->objectsIndex.push_back(1);
    }
}

void Draw::undo()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) or sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
    {
        int index = this->objectsIndex[this->objectsIndex.size()-1];
        if(index == 1)
        {
            this->redoRectangles.push_back(this->rectangles[this->rectangles.size() - 1]);
            this->redoObjectsIndex.push_back(1);

            this->rectangles.pop_back();
            this->objectsIndex.pop_back();
        }
        else if(index == 2)
        {
            this->redoCircles.push_back(this->circles[this->circles.size() - 1]);
            this->redoObjectsIndex.push_back(2);

            this->circles.pop_back();
            this->objectsIndex.pop_back();
        }
    }
}

void Draw::redo()
{
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) or sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) and this->redoObjectsIndex.size() > 0)
    {
        int redoIndex = this->redoObjectsIndex.size() - 1;

         if(this->redoObjectsIndex[redoIndex] == 1)
        {
            this->rectangles.push_back(this->redoRectangles[this->redoRectangles.size() - 1]);
            this->objectsIndex.push_back(1);

            this->redoRectangles.pop_back();
            this->redoObjectsIndex.pop_back();
        }
        else if(this->redoObjectsIndex[redoIndex] == 2)
        {
            this->circles.push_back(this->redoCircles[this->redoCircles.size() - 1]);
            this->objectsIndex.push_back(2);

            this->redoCircles.pop_back();
            this->redoObjectsIndex.pop_back();
        }
    }
}

void Draw::clean()
{
    this->rectangles.clear();
    this->circles.clear();
    this->objectsIndex.clear();
    
    this->redoRectangles.clear();
    this->redoCircles.clear();
    this->redoObjectsIndex.clear();
}

void Draw::openHelpWindow()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) or sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
    {
        fn::HelpWindow helpWindow;

        while(helpWindow.running())
        {
            helpWindow.update();
        }
    }
}

// Update functions
void Draw::updateRadius()
{
    std::string str = "Radius: " + std::to_string(this->radius);
    this->textRadius.setString(str);
}

void Draw::updatePreviewCircle()
{
    if(this->canvasRect.getGlobalBounds().contains(this->mousePos.x, this->mousePos.y))
    {
        this->previewCircle.setPosition(this->mousePos.x, this->mousePos.y);
    }
}

void Draw::updatePreviewRectangle()
{
    sf::Vector2f size;
    size.x = this->mousePos.x;
    size.y = this->mousePos.y;

    size -= this->previewRectangleOrigin;

    this->previewRectangle.setSize(size);
}

// Render Functions
void Draw::renderObjects()
{
    int ic = 0;
    int ir = 0;
    for(int i = 0; i < objectsIndex.size(); i++)
    {
        if(objectsIndex[i] == 2)
        {
            this->window->draw(this->circles[ic]);
            ic++;
        }
        else if(objectsIndex[i] == 1)
        {
            this->window->draw(this->rectangles[ir]);
            ir++;
        }
    }
}

void Draw::renderColorRectangles()
{
    this->window->draw(this->colorRectangleRed->rectangle);
    this->window->draw(this->colorRectangleOrange->rectangle);
    this->window->draw(this->colorRectangleYellow->rectangle);
    this->window->draw(this->colorRectangleGreen->rectangle);
    this->window->draw(this->colorRectangleCyan->rectangle);
    this->window->draw(this->colorRectangleBlue->rectangle);
    this->window->draw(this->colorRectanglePurple->rectangle);
    this->window->draw(this->colorRectangleMagenta->rectangle);
    this->window->draw(this->colorRectangleWhite->rectangle);
    this->window->draw(this->colorRectangleLightGray->rectangle);
    this->window->draw(this->colorRectangleDarkGray->rectangle);
    this->window->draw(this->colorRectangleBlack->rectangle);
    this->window->draw(this->colorPreview->rectangle);
}

// Funciones publicas
void Draw::events()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            
            case sf::Event::KeyPressed:
                this->keyEvent(this->event);
                break;

            case sf::Event::MouseButtonPressed:
                this->mouseButtonPressedEvent(this->event);
                break;

            case sf::Event::MouseButtonReleased:
                if(this->rectMode == true)
                    this->endPreviewRectangle();
                break;

            case sf::Event::MouseWheelMoved:
                this->changeRadius(this->event.mouseWheel.delta);
                break;
        }
    }
}

void Draw::update()
{
    this->mousePos = sf::Mouse::getPosition(*this->window);

    this->checkWindowSize();
    this->events();
    this->updateRadius();
    if(this->rectMode == false)
        this->updatePreviewCircle();
    else if(this->rectMode == true)
        this->updatePreviewRectangle();
}

void Draw::render()
{
    this->window->clear(sf::Color::White);

    this->renderObjects();

    if(this->rectMode == false)
        this->window->draw(this->previewCircle);
    else
        this->window->draw(this->previewRectangle);

    this->window->draw(this->whiteRectangleUp);
    this->window->draw(this->whiteRectangleDown);
    this->window->draw(this->whiteRectangleRight);
    this->window->draw(this->whiteRectangleLeft);
    this->window->draw(this->textTitle);
    this->window->draw(this->textRadius);
    this->window->draw(this->canvasRect);
    this->renderColorRectangles();

    this->window->display();
}
