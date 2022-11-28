
#include <SFML/Graphics.hpp>

/*#include <cmath>
double abs(sf::Vector2f v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);
    //circle.setOrigin(100, 100);
    //circle.setPosition(100, 100);

    sf::RectangleShape rectangle(sf::Vector2f(120.f, 120.f));
    rectangle.setPosition(400, 300);
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.setOrigin(60, 60);
    //rectangle.rotate(45);

    //double vabs = 0.0001;
    //sf::Vector2f v(0.01, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            v.x += -vabs;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            v.x += vabs;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            v.y += -vabs;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            v.y += vabs;*/


        //if (abs(circle.getPosition() - rectangle.getPosition()) < 10 && abs(v) < 1)
        //        window.close();


        rectangle.rotate(0.1);
        circle.move(0.01, 0);

        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
