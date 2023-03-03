#include "Coin.h"

Coin::Coin(sf::CircleShape e, sf::Color c) : coin(e), color(c) {
    coin.setFillColor(sf::Color(243, 199, 13));
    coin.setOutlineThickness(3);
    coin.setOutlineColor(sf::Color(233, 173, 3));
    coin.setPosition(170, 150);
}

void Coin::update(sf::RenderWindow& window)
{
    coin.move(0.f, 0.12f);
}

void Coin::draw(sf::RenderWindow& window) const
{
    window.draw(coin);
}