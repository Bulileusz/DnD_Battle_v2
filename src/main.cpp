#include "character/Player.h"
#include "character/Enemy.h"
#include "logic/BattleManager.h"

int main() {
    Player player(Player::ClassType::Warrior);
    Enemy  goblin = Enemy::createGoblin();

    BattleManager mgr;
    mgr.fight(player, goblin);

    return 0;
}
