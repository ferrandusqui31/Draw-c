#include "Draw.hpp"

void Draw::initVariables()
{
    this->videoMode = toGetWindowSize.getDesktopMode();
    this->window = nullptr;
    this->fontAntonio.loadFromFile("Antonio.ttf");
    this->cursorCross.loadFromSystem(sf::Cursor::Cross);

    this->radius = 20;
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
    this->preview.setFillColor(sf::Color::Black);
    this->preview.setRadius(this->radius);
    this->preview.setOrigin(this->radius, this->radius);
}

void Draw::initColorRectangles()
{
    this->colorRectangleRed = nullptr;
    this->colorRectangleRed = new ColorRect(sf::Color(255,0,0), sf::Vector2f(200, 200), sf::Vector2f(75, 75));
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

void Draw::keyEvent(sf::Event event)
{
    switch(event.key.code)
    {
        case sf::Keyboard::Escape:
            this->window->close();
            break;
    }
}

void Draw::changeRadius(int delta)
{
    this->radius += delta;
    if(this->radius < 1)
        this->radius = 1;
    this->preview.setRadius(this->radius);
    this->preview.setOrigin(sf::Vector2f(this->radius, this->radius));
}

void Draw::pushCircle()
{
    this->circles.push_back(this->preview);
}

void Draw::updateRadius()
{
    std::string str = "Radius: " + std::to_string(this->radius);
    this->textRadius.setString(str);
}

void Draw::updatePreviewCircle()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
    if(this->canvasRect.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        this->preview.setPosition(mousePos.x, mousePos.y);
    }
}

void Draw::renderCircles()
{
    for(int i = 0; i < circles.size(); i++)
    {
        window->draw(circles[i]);
    }
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
                if(this->event.mouseButton.button == sf::Mouse::Button::Left)
                    this->pushCircle();
                break;
            case sf::Event::MouseWheelMoved:
                this->changeRadius(this->event.mouseWheel.delta);
                break;
        }
    }
}

void Draw::update()
{
    this->checkWindowSize();
    this->events();
    this->updateRadius();
    this->updatePreviewCircle();
}

void Draw::render()
{
    this->window->clear(sf::Color::White);

    this->renderCircles();
    this->window->draw(this->preview);
    this->window->draw(this->textTitle);
    this->window->draw(this->textRadius);
    this->window->draw(this->canvasRect);
    this->window->draw(this->colorRectangleRed->rectangle);

    this->window->display();
}