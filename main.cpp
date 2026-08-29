#include "Character.h"

#include <iostream>
#include <memory>

#include "Character/BaseHero.cpp"
#include "Character/EquipmentDecorators.cpp"

// Polymorphic client function:
// Works uniformly with any Character, completely agnostic of whether
// it is a base entity or wrapped in multiple layers of decorators.
void inspectCharacter(const Character& hero) {
    hero.printStats();
}

int main() {
    std::cout << "========================================================\n";
    std::cout << "        DECORATOR PATTERN DEMO - RPG EQUIPMENT          \n";
    std::cout << "========================================================\n\n";

    // Scenario 1: Base Character
    std::cout << "========== Scenario 1: Base Hero (No Equipment) ==========\n";
    std::shared_ptr<Character> arthur = std::make_shared<BaseHero>("Arthur", 15, 10);
    inspectCharacter(*arthur);
    std::cout << '\n';

    // Scenario 2: Equip a Weapon at Runtime
    std::cout << "========== Scenario 2: Equip Iron Sword (+15 Attack) ==========\n";
    arthur = std::make_shared<SwordDecorator>(arthur);
    inspectCharacter(*arthur);
    std::cout << '\n';

    // Scenario 3: Equip a Shield on top of the Sword at Runtime
    std::cout << "========== Scenario 3: Equip Steel Shield (+12 Defense) ==========\n";
    arthur = std::make_shared<ShieldDecorator>(arthur);
    inspectCharacter(*arthur);
    std::cout << '\n';

    // Scenario 4: Equip an Enchanted Ring (Hybrid Buff)
    std::cout << "========== Scenario 4: Equip Enchanted Ring (+8 Atk, +5 Def) ==========\n";
    arthur = std::make_shared<MagicRingDecorator>(arthur);
    inspectCharacter(*arthur);
    std::cout << '\n';

    // Scenario 5: Dynamic Combinations / Stacking (Dual-Wielding)
    std::cout << "========== Scenario 5: Arbitrary Stacking (Dual-Wield Hero) ==========\n";
    std::shared_ptr<Character> lancelot = std::make_shared<BaseHero>("Lancelot", 20, 8);
    // Wrap with two swords and a magic ring dynamically
    lancelot = std::make_shared<SwordDecorator>(lancelot);
    lancelot = std::make_shared<SwordDecorator>(lancelot); // Second sword!
    lancelot = std::make_shared<MagicRingDecorator>(lancelot);
    inspectCharacter(*lancelot);
    std::cout << '\n';

    return 0;
}
