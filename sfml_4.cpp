#include <SFML/Graphics.hpp>

#include <cmath>
double abs(sf::Vector2f v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

int main()
{
    /*sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);*/
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    //window.setFramerateLimit(60);

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);
    circle.setOrigin(100, 100);
    circle.setPosition(100, 100);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            v.x += -vabs;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            v.x += vabs;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            v.y += -vabs;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            v.y += vabs;

        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            rectangle.scale(0.999, 0.999);
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            rectangle.scale(1.001, 1.001);*/

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i i = sf::Mouse::getPosition(window);
            sf::Vector2f p(i.x, i.y);
            //if (abs(p - rectangle.getPosition()) < 10)
                rectangle.setPosition(p);
        }


        if (abs(circle.getPosition() - rectangle.getPosition()) < 10 && abs(v) < 1)
                window.close();


        rectangle.rotate(0.1);
        circle.move(v);

        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
