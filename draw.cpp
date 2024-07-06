#include "draw.hpp"

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

// Constructor / Destructor
Draw::Draw()
{
    this->initVariables();
    this->initWindow();
    this->initTextTitle();
    this->initTextRadius();
    this->initCanvasRect();
    this->initPreviewCircle();
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
    this->preview.setOrigin(sf::Vector2f(this->radius, this->radius));
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

    this->window->draw(preview);
    this->window->draw(textTitle);
    this->window->draw(textRadius);
    this->window->draw(canvasRect);

    this->window->display();
}