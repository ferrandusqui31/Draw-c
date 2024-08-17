#include "HelpWindow.hpp"

void fn::HelpWindow::initWindow()
{
    this->window = nullptr;
    this->window = new sf::RenderWindow(sf::VideoMode(700,700), "Draw Tutorial");
    this->window->setFramerateLimit(5);
}

// Constructor / Destructor
fn::HelpWindow::HelpWindow()
{
    this->initWindow();
}

fn::HelpWindow::~HelpWindow()
{
    delete this->window;
}

const bool fn::HelpWindow::running() const
{
    return this->window->isOpen();
}

void fn::HelpWindow::events()
{
    while(this->window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed or event.key.code == sf::Keyboard::Escape)
            this->window->close();
    }
    
}

void fn::HelpWindow::update()
{
    this->events();
    this->render();
}

void fn::HelpWindow::render()
{
    this->window->clear();
    this->window->display();
}