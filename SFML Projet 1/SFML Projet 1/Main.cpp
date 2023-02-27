#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Enemy.h"
#include "Coin.h"
#include "Player.h"


sf::RenderWindow window(sf::VideoMode(390, 650), "SFML Window");

int main()
{
    Enemy enemy(sf::ConvexShape(3), sf::Color::Red);
    Enemy enemy1(sf::ConvexShape(3), sf::Color::Red);
    Coin coin(sf::CircleShape(10), sf::Color::Red);
    Map map;
    enemy1.enemy.setPosition(160.f, 50.f);
    Player player("name", sf::Color::Blue, sf::CircleShape(20));
    player.shape.setPosition(175, 550);

    sf::FloatRect playerBounds = player.shape.getGlobalBounds();
    sf::FloatRect enemyBounds = enemy.enemy.getGlobalBounds();

    bool canMove;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && canMove)
            {
                canMove = false;
                player.moveLeft();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canMove)
            {
                canMove = false;
                player.moveRight();
            }
            else {
                canMove = true;
            }
        }

        // Mise à jour de la position du joueur
        sf::FloatRect playerBounds = player.shape.getGlobalBounds();

        // Mise à jour de la position de l'ennemi
        enemy1.update(window);
        sf::FloatRect enemyBounds = enemy1.enemy.getGlobalBounds();

        if (playerBounds.intersects(enemyBounds)) {
            // faire disparaître le cercle
            player.shape.setFillColor(sf::Color::Transparent);
        }

        window.clear();

        map.loadMap(window);
        map.moveRectangle(window);
        map.drawMap(window);
        enemy.update(window);
        enemy.draw(window);
        enemy1.draw(window);
        coin.update(window);
        coin.draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}
