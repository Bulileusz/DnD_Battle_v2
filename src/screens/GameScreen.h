#pragma once
#include "Screen.h"
#include "../character/Player.h"
#include "../character/Enemy.h"
#include "../logic/BattleManager.h"
#include <SFML/Graphics.hpp>

class GameScreen : public Screen {
  private:
    Player player;
    Enemy enemy;
    BattleManager battleManager;

    sf::Font font;
    sf::Text playerStats;
    sf::Text enemyStats;
    sf::Text logText;

    sf::RectangleShape attackButton;
    sf::RectangleShape defendButton;
    sf::Text attackLabel;
    sf::Text defendLabel;


    bool finished = false;

    public:
      GameScreen(Player::ClassType selectedClass);
      void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
      void update() override;
      void render(sf::RenderWindow& window) override;
      // bool isFinished() const override { return finished; }
      bool isFinished() const override;
      bool playerLost() const;
      Player& getPlayer() { return player; }
      const Player& getPlayer() const { return player; }

      BattleManager& getBattleManager() { return battleManager; }
      const BattleManager& getBattleManager() const { return battleManager; }
      };