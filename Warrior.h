#ifndef WARRIOR_H
#define WARRIOR_H

#include "Person.h"

class Warrior : public Person{
    public:
        //constructor
        Warrior() {
            setHealthLossPerDay(3);

            setMaxHealth(25);
            setMaxFame(20);
            setMaxMoney(15);

            setHealth(getMaxHealth());
            setFame(getMaxFame() / 2);
            setMoney(getMaxMoney() / 3);

            setTripPercentage(10);
            setMaxTripPercentage(25);
            setTripFameLoss(7);
            setTripMoneyLoss(5);

            setBankRobberyPercentage(50);

            setRobberyPercentage(20);
            setMoneyIncreaseMin(3);
            setMoneyIncreaseMax(6);

            setFameIncreaseMin(4);
            setFameIncreaseMax(9);
            setFameLossAmount(7);
            setFameLossPercentage(15);

            setHealthIncreaseMin(3);
            setHealthIncreaseMax(7);
            setHealthFillPercentage(25);
        }
};

#endif // WARRIOR_H
