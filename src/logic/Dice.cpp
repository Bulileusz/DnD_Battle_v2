#include "Dice.h"
#include <random>

RollResult rollD20() {
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(1, 20);
    int value = dist(rng);

    RollResultType type = RollResultType::Normal;
    if (value == 1)      type = RollResultType::Miss;
    else if (value == 20) type = RollResultType::Critical;

    return { value, type };
}
