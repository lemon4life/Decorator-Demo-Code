#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

// Component Interface:
// Defines the common operations available for base entities and their decorators.
class Character {
public:
    virtual ~Character() = default;

    virtual std::string getDescription() const = 0;
    virtual int getAttack() const = 0;
    virtual int getDefense() const = 0;

    virtual void printStats() const {
        std::cout << "Character: " << getDescription() << '\n';
        std::cout << "  - Attack Power : " << getAttack() << '\n';
        std::cout << "  - Defense Power: " << getDefense() << '\n';
    }
};

#endif 
