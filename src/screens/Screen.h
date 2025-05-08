#pragma once
#include <SFML\Graphics.hpp>


class Screen {
public:
    virtual void handleEvent(sf::Event &event, sf::RenderWindow& window) = 0;

    virtual void update() = 0;

    virtual void render(sf::RenderWindow &window) = 0;

    virtual bool isFinished() const { return false; }

    virtual ~Screen() = default;
};
