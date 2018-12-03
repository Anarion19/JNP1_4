#ifndef JNP1_4_IMPERIALFLEET_H
#define JNP1_4_IMPERIALFLEET_H

#include <iostream>

template<typename U>
class ImperialStarship {
private:
    U shield, attackPower;

    ImperialStarship() = default;

public:
    typedef U valueType;

    ImperialStarship(U shield, U attackPower) : shield(shield), attackPower(attackPower) {}

    U getShield() const { return shield; }

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
using DeathStar = ImperialStarship<U>;

template<typename U>
using ImperialDestroyer = ImperialStarship<U>;

template<typename U>
using TIEFighter = ImperialStarship<U>;

template<typename I, typename U>
void attack(ImperialStarship<I> &imperialShip, Explorer <U> &rebelShip) {
    std::cout << "statek z tarcza: " << imperialShip.getShield() << " atakuje z sila: " <<
              imperialShip.getAttackPower() << " Explorera o tarczy: " << rebelShip.getShield() << std::endl;
    if (rebelShip.getShield() > 0 && imperialShip.getShield() > 0) {
        rebelShip.takeDamage(imperialShip.getAttackPower());
    }
}

template<typename I, typename U>
void attack(ImperialStarship<I> &imperialShip, XWing <U> &rebelShip) {
    std::cout << "statek z tarcza: " << imperialShip.getShield() << " atakuje z sila: " <<
              imperialShip.getAttackPower() << " XWinga o tarczy: " << rebelShip.getShield() << std::endl;
    if (rebelShip.getShield() > 0 && imperialShip.getShield() > 0) {
        rebelShip.takeDamage(imperialShip.getAttackPower());
        imperialShip.takeDamage(rebelShip.getAttackPower());
    }

}

template<typename I, typename U>
void attack(ImperialStarship<I> &imperialShip, StarCruiser <U> &rebelShip) {
    std::cout << "statek z tarcza: " << imperialShip.getShield() << " atakuje z sila: " <<
              imperialShip.getAttackPower() << " StarCruisera o tarczy: " << rebelShip.getShield() << std::endl;
    if (rebelShip.getShield() > 0 && imperialShip.getShield() > 0) {
        rebelShip.takeDamage(imperialShip.getAttackPower());
        imperialShip.takeDamage(rebelShip.getAttackPower());
    }
}

template<typename I, typename R>
void attack(I &imperialShip, R &rebelShip) {
    std::cout << "nie atakuje2:" << std::endl;
    (void) imperialShip;
    (void) rebelShip;
}


#endif //JNP1_4_IMPERIALFLEET_H
