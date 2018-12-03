#ifndef JNP1_4_BATTLE_H
#define JNP1_4_BATTLE_H

#include <type_traits>
#include <array>
#include <tuple>
#include <iostream>
#include <typeinfo>

//#include "imperialfleet.h"
//#include "rebelfleet.h"

//@TODO usunąć niepotrzebne couty
//@TODO zoptymalizować cały kod
//@TODO usunąć konstruktor ustawiajacy attackPower z szablonu Explorer
//@TODO usunąc niepotrzebne metody
//@TODO przejrzeć całą stylistykę

template<typename T, T t0, T t1, typename... S>
class SpaceBattle {
private:
    T actTime = t0;
    const T endTime = t1;
    std::tuple<S...> fleet;

    static constexpr size_t countAttackTimesSize(T timeLimit) {
        size_t size = 0;
        auto limit = static_cast<size_t>(timeLimit);
        while (size * size <= limit) size++;
        return size;
    }

    static constexpr std::array<T, countAttackTimesSize(t1)> getAttackTimes(T t) {
        static constexpr std::array<T, countAttackTimesSize(t1)> array{};
        auto it = array.begin();
        for (T i = 0; i * i <= t; ++i) {
            *it++ = i * i;
        }
        return array;
    }

    static constexpr std::array<T, countAttackTimesSize(t1)> attackTimes = getAttackTimes(t1);

    bool attackTime(T actTime) const {
        for (auto time : attackTimes)
            if (time == actTime)
                return true;
        return false;
    }

    template<typename U>
    void attackSingle(ImperialStarship <U> &impShip) {
        if (impShip.getShield() > 0)
            std::apply([&](auto &...x) { (..., attack(impShip, x)); }, fleet);
    }

    template<typename I>
    void attackSingle(I impShip) {
        (void) impShip;
    }

    void doAttack() {
        std::apply([this](auto &...x) { (..., attackSingle(x)); }, fleet);
    }

    template<typename U>
    void countImperial(size_t &count, ImperialStarship <U> ship) {
        (void) ship;
        if (ship.getShield() > 0) count++;
    }

    template<typename U>
    void countImperial(size_t &count, U ship) {
        (void) ship;
    }

    template<typename U>
    void countRebel(size_t &count, ImperialStarship <U> ship) {
        (void) ship;
    }

    template<typename U>
    void countRebel(size_t &count, U ship) {
        (void) ship;
        if (ship.getShield() > 0) count++;
    }

public:
    explicit SpaceBattle(S... ships)
            : fleet(std::make_tuple(ships...)) {
        static_assert(std::is_integral<T>::value, "time parameter must be an integral type.");
        static_assert(t0 >= 0, "t0 must be greater than 0.");
        static_assert(t1 >= t0, "t1 must be greater than t0.");
    }

    size_t countImperialFleet() {
        size_t impShips = 0;
        std::apply([&](auto ...x) { (..., countImperial(&impShips, x)); }, fleet);
        return impShips;
    }

    size_t countRebelFleet() {
        size_t rebShips = 0;
        std::apply([&](auto ...x) { (..., countRebel(&rebShips, x)); }, fleet);
        return rebShips;
    }

    void tick(T timeStep) {
        // sprawdza czy mamy zwyciezce
        if (countRebelFleet() == 0 && countImperialFleet() == 0) {
            std::cout << "DRAW" << std::endl;
        } else if (countRebelFleet() == 0) {
            std::cout << "IMPERIUM WON" << std::endl;
        } else if (countImperialFleet() == 0) {
            std::cout << "REBELLION WON" << std::endl;
        } else if (attackTime(actTime)) {
                doAttack();
                printState();
            }
        }
        actTime = (actTime + timeStep) % endTime;
    }
};

#endif //JNP1_4_BATTLE_H
