#include "Enemy.h"

Enemy::Enemy(std::string name, int hp, int atk, int def)
        : Character(std::move(name), hp, atk, def) {}

Enemy Enemy::createGoblin() {
    return Enemy("Goblin", 60, 8, 12);
}

Enemy Enemy::createOrc() {
    return Enemy("Orc", 100, 12, 14);
}

Enemy Enemy::createBoss() {
    return Enemy("Demon Lord", 200, 20, 18);
}

void Enemy::setTexture(const sf::Texture& tex) {
    sprite_.setTexture(tex);
    sprite_.setScale(2.0f, 2.0f); //
    sprite_.setPosition(500, 200);
}

const sf::Sprite& Enemy::getSprite() const {
    return sprite_;
}