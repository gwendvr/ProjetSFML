#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class Player
{
public:
	string name;
	sf::Color color;
	sf::CircleShape shape;

	Player(const string, sf::Color, sf::CircleShape);
	Player();
	~Player();

	void draw(sf::RenderWindow&) const;
	
};

