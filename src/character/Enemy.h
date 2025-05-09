#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>

class Enemy : public Character {
public:
    Enemy(std::string name, int hp, int atk, int def);

    // Fabryki wrogów
    static Enemy createGoblin();
    static Enemy createOrc();
    static Enemy createBoss();

    void setTexture(const sf::Texture& tex);
    const sf::Sprite& getSprite() const;

private:
    sf::Sprite sprite_;
};
