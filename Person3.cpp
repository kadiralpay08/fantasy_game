#include "Person.h"

//this method allows for the player to spend money at the shop and buy functional items
void Person::visitShop(std::string character){
    //variables (mostly for prices)
    int purchase; //which item the player will buy
    int healingPotionPrice = 4;
    int statuePrice = 12;
    int gunPrice = 8;
    int maxHealthIncreasePrice = 10;
    int maxFameIncreasePrice = 10;
    bool again = true; //if the player wants to buy more than one item
    int pos;
    ALLEGRO_BITMAP *img = al_load_bitmap("shop.png");

    //clear screen and print bitmap
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(img, 10, 10, 0);

    while (again){
        pos = 60;

        //print options with price and stock while also displaying players money
        //std::cout << "1. Healing Potion (heals 10 health)    Price: " << healingPotionPrice << "    Stock: " << healingPotionStock << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("1. Healing Potion (heals 10 health)    Price: " + std::to_string(healingPotionPrice) + "    Stock: " + std::to_string(healingPotionStock)).c_str());
        //std::cout << "2. Statue (+2 fame a day)    Price: " << statuePrice << "    Stock: " << statueStock << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("2. Statue (+2 fame a day)    Price: " + std::to_string(statuePrice) + "    Stock: " + std::to_string(statueStock)).c_str());
        //std::cout << "3. Gun (?)    Price: " << gunPrice << "    Stock: " << gunStock << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("3. Gun (?)    Price: " + std::to_string(gunPrice) + "    Stock: " + std::to_string(gunStock)).c_str());
        //std::cout << "4. Max Health Increase (+2)    Price: " << maxHealthIncreasePrice << "    Stock: endless" << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("4. Max Health Increase (+2)    Price: " + std::to_string(maxHealthIncreasePrice) + "    Stock: endless").c_str());
        //std::cout << "5. Max Fame Increase (+3)    Price: " << maxFameIncreasePrice << "    Stock: endless" << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("5. Max Fame Increase (+3)    Price: " + std::to_string(maxFameIncreasePrice) + "    Stock: endless").c_str());
        //std::cout << std::endl;
        pos += 20;
        //std::cout << "You have " << money << " coins, what would you like to buy? (input 0 to leave shop)" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("You have " + std::to_string(money) + " coins, what would you like to buy? (input 0 to leave shop)").c_str());
        pos += 20;

        //clear screen and print bitmap
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(img, 10, 10, 0);
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1520, 20, ALLEGRO_ALIGN_LEFT, "Previous Purchase");

        //input valid purchase choice
        bool doexit = false;
        while (!doexit){
            ALLEGRO_EVENT ev;
            al_wait_for_event(event_queue, &ev);

            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                doexit = true;
            } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(ev.keyboard.keycode){
                    case ALLEGRO_KEY_0:
                        purchase = 0;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_1:
                        purchase = 1;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_2:
                        purchase = 2;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_3:
                        purchase = 3;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_4:
                        purchase = 4;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_5:
                        purchase = 5;
                        doexit = true;
                        break;
                }
            }
        }

        //std::cin >> purchase;
        //std::cout << std::endl;
        //while (purchase != 0 && purchase != 1 && purchase != 2 && purchase != 3 && purchase != 4 && purchase != 5){
            //std::cout << "Please input a valid choice: ";
            //std::cin >> purchase;
            //std::cout << std::endl;
        //}

        //make sure player has enough money and shop has enough stock to fulfill purchase, if both are true then go forward with the transaction
        if (purchase == 0){
            //closes shop
            again = false;
        } else if (purchase == 1){
            if (healingPotionStock == 0){
                //std::cout << "Unfortunately we are sold out of healing potions!" << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "Unfortunately we are sold out of healing potions!");
            } else if (money < healingPotionPrice){
                //std::cout << "Unfortunately you are too broke to buy this item, womp womp." << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "Unfortunately you are too broke to buy this item, womp womp.");
            } else {
                //std::cout << "You have bought a healing potion!" << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "You have bought a healing potion!");
                healingPotions++;
                money -= healingPotionPrice;
                healingPotionStock--;
            }
        } else if (purchase == 2){
            if (statueStock == 0){
                //std::cout << "Unfortunately we are sold out of statues!" << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "Unfortunately we are sold out of statues!");
            } else if (money < statuePrice) {
                //std::cout << "Unfortunately you are too broke to buy this item, womp womp." << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "Unfortunately you are too broke to buy this item, womp womp.");
            } else {
                //std::cout << "You have bought a statue!" << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "You have bought a statue!");
                statue = true;
                money -= statuePrice;
                statueStock--;
            }
        } else if (purchase == 3){
            if (gunStock == 0){
                //std::cout << "Unfortunately we are sold out of guns!" << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "Unfortunately we are sold out of guns!");
            } else if (money < gunPrice){
                //std::cout << "Unfortunately you are too broke to buy this item, womp womp." << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "Unfortunately you are too broke to buy this item, womp womp.");
            } else {
                //std::cout << "You have bought a gun!" << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "You have bought a gun!");
                gun = true;
                money -= gunPrice;
                gunStock--;
            }
        } else if (purchase == 4){
            if (money < maxHealthIncreasePrice){
                //std::cout << "Unfortunately you are too broke to buy this item, womp womp." << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "Unfortunately you are too broke to buy this item, womp womp.");
            } else {
                //std::cout << "You have bought a max health increase!" << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "You have bought a max health increase!");
                maxHealth += 2;
                money -= maxHealthIncreasePrice;
            }
        } else if (purchase == 5){
            if (money < maxFameIncreasePrice){
                //std::cout << "Unfortunately you are too broke to buy this item, womp womp." << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "Unfortunately you are too broke to buy this item, womp womp.");
            } else {
                //std::cout << "You have bought a max fame increase!" << std::endl << std::endl;
                al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "You have bought a max fame increase!");
                maxFame += 3;
                money -= maxFameIncreasePrice;
            }
        }
    }
    //clear screen and print bitmap
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(img, 10, 10, 0);
}

int Person::bankRobbery(std::string character){
    int pos = 0;
    ALLEGRO_BITMAP *img;

    //clear screen and print bitmap
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1520, pos += 20, ALLEGRO_ALIGN_LEFT, "Previous Day");

    //random chance bank robbery is a success
    int random = randomNumber(1, 100 / bankRobberyPercentage);
    if (random == 1){
        //print bitmap
        img = al_load_bitmap((character  + "Treasure.png").c_str());
        //std::cout << "The robbery was a success, your max money has been increased by 5 and you now have the maximum amount of money!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "The robbery was a success, your max money has been increased by 5 and you now have the maximum");
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "amount of money!");
        //successful robbery increases max money
        maxMoney += 5;
        money = maxMoney;
    } else {
        //print bitmap
        img = al_load_bitmap((character  + "Attack.png").c_str());
        //std::cout << "You were caught by the Arizona ranger with a big iron on his hip, losing 10 fame and 5 money!" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "You were caught by the Arizona ranger with a big iron on his hip, losing 10 fame and 5 money!");
        fame -= 10;
        money -= 5;
    }
    //clear screen and print bitmap
    al_draw_bitmap(img, 10, 10, 0);
    al_flip_display();
    return pos + 20;
}
