#pragma once
#include <SFML/Graphics.hpp>

class Coin
{
public:
	sf::Color color;
	sf::CircleShape coin;
	Coin(sf::CircleShape, sf::Color);
	void draw(sf::RenderWindow& window) const;
	void update(sf::RenderWindow& window);
};

