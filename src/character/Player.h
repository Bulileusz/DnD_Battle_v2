#pragma once
#include "Character.h"

class Player : public Character {
public:
    enum class ClassType { Warrior, Mage, Archer };

    explicit Player(ClassType type);

    ClassType getClassType() const;

private:
    ClassType classType_;
};
