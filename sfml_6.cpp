
#include <SFML/Graphics.hpp>

const int N = 300;
const int WX = 1980;
const int WY = 1200;

#include <cmath>
double abs(sf::Vector2f v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

#include <chrono>
#include <random>
int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

double rand_dbl(double min, double max) {
    int resolution = 100000;
    return min + rand_uns(0, resolution)*(max - min) / resolution;
}

int main()
{
    sf::RectangleShape rectangle(sf::Vector2f(12000.f, 12000.f));
    rectangle.setPosition(400, 300);
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.setOrigin(60, 60);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WX, WY), "SFML shapes", sf::Style::Default, settings);
    window.setFramerateLimit(240);

    sf::CircleShape *circle = new sf::CircleShape[N];
    sf::Vector2f *vel = new sf::Vector2f[N];
    sf::Vector2f *acc = new sf::Vector2f[N];

    double vabs = 0.0001;
    sf::Vector2f v(0.01, 0);

    for (int i = 0; i < N; i++)
    {
        sf::Color c(rand_uns(0, 255), rand_uns(0, 255), rand_uns(0, 255), 255);
        circle[i].setFillColor(c);
        double rad = rand_uns(1, 10);
        circle[i].setRadius(rad);
        circle[i].setOrigin(rad, rad);
        circle[i].setPosition(rand_uns(0, WX), rand_uns(0, WY));
        vel[i].x = rand_dbl(-2.0, 2.0);
        vel[i].y = rand_dbl(-2.0, 2.0);
        acc[i].x = 0;
        acc[i].y = 0;
    }

    sf::Vector2f center(WX/2, WY/2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i < N; i++)
        {
            acc[i] = circle[i].getPosition() - center;
            double rabs = abs(acc[i]);
            acc[i].x *= - 10000.1 / rabs / rabs / rabs;
            acc[i].y *= - 10000.1 / rabs / rabs / rabs;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            v.y += -vabs;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            v.y += vabs;

        for (int i = 0; i < N; i++)
        {
            vel[i] += acc[i];
        }

        for (int i = 0; i < N; i++)
        {
            circle[i].move(vel[i]);
        }

        window.clear();
        for (int i = 0; i < N; i++)
        {
            window.draw(circle[i]);
        }
        window.display();
        window.draw(rectangle);
    }

    delete[] circle;
    delete[] vel;
    return 0;
}
