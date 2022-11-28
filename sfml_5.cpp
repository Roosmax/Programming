
#include <SFML/Graphics.hpp>

const int N = 10000;
const int WX = 10000;
const int WY = 10000;

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
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WX, WY), "SFML shapes", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::CircleShape circle[N];
    sf::Vector2f vel[N];
    for (int i = 0; i < N; i++)
    {
        //sf::Color c(rand_uns(200, 255), rand_uns(200, 255), rand_uns(200, 255), 255);
        circle[i].setFillColor(sf::Color::Green);
        double rad = rand_uns(1, 10);
        circle[i].setRadius(rad);
        //circle[i].setOrigin(rad, rad);
        circle[i].setPosition(rand_uns(0, WX), rand_uns(0, WY));
        vel[i].x = rand_dbl(-1.0, 1.0);
        vel[i].y = rand_dbl(-1.0, 1.0);
    }

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
            if (circle[i].getPosition().x > WX)
                vel[i].x = vel[i].x > 0 ? -vel[i].x : vel[i].x;
            if (circle[i].getPosition().x < 0)
                vel[i].x = vel[i].x > 0 ? vel[i].x : -vel[i].x;
            if (circle[i].getPosition().y > WY)
                vel[i].y = vel[i].y > 0 ? -vel[i].y : vel[i].y;
            if (circle[i].getPosition().y < 0)
                vel[i].y = vel[i].y > 0 ? vel[i].y : -vel[i].y;
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
    }

    return 0;
}
