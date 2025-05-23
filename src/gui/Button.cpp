#include "Button.h"

Button::Button(const std::wstring& text, sf::Vector2f position, sf::Color color, const sf::Font& font) {
    shape.setSize({140.f, 40.f});
    shape.setPosition(position);
    shape.setFillColor(color);

    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2.f);

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(22);
    label.setFillColor(sf::Color::White);
    label.setPosition(position.x + 40.f, position.y + 8.f);
}

void Button::render(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(label);
}

bool Button::isClicked(sf::Vector2f mousePos) const {
    return shape.getGlobalBounds().contains(mousePos);
}

void Button::setText(const std::wstring& text) {
    label.setString(text);
}



