#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    sf::RenderWindow window(sf::VideoMode(390, 650), "SFML Window");

    std::vector<sf::VertexArray> lines1;
    std::vector<sf::Vector2f> speeds1;
    std::vector<sf::VertexArray> lines2;
    std::vector<sf::Vector2f> speeds2;
    std::vector<sf::VertexArray> lines3;
    std::vector<sf::Vector2f> speeds3;
    srand(time(NULL));

    sf::Clock clock;
    int spawnCounter = 0;

    sf::RectangleShape background(sf::Vector2f(390, 650));
    background.setFillColor(sf::Color(80,80,80));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);

        sf::VertexArray sectionLines(sf::Lines, 4);
        sectionLines[0].position = sf::Vector2f(130, 0);
        sectionLines[0].color = sf::Color::White;
        sectionLines[1].position = sf::Vector2f(130, 650);
        sectionLines[1].color = sf::Color::White;
        sectionLines[2].position = sf::Vector2f(260, 0);
        sectionLines[2].color = sf::Color::White;
        sectionLines[3].position = sf::Vector2f(260, 650);
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

            if (lines1[i][1].position.y >= 600)
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

            if (lines2[i][1].position.y >= 600)
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

            if (lines3[i][1].position.y >= 600)
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

        window.display();
    }

    return 0;
}

