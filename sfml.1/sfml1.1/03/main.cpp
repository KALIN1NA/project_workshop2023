#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Дом");

    window.clear();

    // прямоугольник для дома
    sf::RectangleShape house(sf::Vector2f(400, 300));
    house.setFillColor(sf::Color{150, 75, 0});
    house.setPosition(200, 300);

    // трапеция для крыши
    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(sf::Color{176, 0, 0}));
    roof.setPosition({400, 200});
    roof.setPointCount(4);
    roof.setPoint(0, {-180, 0});
    roof.setPoint(1, {+180, 0});
    roof.setPoint(2, {+300, 100});
    roof.setPoint(3, {-300, 100});
    roof.setFillColor(sf::Color::Blue);

    // вертикальный прямоугольник для трубы
    sf::RectangleShape chimney1(sf::Vector2f(40, 80));
    chimney1.setFillColor(sf::Color{128, 128, 128});
    chimney1.setPosition(500, 180);

    // горизонтальный прямоугольник для трубы
    sf::RectangleShape chimney2(sf::Vector2f(70, 50));
    chimney2.setFillColor(sf::Color{128, 128, 128});
    chimney2.setPosition(484, 140);

    // прямоугольник для двери
    sf::RectangleShape door(sf::Vector2f(100, 200));
    door.setFillColor(sf::Color::Black);
    door.setPosition(250, 400);

    // дым
    sf::CircleShape smoke1(20);
    smoke1.setPosition(510, 100);
    smoke1.setFillColor(sf::Color{211, 211, 211});

    sf::CircleShape smoke2(30);
    smoke2.setPosition(520, 70);
    smoke2.setFillColor(sf::Color{211, 211, 211});

    sf::CircleShape smoke3(35);
    smoke3.setPosition(530, 40);
    smoke3.setFillColor(sf::Color{211, 211, 211});

    sf::CircleShape smoke4(40);
    smoke4.setPosition(540, 20);
    smoke4.setFillColor(sf::Color{211, 211, 211});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.clear(sf::Color::White);
        window.draw(house);
        window.draw(door);
        window.draw(roof);
        window.draw(chimney1);
        window.draw(chimney2);
        window.draw(smoke1);
        window.draw(smoke2);
        window.draw(smoke3);
        window.draw(smoke4);

        window.display();
    }

    return 0;
}