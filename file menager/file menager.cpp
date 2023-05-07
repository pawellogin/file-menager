#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include "Header.h"
#include "file.h"

using namespace std;

int main() {
	int choice = 0;
	vector<string> options = { "1. add file","2. delete file","3. open file","4. load files ","5. save files ","6. exit"};
	vector<file> file_list;

	file_list.push_back(*(new file));
	file_list.push_back(*(new file));

	while (1) {

		cout << "file list :"<<endl;
		for (auto i : file_list) {
			cout << i.name << endl;
		}

		cout << endl;
		for (auto i : options) {
			cout << i << endl;
		}

		cin >> choice;
		
		switch (choice) {
		case 1: add_file(file_list); break;
		case 2: delete_file(file_list); break;
		case 3: open_file(file_list); break;
		case 4: //load_files(file_list); break;
		case 5: save_filesv2(file_list); break;
		case 6: return 0; break;
		default: cout << "chose the correct option";
		system("cls");

		}
	}
} 