#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text label;

    public:
        Button() = default;
      Button(const std::wstring& text, sf::Vector2f position, sf::Color color, const sf::Font& font);

      void render(sf::RenderWindow& window) const;
      bool isClicked(sf::Vector2f mousePos) const;
      void setText(const std::wstring& text);
      };