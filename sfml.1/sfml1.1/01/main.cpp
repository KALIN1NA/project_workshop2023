#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(200, 500), "Traffic Light");

    window.clear(sf::Color{128, 128, 128});

    sf::CircleShape redLight(70);
    redLight.setPosition(30, 30);
    redLight.setFillColor(sf::Color::Red);
    window.draw(redLight);

    sf::CircleShape yellowLight(70);
    yellowLight.setPosition(30, 180);
    yellowLight.setFillColor(sf::Color::Yellow);
    window.draw(yellowLight);

    sf::CircleShape greenLight(70);
    greenLight.setPosition(30, 330);
    greenLight.setFillColor(sf::Color::Green);
    window.draw(greenLight);

    window.display();

    sf::sleep(sf::seconds(5));
}
