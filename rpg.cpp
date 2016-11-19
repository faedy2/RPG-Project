/*





*/


#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<fstream>


using namespace std;


//Prototypes:

void quit();
void menu();
void game();
void human(int& points);
void ogre(int& points);
void elf(int& points);


int main() {

	game();

	return 0;
}


void game() {

	int choice = 0, points = 0;

	do {

		cout << setw(30) << right << "Welcome to RPG Adventures!\n" << endl;
		cout << "Please Select an Option: \n" <<
			"\t1. See Rules.\n" <<
			"\t2. PLAY Game!\n" <<
			"\t3. Quit/n" << endl;
		cin >> choice;

		switch (choice) {

		case 1:
			menu();
			break;
		case 2:
			
			break;

		case 3:
			quit();

		}

	} while (choice != 3);
	return;
}

void quit() {

	cout << "\n\tThank you for Playing! \n";
	exit(EXIT_SUCCESS);
	return;
}


void menu(){

	cout << "Rules: Pick your Character: \n"
		<< "\tHuman\n" 
		<< "\t Ogre\n"
		<< "\t Elf\n\n";
	cout << "Next you will Pick from three Weapons: \n"
		<< "\t1. Flame Thrower \n"
		<< "\t2. Bow and Arrow \n"
		<< "\t3. Magic Potion \n" << endl;
	cout << "You will fight and gain scores based on which\n"
	    << "race you picked and you will accumulate points depending"
		<< " on how well you do accumulating points.\n" << endl;
	

		return;
}


void human(int& points) {

	points = 100;
}

void ogre(int& points) {
	
	points = 200;
}

void elf(int& points) {

	points = 300;
}
