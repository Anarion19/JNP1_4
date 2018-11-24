//
// Created by kacper on 24.11.18.
//

#ifndef JNP1_4_IMPERIALFLEET_H
#define JNP1_4_IMPERIALFLEET_H

template <typename U>
class ImperialStarship
{
private:
    U shield, attackPower;
    bool isAlive = true;
public:
    template <typename T, T t0, T t1, typename... S>
    friend class SpaceBattle;

    ImperialStarship(U shield, U attackPower) : shield(shield), attackPower(attackPower) {}

    U getShield() const { return shield; }

    U getAttackPower() const { return attackPower; }

    void takeDamage(U damage)
    {
        if(isAlive)
        {
            if (damage < shield)
            {
                shield -= damage;
            } else {
                isAlive = false;
            }
        }
    }
};
#endif //JNP1_4_IMPERIALFLEET_H
