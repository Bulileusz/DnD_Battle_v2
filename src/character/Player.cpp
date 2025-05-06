#include "Player.h"
#include <iostream>

Player::Player(ClassType type)
    : Character("Hero", 0, 0, 0), classType_(type), level_(1), exp_(0)
{
    switch (type) {
        case ClassType::Warrior:
            hp_ = 100; attack_ = 12; defense_ = 8; break;
        case ClassType::Mage:
            hp_ =  70; attack_ = 18; defense_ =  3; break;
        case ClassType::Archer:
            hp_ = 85; attack_ = 15; defense_ =  5; break;
    }
}

Player::ClassType Player::getClassType() const {
    return classType_;
}

void Player::gainExp(int amount) {
    exp_+=amount;
    std::cout << "Zdobyto " << amount << " EXPa! (Obecnie posiadasz: " << exp_ << ")\n";
    checkLevelUp();
}

void Player::checkLevelUp() {
    while (exp_ >= 100) {
        exp_ -= 100;
        level_++;
        hp_ += 10;
        attack_ += 2;
        defense_ += 1;

        std::cout << "\n Level UP! Osiągasz poziom " << level_ << "!\n";
        std::cout << "+10 HP, +2 Atak, +1 Obrona\n";
    }
}