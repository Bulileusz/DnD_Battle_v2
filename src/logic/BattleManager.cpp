#include "BattleManager.h"
#include <iostream>

void BattleManager::fight(Player& p, Enemy& e)
{
    std::cout << "\n--- Walka startuje: " << e.name() << " ---\n";

    while (p.isAlive() && e.isAlive()) {

        // ====== TURA GRACZA ======
        std::cout << "\n> Rzut gracza d20...\n";
        auto pRoll = rollD20();
        std::cout << "  Wynik: " << pRoll.value << "\n";

        // NAT 1 → pudło
        if (pRoll.type == RollResultType::Miss) {
            std::cout << "  Pudło!\n";
        }
        // NAT 20 → trafienie krytyczne
        else if (pRoll.type == RollResultType::Critical ||
                 pRoll.value > e.getDefense() + rollD20().value) {
            int dmg = p.basicAttack();
            if (pRoll.type == RollResultType::Critical) dmg *= 2;

            e.takeDamage(dmg);
            std::cout << "  Trafiasz za " << dmg
                      << "  |  HP wroga: " << e.hp() << "\n";
                 } else {
                     std::cout << "  Twoje uderzenie zostało sparowane!\n";
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
                 eRoll.value > p.getDefense() + rollD20().value) {
            int dmg = e.basicAttack();
            if (eRoll.type == RollResultType::Critical) dmg *= 2;

            p.takeDamage(dmg);
            std::cout << "  Wróg trafia za " << dmg
                      << "  |  Twoje HP: " << p.hp() << "\n";
                 } else {
                     std::cout << "  Parujesz atak!\n";
                 }
    }

    std::cout << "\n=== "
              << (p.isAlive() ? "ZWYCIĘSTWO!" : "PORAŻKA...")
              << " ===\n";
}
