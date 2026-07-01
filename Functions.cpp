#include "Functions.h"

ALLEGRO_DISPLAY *display;
ALLEGRO_TIMER *timer;
ALLEGRO_FONT *arial;
ALLEGRO_EVENT_QUEUE *event_queue;

//returns a random number between min and max
int randomNumber(int min, int max){
    return rand() % (max - min + 1) + min;
}

//opens and initializes the allegro graphics screen (written by Mr. Creelman)
int initializeAllegro(int width, int height, const char title[]) {

    const float FPS = 16;           // set frame rate
    ALLEGRO_COLOR background = al_map_rgb(255, 255, 255);       // make background white.

    // Initialize Allegro
    al_init();


    // initialize display
    display = al_create_display(width, height);
    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    al_set_window_title(display, title);

    // Initialize keyboard routines
    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // need to add image processor
    if (!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    // 2. setup timer
    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    // Add fonts


   al_init_font_addon(); // initialize the font addon
   al_init_ttf_addon();// initialize the ttf (True Type Font) addon

   arial = al_load_ttf_font("C:/Windows/Fonts/arial.ttf", 16, 0);
   if (!arial){
      al_show_native_message_box(display, "Error", "Error", "Could not load arial.ttf",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      return -1;
   }
    // Initialize primative add on
    if (!al_init_primitives_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // set up event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));        // 3. register timer events

    al_clear_to_color(background);

    al_flip_display();
    //al_start_timer(timer);
//  std::cout << "Init return zero " << std::endl;
    return 0;
}
