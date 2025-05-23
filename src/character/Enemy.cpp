#include "Enemy.h"

Enemy::Enemy(std::string name, int hp, int atk, int def)
        : Character(std::move(name), hp, atk, def), maxHp_(hp) {}

Enemy Enemy::createGoblin() {
    return Enemy("Goblin", 50, 8, 2);
}

Enemy Enemy::createOrc() {
    return Enemy("Orc", 50, 12, 2);
}

Enemy Enemy::createBoss() {
    return Enemy("Demon Lord", 50, 20, 2);
}

void Enemy::setTexture(const sf::Texture& tex) {
    sprite_.setTexture(tex);

    if (name_ == "Goblin") {
        sprite_.setScale(0.2f, 0.2f); //
        sprite_.setPosition(360.f, 240.f);
    }

    else if (name_ == "Orc") {
        sprite_.setScale(0.4f, 0.4f);
        sprite_.setPosition(280.f, 120.f);
    }

    else if (name_ == "Demon Lord") {
        sprite_.setScale(0.4f, 0.4f);
        sprite_.setPosition(200.f, 30.f);
    }
    else {
        sprite_.setScale(0.2f, 0.2f);
        sprite_.setPosition(500.f, 300.f);
    }
}

const sf::Sprite& Enemy::getSprite() const {
    return sprite_;
}

int Enemy::getMaxHp() const {
    return maxHp_;
}