#include <SFML/Graphics.hpp>
#include "../objects/Ball.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics Simulator");

    std::vector<Ball> balls;

    float gravity = 980.0f;
    float dt = 1.0f / 60.0f;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                float x = event.mouseButton.x;
                float y = event.mouseButton.y;

                Ball newBall(x, y, 20);

                int r = rand() % 256;
                int g = rand() % 256;
                int b = rand() % 256;

                newBall.setColor(sf::Color(r, g, b));

                balls.push_back(newBall);
            }
        }

        for (auto& ball : balls)
        {
            ball.update(gravity, dt);
        }

        window.clear();

        for (auto& ball : balls)
        {
            ball.draw(window);
        }

        window.display();
    }

    return 0;
}