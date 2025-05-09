#pragma once
#include "../character/Player.h"
#include "../character/Enemy.h"
#include "Dice.h"

class BattleManager {
private:
    int waveNumber_ = 1;
public:
    // rozgrywa pojedynczą walkę gracz  vs  jeden przeciwnik
    void fight(Player& player, Enemy& enemy);

    void runLoop(Player& player);
    Enemy spawnEnemyForLevel(int level);
    int getWaveNumber() const {return waveNumber_; }
};




