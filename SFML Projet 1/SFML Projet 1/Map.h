#pragma once
#include <SFML/Graphics.hpp>

class Map {
public:
    Map();
    void loadMap(sf::RenderWindow& window);
    void drawMap(sf::RenderWindow& window);
    void moveRectangle(sf::RenderWindow& window);
private:
    std::vector<sf::VertexArray> lines1;
    std::vector<sf::Vector2f> speeds1;
    std::vector<sf::VertexArray> lines2;
    std::vector<sf::Vector2f> speeds2;
    std::vector<sf::VertexArray> lines3;
    std::vector<sf::Vector2f> speeds3;
    float speed = 3;
    sf::Clock clock;
    int spawnCounter = 0;
};

void coinSpawner();