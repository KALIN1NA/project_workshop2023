#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    sf::Vector2f circleOffset = {400.f, 300.f};
    sf::Vector2f circleWayRadius = {200.f, 100.f};
    sf::Vector2f circleRadius = {200.f, 200.f};
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    constexpr int pointCount = 200;
    float pointWay = 0;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Rosie", sf::Style::Default, settings);

    sf::ConvexShape rose;
    rose.setFillColor(sf::Color(255, 12, 121));

    rose.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; pointNo++)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = sf::Vector2f{
            circleRadius.x * std::cos(6 * angle) * std::cos(angle),
            circleRadius.y * std::cos(6 * angle) * std::sin(angle)};
        rose.setPoint(pointNo, point);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        float deltaTime = float(2 * M_PI * pointWay) / float(pointCount);
        rose.setPosition({
            circleOffset.x + circleWayRadius.x * std::cos(deltaTime),
            circleOffset.y + circleWayRadius.y * std::sin(deltaTime),
        });
        pointWay += 0.1;

        window.clear();
        window.draw(rose);
        window.display();
    }
}