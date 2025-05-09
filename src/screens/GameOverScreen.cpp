#include "GameOverScreen.h"
#include <iostream>

GameOverScreen::GameOverScreen(int level, int exp, int wave) {
  if (!font.loadFromFile("assets/arial.ttf")) {
    std::cerr << "Czcionka error - game over screen\n";
    }

    title.setFont(font);
    title.setString("KONIEC GRY");
    title.setCharacterSize(36);
    title.setPosition(270, 100);

    statsText.setFont(font);
    statsText.setCharacterSize(24);
    statsText.setPosition(200, 200);
    statsText.setString("Poziom: " + std::to_string(level) +
                        "    | EXP: " + std::to_string(exp) +
                        "    | Fala: " + std::to_string(wave));

    prompt.setFont(font);
    prompt.setCharacterSize(20);
    prompt.setPosition(220, 300);
    prompt.setString("Wciśnij ENTER, aby zagrać ponownie");

 }

void GameOverScreen::handleEvent(sf::Event& event, sf::RenderWindow& window) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
    finished = true;
    }
}

void GameOverScreen::render(sf::RenderWindow& window) {
  window.draw(title);
  window.draw(statsText);
  window.draw(prompt);
}
