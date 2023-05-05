#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

class file {
public:
    static int id;
    string name;
    string data;

    file() {
        id++;
        name = "file" + to_string(id);
        data = "NULL";
        data.reserve(100);

    }

    file(string s) {
        id++;
        name = s;
        data = "NULL";
        data.reserve(100);
    }

    ~file() {
        id--;
    }

    void edit_name() {
        system("cls");
        cout << "enter new name" << endl;
        cin.ignore();
        getline(cin, name);
        system("cls");
    }

    void edit_data() {
        system("cls");
        cout << "enter new data" << endl;
        cin.ignore();
        getline(cin,data);
        system("cls");
    }
};

int file::id = 0;