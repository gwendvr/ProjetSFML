#include "map.h"
#include <ctime>
#include <cstdlib>

Map::Map() {
    srand(time(NULL));
}

void Map::loadMap(sf::RenderWindow& window) {
    std::vector<sf::VertexArray> lines1;
    std::vector<sf::Vector2f> speeds1;
    std::vector<sf::VertexArray> lines2;
    std::vector<sf::Vector2f> speeds2;
    std::vector<sf::VertexArray> lines3;
    std::vector<sf::Vector2f> speeds3;
    srand(time(NULL));

    float speed = 3;
    sf::Clock clock;
    int spawnCounter = 0;

    sf::RectangleShape background(sf::Vector2f(390, 650));
    sf::CircleShape coin(10);
    coin.setFillColor(sf::Color(243, 199, 13));
    // set a 10-pixel wide orange outline
    coin.setOutlineThickness(3);
    coin.setOutlineColor(sf::Color(233, 173, 3));
    coin.setPosition(170, 150);

    background.setFillColor(sf::Color(80, 80, 80));

    window.draw(background);

    sf::VertexArray sectionLines(sf::Lines, 4);
    sectionLines[0].position = sf::Vector2f(130, 0);
    sectionLines[0].color = sf::Color::White;
    sectionLines[1].position = sf::Vector2f(130, 750);
    sectionLines[1].color = sf::Color::White;
    sectionLines[2].position = sf::Vector2f(260, 0);
    sectionLines[2].color = sf::Color::White;
    sectionLines[3].position = sf::Vector2f(260, 750);
    sectionLines[3].color = sf::Color::White;

    window.draw(sectionLines);

    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() >= 0.2f)
    {
        clock.restart();

        int xPos = 65 + 130 * (spawnCounter % 3);
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(xPos, 0);
        line[0].color = sf::Color::White;
        line[1].position = sf::Vector2f(xPos, 10);
        line[1].color = sf::Color::White;

        sf::Vector2f speed(0, 0.1f);

        switch (spawnCounter % 3)
        {
        case 0:
            lines1.push_back(line);
            speeds1.push_back(speed);
            break;
        case 1:
            lines2.push_back(line);
            speeds2.push_back(speed);
            break;
        case 2:
            lines3.push_back(line);
            speeds3.push_back(speed);
            break;
        }

        spawnCounter++;
    }

    for (int i = 0; i < lines1.size(); i++)
    {
        lines1[i][0].position += speeds1[i];
        lines1[i][1].position += speeds1[i];

        if (lines1[i][1].position.y >= 650)
        {
            lines1.erase(lines1.begin() + i);
            speeds1.erase(speeds1.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < lines2.size(); i++)
    {
        lines2[i][0].position += speeds2[i];
        lines2[i][1].position += speeds2[i];

        if (lines2[i][1].position.y >= 650)
        {
            lines2.erase(lines2.begin() + i);
            speeds2.erase(speeds2.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < lines3.size(); i++)
    {
        lines3[i][0].position += speeds3[i];
        lines3[i][1].position += speeds3[i];

        if (lines3[i][1].position.y >= 650)
        {
            lines3.erase(lines3.begin() + i);
            speeds3.erase(speeds3.begin() + i);
            i--;
        }
    }

    for (auto line : lines1)
        window.draw(line);
    for (auto line : lines2)
        window.draw(line);
    for (auto line : lines3)
        window.draw(line);
}
