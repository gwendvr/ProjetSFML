#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Enemy.h"
#include "Player.h"


sf::RenderWindow window(sf::VideoMode(390, 650), "SFML Window");

int main()
{
    Enemy enemy(sf::ConvexShape(3), sf::Color::Red);
    Map map;
    Player player("name", sf::Color::Blue, sf::CircleShape(20));
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

        window.clear();

        map.loadMap(window);
        map.moveRectangle(window);
        map.drawMap(window);
        enemy.update(window);
        enemy.draw(window);
        player.draw(window);

        window.display();
    }

    coinSpawner();

    return 0;
}
