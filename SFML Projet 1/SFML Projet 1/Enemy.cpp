#include "Enemy.h"

Enemy::Enemy(sf::ConvexShape e, sf::Color c) : enemy(e), color(c) {
    enemy.setPointCount(3);
    enemy.setPoint(0, sf::Vector2f(25.f, 50.f));
    enemy.setPoint(1, sf::Vector2f(0.f, 25.f));
    enemy.setPoint(2, sf::Vector2f(50.f, 25.f));
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(50.f, 50.f);
}

void Enemy::update(sf::RenderWindow& window)
{
    enemy.move(0.f, 0.12f);
}

void Enemy::draw(sf::RenderWindow& window) const
{
    window.draw(enemy);
}