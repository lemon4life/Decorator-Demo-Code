#pragma once
#include "../Character.h"

#include <string>
#include <utility>

// Concrete Component:
// The base entity with initial attributes that can be augmented dynamically.
class BaseHero : public Character {
private:
    std::string name;
    int baseAttack;
    int baseDefense;

public:
    BaseHero(std::string heroName = "Hero", int attack = 15, int defense = 10)
        : name(std::move(heroName)),
          baseAttack(attack),
          baseDefense(defense) {}

    std::string getDescription() const override {
        return name;
    }

    int getAttack() const override {
        return baseAttack;
    }

    int getDefense() const override {
        return baseDefense;
    }
};
