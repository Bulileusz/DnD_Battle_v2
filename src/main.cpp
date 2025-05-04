#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DnD Battle Test");

    sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(300.f, 250.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
