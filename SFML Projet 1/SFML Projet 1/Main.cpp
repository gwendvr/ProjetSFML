#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(390, 650), "SFML Window");
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

        sf::VertexArray lines(sf::Lines, 4);
        lines[0].position = sf::Vector2f(130, 0);
        lines[0].color = sf::Color::White;
        lines[1].position = sf::Vector2f(130, 650);
        lines[1].color = sf::Color::White;
        lines[2].position = sf::Vector2f(260, 0);
        lines[2].color = sf::Color::White;
        lines[3].position = sf::Vector2f(260, 650);
        lines[3].color = sf::Color::White;

        window.draw(background);
        window.draw(lines);
        window.display();
    }

    return 0;
}

