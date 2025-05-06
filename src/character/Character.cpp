#include "Character.h"
#include <algorithm>
#include <iostream>

Character::Character(std::string name, int hp, int atk, int def)
        : name_(std::move(name)), hp_(hp), attack_(atk), defense_(def) {}

int Character::basicAttack() const {
    return attack_;
}

void Character::takeDamage(int dmg) {
    hp_ -= dmg;
    std::cout << "[DEBUG] HP po ataku: " << hp_ << " (-" << dmg << ")\n";
}
