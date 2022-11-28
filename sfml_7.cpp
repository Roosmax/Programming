
#include <SFML/Graphics.hpp>

const int N = 2000;
const int WX = 1600;
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
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WX, WY), "SFML shapes", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::CircleShape *circle = new sf::CircleShape[N];
    sf::Vector2f *vel = new sf::Vector2f[N];
    sf::Vector2f *acc = new sf::Vector2f[N];
    for (int i = 0; i < N; i++)
    {
        sf::Color c(rand_uns(0, 255), rand_uns(0, 255), rand_uns(0, 255), 255);
        circle[i].setFillColor(c);
        double rad = rand_uns(10, 50);
        circle[i].setRadius(rad);
        circle[i].setOrigin(rad, rad);
        circle[i].setPosition(rand_uns(WX * 0.2, WX * 0.4), rand_uns(WY * 0.2, WY * 0.4));
        vel[i].x = rand_dbl(50.0, 100.0);
        vel[i].y = rand_dbl(-100.0, -50.0);
        acc[i].x = 0;
        acc[i].y = 0;
    }

    sf::Vector2f center(WX/2, WY/2);
    double dt_model = 0.0001;
    double dt_draw = 0.016;

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

        double t = 0;

        while (t < dt_draw)
        {
            for (int i = 0; i < N; i++)
            {
                acc[i] = circle[i].getPosition() - center;
                double rabs = abs(acc[i]);
                double coeff = 10000000.0;// * circle[i].getRadius() * circle[i].getRadius();
                acc[i].x *= - coeff / rabs / rabs / rabs;
                acc[i].y *= - coeff / rabs / rabs / rabs;
            }

            for (int i = 0; i < N; i++)
            {
                vel[i].x += acc[i].x * dt_model;
                vel[i].y += acc[i].y * dt_model;
            }

            for (int i = 0; i < N; i++)
            {
                sf::Vector2f dx(vel[i].x * dt_model, vel[i].y * dt_model);
                circle[i].move(dx);
            }
            t += dt_model;
        }

        window.clear();
        for (int i = 0; i < N; i++)
        {
            window.draw(circle[i]);
        }
        window.display();
    }

    delete[] circle;
    delete[] vel;
    return 0;
}
