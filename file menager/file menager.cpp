#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include "Header.h";

using namespace std;

const int MAX_OPTIONS = 4; // maximum number of options in the menu
const int ARROW_DELAY_MS = 300; // delay time in milliseconds for changing options with arrow keys

int file_num = 1;

void menu_options(int i);

int menu();

class file {
public:
    int id;
    string name;
    string data;

    file() {
        id = file_num-1;
        name = "file" + to_string(file_num);
        data = "NULL";
    }
};

vector<file*> file_list;

file* new_file() {
     file* new_file = new file;
     new_file->id = file_num;
     
     return new_file;
}

void edit_file(); 

void open_file();

int main() {

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    

    while (1) {
        
        

        switch (menu()) {
        case 1: file_list.push_back(new_file()); file_num++; 
            system("cls");
            cout << "creating new file...";
            Sleep(1000); break;

        case 2:cout << "2"; Sleep(1000); break;

        case 3:edit_file();
            system("cls");
            cout << "saving file...";
            Sleep(1000); break;
        case 4: open_file(); continue; break;
        }
         
        
    }

    return 0;
}

void edit_file() {
    int file_id = 0;
    system("cls");
    cout << "enter file id (starts at 0)";
    cin >> file_id;
    system("cls");
    cout << "type in new data : " << endl;
    cin >> file_list[file_id]->data;


}

void open_file() {
    int file_id = 0;
    system("cls");
    cout << "enter file id (starts at 0)";
    cin >> file_id;
    system("cls");
    cout << file_list[file_id]->data<<endl;
    cout << "press enter to exit";
    Sleep(3000);
   
    
    
}

void menu_options(int i) {
    switch (i) {
    case 1: cout << "add file"; break;
    case 2: cout << "delete file"; break;
    case 3: cout << "edit file"; break;
    case 4: cout << "open file"; break;
    default: cout << "error"; break;
    }
}

void display_menu(int current_option) {
    system("cls");

    cout << "File list : " << endl;
    if (file_list.size() == 0) cout << "empty\n";
    for (int i = 0; i < file_list.size(); i++) {
        cout << file_list[i]->name << endl;
    }
    cout << endl;

    cout << "Menu:\n";

    for (int i = 1; i <= MAX_OPTIONS; i++) {
        if (i == current_option) {
            cout << " --> "; menu_options(i); cout << endl;
        }
        else {
            cout << "     "; menu_options(i); cout << endl;
        }
    }
}

int menu() {
    int current_option = 1; // start with the first option selected
    int key; // to store the keyboard input
    bool is_arrow_key_pressed = false; // flag to indicate if an arrow key is currently pressed
    unsigned long arrow_key_last_pressed_time = 0; // last time an arrow key was pressed (in milliseconds)

    do {
        display_menu(current_option);

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