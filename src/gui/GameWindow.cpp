#include "GameWindow.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../screens/MainMenuScreen.h"
#include "GameWindow.h"
#include "../screens/ClassSelectionScreen.h"
#include "../character/Player.h"
#include "../screens/GameScreen.h"
#include "../screens/GameOverScreen.h"

void GameWindow::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DnD Battle");

    // 1. Menu
    currentScreen = std::make_unique<MainMenuScreen>();

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Nie udało się wczytaj czcionki" << std::endl;
    }

    sf::Text title("DnD Battle", font, 32); // tytuł, też możemy zmienić
    title.setPosition(250, 30);

    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("assets/backgroundPlaceholder.png")) {
        std::cerr << "Nie udało się wczytać tła\n";
    }
    sf::Sprite background(bgTexture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (currentScreen)
                currentScreen->handleEvent(event, window);
        }
        if (currentScreen)
            currentScreen->update();

        if (currentScreen && currentScreen->isFinished()) {
            // currentScreen = std::make_unique<ClassSelectionScreen>();
            if (dynamic_cast<MainMenuScreen *>(currentScreen.get())) {
                currentScreen = std::make_unique<ClassSelectionScreen>();
            } else if (auto classScreen = dynamic_cast<ClassSelectionScreen *>(currentScreen.get())) {
                Player::ClassType selected;
                switch (classScreen->getSelectedClass()) {
                    case 1: selected = Player::ClassType::Warrior;
                    break;
                    case 2: selected = Player::ClassType::Mage;
                    break;
                    case 3: selected = Player::ClassType::Archer;
                    break;
                    default: selected = Player::ClassType::Warrior;
                }
                currentScreen = std::make_unique<GameScreen>(selected);
            } else if (auto game = dynamic_cast<GameScreen *>(currentScreen.get())) {
                if (game->playerLost() || game->isFinished()) {
                    currentScreen = std::make_unique<GameOverScreen>(
                        game->getPlayer().getLevel(),
                        game->getPlayer().getExp(),
                        game->getWaveNumber()
                    );
                }
            } else if (dynamic_cast<GameOverScreen *>(currentScreen.get())) {
                currentScreen = std::make_unique<ClassSelectionScreen>();
            }
        }
        window.clear();
        if (currentScreen)
            currentScreen->render(window);
        window.display();
    }

}


