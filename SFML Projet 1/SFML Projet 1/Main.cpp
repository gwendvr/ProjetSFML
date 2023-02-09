#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Enemy.h"


sf::RenderWindow window(sf::VideoMode(390, 650), "SFML Window");

int main()
{
    Enemy enemy;
    Map map;

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
        enemy.spawnerEnemy(window);
        window.display();
    }

    coinSpawner();

    return 0;
}
