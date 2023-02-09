#pragma once
#include <SFML/Graphics.hpp>

class Map {
public:
    Map();
    void loadMap(sf::RenderWindow& window);
};

void coinSpawner();