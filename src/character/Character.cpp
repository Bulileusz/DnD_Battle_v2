#include "Character.h"
#include <algorithm>

Character::Character(std::string name, int hp, int atk, int def)
        : name_(std::move(name)), hp_(hp), attack_(atk), defense_(def) {}

int Character::basicAttack() const {
    return attack_;
}

void Character::takeDamage(int dmg) {
    int real = std::max(0, dmg - defense_);
    hp_ -= real;
}
