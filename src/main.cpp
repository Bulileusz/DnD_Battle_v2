#include "character/Player.h"
#include "character/Enemy.h"
#include "logic/BattleManager.h"
#include <iostream>

// int main() {
//     Player player(Player::ClassType::Warrior);
//     Enemy  goblin = Enemy::createGoblin();
//
//     BattleManager mgr;
//     mgr.fight(player, goblin);
//
//     return 0;
// }

int main() {
    Player player(Player::ClassType::Warrior);
    BattleManager mgr;
    mgr.runLoop(player);


    // Test EXP i levela po walce
    std::cout << "\nPoziom gracza: " << player.getLevel() << "\n";
    std::cout << "Aktualny EXP: " << player.getExp() << "\n";

    return 0;
}

