#include "Enemy.h"

Enemy::Enemy(std::string name, int hp, int atk, int def)
        : Character(std::move(name), hp, atk, def) {}

Enemy Enemy::createGoblin() {
    return Enemy("Goblin", 60, 10, 4);
}

Enemy Enemy::createOrc() {
    return Enemy("Orc", 100, 14, 6);
}

Enemy Enemy::createBoss() {
    return Enemy("Demon Lord", 200, 25, 10);
}
