#pragma once
#include "file.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void add_file(vector<file>& file_list) {

	string new_name = "file" + to_string(1 + file_list.size());

	bool name_exists = true;
	int suffix = 0;
	while (name_exists) {
		name_exists = false;
		for (file f : file_list) {
			if (f.name == new_name) {
				name_exists = true;
				suffix++;
				new_name = new_name + "_" + to_string(suffix);
				break;
			}
		}
	}
	
	file_list.push_back(*(new file(new_name)));
	
	system("cls");
}


void delete_file(vector<file>& file_list) {
	string file_name="";
	system("cls");
	Sleep(300);

	for (auto i : file_list) {
		cout << i.name << endl;
	}

	cout << "enter file name you want to delete" << endl;
	cin >> file_name;

	auto it = find_if(file_list.begin(), file_list.end(),
			[file_name](const file p) { return p.name == file_name; });

	if (it != file_list.end()) {
		file_list.erase(it);
	}

	system("cls");
}

void open_file(vector<file>& file_list) {
	string file_name = "";
	int choice =0 ;
	system("cls");
	Sleep(300);

	for (auto i : file_list) {
		cout << i.name << endl;
	}

	cout << "enter file name you want to open" << endl;
	cin >> file_name;
	system("cls");
	auto it = find_if(file_list.begin(), file_list.end(),
		[file_name](const file p) { return p.name == file_name; });

	if (it != file_list.end()) {
		cout << (*it).data<<endl;
	}

	cout << "1. edit name" << endl;
	cout << "2. edit data" << endl;
	cout << "3. delete file" << endl;
	cout << "4. return" << endl;

	
	cin >> choice;
	
	switch (choice) {
	case 1:(*it).edit_name(); break;
	case 2:(*it).edit_data(); break;
	case 3:
		if (it != file_list.end()) {
		delete &it;
		file_list.erase(it);
		system("cls");
	} break;
	case 4:system("cls"); return; break;
	}
}

void load_files(vector<file>& file_list) {

}

void save_files(vector<file>& file_list) {
	
	ofstream* file;
	string folderPath = "C:/Users/pawel/source/repos/Lernign/file menager/file menager/saved_files";

	fs::create_directory(folderPath);

	for (int i = 0; i < file_list.size(); i++) {

		file = new ofstream;

		file->open(folderPath+"/"+ file_list[i].name + ".txt");

		if (file->is_open()) { 
			*file << file_list[i].data;
			file->close();
			std::cout << "File saved successfully." << std::endl;
			Sleep(200);
		}
		else {
			std::cout << "Failed to open the file." << std::endl;
			Sleep(600);
		}

		delete file;
	}
	Sleep(400);
	system("cls");
}

void save_filesv2(vector<file>& file_list) {
	string diskPath;

#ifdef _WIN32
	const char* diskEnvVar = "USERPROFILE";
#else
	const char* diskEnvVar = "HOME";
#endif

	char diskPathBuffer[FILENAME_MAX];
	size_t diskPathSize;

	int result = getenv_s(&diskPathSize, diskPathBuffer, sizeof(diskPathBuffer), diskEnvVar);
	if (result == 0) {
		
		diskPath = "C:";
	}
	else {
		std::cout << "Failed to get the disk path." << std::endl;
		return;
	}

	std::cout << "Disk Path: " << diskPath << std::endl;
	
	string folderPath = diskPath + "\\saved_files";

	fs::create_directory(folderPath);

	for (const auto& file : file_list) {
		std::string filePath = folderPath + "\\" + file.name + ".txt";
		std::ofstream outputFile(filePath);

		if (outputFile.is_open()) {
			outputFile << file.data;
			outputFile.close();
			std::cout << "File saved successfully: " << filePath << std::endl;
			Sleep(200);
		}
		else {
			std::cout << "Failed to open the file: " << filePath << std::endl;
			Sleep(200);
		}
	}
	Sleep(2000);
	system("cls");
}



