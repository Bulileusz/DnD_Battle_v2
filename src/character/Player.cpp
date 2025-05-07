#include "Player.h"
#include <iostream>

Player::Player(ClassType type)
    : Character("Hero", 0, 0, 0), classType_(type), level_(1), exp_(0)
{
    initStats();
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
        hp_ = getMaxHp();
        attack_ += 2;
        defense_ += 1;

        std::cout << "\n Level UP! Osiągasz poziom " << level_ << "!\n";
        std::cout << "+10 HP, +2 Atak, +1 Obrona, dodatkowo leczysz się do pełna!\n";
    }
}

void Player::initStats() {
    hp_ = getBaseHp();
    switch (classType_) {
        case ClassType::Warrior:
            attack_ = 12; defense_ = 8; break;
        case ClassType::Mage:
            attack_ = 18; defense_ =  3; break;
        case ClassType::Archer:
            attack_ = 15; defense_ =  5; break;
    }
}

void Player::reset() {
    level_ = 1;
    exp_ = 0;
    isDefending_ = false;
    initStats();
}

int Player::getBaseHp() const {
    switch (classType_) {
        case ClassType::Warrior: return 100;
        case ClassType::Mage: return 70;
        case ClassType::Archer: return 85;
    }
    return 0;
}

int Player::getMaxHp() const {
    return getBaseHp() + (level_ - 1) * 10;
}

void Player::heal(int amount) {
    hp_+= amount;
    int maxHp = getMaxHp();
    if (hp_ > maxHp) hp_ = maxHp;
}