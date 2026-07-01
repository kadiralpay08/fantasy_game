#ifndef HUNTER_H
#define HUNTER_H

#include "Person.h"

class Hunter : public Person{
    public:
        //constructor
        Hunter() {
            setHealthLossPerDay(2);

            setMaxHealth(15);
            setMaxFame(20);
            setMaxMoney(25);

            setHealth(getMaxHealth());
            setFame(getMaxFame() / 2);
            setMoney(getMaxMoney() / 3);

            setTripPercentage(10);
            setMaxTripPercentage(25);
            setTripFameLoss(5);
            setTripMoneyLoss(7);

            setBankRobberyPercentage(50);

            setRobberyPercentage(15);
            setMoneyIncreaseMin(4);
            setMoneyIncreaseMax(9);

            setFameIncreaseMin(3);
            setFameIncreaseMax(8);
            setFameLossAmount(7);
            setFameLossPercentage(30);

            setHealthIncreaseMin(2);
            setHealthIncreaseMax(6);
            setHealthFillPercentage(25);
        }
};

#endif // HUNTER_H
