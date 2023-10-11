#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "KAD");

    window.clear();

    sf::RectangleShape shapeK1(sf::Vector2f(20, 200));
    shapeK1.setPosition(60, 100);
    shapeK1.setFillColor(sf::Color::Blue);

    sf::RectangleShape shapeK2(sf::Vector2f(20, 120));
    shapeK2.setPosition(150, 100);
    shapeK2.setFillColor(sf::Color::Blue);
    shapeK2.setRotation(45);

    sf::RectangleShape shapeK3(sf::Vector2f(20, 140));
    shapeK3.setPosition(60, 200);
    shapeK3.setFillColor(sf::Color::Blue);
    shapeK3.setRotation(-45);

    sf::RectangleShape shapeA1(sf::Vector2f(200, 20));
    shapeA1.setPosition(200, 290);
    shapeA1.setFillColor(sf::Color::Blue);
    shapeA1.setRotation(290);

    sf::RectangleShape shapeA2(sf::Vector2f(200, 20));
    shapeA2.setPosition(300, 100);
    shapeA2.setFillColor(sf::Color::Blue);
    shapeA2.setRotation(-290);

    sf::RectangleShape shapeA3(sf::Vector2f(80, 20));
    shapeA3.setPosition(320, 200);
    shapeA3.setFillColor(sf::Color::Blue);
    shapeA3.setRotation(180);

    sf::RectangleShape shapeD1(sf::Vector2f(20, 190));
    shapeD1.setPosition(400, 100);
    shapeD1.setFillColor(sf::Color::Blue);

    sf::RectangleShape shapeD2(sf::Vector2f(130, 20));
    shapeD2.setPosition(420, 100);
    shapeD2.setFillColor(sf::Color::Blue);
    shapeD2.setRotation(45);

    sf::RectangleShape shapeD3(sf::Vector2f(130, 20));
    shapeD3.setPosition(400, 277);
    shapeD3.setFillColor(sf::Color::Blue);
    shapeD3.setRotation(-45);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(shapeK1);
        window.draw(shapeK2);
        window.draw(shapeK3);
        window.draw(shapeA1);
        window.draw(shapeA2);
        window.draw(shapeA3);
        window.draw(shapeD1);
        window.draw(shapeD2);
        window.draw(shapeD3);
        window.display();
    }

    return 0;
}