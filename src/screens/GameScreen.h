#pragma once
#include "Screen.h"
#include "../character/Player.h"
#include "../character/Enemy.h"
#include "../logic/BattleManager.h"
#include <SFML/Graphics.hpp>
#include "../gui/HealthBar.h"
#include "../gui/Button.h"



class GameScreen : public Screen {
  private:

    Button attackButton;
    Button defendButton;
    HealthBar playerHpBar;
    HealthBar enemyHpBar;

    Player player;
    Enemy enemy;
    BattleManager battleManager;

    sf::Font font;
    sf::Text playerStats;
    sf::Text enemyStats;

    std::string playerLog;
    std::string enemyLog;
    sf::Text logLeftText;
    sf::Text logRightText;

    // sf::RectangleShape attackButton;
    // sf::RectangleShape defendButton;
    sf::Text attackLabel;
    sf::Text defendLabel;

    sf::Texture backgroundTexture;
    sf::Sprite background;

    sf::RectangleShape logBackground;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    bool showPopup = false;
    sf::RectangleShape popupBox;
    sf::Text popupText;

    void performPlayerAttack();
    void performPlayerDefense();

    void performEnemyAttack();
    void assignEnemyTexture();
    bool finished = false;

    int waveNumber = 1;


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
      int getWaveNumber() const { return waveNumber; }
      };

