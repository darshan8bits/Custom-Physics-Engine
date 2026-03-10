#include "Ball.h"

Ball::Ball(float x, float y, float radius, float x_vel, float y_vel, float e)
{
    shape.setRadius(radius);
    shape.setPosition(x, y);
    velocityY = y_vel;
    velocityX = x_vel;
    coeff = e;
}

void Ball::setColor(sf::Color color)
{
    shape.setFillColor(color);
}

void Ball::updateY(float gravity, float dt)
{
    velocityY += gravity * dt;

    float posY = shape.getPosition().y;
    posY += velocityY * dt;

    if (posY + shape.getRadius() >= 600)
    {
        posY = 600 - shape.getRadius();
        velocityY *= -coeff;
    }

    if (posY + shape.getRadius() <= 0) {
        posY = 0;
        velocityY *= -coeff;
    }

    shape.setPosition(shape.getPosition().x, posY);
}
void Ball::updateX()
{
    float posX = shape.getPosition().x;
    posX += velocityX;
    if (posX + shape.getRadius() >= 800)
    {
        posX = 800 - shape.getRadius();
        velocityX *= -coeff;
    }
    if (posX + shape.getRadius() <= 0) {
        posX = 0;
        velocityX *= -coeff;
    }
    shape.setPosition(posX, shape.getPosition().y);
}
void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}