#include "Enemy.h"

Enemy::Enemy() {

}

void Enemy::spawnerEnemy(sf::RenderWindow& window) {
    sf::ConvexShape Enemy;
    Enemy.setPointCount(3);
    Enemy.setPoint(0, sf::Vector2f(25.f, 50.f));
    Enemy.setPoint(1, sf::Vector2f(0.f, 25.f));
    Enemy.setPoint(2, sf::Vector2f(50.f, 25.f));
    Enemy.setFillColor(sf::Color::Red);
    Enemy.setPosition(50.f, 50.f);

    window.draw(Enemy);
}