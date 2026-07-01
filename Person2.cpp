#include "Person.h"

//this method will print out an update of the character's stats
void Person::toString(int &pos){
    //std::cout << "Health: " << health << "/" << maxHealth << std::endl;
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("Health: " + std::to_string(health) + "/" + std::to_string(maxHealth)).c_str());
    //std::cout << "Fame: " << fame << "/" << maxFame << std::endl;
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("Fame: " + std::to_string(fame) + "/" + std::to_string(maxFame)).c_str());
    //std::cout << "Money: " << money << "/" << maxMoney << std::endl << std::endl;
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("Money: " + std::to_string(money) + "/" + std::to_string(maxMoney)).c_str());
}

//this method will make the player hunt for food to increase their health
int Person::findFood(std::string character){
    int pos = 0;

    //clear screen and print bitmap
    ALLEGRO_BITMAP *img = al_load_bitmap((character  + "Food.png").c_str()); //chatgpt helped me realize that I was trying to concatenate a c-style string and a C++ string, so I fixed it by converting to c-style string for allegro
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(img, 10, 10, 0);
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1520, pos += 20, ALLEGRO_ALIGN_LEFT, "Previous Day");

    //random chance that health will be fully filled or no health will be filled
    int random = randomNumber(1, 100 / healthFillPercentage);
    if (random == 1){
        health = maxHealth;
        //std::cout << "You manage to come home after a bountiful feast feeling replenished." << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "You manage to come home after a bountiful feast feeling replenished.");
    } else if (random == 2){
        //std::cout << "You spend the day searching for food, but unfortunately find nothing." << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "You spend the day searching for food, but unfortunately find nothing.");
    } else {
        //random amount of increase in health
        random = randomNumber(healthIncreaseMin, healthIncreaseMax);
        //std::cout << "You have gained " << random << " health!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("You have gained " + std::to_string(random) + " health!").c_str());
        //make sure max health isn't surpassed
        if (health + random > maxHealth){
            health = maxHealth;
        } else {
            health += random;
        }
    }
    al_flip_display();
    return pos + 20;
}

//this method will make the player fight a monster to increase fame
int Person::fightMonsters(std::string character){
    int pos = 0;

    //clear screen and print bitmap
    ALLEGRO_BITMAP *img = al_load_bitmap((character  + "Attack.png").c_str());
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(img, 10, 10, 0);
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1520, pos += 20, ALLEGRO_ALIGN_LEFT, "Previous Day");

    //random chance player loses against the monster
    int random = randomNumber(1, 100 / fameLossPercentage);
    if (random == 1){
        //std::cout << "You have been humiliated by the monster, losing " << fameLossAmount << " fame and health!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("You have been humiliated by the monster, losing " + std::to_string(fameLossAmount) + " fame and health!").c_str());
        fame -= fameLossAmount;
        health -= fameLossAmount;
    } else {
        //random amount of increase in fame
        random = randomNumber(fameIncreaseMin, fameIncreaseMax);
        //std::cout << "You have defeated the mighty monster and gained " << random << " fame, but lost " << random / 2 << " health!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("You have defeated the mighty monster and gained " + std::to_string(random) + " fame, but lost " + std::to_string(random / 2) + " health!").c_str());
        //make sure max fame isn't surpassed
        if (fame + random > maxFame){
            fame = maxFame;
        } else {
            fame += random;
        }
        health -= random / 2;
    }
    al_flip_display();
    return pos + 20;
}

//this method will make the player search for treasure to increase money
int Person::searchTreasure(std::string character){
    int pos = 0;

    //clear screen and print bitmap
    ALLEGRO_BITMAP *img = al_load_bitmap((character  + "Treasure.png").c_str());
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(img, 10, 10, 0);
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1520, pos += 20, ALLEGRO_ALIGN_LEFT, "Previous Day");

    //random chance that player gets robbed
    int random = randomNumber(1, 100 / robberyPercentage);
    if (random == 1){
        //std::cout << "You were robbed by bandits on your search for treasure, they have taken more than half your gold!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "You were robbed by bandits on your search for treasure, they have taken more than half your gold!");
        money = money / 2 - 2;
    } else {
        //random amount of increase in money
        random = randomNumber(moneyIncreaseMin, moneyIncreaseMax);
        //std::cout << "You have found a treasure of " << random << " coins!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("You have found a treasure of " + std::to_string(random) + " coins!").c_str());
        //make sure max money isn't surpassed
        if (money + random > maxMoney){
            money = maxMoney;
        } else {
            money += random;
        }
    }
    al_flip_display();
    return pos + 20;
}

int Person::businessMeeting(std::string character){
    int pos = 0;
    int businessMeetingPercentage = 50;
    ALLEGRO_BITMAP *img;

    //clear screen and print bitmap
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1520, pos += 20, ALLEGRO_ALIGN_LEFT, "Previous Day");

    //random chance business meeting goes well
    int random = randomNumber(1, 100 / businessMeetingPercentage);
    if (random == 1){
        //
        img = al_load_bitmap((character  + "Treasure.png").c_str());
        //std::cout << "Your rich friends help you get richer (faint sounds of suffering villagers crying can be heard in the background). You gain 8 gold!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "Your rich friends help you get richer (faint sounds of suffering villagers crying can be heard in");
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "the background). You gain 20 gold, 10 extra max gold, and 5 fame!");
        maxMoney += 10;
        if (money + 20 > maxMoney){
            money = maxMoney;
        } else {
            money += 20;
        }
        if (fame + 5 > maxFame){
            fame = maxFame;
        } else {
            fame += 5;
        }
        moneyIsTheRootOfAllEvil++;
    } else {
        //
        img = al_load_bitmap((character  + "Attack.png").c_str());
        //std::cout << "Your rich friends reveal themselves to be human eating lizard people! You narrowly escape, losing 8 health!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "Your rich friends reveal themselves to be human eating lizard people! You narrowly escape, losing");
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "8 health!");
        health -= 8;
    }
    al_draw_bitmap(img, 10, 10, 0);
    al_flip_display();
    return pos + 20;
}
