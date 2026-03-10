#include <SFML/Graphics.hpp>
#include "../objects/Ball.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    float dt = 1.0f / 60.0f;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics Simulator");

    std::vector<Ball> balls;

    float gravity = 1.0f;
    float xvelocity = 120.0f;
    float yvelocity = -80.0f;
    float coefficient_of_restitution = 0.7f;

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

                Ball newBall(x, y, 10.0f, xvelocity, yvelocity, coefficient_of_restitution);

                int r = rand() % 256;
                int g = rand() % 256;
                int b = rand() % 256;

                newBall.setColor(sf::Color(r, g, b));

                balls.push_back(newBall);
            }
        }

        // update positions:

        for (auto& ball : balls)
        {
            ball.updateX(dt);
            ball.updateY(gravity, dt);
        }

        // collision tracker algorithms:

        for (size_t i = 0; i < balls.size(); i++)
        {
            for (size_t j = i + 1; j < balls.size(); j++)
            {
                if (balls[i].checkCollision(balls[j]))
                {
                    balls[i].resolveCollision(balls[j]);
                }
            }
        }

        // render (clears and draws every frame -- 60 times a second)

        window.clear();

        for (auto& ball : balls)
        {
            ball.draw(window);
        }

        window.display();
    }

    return 0;
}