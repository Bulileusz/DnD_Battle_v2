#include "ClassSelectionScreen.h"
#include <iostream>

ClassSelectionScreen::ClassSelectionScreen() {
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Czcionka - w selekcji klasy - problem\n";
    }

    title.setFont(font);
    title.setString("Wybierz klasę postaci:");
    title.setCharacterSize(30);
    title.setPosition(220, 80);

    warriorOption.setFont(font);
    warriorOption.setString("1. Wojownik");
    warriorOption.setCharacterSize(24);
    warriorOption.setPosition(250, 160);

    mageOption.setFont(font);
    mageOption.setString("2. Mag");
    mageOption.setCharacterSize(24);
    mageOption.setPosition(250, 200);

    archerOption.setFont(font);
    archerOption.setString("3. Łucznik");
    archerOption.setCharacterSize(24);
    archerOption.setPosition(250, 240);
}

void ClassSelectionScreen::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::KeyPressed) {
        std::cout<< "[debug] key pressed: " << event.key.code << "\n";
        switch (event.key.code) {
            case sf::Keyboard::Num1:
            case sf::Keyboard::Numpad1:
                selectedClass = 1;
                finished = true;
                break;
            case sf::Keyboard::Num2:
            case sf::Keyboard::Numpad2:
                selectedClass = 2;
                finished = true;
                break;
            case sf::Keyboard::Num3:
            case sf::Keyboard::Numpad3:
                selectedClass = 3;
                finished = true;
                break;
            default:
                break;
        }
    }
}

void ClassSelectionScreen::render(sf::RenderWindow &window) {
    window.draw(title);
    window.draw(warriorOption);
    window.draw(mageOption);
    window.draw(archerOption);
}
