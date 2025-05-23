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
    title.setFillColor(sf::Color::White);
    title.setPosition(800/2.f - title.getLocalBounds().width / 2.f, 150.f);

    statsText.setFont(font);
    statsText.setCharacterSize(24);
    statsText.setFillColor(sf::Color::White);



  std::wstring stats = L"Poziom: " + std::to_wstring(level) +
                   L"    |    EXP: " + std::to_wstring(exp) +
                   L"    |    Fala: " + std::to_wstring(wave);

  statsText.setString(stats);
  statsText.setPosition(800/2.f - statsText.getLocalBounds().width / 2.f, 230.f);

  prompt.setFont(font);
  prompt.setCharacterSize(18);
  prompt.setFillColor(sf::Color::White);
  prompt.setString(L"Wciśnij ENTER, aby wrócić do wyboru klasy.");
  prompt.setPosition(800/2.f - prompt.getLocalBounds().width / 2.f, 310.f);

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
