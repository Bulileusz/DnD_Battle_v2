#pragma once
#include "Character.h"

class Enemy : public Character {
public:
    Enemy(std::string name, int hp, int atk, int def);

    // Fabryki wrogów
    static Enemy createGoblin();
    static Enemy createOrc();
    static Enemy createBoss();
};
