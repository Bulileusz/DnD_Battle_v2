#include "MainMenuScreen.h"
#include <iostream>

MainMenuScreen::MainMenuScreen() {
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Nie udało się wczytać czcionki\n";
    }
    if (!backgroundTexture.loadFromFile("assets/backgroundPlaceholder.png")) {
        std::cerr << "Nie wczytano tła\n";
    }
    background.setTexture(backgroundTexture);


    title.setFont(font);
    title.setString("DnD Battle");
    title.setCharacterSize(36);
    title.setPosition(280, 100);

    startOption.setFont(font);
    startOption.setString("Press ENTER to start");
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
