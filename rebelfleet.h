//
// Created by kacper on 24.11.18.
//

#ifndef PROJECT_REBELFLEET_H
#define PROJECT_REBELFLEET_H

template <typename U>
class RebelStarship
{
private:
    U shield, speed;
    bool isAlive = true;
public:
    RebelStarship(U shield, U speed) : shield(shield), speed(speed) {}
    template <typename T, T t0, T t1, typename... S>
    friend class SpaceBattle;
    U getShield() const { return shield; }

    U getSpeed() const { return speed; }

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

#endif //PROJECT_REBELFLEET_H
