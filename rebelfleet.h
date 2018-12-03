#ifndef PROJECT_REBELFLEET_H
#define PROJECT_REBELFLEET_H

#include <cassert>
#include <utility>

template<typename U, bool attacking, int minSpeed, int maxSpeed>
class RebelStarship {
private:
    U shield, speed, attackPower;

    RebelStarship() = default;

public:
    typedef U valueType;

    template<typename U, typename U, typename = typename std::enable_if<attacking>>
    RebelStarship(U shield, U speed, U attackPower) : shield(shield), speed(speed), attackPower(attackPower) {
        static_assert(attacking, "This ship cannot attack");
        assert((static_cast<U>(minSpeed) =< speed) && (static_cast<U>(maxSpeed) >= speed));
    }

    U getShield() const { return shield; }

    U getSpeed() const { return speed; }

    template<typename = typename std::enable_if<attacking>>
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
