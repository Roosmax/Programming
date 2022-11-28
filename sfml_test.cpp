#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

sf::RenderWindow window(sf::VideoMode(1280,860),"SFMLworks!");

sf::Clock clockTick;
sf::Time timeTick=sf::milliseconds(10);


float x=640.0f;
float y=430.0f;

char key =' ';
float shift =3.0f;

void Tick()                             //метод для отдельного потока внутренних событий
{
    while(true)
    {
        switch (key)
        {
            case 'u':
                y-=shift;
            break;
            case 'd':
                y+=shift;
            break;
            case 'r':
                x+=shift;
            break;
            case 'l':
                x-=shift;
            break;
        }
        //end
        if (clockTick.getElapsedTime()<timeTick)                //контроль времени
            sf::sleep(timeTick-clockTick.getElapsedTime());
        clockTick.restart();
    }
}


int main()
{

    window.setFramerateLimit (60);

    sf::Thread tickThread(&Tick);                           //создаем и запускаем отдельный поток
    tickThread.launch();

    while(window.isOpen())                                  //это отрисовка и обработка внешних событий
    {
        sf::Event event;
        while(window.pollEvent(event))                      //обрабатываемп события
        {

            if (event.type==sf::Event::Closed)
                window.close();
            if (event.type==sf::Event::KeyPressed)          //нажатия клавиш
                switch (event.key.code){
                    case sf::Keyboard::Up:
                        key='u';
                    break;
                    case sf::Keyboard::Down:
                        key='d';
                    break;
                    case sf::Keyboard::Left:
                        key='l';
                    break;
                    case sf::Keyboard::Right:
                        key='r';
                    break;
                    }
            if (event.type==sf::Event::KeyReleased)         //отпустили клавишу
                key=' ';
        }

        window.clear ();                                            //очищаем экран

        sf::Vertex line[] ={sf::Vertex(sf::Vector2f(x+0.f, y+5.f)),
                            sf::Vertex(sf::Vector2f(x+5.f, y-5.f)),
                            sf::Vertex(sf::Vector2f(x-5.f, y-5.f))};//задаем форму треугольник

        window.draw(line, 4, sf::Triangles);                        //рисуем треугольник

        float r = 2.0f;
        sf::CircleShape circle;                                     //задаем параметры кружка
        circle.setFillColor(sf::Color::Red);
        circle.setRadius(r);
        circle.setPosition(x-r, y-10.0f-r);

        window.draw(circle);                                        //рисуем кружок

        window.display();                                           //отображаем всё
    }

    tickThread.terminate();

    return 0;
}
