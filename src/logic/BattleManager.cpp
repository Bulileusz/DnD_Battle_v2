#include "BattleManager.h"
#include <iostream>

void BattleManager::fight(Player& p, Enemy& e)
{
    std::cout << "\n--- Walka startuje: " << e.name() << " ---\n";

    while (p.isAlive() && e.isAlive()) {

        // ====== TURA GRACZA ======
        std::cout << "\n== Twoja tura ==\n";
        std::cout << "1) Atak\n2) Obrona (+5 DEF na 1 turę)\n ";

        int choice;
        std::cin >> choice;
        p.setDefending(false); // reset przed wyborem

        if (choice == 2) {
            p.setDefending(true);
            std::cout << " Bronisz się!\n";
        }

        if (choice == 1) {
            std::cout << "\n> Rzut gracza d20...\n";
            auto pRoll = rollD20();
            std::cout << "  Wynik: " << pRoll.value << "\n";

            // NAT 1 → pudło
            if (pRoll.type == RollResultType::Miss) {
                std::cout << "  Pudło!\n";
            }
            // NAT 20 → trafienie krytyczne
            else if (pRoll.type == RollResultType::Critical ||
                     pRoll.value + p.getAttack() > e.getDefense()) {
                int dmg = p.basicAttack();
                if (pRoll.type == RollResultType::Critical) dmg *= 2;

                e.takeDamage(dmg);
                std::cout << "  Trafiasz za " << dmg
                          << "  |  HP wroga: " << e.hp() << "\n";
                     } else {
                         std::cout << "  Twoje uderzenie zostało sparowane!\n";
                     }
        }
        if (!e.isAlive()) break;

        // ====== TURA WROGA ======
        std::cout << "\n> Rzut wroga d20...\n";
        auto eRoll = rollD20();
        std::cout << "  Wynik: " << eRoll.value << "\n";

        if (eRoll.type == RollResultType::Miss) {
            std::cout << "  Wróg pudłuje!\n";
        }

        else if (eRoll.type == RollResultType::Critical ||
                 eRoll.value + e.getAttack() > p.getDefense()) {

            int dmg = e.basicAttack();
            if (eRoll.type == RollResultType::Critical) dmg *= 2;

            p.takeDamage(dmg);
            std::cout << "  Wróg trafia za " << dmg
                      << "  |  Twoje HP: " << p.hp() << "\n";
                 } else {
                     std::cout << "  Parujesz atak!\n";
                 }
    }

    if (p.isAlive()) {
        std::cout << "\n Otrzymujesz 50 EXP!\n";
        p.gainExp(50);
    }
    std::cout << "\n=== "
              << (p.isAlive() ? "ZWYCIĘSTWO!" : "PORAŻKA...")
              << " ===\n";
}

Enemy BattleManager::spawnEnemyForLevel(int level) {
    if (level < 3)      return Enemy::createGoblin();
    else if (level < 5) return Enemy::createOrc();
    else                return Enemy::createBoss();
}

void BattleManager::runLoop(Player& player) {
    bool playing = true;

    while (playing) {
        int wave = 1;
        player.reset();
        std::cout << "\n=== NOWA GRA ===\n";

        while (player.isAlive()) {
            std::cout << "\n FALA " << wave << " | Poziom gracza: " << player.getLevel() << "\n";

            Enemy enemy = spawnEnemyForLevel(player.getLevel());
            fight(player, enemy);

            if (player.isAlive()) {
                int before = player.hp();
                int heal = player.getMaxHp() * 0.2;
                player.heal(heal);
                int healedAmount = player.hp() - before;



                if (healedAmount > 0) {
                    std::cout << ">> Opatrujesz rany po walce. Leczysz się " << heal << " HP.\n";
                }
            }
            wave++;
        }

        std::cout << "\n=== KONIEC GRY ===\n";
        std::cout << "Fala:     " << wave << "\n";
        std::cout << "Poziom:   " << player.getLevel() << "\n";
        std::cout << "EXP:      " << player.getExp() << "\n";

        std::cout << "\nSpróbować jeszcze raz? (t/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 't' && choice != 'T') {
            playing = false;
        }
    }
}