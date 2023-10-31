#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    sf::Vector2f speed = {100.f, 20.f};
    constexpr float BALL_SIZE = 50;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Moving Ball");
    sf::Clock clock;

    sf::CircleShape ball(BALL_SIZE);
    ball.setPosition({200, 210});
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

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

        const float dt = clock.restart().asSeconds();

        sf::Vector2f position = ball.getPosition();
        position.x += speed.x * dt;
        position.y = 200 + 100 * std::cos(position.x / 20.f);

        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speed.x > 0))
        {
            speed.x = -speed.x;
            position.y = -position.y;
        }
        if ((position.x < 0) && (speed.x < 0))
        {
            speed.x = -speed.x;
            position.y = -position.y;
        }
        if ((position.y + 2 * BALL_SIZE >= WINDOW_HEIGHT) && (speed.y > 0))
        {
            speed.y = -speed.y;
        }
        if ((position.y < 0) && (speed.y < 0))
        {
            speed.y = -speed.y;
        }

        ball.setPosition(position);

        // Draw current state
        window.clear();
        window.draw(ball);
        window.display();
    }
}