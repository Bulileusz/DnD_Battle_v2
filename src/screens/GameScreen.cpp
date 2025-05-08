#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen(Player::ClassType selectedClass)
    : player(selectedClass), enemy(BattleManager().spawnEnemyForLevel(1))
{
  if (!font.loadFromFile("assets/arial.ttf")) {
    std::cerr << "Nie wczytano czcionki\n";
}
  // Staty
  playerStats.setFont(font);
  playerStats.setCharacterSize(20);
  playerStats.setPosition(50, 30);

  enemyStats.setFont(font);
  enemyStats.setCharacterSize(20);
  enemyStats.setPosition(500, 30);

  // Log
  logText.setFont(font);
  logText.setCharacterSize(18);
  logText.setPosition(50, 400);
  logText.setString("Start walki");

  // Przyciski
  attackButton.setSize({140,40});
  attackButton.setPosition(50, 500);
  attackButton.setFillColor(sf::Color(150, 50, 50));

  attackLabel.setFont(font);
  attackLabel.setCharacterSize(20);
  attackLabel.setString("Atak");
  attackLabel.setPosition(90, 508);

  defendButton.setSize({140, 40});
  defendButton.setPosition(250, 500);
  defendButton.setFillColor(sf::Color(50, 50, 150));

  defendLabel.setFont(font);
  defendLabel.setCharacterSize(20);
  defendLabel.setString("Obrona");
  defendLabel.setPosition(275, 508);
  }

  void GameScreen::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
      auto mousePos = sf::Mouse::getPosition(window);
      // kliki tutaj
    }
  }
  void GameScreen::update() {
    playerStats.setString("Gracz HP: " + std::to_string(player.hp()));
    enemyStats.setString("Wróg HP: " + std::to_string(enemy.hp()));
    }

  void GameScreen::render(sf::RenderWindow& window) {
    window.draw(playerStats);
    window.draw(enemyStats);
    window.draw(logText);
    window.draw(attackButton);
    window.draw(attackLabel);
    window.draw(defendButton);
    window.draw(defendLabel);
    }


//  sf::Text text("Trwa walka...", font, 24);
//  text.setPosition(200, 280);
//  window.draw(text);
