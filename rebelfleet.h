#ifndef PROJECT_REBELFLEET_H
#define PROJECT_REBELFLEET_H

#include <cassert>
#include <utility>
//#include "imperialfleet.h"
//@TODO poprawić te include, żeby nie było problemów ze sprawdzaniem ifndef
//@TODO wyrzucić wszystkie stałe z kodu
//@TODO przy sprawdzaniu ich poprawności użyć rzutowania statycznego: static_cast<>()

template <typename U, bool attacking = false, int minSpeed = 299796, int maxSpeed = 2997960>
class RebelStarship {
private:
    U shield, speed, attackPower;
    RebelStarship() = default;

public:
    typedef U valueType;

    RebelStarship(U shield, U speed) : shield(shield), speed(speed) {
        assert((static_cast<int>(speed) >= minSpeed) && (static_cast<int>(speed) <= maxSpeed));
    }
    RebelStarship(U shield, U speed, U attackPower) : shield(shield), speed(speed), attackPower(attackPower) {
        assert((static_cast<int>(speed) >= minSpeed) && (static_cast<int>(speed) <= maxSpeed));
    }

    U getShield() const { return shield; }

    U getSpeed() const { return speed; }
    template <typename = typename std::enable_if<attacking>>
    U getAttackPower() const { return attackPower; }

    void takeDamage(U damage) {
        if (damage < shield) {
            shield -= damage;
        } else {
            shield = 0;
        }
    }
};

template<typename U>
using Explorer = RebelStarship<U, false, 299796, 2997960>;

template<typename U>
using XWing = RebelStarship<U, true, 299796, 2997960>;

template<typename U>
using StarCruiser = RebelStarship<U, true, 99999, 299795>;

#endif //PROJECT_REBELFLEET_H
