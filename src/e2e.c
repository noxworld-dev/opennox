#include "platform.h"

#ifdef NOX_E2E_TEST

void run_for(unsigned int dt) {
    script_hold(SDL_BUTTON_RIGHT);
    script_wait(dt);
    script_release(SDL_BUTTON_RIGHT);
}

void click_at(int x, int y) {
    script_move_to(x, y);
    script_click(SDL_BUTTON_LEFT);
}

void init_script_events() {
    // click through movies
    script_click(SDL_BUTTON_LEFT);
    script_click(SDL_BUTTON_LEFT);

    // move the mouse closer to the center,
    // click through the initial loading screen
    script_wait(50);
    click_at(300, 100);

    // move the mouse to the singleplayer button
    click_at(250, 100);

    // click new game
    click_at(200, 380);

    // select wizard and click accept
    click_at(450, 130);
    click_at(300, 410);

    // click accept on character screen
    click_at(220, 380);

    // wait for game to load and click bye on the dialog
    script_wait(1800);
    click_at(770, 750);

    // look north and run there
    script_move_to(520, 150);
    run_for(300);
    // smash the wall, run to the chest
    script_click(SDL_BUTTON_LEFT);
    run_for(280);
    // open the chest
    click_at(525, 330);
    // pick gold
    click_at(545, 330);

    // look south, run out of the cave
    script_move(0, 400);
    run_for(380);
    // look east, run across the beach
    script_move(400, -400);
    run_for(450);

    // pick the spell
    script_move(-200, 0);
    script_click(SDL_BUTTON_LEFT);

    // wait some time before killing the game
    script_wait(3000);
}

#endif // NOX_E2E_TEST
