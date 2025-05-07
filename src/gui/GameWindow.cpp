#include "GameWindow.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void GameWindow::run() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "DnD Battle");

  sf::Font font;
  if (!font.loadFromFile("../assets/arial.ttf")) {
      std::cerr << "Nie udało się wczytaj czcionki" << std::endl;
      }

  sf::Text title("DnD Battle", font, 32); // tytuł, też możemy zmienić
  title.setPosition(250, 30);

    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("../assets/backgroundPlaceholder.png")) {
        std::cerr << "Nie udało się wczytać tła\n";
    }
    sf::Sprite background(bgTexture);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
      window.draw(background);
    window.draw(title);
    window.display();
}
}

