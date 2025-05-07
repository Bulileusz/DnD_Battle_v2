#include "character/Player.h"
#include "character/Enemy.h"
#include "logic/BattleManager.h"
#include <iostream>
#include "gui/GameWindow.h"

// int main() {
//     Player player(Player::ClassType::Warrior);
//     Enemy  goblin = Enemy::createGoblin();
//
//     BattleManager mgr;
//     mgr.fight(player, goblin);
//
//     return 0;
// }

// int main() {
//     Player player(Player::ClassType::Warrior);
//     BattleManager mgr;
//     mgr.runLoop(player);
//
//
//     // Test EXP i levela po walce
//     std::cout << "\nPoziom gracza: " << player.getLevel() << "\n";
//     std::cout << "Aktualny EXP: " << player.getExp() << "\n";
//
//     return 0;
// }

// int main() {
//     std::cout << "Wybierz klasę postaci:\n";
//     std::cout << "1) Wojownik\n";
//     std::cout << "2) Mag\n";
//     std::cout << "3) Łucznik\n";
//
//     int choice;
//     std::cin >> choice;
//
//     Player::ClassType selectedClass;
//
//     switch (choice) {
//         case 2: selectedClass = Player::ClassType::Mage; break;
//         case 3: selectedClass = Player::ClassType::Archer; break;
//         default: selectedClass = Player::ClassType::Warrior; break;
//     }
//     Player player(selectedClass);
//     BattleManager mgr;
//     mgr.runLoop(player);
//
// }

int main() {
    GameWindow window;
    window.run();
    return 0;
}