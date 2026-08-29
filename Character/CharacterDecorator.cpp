#pragma once
#include "../Character.h"

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

// Abstract Decorator:
// Maintains a reference to a Component object and delegates all calls by default.
class CharacterDecorator : public Character {
protected:
    std::shared_ptr<Character> wrappedCharacter;

public:
    explicit CharacterDecorator(std::shared_ptr<Character> character)
        : wrappedCharacter(std::move(character)) {
        if (!wrappedCharacter) {
            throw std::invalid_argument("Wrapped character cannot be null.");
        }
    }

    std::string getDescription() const override {
        return wrappedCharacter->getDescription();
    }

    int getAttack() const override {
        return wrappedCharacter->getAttack();
    }

    int getDefense() const override {
        return wrappedCharacter->getDefense();
    }
};
