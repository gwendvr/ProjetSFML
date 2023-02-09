#include <SFML/Graphics.hpp>
#include <vector>

void coinSpawner() {
    sf::CircleShape coin(10);
    coin.setFillColor(sf::Color(243, 199, 13));
    // set a 10-pixel wide orange outline
    coin.setOutlineThickness(3);
    coin.setOutlineColor(sf::Color(233, 173, 3));
    coin.setPosition(170, 150);
}