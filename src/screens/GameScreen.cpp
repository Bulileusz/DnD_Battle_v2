#include "GameScreen.h"
#include <iostream>
#include "../character/Player.h"
#include "../logic/Dice.h"

sf::Texture goblinTex, orcTex, bossTex;

GameScreen::GameScreen(Player::ClassType selectedClass)
    : player(selectedClass), enemy(BattleManager().spawnEnemyForLevel(1)),
    attackButton(L"Atak", sf::Vector2f(480.f, 500.f), sf::Color(200,60, 60), font),
    defendButton(L"Obrona", sf::Vector2f(640.f, 500.f), sf::Color(60, 60, 200), font)
{
    std::string PlayerPath;

    std::string path = player.getSpritePath();
    if (!playerTexture.loadFromFile(path)) {
        std::cerr << "Nie wczytano sprite'a gracza!\n";
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(.7f, .7f);
    playerSprite.setPosition(-60.f,280.f);

    assignEnemyTexture();
    if (!font.loadFromFile("assets/Spectral-Regular.ttf")) {
        std::cerr << "Nie wczytano czcionki\n";
    }
    std::string bgPath = (enemy.name() == "Demon Lord")
                             ? "assets/boss_bg.png"
                             : "assets/fight_bg.png";

    if (!backgroundTexture.loadFromFile(bgPath)) {
        std::cerr << "nie wczytano tła walki\n";
    }
    background.setTexture(backgroundTexture);

    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize(800, 600);

    background.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );
    // Staty


    playerStats.setFont(font);
    playerStats.setCharacterSize(13);

    // sf::Vector2f hpBarPos = playerHpBar.getPosition();
    //
    // playerStats.setOrigin(playerStats.getLocalBounds().width / 2.f, 0.f);
    // playerStats.setPosition(hpBarPos.x + 10.f, hpBarPos.y - 20.f);

    // enemyStats.setFont(font);
    // enemyStats.setCharacterSize(20);
    // enemyStats.setPosition(500, 30);

    // Logi
    logLeftText.setFont(font);
    logLeftText.setCharacterSize(16);
    logLeftText.setPosition(60, 20);
    logLeftText.setFillColor(sf::Color::White);

    logRightText.setFont(font);
    logRightText.setCharacterSize(16);
    logRightText.setPosition(440, 20);
    logRightText.setFillColor(sf::Color::White);

    logBackground.setSize(sf::Vector2f(700, 60));
    logBackground.setPosition(40, 15);
    logBackground.setFillColor(sf::Color(0, 0, 0, 180));
    logBackground.setOutlineThickness(1);
    logBackground.setOutlineColor(sf::Color::White);

    // Przyciski
    // attackButton = Button(L"Atak",{50, 500}, sf::Color(150,50,50),font);
    // defendButton = Button(L"Obrona", {250, 500}, sf::Color(50, 50, 150), font);

    // attackButton.setSize({140, 40});
    // attackButton.setPosition(50, 500);
    // attackButton.setFillColor(sf::Color(150, 50, 50));
    //
    // attackLabel.setFont(font);
    // attackLabel.setCharacterSize(20);
    // attackLabel.setString(L"Atak");
    // attackLabel.setPosition(90, 508);
    //
    // defendButton.setSize({140, 40});
    // defendButton.setPosition(250, 500);
    // defendButton.setFillColor(sf::Color(50, 50, 150));
    //
    // defendLabel.setFont(font);
    // defendLabel.setCharacterSize(20);
    // defendLabel.setString(L"Obrona");
    // defendLabel.setPosition(275, 508);

    // Tekst na środku:
    popupBox.setSize({600.f, 140.f});
    popupBox.setPosition(100.f, 200.f);
    popupBox.setFillColor(sf::Color(0, 0, 0, 180));
    popupBox.setOutlineColor(sf::Color::White);
    popupBox.setOutlineThickness(2.f);

    popupText.setFont(font);
    popupText.setCharacterSize(20);
    popupText.setFillColor(sf::Color::White);
    popupText.setPosition(120.f, 220.f);


    //HP
    playerHpBar.setPosition(100.f,440.f);
    enemyHpBar.setPosition(500.f, 200.f);


    //TEST - INSTANT LOSE:
    // player.takeDamage(player.hp());
}

void GameScreen::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    if (showPopup && event.type == sf::Event::MouseButtonPressed) {
        showPopup = false;
        return;
    }


    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);

        if (attackButton.isClicked(mouseWorldPos)) {
            performPlayerAttack();
            //TEST - INSTA DEAD:
            // player.takeDamage(player.hp());
            // logText.setString("Gracz padł!");
        } else if (defendButton.isClicked(mouseWorldPos)) {
            performPlayerDefense();
        }
    }
}

void GameScreen::update() {
    if (enemy.hp() <= 0 && !finished) {
        finished = true;
    }


    sf::Vector2f playerPos = playerSprite.getPosition();
    playerHpBar.setPosition(playerSprite.getPosition().x + 180.f, playerSprite.getPosition().y - 15.f);

    sf::Vector2f enemyPos = enemy.getSprite().getPosition();
    enemyHpBar.setPosition(enemy.getSprite().getPosition().x + 45.f, enemy.getSprite().getPosition().y - 15.f);


    playerHpBar.update(player.hp(), player.getMaxHp());
    sf::Vector2f hpBarPos = playerHpBar.getPosition();
    playerStats.setString(L"HP: " + std::to_wstring(player.hp()));
    playerStats.setOrigin(playerStats.getLocalBounds().width / 2.f, 0.f);
    playerStats.setPosition(hpBarPos.x + 30.f, hpBarPos.y - 5.f);

    enemyHpBar.update(enemy.hp(), enemy.getMaxHp());

}

void GameScreen::render(sf::RenderWindow &window) {
    window.draw(background);

    // window.draw(enemyStats);
    window.draw(enemy.getSprite());
    window.draw(playerSprite);

    window.draw(logBackground);
    window.draw(logLeftText);
    window.draw(logRightText);

    // window.draw(attackButton);
    attackButton.render(window);
    window.draw(attackLabel);
    // window.draw(defendButton);
    defendButton.render(window);
    window.draw(defendLabel);

    playerHpBar.render(window);
    enemyHpBar.render(window);
    window.draw(playerStats);

    if (showPopup) {
        window.draw(popupBox);
        window.draw(popupText);
    }
}

bool GameScreen::isFinished() const {
    return playerLost() || finished;
}

bool GameScreen::playerLost() const {
    return player.hp() <= 0;
}

void GameScreen::performPlayerAttack() {
    player.setDefending(false);

    RollResult roll = rollD20();
    playerLog = "Rzut gracza d20: " + std::to_string(roll.value) + "\n";

    if (roll.type == RollResultType::Miss) {
        playerLog += "Pudło!";
    } else if (roll.type == RollResultType::Critical || (roll.value > enemy.getDefense())) {
        int dmg = player.basicAttack();
        if (roll.type == RollResultType::Critical) {
            dmg *= 2;
            playerLog += "Trafienie krytyczne! ";
        }

        enemy.takeDamage(dmg);
        playerLog += "Trafiasz za " + std::to_string(dmg) + " obrażeń!\n";


        if (enemy.hp() <= 0 && enemy.name() == "Demon Lord") {
            finished = true;
            return;
        }


        else if (enemy.hp() <= 0) {
            waveNumber++;
            player.gainExp(50);
            int heal = player.getMaxHp() * 0.2;
            player.heal(heal);

            std::string popup = "Wróg pokonany!\n";
            popup += "Leczysz się " + std::to_string(heal) + " HP.\n";
            popup += "Pojawił się nowy wróg (Fala " + std::to_string(waveNumber) + ")";

            popupText.setString(sf::String::fromUtf8(popup.begin(), popup.end()));
            showPopup = true;

            enemy = battleManager.spawnEnemyForLevel(waveNumber);
            assignEnemyTexture();

            std::string bgPath = (enemy.name() == "Demon Lord")
                                     ? "assets/boss_bg.png"
                                     : "assets/fight_bg.png";

            if (!backgroundTexture.loadFromFile(bgPath)) {
                std::cerr << "Nie wczytano tła walki\n";
            }

            background.setTexture(backgroundTexture);
            background.setScale(
                800.f / backgroundTexture.getSize().x,
                600.f / backgroundTexture.getSize().y
            );
        }
    } else {
        playerLog += "Wróg zablokował atak.";
    }


    if (enemy.hp() > 0) {
        performEnemyAttack();
    }

    logLeftText.setString(sf::String::fromUtf8(playerLog.begin(), playerLog.end()));
    logRightText.setString(sf::String::fromUtf8(enemyLog.begin(), enemyLog.end()));
}


void GameScreen::performEnemyAttack() {
    RollResult roll = rollD20();
    enemyLog = "Rzut wroga D20: " + std::to_string(roll.value) + "\n";

    if (roll.type == RollResultType::Miss) {
        enemyLog += "Wróg pudłuje!";
    } else if (roll.type == RollResultType::Critical || (roll.value > player.getDefense())) {
        int dmg = enemy.basicAttack();
        if (roll.type == RollResultType::Critical) {
            dmg *= 2;
            enemyLog += "Trafienie krytyczne!\n";
        }

        player.takeDamage(dmg);
        enemyLog += "Wróg trafia za " + std::to_string(dmg) + " obrażeń!";
    } else {
        enemyLog += "Parujesz atak!";
    }
}

void GameScreen::performPlayerDefense() {
    player.setDefending(true);

    performEnemyAttack();
    std::string playerLog = "Gracz się broni (+5 DEF na jedną turę.)\n";
    logLeftText.setString(sf::String::fromUtf8(playerLog.begin(), playerLog.end()));
    logRightText.setString(sf::String::fromUtf8(enemyLog.begin(), enemyLog.end()));

}

void GameScreen::assignEnemyTexture() {
    if (enemy.name() == "Goblin") {
        goblinTex.loadFromFile("assets/goblin.png");
        enemy.setTexture(goblinTex);
    } else if (enemy.name() == "Orc") {
        orcTex.loadFromFile("assets/orc.png");
        enemy.setTexture(orcTex);
    } else if (enemy.name() == "Demon Lord") {
        bossTex.loadFromFile("assets/demon_lord.png");
        enemy.setTexture(bossTex);
    }
}

//  sf::Text text("Trwa walka...", font, 24);
//  text.setPosition(200, 280);
//  window.draw(text);
