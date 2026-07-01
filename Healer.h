#ifndef HEALER_H
#define HEALER_H

#include "Person.h"

class Healer : public Person{
    public:
        //constructor
        Healer() {
            setHealthLossPerDay(-2);

            setMaxHealth(10);
            setMaxFame(15);
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

            setFameIncreaseMin(3);
            setFameIncreaseMax(7);
            setFameLossAmount(6);
            setFameLossPercentage(20);

            setHealthIncreaseMin(2);
            setHealthIncreaseMax(4);
            setHealthFillPercentage(10);
        }
};

#endif // HEALER_H
