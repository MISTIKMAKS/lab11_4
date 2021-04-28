#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Note
{
	string last_name;
	string name;
	string telephone;
	int day;
	int month;
	int year;
};

void enter_save(char* fname);
void load_print(char* fname);
void telephone_find(char* fname, char* ftelephone);
void sort_binary(char* fname);

int main()
{
	char fname[61];
	char ftelephone[151];
	char ch;
	do
	{
		cout << "--------------------------------\n";
		cout << "Main Menu\n";
		cout << "Please make your selection\n" << endl;
		cout << "[1] - Enter & Save Data\n" << endl;
		cout << "[2] - Load & Print Data\n" << endl;
		cout << "[3] - Sort Binary\n" << endl;
		cout << "[4] - Find Friend By Telephone\n" << endl;
		cout << "[0] - Exit\n";
		cout << "--------------------------------\n";
		cout << "Your Choise: "; cin >> ch;
		switch (ch)
		{
		case '0':
			cout << "Goodbye! See Ya Later, Aligator!!!";
			break;
		case '1':
			cout << "You Chosen [1] - Enter & Save Data:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			enter_save(fname);
			break;
		case '2':
			cout << "You Chosen [2] - Load & Print Data:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			load_print(fname);
			break;
		case '3':
			cout << "You Chosen [3] - Sort Binary:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			sort_binary(fname);
			load_print(fname);
			break;
		case '4':
			cout << "You Chosen [4] - Find Friend By Telephone:\n";
			cin.get();
			cin.sync();
			cout << "Enter File Name: "; cin.getline(fname, sizeof(fname));
			cout << "Enter Telephone Number: "; cin.getline(ftelephone, sizeof(ftelephone));
			sort_binary(fname);
			telephone_find(fname, ftelephone);
			break;
		default:
			cout << endl;
			cout << "--------------------------------\n";
			cout << "Main Menu\n";
			cout << "Please make your selection\n";
			cout << "[1] - Enter & Save Data\n" << endl;
			cout << "[2] - Load & Print Data\n" << endl;
			cout << "[3] - Find Friend By Telephone\n" << endl;
			cout << "[0] - Exit\n";
			cout << "--------------------------------\n";
			cout << "Your Choise: "; cin >> ch;
		}
	} while (ch != '0');
	return 0;
}
void enter_save(char* fname)
{
	ofstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	Note friends;
	char ch;
	do
	{
		cout << endl;
		cout << "Last Name: "; cin.sync();
		cin >> friends.last_name;
		cout << "Name: "; cin.sync();
		cin >> friends.name;
		cout << "Telephone: ";
		cin >> friends.telephone;
		cout << "Birthday Day: ";
		cin >> friends.day;
		cout << "Birthday Month: ";
		cin >> friends.month;
		cout << "Birthday Year: ";
		cin >> friends.year;

		if (!f.write((char*)&friends, sizeof(Note)))
		{
			cerr << "Error writing file." << endl;
		}
		cout << "Continue? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
void load_print(char* fname)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Note friends;
	while (f.read((char*)&friends, sizeof(Note)))
	{
		cout << endl;
		cout << "Last Name: " << friends.last_name << endl;
		cout << "Name: " << friends.name << endl;
		cout << "Telephone: " << friends.telephone << endl;
		cout << "Birthday Day: " << friends.day << endl;
		cout << "Birthday Month: " << friends.month << endl;
		cout << "Birthday Year: " << friends.year << endl;
	}
}
void telephone_find(char* fname, char* ftelephone)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Note friends;
	while (f.read((char*)&friends, sizeof(Note)))
	{
		if (friends.telephone == ftelephone) {
			cout << endl;
			cout << "Found Friend With Telephone (" << ftelephone << ") :" << endl;
			cout << endl;
			cout << "Last Name: " << friends.last_name << endl;
			cout << "Name: " << friends.name << endl;
			cout << "Telephone: " << friends.telephone << endl;
			cout << "Birthday Day: " << friends.day << endl;
			cout << "Birthday Month: " << friends.month << endl;
			cout << "Birthday Year: " << friends.year << endl;
		}
		else
		{
			cout << "...";
			cout << endl;
		}
	}
}
void sort_binary(char* fname) {
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	else {
		f.seekg(0, ios::end);
		int size = f.tellg();
		size = size / sizeof(Note);
		f.seekg(0, ios::beg);
		Note* friends = new Note[size];
		f.read((char*)friends, size * sizeof(Note));
		f.close();
		for (int i = 0; i < size - 1; i++) {
			for (int j = size - 1; j > i; j--) {
				if (friends[j].year < friends[j - 1].year) {
					float temp = friends[j].year;
					friends[j].year = friends[j - 1].year;
					friends[j - 1].year = temp;
				}
				else if (friends[j].year = friends[j - 1].year) {
					if (friends[j].month < friends[j - 1].month) {
						float temp = friends[j].month;
						friends[j].month = friends[j - 1].month;
						friends[j - 1].month = temp;
					}
					else if (friends[j].month = friends[j - 1].month) {
						if (friends[j].day < friends[j - 1].day) {
							float temp = friends[j].day;
							friends[j].day = friends[j - 1].day;
							friends[j - 1].day = temp;
						}
					}
				}
			}
		}
	}
}


