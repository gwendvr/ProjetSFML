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