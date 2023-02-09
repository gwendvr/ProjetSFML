#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>


Player::Player(const string name, sf::Color color, sf::CircleShape shape) : name(name), color(color), shape(shape) {
	
}