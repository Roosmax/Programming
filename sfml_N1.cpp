
#include <SFML/Graphics.hpp>

#include <cmath>
double abs(sf::Vector2f v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::CircleShape triangle(200, 3);
    triangle.setPosition(400, 300);
    triangle.setFillColor(sf::Color::Blue);
    triangle.setOrigin(200, 200);

    sf::RectangleShape rectangle(sf::Vector2f(120.f, 120.f));
    rectangle.setPosition(400, 300);
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.setOrigin(60, 60);

    double vabs = 0.0001;
    sf::Vector2f v(0.01, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i i = sf::Mouse::getPosition(window);
            sf::Vector2f p(i.x, i.y);
            //if (abs(p - rectangle.getPosition()) < 10)
            rectangle.setPosition(p);
        }

        triangle.rotate(0.2);

        window.clear();
        window.draw(triangle);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
