#ifndef JNP1_4_BATTLE_H
#define JNP1_4_BATTLE_H

#include <stddef.h>
#include <type_traits>
#include <array>
#include <tuple>
#include <iostream>



template <typename T, T t0, T t1, typename... S>
class SpaceBattle {
private:
    T actTime = t0;
    const T endTime = t1;
    std::tuple<S...> fleet;
    size_t tuple_size;
    static constexpr size_t countAttackTimesSize(T timeLimit) {
        size_t size = 0;
        size_t limit = static_cast<size_t>(timeLimit);
        while (size*size <= limit) size++;
        return size;
    }
    static constexpr std::array<T, countAttackTimesSize(t1)> getAttackTimes(T t) {
        std::array<T, countAttackTimesSize(t1)> array{};
        auto it = array.begin();
        for(T i = 0; i*i <= t; ++i) {
            *it++ = i*i;
        }
        return array;
    }
    std::array<T, countAttackTimesSize(t1)> attackTimes = getAttackTimes(t1);

    bool attackTime(T actTime) const {
        for (auto time : attackTimes)
            if (time == actTime) return true;
        return false;
    }
    void attack() {
        std::cout << "ATAK!" << std::endl;
    }
public:
    SpaceBattle(S... ships)
    : fleet(std::make_tuple(ships...))
    {
        static_assert(std::is_integral<T>::value, "time parameter must be an integral type.");
        static_assert(t0 >= 0, "t0 must be greater than 0.");
        static_assert(t1 >= t0, "t1 must be greater than t0.");
        for(auto i : attackTimes)
            std::cout << i << " ";
        std::cout << std::endl;
        tuple_size =  sizeof...(ships);
    }
    size_t countImperialFleet() const {
        size_t count = 0;
        //for(size_t i = 0; i<tuple_size; i++)
        //    if(std::get<i>(fleet).isImperial()) count++;
        return count;
    }
    size_t countRebelFleet() const {
        size_t count = 0;
        //for(size_t i = 0; i<tuple_size; i++)
        //    if(!std::get<i>(fleet).isImperial()) count++;
        return count;
    }
    void tick(T timeStep) {
        // sprawdza czy mamy zwyciezce
        std::cout << "czas: " << actTime << std::endl;
        if (attackTime(actTime)) {
            attack();
        }
        actTime = (actTime + timeStep) % endTime;
    }
};
#endif //JNP1_4_BATTLE_H
