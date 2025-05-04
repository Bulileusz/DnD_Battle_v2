#include "character/Character.h"
#include <iostream>

int main() {
    Character hero("Hero", 100, 15, 5);
    Character goblin("Goblin", 40, 8, 2);

    std::cout << "Hero HP: "   << hero.hp()   << '\n';
    std::cout << "Goblin HP: " << goblin.hp() << '\n';

    goblin.takeDamage(hero.basicAttack());
    std::cout << "Goblin dostał cios! Zostało mu HP: " << goblin.hp() << '\n';
    return 0;
}
