#pragma once
#include <SFML/Graphics.hpp>

class HealthBar {
private:

    sf::RectangleShape backgroundBar;
    sf::RectangleShape currentBar;
    float width;
    float height;

public:
    HealthBar(float width = 100.f, float height = 10.f);
    void setPosition(float x, float y);
    void update(int currentHp, int maxHp);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
};

