#include "MainMenuScreen.h"
#include <iostream>

MainMenuScreen::MainMenuScreen() {
    if (!font.loadFromFile("assets/Spectral-Regular.ttf")) {
        std::cerr << "Nie udało się wczytać czcionki\n";
    }
    if (!backgroundTexture.loadFromFile("assets/menu_bg.png")) {
        std::cerr << "Nie wczytano tła\n";
    }
    background.setTexture(backgroundTexture);

    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize(800,600);

    background.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
        );

    title.setFont(font);
    title.setString(L"DnD Battle");
    title.setCharacterSize(36);
    title.setPosition(280, 100);

    startOption.setFont(font);
    startOption.setString(L"Naciśnij ENTER żeby rozpocząć");
    startOption.setCharacterSize(24);
    startOption.setPosition(200, 200);
}

void MainMenuScreen::handleEvent(sf::Event &event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        finished = true;
    }
}

void MainMenuScreen::render(sf::RenderWindow &window) {
    // std::cout <<"[DEBUG] render menu screen\n";
    window.draw(background);
    window.draw(title);
    window.draw(startOption);
}
