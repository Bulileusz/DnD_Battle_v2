#pragma once
#include "Screen.h"
#include <SFML\Graphics.hpp>

class MainMenuScreen : public Screen {
private:
    sf::Font font;
    sf::Text title;
    sf::Text startOption;
    sf::Texture backgroundTexture;
    sf::Sprite background;

    bool finished = false;

public:
    MainMenuScreen();

    void handleEvent(sf::Event &event, sf::RenderWindow& window) override;

    void update() override {
    }

    void render(sf::RenderWindow &window) override;

    bool isFinished() const override { return finished; }
};
