#pragma once

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

void display_menu(int current_option,int MAX_OPTIONS) {
    
    vector<string> options = {"add file","delete file","open file"};

    for (int i = 1; i <= MAX_OPTIONS; i++) {
        if (i == current_option) {
            cout << " --> " << options[i-1] << endl;
        }
        else {
            cout << "     " << options[i-1] << endl;
        }
    }
}

//arrow chosing function

int arrow_menu() {

    const int MAX_OPTIONS = 4; // maximum number of options in the menu
    const int ARROW_DELAY_MS = 300; // delay time in milliseconds for changing options with arrow keys

    int current_option = 1; // start with the first option selected
    int key; // to store the keyboard input
    bool is_arrow_key_pressed = false; // flag to indicate if an arrow key is currently pressed
    unsigned long arrow_key_last_pressed_time = 0; // last time an arrow key was pressed (in milliseconds)

    do {
        display_menu(current_option,MAX_OPTIONS);

        key = 0; // reset the value of key to 0
        while (key == 0) { // wait for a key press
            for (int i = 8; i <= 256; i++) { // scan all possible virtual key codes
                if (GetAsyncKeyState(i) & 0x8000) { // check if the key is currently pressed
                    key = i; // store the virtual key code
                    break; // exit the loop
                }
            }
        }

        switch (key) {
        case 38: // up arrow
            if (!is_arrow_key_pressed || (GetTickCount64() - arrow_key_last_pressed_time >= ARROW_DELAY_MS)) {
                // check if the arrow key is not currently pressed, or if it was pressed more than ARROW_DELAY_MS milliseconds ago
                current_option--;
                if (current_option < 1) {
                    current_option = MAX_OPTIONS;
                }
                is_arrow_key_pressed = true; // set the arrow key pressed flag
                arrow_key_last_pressed_time = GetTickCount64(); // update the last pressed time
            } break;
        case 40: // down arrow
            if (!is_arrow_key_pressed || (GetTickCount64() - arrow_key_last_pressed_time >= ARROW_DELAY_MS)) {
                // check if the arrow key is not currently pressed, or if it was pressed more than ARROW_DELAY_MS milliseconds ago
                current_option++;
                if (current_option > MAX_OPTIONS) {
                    current_option = 1;
                }
                is_arrow_key_pressed = true; // set the arrow key pressed flag
                arrow_key_last_pressed_time = GetTickCount64(); // update the last pressed time

            }break;

        default: break;
        }

    } while (key != 13); // repeat until the Enter key is pressed

    return current_option;
}


