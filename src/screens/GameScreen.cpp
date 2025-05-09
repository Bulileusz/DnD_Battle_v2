#include "GameScreen.h"
#include <iostream>
#include "../character/Player.h"
#include "../logic/Dice.h"

sf::Texture goblinTex, orcTex, bossTex;

GameScreen::GameScreen(Player::ClassType selectedClass)
    : player(selectedClass), enemy(BattleManager().spawnEnemyForLevel(1)) {
    assignEnemyTexture();
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
    attackButton.setSize({140, 40});
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

    //TEST - INSTANT LOSE:
    // player.takeDamage(player.hp());
}

void GameScreen::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);

        if (attackButton.getGlobalBounds().contains(mouseWorldPos)) {
            performPlayerAttack();
            //TEST - INSTA DEAD:
            // player.takeDamage(player.hp());
            // logText.setString("Gracz padł!");
        } else if (defendButton.getGlobalBounds().contains(mouseWorldPos)) {
            performPlayerDefense();
        }
    }
}

void GameScreen::update() {
    if (enemy.hp() <= 0 && !finished) {
        finished = true;
    }
    playerStats.setString("Gracz HP: " + std::to_string(player.hp()));
    enemyStats.setString("Wróg HP: " + std::to_string(enemy.hp()));
}

void GameScreen::render(sf::RenderWindow &window) {
    window.draw(playerStats);
    window.draw(enemyStats);

    window.draw(enemy.getSprite());
    window.draw(logText);
    window.draw(attackButton);
    window.draw(attackLabel);
    window.draw(defendButton);
    window.draw(defendLabel);
}

bool GameScreen::isFinished() const {
    return playerLost();
}

bool GameScreen::playerLost() const {
    return player.hp() <= 0;
}

void GameScreen::performPlayerAttack() {
    player.setDefending(false);

    RollResult roll = rollD20();
    std::string log = "> Rzut gracza d20: " + std::to_string(roll.value) + "\n";

    if (roll.type == RollResultType::Miss) {
        log += "Pudło!";
    } else if (roll.type == RollResultType::Critical || (roll.value > enemy.getDefense())) {
        int dmg = player.basicAttack();
        if (roll.type == RollResultType::Critical) {
            dmg *= 2;
            log += "Trafienie krytyczne!\n";
        }

        enemy.takeDamage(dmg);
        log += "Trafiasz za " + std::to_string(dmg) + " obrażeń!\n";
    } else {
        log += "Wróg zablokował atak.";
    }

    if (enemy.hp() <= 0) {
        log += "\nWróg pokonany!";
        waveNumber++;
        player.gainExp(50);
        int heal = player.getMaxHp() * 0.2;
        player.heal(heal);

        log += "\nLeczysz się " + std::to_string(heal) + " HP.";
        enemy = battleManager.spawnEnemyForLevel(waveNumber);
        assignEnemyTexture();

        log += "\n Pojawił się nowy wróg (Fala " + std::to_string(waveNumber) + ")";
    } else {
        performEnemyAttack(log);
    }

    logText.setString(log);
}

void GameScreen::performEnemyAttack(std::string& log) {
    RollResult roll = rollD20();
    log += "\n Rzut wroga D20: " + std::to_string(roll.value) + "\n";

    if (roll.type == RollResultType::Miss) {
        log += "Wróg pudłuje!";
    } else if (roll.type ==RollResultType::Critical || (roll.value > player.getDefense())) {
        int dmg = enemy.basicAttack();
        if (roll.type == RollResultType::Critical) {
            dmg *= 2;
            log += "Trafienie krytyczne!\n";
        }

        player.takeDamage(dmg);
        log += "Wróg trafia za " + std::to_string(dmg) + " obrażeń!";
    } else {
        log += "Parujesz atak!";
    }
}

void GameScreen::performPlayerDefense() {
    player.setDefending(true);
    std::string log = "Gracz się broni (+5 DEF na jedną turę.)\n";
    performEnemyAttack(log);
    logText.setString(log);
}

void GameScreen::assignEnemyTexture() {
    if (enemy.name() == "Goblin") {
        goblinTex.loadFromFile("assets/goblin.jpeg");
        enemy.setTexture(goblinTex);
    }
}
//  sf::Text text("Trwa walka...", font, 24);
//  text.setPosition(200, 280);
//  window.draw(text);
