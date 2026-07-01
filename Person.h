//functions I ended up not needing to use are commented out, but still left there in case I ever need to implement them (they do not appear in UML diagrams)

#include <string>
#include "Functions.h"

#ifndef PERSON_H
#define PERSON_H

// Tell other files these exist somewhere else (found this on GitHub)
extern ALLEGRO_DISPLAY* display;
extern ALLEGRO_TIMER* timer;
extern ALLEGRO_FONT* arial;
extern ALLEGRO_EVENT_QUEUE* event_queue;

class Person{
    public:
        //destructor
        ~Person() {}

        //getters
        int getHealthLossPerDay() { return healthLossPerDay; }

        int getHealth() { return health; }
        int getFame() { return fame; }
        int getMoney() { return money; }
        int getDay() { return day; }

        int getMaxHealth() { return maxHealth; }
        int getMaxFame() { return maxFame; }
        int getMaxMoney() { return maxMoney; }

        int getMoneyIsTheRootOfAllEvil() { return moneyIsTheRootOfAllEvil; }

        //int getTripPercentage() { return tripPercentage; }
        //int getMaxTripPercentage() { return maxTripPercentage ; }
        //int getTripFameLoss() { return tripFameLoss; }
        //int getTripMoneyLoss() { return tripMoneyLoss; }

        //int getBankRobberyPercentage() { return bankRobberyPercentage; }

        //int getRobberyPercentage() { return robberyPercentage; }
        //int getMoneyIncreaseMin () { return moneyIncreaseMin; }
        //int getMoneyIncreaseMax () { return moneyIncreaseMax; }

        //int getFameIncreaseMin() { return fameIncreaseMin; }
        //int getFameIncreaseMax() { return fameIncreaseMax; }
        //int getFameLossAmount() { return fameLossAmount; }
        //int getFameLossPercentage() { return fameLossPercentage; }

        //int getHealthIncreaseMin() { return healthIncreaseMin; }
        //int getHealthIncreaseMax() { return healthIncreaseMax; }
        //int getHealthFillPercentage() { return healthFillPercentage; }

        //setters
        void setHealthLossPerDay(int h) { healthLossPerDay = h; }

        void setHealth(int h) { health = h; }
        void setFame(int f) { fame = f; }
        void setMoney(int m) { money = m; }
        void setDay(int d) { day = d; }

        void setMaxHealth(int m) { maxHealth = m; }
        void setMaxFame(int m) { maxFame = m; }
        void setMaxMoney(int m) { maxMoney = m; }

        void setTripPercentage(int t) { tripPercentage = t; }
        void setMaxTripPercentage(int m) { maxTripPercentage = m; }
        void setTripFameLoss(int t) { tripFameLoss = t; }
        void setTripMoneyLoss(int t) { tripMoneyLoss = t; }

        void setBankRobberyPercentage(int b) { bankRobberyPercentage = b; }

        void setRobberyPercentage(int r) { robberyPercentage = r; }
        void setMoneyIncreaseMin(int m) { moneyIncreaseMin = m; }
        void setMoneyIncreaseMax(int m) { moneyIncreaseMax = m; }

        void setFameIncreaseMin(int f) { fameIncreaseMin = f; }
        void setFameIncreaseMax(int f) { fameIncreaseMax = f; }
        void setFameLossAmount(int f) { fameLossAmount = f; }
        void setFameLossPercentage(int f) { fameLossPercentage = f; }

        void setHealthIncreaseMin(int h) { healthIncreaseMin = h; }
        void setHealthIncreaseMax(int h) { healthIncreaseMax = h; }
        void setHealthFillPercentage(int h) { healthFillPercentage = h; }

        //other methods
        void menu(int choice);
        void toString(int &pos);
        int findFood(std::string character);
        int fightMonsters(std::string character);
        int searchTreasure(std::string character);
        void visitShop(std::string character);
        int bankRobbery(std::string character);
        int businessMeeting(std::string character);

    private:
        //variables
        int healthLossPerDay;

        int health;
        int fame;
        int money;
        int day = 1;

        int maxHealth;
        int maxFame;
        int maxMoney;

        int tripPercentage;
        int maxTripPercentage;
        int tripFameLoss;
        int tripMoneyLoss;

        int bankRobberyPercentage;

        int robberyPercentage;
        int moneyIncreaseMin;
        int moneyIncreaseMax;

        int fameIncreaseMin;
        int fameIncreaseMax;
        int fameLossAmount;
        int fameLossPercentage;

        int healthIncreaseMin;
        int healthIncreaseMax;
        int healthFillPercentage;

        int healingPotionStock = 3;
        int statueStock = 1;
        int gunStock = 1;

        int healingPotions = 0;
        bool statue = false;
        bool gun = false;

        int checkpointCount = 0; //counts days when stats are above a certain level to activate a checkpoint type of thing
        bool checkpoint = false;

        int moneyIsTheRootOfAllEvil = 0; //counts times player has been evil with other rich people and if it is done too much, player gets what they deserve
};

#endif // PERSON_H
