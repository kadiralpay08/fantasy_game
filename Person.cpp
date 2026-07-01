#include "Person.h"

//calls upon the player to choose an action each day after printing current stats
void Person::menu(int choice){
    //variables
    std::string character;
    int turn; //for choice of action
    int random; //for random events
    int again = true; //tracks actions that don't prompt a new day
    int gracePeriod = 3; //day when certain bad random events begin to happen
    int statueTopplePercentage = 5; //chance statue bought in shop is toppled
    int pos = 0; //position of text
    ALLEGRO_BITMAP *img; //pointer to image

    //while new day is not prompted
    while (again){
        pos = 240;

        //print basic information and stats each day
        //std::cout << "     DAY " << getDay() << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1550, pos += 20, ALLEGRO_ALIGN_LEFT, ("DAY " + std::to_string(getDay())).c_str());

        if (choice == 1){
            character = "Warrior";
            //std::cout << "Character: Warrior" << std::endl << std::endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "Character: Warrior");
        } else if (choice == 2){
            character = "Hunter";
            //std::cout << "Character: Hunter" << std::endl << std::endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "Character: Hunter");
        } else if (choice == 3){
            character = "Healer";
            //std::cout << "Character: Healer" << std::endl << std::endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "Character: Healer");
        }

        //print update on characters stats
        toString(pos);
        pos += 20;

        //print options
        //std::cout << "What would you like to do?" << std::endl << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "What would you like to do?");
        //std::cout << "1. Hunt for food" << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "1. Hunt for food");
        //std::cout << "2. Fight monsters" << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "2. Fight monsters");
        //std::cout << "3. Search for treasure" << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "3. Search for treasure");
        //std::cout << "4. Visit the shop" << std::endl;
        al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "4. Visit the shop");

        //print option to drink healing potion if player has any
        if (healingPotions > 0){
            //std::cout << "5. Drink a healing potion to recover 10 health" << std::endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "5. Drink a healing potion to recover 10 health");
        }

        //print option to rob bank if player owns gun
        if (gun){
            //std::cout << "6. Rob a bank" << std::endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "6. Rob a bank");
        }

        if (checkpoint){
            //std::cout << "7. Business meeting with the uber-wealthy" << std::endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "7. Business meeting with the uber-wealthy");
        }

        //display everything on the allegro screen
        al_flip_display();

        //input valid choice
        bool doexit = false;
        while (!doexit){
            ALLEGRO_EVENT ev;
            al_wait_for_event(event_queue, &ev);

            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                doexit = true;
            } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(ev.keyboard.keycode){
                    case ALLEGRO_KEY_1:
                        turn = 1;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_2:
                        turn = 2;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_3:
                        turn = 3;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_4:
                        turn = 4;
                        doexit = true;
                        break;
                    case ALLEGRO_KEY_5:
                        if (healingPotions > 0){
                            turn = 5;
                            doexit = true;
                        }
                        break;
                    case ALLEGRO_KEY_6:
                        if (gun){
                            turn = 6;
                            doexit = true;
                        }
                        break;
                    case ALLEGRO_KEY_7:
                        if (checkpoint){
                            turn = 7;
                            doexit = true;
                        }
                        break;
                }
            }
        }
        //std::cout << std::endl;
        //std::cin >> turn;
        //std::cout << std::endl;
        //while (turn != 1 && turn != 2 && turn != 3 && turn != 4){
            //if (turn == 5 && healingPotions > 0){
                //break;
            //} else if (turn == 6 && gun){
                //break;
            //} else if (turn == 7 && checkpoint) {
                //break;
            //} else {
                //std::cout << "Please input a valid choice: ";
                //std::cin >> turn;
                //std::cout << std::endl;
            //}
        //}

        //call correct function based on choice, and make again variable true if action does not prompt new day
        again = false;
        if (turn == 1){
            pos = findFood(character);
        } else if (turn == 2){
            pos = fightMonsters(character);
        } else if (turn == 3){
            pos = searchTreasure(character);
        } else if (turn == 4){
            visitShop(character);
            again = true;
            al_clear_to_color(al_map_rgb(0,0,0));
            img = al_load_bitmap((character + "SpriteBasic.png").c_str());
            al_draw_bitmap(img, 10, 10, 0);
        } else if (turn == 5){
            //increase health by 10 or to max if healing potion is consumed
            if (choice == 1 && health + 10 > maxHealth){
                health = maxHealth;
            } else if (choice == 2 && health + 10 > maxHealth){
                health = maxHealth;
            } else {
                health += 10;
            }
            healingPotions--;
            al_clear_to_color(al_map_rgb(0,0,0));
            img = al_load_bitmap("HealingPotion.png");
            al_draw_bitmap(img, 10, 10, 0);
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1520, 20, ALLEGRO_ALIGN_LEFT, "Previous Action");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 40, ALLEGRO_ALIGN_LEFT, "You have consumed a healing potion and gained 10 health!");
            again = true;
        } else if (turn == 6){
            pos = bankRobbery(character);
        } else if (turn == 7){
            pos = businessMeeting(character);

        }
    }

    //random chance for player to trip and lose fame and money after grace period
    if (day > gracePeriod){
        random = randomNumber(1, 100 / tripPercentage);
        if (random == 1){
            //std::cout << "Unfortunately you have tripped and fallen amongst some villagers who begin laughing and taking the gold coins that fell out of your pocket, you have lost " << tripFameLoss << " fame and " << tripMoneyLoss << " coins!" << std::endl << std::endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "Unfortunately you have tripped and fallen amongst some villagers who begin laughing and taking the");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, ("gold coins that fell out of your pocket, you have lost " + std::to_string(tripFameLoss) + " fame and " + std::to_string(tripMoneyLoss) + " coins!").c_str());
            fame -= tripFameLoss;
            money -= tripMoneyLoss;
            //increase trip percentage after each trip until max is reacher
            if (tripPercentage < maxTripPercentage){
                tripPercentage += 5;
            }
        }
    }

    //if player has a statue, add fame each round (unless fame is maxed)
    if (statue == true){
        //random chance statue is toppled
        if (randomNumber(1, 100 / statueTopplePercentage) == 1){
            //std::cout << "The villagers have gotten sick of your tyranny and toppled down your statue, you may buy a new one in the shop!" << std::endl << std::endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "The villagers have gotten sick of your tyranny and toppled down your statue, you may buy a new");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "one in the shop!");
            statue = false;
            statueStock = 1;
        } else {
            if (fame + 3 > maxFame){
            fame = maxFame;
            } else {
            fame += 2;
            }
        }
    }

    //decrease health each day and make sure healer doesn't exceed max health
    if (health - healthLossPerDay > maxHealth){
        health = maxHealth;
    } else {
        health -= healthLossPerDay;
    }

    if (fame >= 15 && money >= 15){
        checkpointCount++;
        if (checkpointCount >= 5){
            checkpoint = true;
        }
    } else {
        checkpointCount = 0;
        checkpoint = false;
    }

    //increase the day
    al_flip_display();
    day++;
}
