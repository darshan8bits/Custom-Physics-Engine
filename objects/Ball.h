#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::CircleShape shape;
	float velocityY;
public:
	Ball(float x, float y, float radius);
	void setColor(sf::Color color);

	void update(float gravity, float dt);

	void draw(sf::RenderWindow& window);

};
