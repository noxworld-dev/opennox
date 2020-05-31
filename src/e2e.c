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
    // move the mouse closer to the center,
    // click through the initial loading screen
    script_wait(10);
    click_at(300, 100);

    // click the singleplayer button
    click_at(250, 100);
    // wait for animation
    script_wait(10);

    // click new game
    click_at(200, 380);

    // select wizard and click accept
    click_at(450, 130);
    click_at(300, 410);
    // wait for animation
    script_wait(10);

    // click accept on character screen
    click_at(220, 380);

    // wait for game to load
    script_wait(200);
    click_at(220, 400);
    script_wait(100);
    // click bye on the dialog
    click_at(770, 750);

    // look north and run there
    script_move_to(520, 150);
    run_for(28);
    // smash the wall, run to the chest
    script_click(SDL_BUTTON_LEFT);
    run_for(25);
    // open the chest
    click_at(525, 330);
    // pick gold
    click_at(570, 355);

    // look south, run out of the cave
    script_move(0, 400);
    run_for(38);
    // look east, run across the beach
    script_move(400, -400);
    run_for(45);

    // pick the spell
    script_move(-200, 0);
    script_click(SDL_BUTTON_LEFT);

    // wait some time before killing the game
    script_wait(150);

    // kill the game; comment out to explore after the script is done
    script_exit();
}

#endif // NOX_E2E_TEST
