#pragma once
#include "file.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void add_file(vector<file*>& file_list) {

	string new_name = "file" + to_string(file::id+1);

	bool name_exists = true;
	int suffix = 0;
	while (name_exists) {
		name_exists = false;
		for (file* f : file_list) {
			if (f->name == new_name) {
				name_exists = true;
				suffix++;
				new_name = new_name + "_" + to_string(suffix);
				break;
			}
		}
	}
	
	file_list.push_back(new file(new_name));
	
	system("cls");
}


void delete_file(vector<file*>& file_list) {
	string file_name="";
	system("cls");
	Sleep(300);

	for (auto i : file_list) {
		cout << i->name << endl;
	}

	cout << "enter file name you want to delete" << endl;
	cin >> file_name;

	auto it = find_if(file_list.begin(), file_list.end(),
			[file_name](const file* p) { return p->name == file_name; });

	if (it != file_list.end()) {
		delete *it;
		file_list.erase(it);
	}

	system("cls");
}

void open_file(vector<file*>& file_list) {
	string file_name = "";
	int choice =0 ;
	system("cls");
	Sleep(300);

	for (auto i : file_list) {
		cout << i->name << endl;
	}

	cout << "enter file name you want to open" << endl;
	cin >> file_name;
	system("cls");
	auto it = find_if(file_list.begin(), file_list.end(),
		[file_name](const file* p) { return p->name == file_name; });

	if (it != file_list.end()) {
		cout << (*it)->data<<endl;
	}

	cout << "1. edit name" << endl;
	cout << "2. edit data" << endl;
	cout << "3. delete file" << endl;
	cout << "4. exit" << endl;

	
	cin >> choice;
	
	switch (choice) {
	case 1:(*it)->edit_name(); break;
	case 2:(*it)->edit_data(); break;
	case 3:
		if (it != file_list.end()) {
		delete* it;
		file_list.erase(it);
		system("cls");
	} break;
	case 4:system("cls"); return; break;
	}
}

void fileManipulation(vector<file*>& file_list) {
	int choice = 0;
	int line_id = 0;
	string line = "";

	string name = "NULL";
	string data = "NULL";

	vector<fstream> files;

	cout << "1. load from file" << endl;
	cout << "2. save to file" << endl;
	cout << "3. cancel" << endl;
	cout << "choose option : ";
	cin >> choice;

	switch (choice) {
	case 1: break;

	case 2:	
		break;

	case 3: return; break;
	}
}
