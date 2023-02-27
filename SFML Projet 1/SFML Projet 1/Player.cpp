#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

Player::Player(const string n, sf::Color c, sf::CircleShape s) : name(n), color(c), shape(s) {
	shape.setFillColor(c);
}

Player::Player() {}
Player::~Player() {}


void Player::draw(sf::RenderWindow& window) const
{
	window.draw(shape);
}

void Player::moveLeft()
{
	int coord = static_cast <int>(shape.getPosition().x);
	if (coord > 45) {
		shape.setPosition(coord - 130, 550);
	}
}

void Player::moveRight()
{
	int coord = static_cast <int>(shape.getPosition().x);
	if (coord < 305) {
		shape.setPosition(coord + 130, 550);
	}
}