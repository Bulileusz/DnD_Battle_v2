#include "Player.h"

Player::Player(ClassType type)
    : Character("Hero", 0, 0, 0), classType_(type)
{
    switch (type) {
        case ClassType::Warrior:
            hp_ = 120; attack_ = 18; defense_ = 10; break;
        case ClassType::Mage:
            hp_ =  80; attack_ = 25; defense_ =  4; break;
        case ClassType::Archer:
            hp_ = 100; attack_ = 20; defense_ =  6; break;
    }
}

Player::ClassType Player::getClassType() const {
    return classType_;
}
