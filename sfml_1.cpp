#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);

    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setPosition(400, 300);
    //rectangle.setFillColor(sf::Color::Cyan);
    //rectangle.rotate(45);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
