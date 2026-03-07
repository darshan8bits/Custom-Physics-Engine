#include "Ball.h"

Ball::Ball(float x, float y, float radius)
{
    shape.setRadius(radius);
    shape.setPosition(x, y);
    velocityY = 0;
}

void Ball::setColor(sf::Color color)
{
    shape.setFillColor(color);
}

void Ball::update(float gravity, float dt)
{
    velocityY += gravity * dt;

    float posY = shape.getPosition().y;
    posY += velocityY * dt;

    if (posY + shape.getRadius() >= 600)
    {
        posY = 600 - shape.getRadius();
        velocityY *= -0.8f;
    }

    shape.setPosition(shape.getPosition().x, posY);
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}