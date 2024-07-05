#include "draw.hpp"

int main()
{
    Draw app;

    while(app.running())
    {
        // events() inside update()
        app.update();

        app.render();
    }

return 0;
}