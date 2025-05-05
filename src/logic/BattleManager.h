#pragma once
#include "../character/Player.h"
#include "../character/Enemy.h"
#include "Dice.h"

class BattleManager {
public:
    // rozgrywa pojedynczą walkę gracz  vs  jeden przeciwnik
    void fight(Player& player, Enemy& enemy);
};
