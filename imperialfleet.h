#ifndef JNP1_4_IMPERIALFLEET_H
#define JNP1_4_IMPERIALFLEET_H

//#include "rebelfleet.h"
//@TODO poprawić te include, żeby nie było problemów ze sprawdzaniem ifndef
//@TODO wyrzucić wszystkie stałe z kodu
//@TODO przy sprawdzaniu ich poprawności użyć rzutowania statycznego: static_cast<>()
template<typename U>
class ImperialStarship {
private:
    U shield, attackPower;
protected:
    ImperialStarship() = default;

public:
/*    ImperialStarship &operator-=(const XWing<U> &a) {
        takeDamage(a.getAttackPower());
        return *this;
    }

    ImperialStarship &operator-=(const StarCruiser<U> &a) {
        takeDamage(a.getAttackPower());
        return *this;
    }*/

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
class DeathStar : public ImperialStarship<U> {
public:
//    template<typename I, typename R>
//    friend void attack(I &imperialShip, R &rebelShip);

    DeathStar(U shield, U attackPower) : ImperialStarship<U>(shield, attackPower) {}
};

template<typename U>
class ImperialDestroyer : public ImperialStarship<U> {
public:
//    template<typename I, typename R>
//    friend void attack(I &imperialShip, R &rebelShip);

    ImperialDestroyer(U shield, U attackPower) : ImperialStarship<U>(shield, attackPower) {}
};

template<typename U>
class TIEFighter : public ImperialStarship<U> {
public:
//    template<typename I, typename R>
//    friend void attack(I &imperialShip, R &rebelShip);

    TIEFighter(U shield, U attackPower) : ImperialStarship<U>(shield, attackPower) {}
};

template<typename I, typename R>
void attack(I &imperialShip, R &rebelShip) {
    rebelShip -= imperialShip;
}

template<typename I, typename U>
void attack(I &imperialShip, XWing<U> &rebelShip) {
    rebelShip -= imperialShip;
    imperialShip -= rebelShip;
}

template<typename I, typename U>
void attack(I &imperialShip, StarCruiser<U> &rebelShip) {
    rebelShip -= imperialShip;
    imperialShip -= rebelShip;
}

#endif //JNP1_4_IMPERIALFLEET_H
