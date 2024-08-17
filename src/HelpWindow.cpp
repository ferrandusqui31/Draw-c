#include "HelpWindow.hpp"

void fn::HelpWindow::initVariables()
{
    this->window = nullptr;
    this->fontUbuntu.loadFromFile("../fonts/Ubuntu-Medium.ttf");
}

void fn::HelpWindow::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(700,330), "Draw Tutorial");
    this->window->setFramerateLimit(5);
}

void fn::HelpWindow::initText()
{
    this->tutorialText.setPosition(sf::Vector2f(10, 10));
    this->tutorialText.setFont(this->fontUbuntu);
    this->tutorialText.setFillColor(sf::Color::Black);
    this->tutorialText.setCharacterSize(23);
    this->tutorialText.setLineSpacing(1.5);

    std::string instr;
    std::string totalstr;

    std::ifstream inFile;
    inFile.open("../texts/tutorial.txt");
    while(inFile >> instr)
    {
        if(instr != "\\n")
        {
            totalstr.append(instr);
            totalstr.push_back(' ');
        }
        else if(instr == "\\n")
        {
            totalstr.push_back('\n');
        }
        
    }
    inFile.close();

    this->tutorialText.setString(totalstr);

}

// Constructor / Destructor
fn::HelpWindow::HelpWindow()
{
    this->initVariables();
    this->initWindow();
    this->initText();
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
    this->window->clear(sf::Color::White);
    this->window->draw(this->tutorialText);
    this->window->display();
}