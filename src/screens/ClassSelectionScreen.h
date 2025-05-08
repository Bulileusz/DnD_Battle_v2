#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>

class ClassSelectionScreen : public Screen {
  private:
    sf::Font font;
    sf::Text title;
    sf::Text warriorOption;
    sf::Text mageOption;
    sf::Text archerOption;

    bool finished = false;
    int selectedClass = 0;

  public:
    ClassSelectionScreen();

    void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
    void update() override {}
    void render(sf::RenderWindow& window) override;

    bool isFinished() const override { return finished; }
    int getSelectedClass() const { return selectedClass; }
    };