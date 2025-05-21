#pragma once
#include "Screen.h"
#include <SFML\Graphics.hpp>

class GameOverScreen : public Screen {
private:
  sf::Font font;
  sf::Text title;
  sf::Text statsText;
  sf::Text prompt;
  sf::Texture backgroundTexture;
  sf::Sprite background;

  bool finished = false;

public:
  GameOverScreen(int level, int exp, int wave);

  void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
  void update() override {}
  void render(sf::RenderWindow& window) override;
  bool isFinished() const override { return finished; }
};