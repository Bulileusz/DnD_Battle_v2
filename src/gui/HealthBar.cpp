#include "HealthBar.h"

HealthBar::HealthBar(float width, float height)
    : width(width), height(height) {
    backgroundBar.setSize(sf::Vector2f(width, height));
    backgroundBar.setFillColor(sf::Color(50, 50, 50));

    currentBar.setSize(sf::Vector2f(width, height));
    currentBar.setFillColor(sf::Color(200, 50, 50));
}

void HealthBar::setPosition(float x, float y) {
    backgroundBar.setPosition(x,y);
    currentBar.setPosition(x,y);
}

void HealthBar::update(int currentHp, int maxHp) {
    float ratio = (maxHp > 0) ? static_cast<float>(currentHp) / maxHp : 0.f;
    currentBar.setSize(sf::Vector2f(width * ratio, height));
}

void HealthBar::render(sf::RenderWindow& window) {
    window.draw(backgroundBar);
    window.draw(currentBar);
}

sf::Vector2f HealthBar::getPosition() const {
    return backgroundBar.getPosition();
}