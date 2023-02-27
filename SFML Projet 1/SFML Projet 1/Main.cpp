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
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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
