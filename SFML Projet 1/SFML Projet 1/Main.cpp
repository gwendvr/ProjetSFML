#include <SFML/Graphics.hpp>

void spawnRectangles(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rectangles, float spawnInterval) {
    float spawnTimer = 0.f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        spawnTimer += 1.f / 60.f;

        if (spawnTimer >= spawnInterval) {
            spawnTimer = 0.f;

            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(10, 50));
            rect.setFillColor(sf::Color::White);
            rect.setPosition(rand() % 800, -50);
            rectangles.push_back(rect);
        }

        for (auto it = rectangles.begin(); it != rectangles.end();) {
            it->move(0, 5);

            if (it->getPosition().y > 600) {
                it = rectangles.erase(it);
            }
            else {
                ++it;
            }
        }

        window.clear();

        for (const auto& rect : rectangles) {
            window.draw(rect);
        }

        window.display();
    }
}

int main()
{

    std::vector<sf::RectangleShape> rectangles;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Barrière");
    window.setFramerateLimit(60);

    //Création de la barrière rouge
    sf::RectangleShape barriere(sf::Vector2f(100, 15));
    barriere.setFillColor(sf::Color::Red);
    barriere.setPosition(50, 363);

    //Création des pieds en béton gris
    sf::RectangleShape pied1(sf::Vector2f(15, 40));
    sf::RectangleShape pied2(sf::Vector2f(15, 40));
    pied1.setFillColor(sf::Color(128, 128, 128));
    pied2.setFillColor(sf::Color(128, 128, 128));
    pied1.setPosition(35, 350);
    pied2.setPosition(135, 350);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(pied1);
        window.draw(pied2);
        window.draw(barriere);
        spawnRectangles(window, rectangles, 0.1f);
        window.display();
    }

    return 0;
}


