#pragma once
#include "../Character.h"
#include "CharacterDecorator.cpp"

#include <memory>
#include <string>
#include <utility>

// Concrete Decorator 1: Weapon (Sword)
// Augments Attack attribute and updates description.
class SwordDecorator : public CharacterDecorator {
private:
    int bonusAttack;

public:
    SwordDecorator(std::shared_ptr<Character> character, int bonus = 15)
        : CharacterDecorator(std::move(character)),
          bonusAttack(bonus) {}

    std::string getDescription() const override {
        return wrappedCharacter->getDescription() + " + Iron Sword";
    }

    int getAttack() const override {
        return wrappedCharacter->getAttack() + bonusAttack;
    }
};

// Concrete Decorator 2: Armor (Shield)
// Augments Defense attribute and updates description.
class ShieldDecorator : public CharacterDecorator {
private:
    int bonusDefense;

public:
    ShieldDecorator(std::shared_ptr<Character> character, int bonus = 12)
        : CharacterDecorator(std::move(character)),
          bonusDefense(bonus) {}

    std::string getDescription() const override {
        return wrappedCharacter->getDescription() + " + Steel Shield";
    }

    int getDefense() const override {
        return wrappedCharacter->getDefense() + bonusDefense;
    }
};

// Concrete Decorator 3: Magical Accessory (Ring)
// Augments both Attack and Defense attributes.
class MagicRingDecorator : public CharacterDecorator {
private:
    int bonusAttack;
    int bonusDefense;

public:
    MagicRingDecorator(std::shared_ptr<Character> character,
                       int attackBonus = 8,
                       int defenseBonus = 5)
        : CharacterDecorator(std::move(character)),
          bonusAttack(attackBonus),
          bonusDefense(defenseBonus) {}

    std::string getDescription() const override {
        return wrappedCharacter->getDescription() + " + Enchanted Ring";
    }

    int getAttack() const override {
        return wrappedCharacter->getAttack() + bonusAttack;
    }

    int getDefense() const override {
        return wrappedCharacter->getDefense() + bonusDefense;
    }
};
