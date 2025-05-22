#include "GameOverScreen.h"
#include <iostream>

GameOverScreen::GameOverScreen(int level, int exp, int wave) {
  if (!font.loadFromFile("assets/Spectral-Regular.ttf")) {
    std::cerr << "Czcionka error - game over screen\n";
    }
  if (!backgroundTexture.loadFromFile("assets/gameover_bg.png")) {
    std::cerr << "Nie wczytano tła game over.\n";
  }
  background.setTexture(backgroundTexture);

  sf::Vector2u textureSize = backgroundTexture.getSize();
  sf::Vector2u windowSize(800,600);

  background.setScale(
      static_cast<float>(windowSize.x) / textureSize.x,
      static_cast<float>(windowSize.y) / textureSize.y
      );

    title.setFont(font);
    title.setString(L"KONIEC GRY");
    title.setCharacterSize(36);
    title.setPosition(270, 100);

    statsText.setFont(font);
    statsText.setCharacterSize(24);
    statsText.setPosition(200, 200);
  statsText.setString(L"Poziom: " + std::to_wstring(level) +
                  L"    | EXP: " + std::to_wstring(exp) +
                  L"    | Fala: " + std::to_wstring(wave));

    prompt.setFont(font);
    prompt.setCharacterSize(20);
    prompt.setPosition(220, 300);
    prompt.setString(L"Wciśnij ENTER, aby wrócić do menu");

 }

void GameOverScreen::handleEvent(sf::Event& event, sf::RenderWindow& window) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
    finished = true;
    }
}

void GameOverScreen::render(sf::RenderWindow& window) {
  window.draw(background);
  window.draw(title);
  window.draw(statsText);
  window.draw(prompt);
}
