#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	sf::Color color;
	sf::ConvexShape enemy;
	Enemy(sf::ConvexShape, sf::Color);
	void draw(sf::RenderWindow& window) const;
	void update(sf::RenderWindow& window);
};

