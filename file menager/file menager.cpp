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
	vector<string> options = { "1. add file","2. delete file","3. open file","4. load files ","5. save files ","6. change path","7. exit"};
	vector<file> file_list;

	string savePath = "C:\\saved_files";
	string loadPath = "C:\\files_to_load";

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
		case 4: load_files(loadPath,file_list); break;
		case 5: save_files(savePath,file_list); break;
		case 6: changePaths(savePath,loadPath); break;
		case 7: return 0; break;

		default: cout << "chose the correct option";
		system("cls");

		}
	}
} 