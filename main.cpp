/*Kadir Alpay - October 2025 - Fantasy Game: featuring classes of characters that have stats that need to be kept above 0 to stay alive

Note: The old console code (cout, cin, etc.) has been commented out and replaced by allegro functions, the comments are still in the program by choice

Known Bugs/Refinements:
Resolution should be smaller to fit on any screen
Code in main.cpp can be less repetitive with the use of pointers
Rob a bank is number 6 even if number 5 isnt there, the numbers for each action are hard-coded
Some players (Ayaan, Ian, Victor) reported finding it weird that players health could never exceed 13 even though max health was 15 because you would lose 2 health at the end of everyday, maybe health decrease can occur before increase to improve user experience
Ayaan suggested game could be easier, but others enjoy the challenge
*/
#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include "Person.h"
#include "Warrior.h"
#include "Hunter.h"
#include "Healer.h"

using namespace std;

int main()
{
    //defining variables
    int choice;
    int pos = 0;
    ALLEGRO_BITMAP *img;
    int finalPos;

    //seed random numbers
    srand(time(0));

    //prepare the graphics screen
    al_set_new_window_position(0, 0);       //Move window to top-left (chatgpt helped me fix a bug where the window was off screen)
    initializeAllegro(1920, 1080, "Fantasy Game");
    srand(time(NULL));

    //print game information
    //cout << "Welcome to the Fantasy Character Game! You can play as one of two characters. You will need to manage your health, fame, and money in order to survive!" << endl;
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "Welcome to the Fantasy Character Game! You can play as one of two characters.");
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "You will need to manage your health, fame, and money in order to survive!");
    //cout << endl << "Who would you like to play as?" << endl;
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "Who would you like to play as?");
    //cout << endl << "    1. Warrior" << endl << "    2. Hunter" << endl << "    3. Healer" << endl << endl;
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "1. Warrior");
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "2. Hunter");
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, pos += 20, ALLEGRO_ALIGN_LEFT, "3. Healer");

    //print menu image and flip
    img = al_load_bitmap("menu.png");
    al_draw_bitmap(img, 10, 10, 0);
    al_flip_display();

    //input valid character choice (credit to Mr. Creelman's Allegro tutorial)
    bool doexit = false;
    while (!doexit){
    	ALLEGRO_EVENT ev;
      	al_wait_for_event(event_queue, &ev);

      	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        	doexit = true;
      	} else if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
         	switch(ev.keyboard.keycode){
            	case ALLEGRO_KEY_1:
               		choice = 1;
               		doexit = true;
               		break;
	            case ALLEGRO_KEY_2:
    		        choice = 2;
    		        doexit = true;
            		break;
            	case ALLEGRO_KEY_3:
               		choice = 3;
               		doexit = true;
               		break;
         	}
		}
	}
    //cin >> choice;
    //cout << endl;
    //while (choice != 1 && choice != 2 && choice != 3){
        //cout << "Please input a valid choice: 1 for Warrior or 2 for Hunter or 3 for Healer" << endl << endl;
        //cin >> choice;
        //cout << endl;
    //}

    //if Warrior
    if (choice == 1){
        //create warrior object
        //cout << "You have selected Warrior!" << endl << endl;
        //al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 160, ALLEGRO_ALIGN_LEFT, "You have selected Warrior!");
        //al_flip_display();
        Warrior warrior;

        //print sprite then flip
        ALLEGRO_BITMAP *img = al_load_bitmap("WarriorSpriteBasic.png");
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(img, 10, 10, 0);
        al_flip_display();

        //while all of the values are above zero, the game continues
        while (warrior.getHealth() > 0 && warrior.getFame() > 0 && warrior.getMoney() > 0 && warrior.getMoneyIsTheRootOfAllEvil() != 5){
            warrior.menu(choice);
        }
        //game ends if player does 5 evil business meetings
        if (warrior.getMoneyIsTheRootOfAllEvil() == 5){
            //cout << "This is what you get for colluding with other corrupt rich people and undermining the needs of the suffering villagers you capitalist swine! Fortunately for the villagers, you have lost, you survived for " << warrior.getDay() - 2 << " days." << endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, "The villagers organized a riot outside of your estate and took your head to the guillotine!");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, "This is what you get for colluding with other corrupt rich people and undermining the needs of");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 320, ALLEGRO_ALIGN_LEFT, "suffering villagers you capitalist swine! Fortunately for the villagers, you have lost, you");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 340, ALLEGRO_ALIGN_LEFT, ("survived for " + to_string(warrior.getDay() - 2) + " day(s).").c_str());
            finalPos = 360;
        } else {
            //cout << "Unfortunately you have lost. You survived for " << warrior.getDay() - 2 << " days!" << endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, ("Unfortunately you have lost. You survived for " + to_string(warrior.getDay() - 2) + " day(s)!").c_str());
            finalPos = 320;
        }
    //if Hunter
    } else if (choice == 2){
        //create hunter object
        //cout << "You have selected Hunter!" << endl << endl;
        //al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 160, ALLEGRO_ALIGN_LEFT, "You have selected Hunter!");
        //al_flip_display();
        Hunter hunter;

        //print sprite then flip
        ALLEGRO_BITMAP *img = al_load_bitmap("HunterSpriteBasic.png");
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(img, 10, 10, 0);
        al_flip_display();

        //while all of the values are above zero, the game continues
        while (hunter.getHealth() > 0 && hunter.getFame() > 0 && hunter.getMoney() > 0 && hunter.getMoneyIsTheRootOfAllEvil() != 5){
            hunter.menu(choice);
        }
        //game ends if player does 5 evil business meetings
        if (hunter.getMoneyIsTheRootOfAllEvil() == 5){
            //cout << "This is what you get for colluding with other corrupt rich people and undermining the needs of the suffering villagers you capitalist swine! You survived for " << hunter.getDay() - 2 << " days." << endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, "The villagers organized a riot outside of your estate and took your head to the guillotine!");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, "This is what you get for colluding with other corrupt rich people and undermining the needs of");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 320, ALLEGRO_ALIGN_LEFT, "the suffering villagers you capitalist swine! Fortunately for the villagers, you have lost, you");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 340, ALLEGRO_ALIGN_LEFT, ("survived for " + to_string(hunter.getDay() - 2) + " day(s).").c_str());
            finalPos = 360;
        } else {
            //cout << "Unfortunately you have lost. You survived for " << hunter.getDay() - 2 << " days!" << endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, ("Unfortunately you have lost. You survived for " + to_string(hunter.getDay() - 2) + " day(s)!").c_str());
            finalPos = 320;
        }
    //if Healer
    } else if (choice == 3){
        //create healer object
        //cout << "You have selected Healer!" << endl << endl;
        //al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 160, ALLEGRO_ALIGN_LEFT, "You have selected Healer!");
        //al_flip_display();
        Healer healer;

        //print sprite then flip
        ALLEGRO_BITMAP *img = al_load_bitmap("HealerSpriteBasic.png");
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(img, 10, 10, 0);
        al_flip_display();

        //while all of the values are above zero, the game continues
        while (healer.getHealth() > 0 && healer.getFame() > 0 && healer.getMoney() > 0 && healer.getMoneyIsTheRootOfAllEvil() != 5){
            healer.menu(choice);
        }
        //game ends if player does 5 evil business meetings
        if (healer.getMoneyIsTheRootOfAllEvil() == 5){
            //cout << "This is what you get for colluding with other corrupt rich people and undermining the needs of the suffering villagers you capitalist swine! You survived for " << healer.getDay() - 2 << " days." << endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, "The villagers organized a riot outside of your estate and took your head to the guillotine!");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, "This is what you get for colluding with other corrupt rich people and undermining the needs of");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 320, ALLEGRO_ALIGN_LEFT, "suffering villagers you capitalist swine! Fortunately for the villagers, you have lost, you");
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 340, ALLEGRO_ALIGN_LEFT, ("survived for " + to_string(healer.getDay() - 2) + " day(s).").c_str());
            finalPos = 360;
        } else {
            //cout << "Unfortunately you have lost. You survived for " << healer.getDay() - 2 << " days!" << endl;
            al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, 300, ALLEGRO_ALIGN_LEFT, ("Unfortunately you have lost. You survived for " + to_string(healer.getDay() - 2) + " day(s)!").c_str());
            finalPos = 320;
        }
    }
    al_draw_text(arial, al_map_rgb(255, 255, 255), 1200, finalPos, ALLEGRO_ALIGN_LEFT, "Press the ESCAPE key to close the game!");
    al_flip_display();

    //close game when escape key is pressed
    doexit = false;
    while (!doexit){
    	ALLEGRO_EVENT ev;
      	al_wait_for_event(event_queue, &ev);

      	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        	doexit = true;
      	} else if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
         	if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                doexit = true;
         	}
		}
	}
    return 0;
}
