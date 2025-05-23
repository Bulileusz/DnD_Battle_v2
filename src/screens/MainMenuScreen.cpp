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
    title.setFillColor(sf::Color::White);
    title.setPosition(800/2.f - title.getLocalBounds().width / 2.f, 200.f);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(2.f);

    startOption.setFont(font);
    startOption.setString(L"Naciśnij ENTER żeby rozpocząć");
    startOption.setCharacterSize(24);
    startOption.setFillColor(sf::Color::White);
    startOption.setPosition(800/2.f - startOption.getLocalBounds().width/2.f, 270.f);
    startOption.setOutlineColor(sf::Color::Black);
    startOption.setOutlineThickness(1.5f);
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
