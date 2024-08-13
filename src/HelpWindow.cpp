#include "HelpWindow.hpp"

void fn::HelpWindow::initWindow()
{
    this->window = nullptr;
    this->window = new sf::RenderWindow(sf::VideoMode(800,800), "Draw Tutorial");
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
        if(event.type == sf::Event::Closed)
            this->window->close();
    }
    
}
