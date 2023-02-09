#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Map.h"


sf::RenderWindow window(sf::VideoMode(390, 650), "SFML Window");

int main()
{


    Map map;
    map.loadMap(window);
    coinSpawner();

    return 0;
}
