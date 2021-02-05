//https://www.youtube.com/watch?v=mtEiyDbYMxQ
//https://www.youtube.com/watch?v=WOyp5n2FmZY
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Awesome Game");
    
    while(window.isOpen())
        {
            sf::Event event;
            //handle all events
            while(window.pollEvent(event))
            {
                switch(event.type)
                {
                    case sf::Event::Closed:
                        window.clear();
                        break;
                }
            }
            //update the game
            window.clear();
            //draw objects here
            window.display();
        }
}
