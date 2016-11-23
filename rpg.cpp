/*
	RPG Adventures V7.2

	Victor Martins and Fayyaadh Razak

	Input:
	1.Pick Race
	2. Pick Weapon
	3. Fight
	4. Craft Success/Failure.
	5. Input Player Name if their score is the highest.

	Proccessing: 
	1. The player gets to pick his/her race
	2. Player gets to pick their weapon, 
	3. You can fight mosnters until you want to switch
	4. In the end it'll mark your score.
	5. If you do not have a score it will create the "highscore.txt" and save the score.

	Output: The Gme will play based on the decisions you will make, You can start by Picking a race and
	weapon and play the game. You will kill 3 different knds of monsters for different amount of points.

	You can also craft potions and you can fail at making them which you lose points for as well.


*/

//Headers
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
int human(int);
int ogre(int);
int elf(int);
int weaponAttack(int);
int potionSuccess(int);
int potionFail(int);
int weaponMagicPotion(int&);
void saveHighscore(string&, int&);
void readHighscore(int, string, string&, int&);


struct monsters {

	string monsterGoblin = "Goblin Grunt";
	string monsterHarpy = "Harpy";
	string monsterBalrog = "Balrog";
	int goblinPoints = 100;
	int harpyPoints = 200;
	int balrogPoints = 300;
	int action_miss = 1;
	int mID_Goblin = 2;
	int mID_Harpy = 3;
	int mID_Balrog = 4;
	
};

int main() {

	game();// Calls for the whole game

	return 0;
}


void game() {
	string name, currentName;			//variables
	int choice = 0, points = 0, random = 0;
	int weapon = 0, race = 0, highscore = 0;
	int monster = 0;
	int Success = 0, Fail = 0, curentScore;
	monsters creatures;


	do {// Main selection menu

		cout << setw(30) << right << endl <<"\n\tWelcome to RPG Adventures!\n" << endl;
		cout << "Please Select an Option: \n" <<
			"\t1. See Rules.\n" <<
			"\t2. PLAY Game!\n" <<
			"\t3. Quit\n" <<
			" \tChoose: ";
		cin >> choice;
		if (choice < 0 || choice > 4) {
			cout << "\n\tWrong Values Try Again.";
		
		}
		switch (choice) {

		case 1:
			menu();
			break;
		case 2:		//Pick race

			do {
				cout << "\n\tPick your Race: \n"
					<< "\t1. Human \n"
					<< "\t2. Ogre \n"
					<< "\t3. Elf \n"
					<< "\t Choose: ";

				cin >> race;

				if (race <= 0 || race > 3)
					cout << "\n\tWrong Value Try again.";

				else if (race == 1) {
					points = human(points);
					highscore += points;
				}
				else if (race == 2) {
					points = ogre(points);
					highscore += points;
				}
				else if (race == 3) {
					points = elf(points);
					highscore += points;
				}

			} while (race <= 0 || race > 3);


			do {		//Pick Weapon

				cout << "\n\tPick your Weapon: \n"
					<< "\t1. Flamethrower \n"
					<< "\t2. Bow and Arrow(s) \n"
					<< "\t3. Magic Potion \n" <<
					"\tChoose: ";

				cin >> weapon;

				if (weapon <= 0 || weapon > 3)
					cout << "\n\tWrong Value Try Again. ";

			} while (weapon <= 0 || weapon > 3);

			// Flamethrower Battle!

			if (weapon == 1) {
				cout << "\tYou have Entered the Blasted Lands!\n";
				int attack = 0;
				cout << "\n\tYou have encountered a Monster do you wish to Take out your Flamethrower?\n"
					<< "\tPress 1 to Take FLamethrower!" <<
					"'\n\t Choose: ";

				

				do {
					cin >> attack;

				if (attack <= 0 || attack >= 3)
				cout << "\n\tWrong Choice Try Again.";


					if (attack == 1) {

						// Random flamethrower attack options

						if (weaponAttack(random) == creatures.mID_Goblin) {
							cout << "\n\tYou Have Taken your Flamethrower out of your back-pack!\n";
							cout << "\n\tYou have BURNED A " << creatures.monsterGoblin << "! \n\n";
							highscore += creatures.goblinPoints;
							cout << "\tPress 1 to Attack Again!\n"
								<< "\tPress 2 to go to Main Menu" <<
								"'\n\t Choose: ";
						}

						else if (weaponAttack(random) == creatures.mID_Harpy) {
							cout << "\n\tYou Have Taken your Flamethrower out of your back-pack!\n";
							cout << "\n\tYou have BURNED A " << creatures.monsterHarpy << "! \n\n";
							highscore += creatures.harpyPoints;
							cout << "\tPress 1 to Attack Again!\n"
								<< "\tPress 2 to go to Main Menu" <<
								"'\n\t Choose: ";
						}
	
						else if (weaponAttack(random) == creatures.mID_Balrog) {
							cout << "\n\tYou Have Taken your Flamethrower out of your back-pack!\n";
							cout << "\n\tYou have BURNED A " << creatures.monsterBalrog << "! \n\n";
							highscore += creatures.balrogPoints;
							cout << "\tPress 1 to Attack Again!\n"
								<< "\tPress 2 to go to Main Menu" <<
								"'\n\t Choose: ";
						}

						else if (weaponAttack(random) == creatures.action_miss) {
							cout << "\n\tYou Have Taken your Flamethrower out of your back-pack!\n";
							cout << "\n\tYou missed Monsters got AWAY!!\n";
							cout << "\tPress 1 to Attack Again!\n\n"
								<< "\tPress 2 to go to Main Menu!" <<
								"'\n\t Choose: ";
						}

					}	//Main if attack 1

				} while (attack != 2);	//Random attacks


			}	// weapon 1 if statement.



			// Bow and Arrow Battle
			if (weapon == 2) {
				cout << "\tYou have Entered the Archer Forest!\n";
				int attack = 0;
				cout << "\n\tYou have encountered a Monster do you wish to Take out your Bow and Arrow(s) from your Quiver?\n"
					<< "\tPress 1 to Equipt Bow and Arrow(s)!";

				cout << "\n\tYou Have Take out your Bow and Arrow(s) from your Quiver!\n";
				cout << "\tPress 1. ";
				do {// Random bow and arrow attack options
					cin >> attack;

					if (attack <= 0 || attack >= 3)
						cout << "\n\tWrong Choice Try Again.";

					if (attack == 1) {


						if (weaponAttack(random) == creatures.mID_Goblin) {
							cout << "\n\tYou have SHOT A Goblin  Grunt! \n\n";
							highscore += creatures.goblinPoints;
							cout << "\tPress 1 to Attack Again!\n"
								<< "\tPress 2 to go to Main Menu" <<
								"'\n\t Choose: ";
						}

						else if (weaponAttack(random) == creatures.mID_Harpy) {
							cout << "\n\tYou have SHOT A " << creatures.monsterHarpy << "! \n\n";
							highscore += creatures.harpyPoints;
							cout << "\tPress 1 to Attack Again!\n"
								<< "\tPress 2 to go to Main Menu" <<
								"'\n\t Choose: ";
						}
						else if (weaponAttack(random) == creatures.mID_Balrog) {
							cout << "\n\tYou have SHOT A " << creatures.monsterBalrog << "! \n\n";
							highscore += creatures.balrogPoints;
							cout << "\tPress 1 to Attack Again!\n"
								<< "\tPress 2 to go to Main Menu" <<
								"'\n\t Choose: ";
						}
						else if (weaponAttack(random) == creatures.action_miss) {
							cout << "\n\tYou missed, Arrow Wasted!!\n\n";
							cout << "\tPress 1 to Attack Again!\n"
								<< "\tPress 2 to go to Main Menu!" <<
								"'\n\t Choose: ";
						}

					}	//Main if attack 2
	

				} while (attack != 2);	//Random attacks


			}	// weapon 2 if statement.



			//Crafting Potion
			if (weapon == 3) {
				cout << "\tYou have Entered the Crafting Tavern!\n";
				int attack = 0;
				cout << "\n\tYou walk up to an Alchemy Table?\n"
					<< "\tPress 1 to Start Crafting Potions!\n" <<
					"\n\t Choose: ";

				

				do {
					cin >> attack;

					if (attack <= 0 || attack >= 3)
						cout << "\n\tWrong Choice Try Again.";

					if (attack == 1) {
						cout << "\tYou Have begun mixing magical ingredients!\n";
						
						if (weaponMagicPotion(random) == 1) {// If your are successful this if statement executes
							cout << "\n\tYou have Created a Magic Potion CONGRATULATIONS! \n\n";
							Success = potionSuccess(Success);
							highscore += Success;
							cout << "\tPress 1 to CRAFT Again!\n"
								<< "\tPress 2 to go to Main Menu" <<
								"'\n\t Choose: ";
						}

						else if (weaponMagicPotion(random) == 2) {// If you fail this statemnet executes
							cout << "\n\tYou have EXPLODED the Tavern! \n";
							Fail = potionFail(Fail);
							highscore += Fail;
							cout << "\tPress 1 to CRAFT at another Tavern!\n"
								<< "\tPress 2 to go to Main Menu" <<
								"'\n\t Choose: ";
						}

					}	//Main if attack 3

				} while (attack != 2);	//Random attacks


			}	// weapon 3 if statement.

			readHighscore(highscore, name, currentName, curentScore);	/* Reads Writes the Name of the player and the current highest score in the game 
																		if the file doesnt exist itll create one and make the player the highscore and write it to the "highscore.txt"
																		If the file exist itll check to see if the score is higher than the current highest.
																		If it is itll replace it and ask for the players name.
																		If not itll display a message saying You are not the highest score.
																		*/



		case 3:	// case 3 QUIT
			break;
		}// End of Switch statement



	} while (choice != 3);	//main do while.

	return;
}
//quit function to leave game.
void quit() {

	cout << "\n\tThank you for Playing! \n";
	exit(EXIT_SUCCESS);
	return;
}

//main menu selection function.
void menu() {

	cout << "Rules: Pick your Character: \n"
		<< "\tHuman\n"
		<< "\t Ogre\n"
		<< "\t Elf\n\n";
	cout << "Next you will Pick from three Weapons: \n"
		<< "\t1. Flame Thrower \n"
		<< "\t2. Bow and Arrow \n"
		<< "\t3. Magic Potion \n" << endl;
	cout << "You will fight and gain POINTS based on which\n"
		<< "race you picked and you will accumulate points depending"
		<< " on how well you do accumulating points.\n" << endl;
	cout << "Records and displays Score to you." << endl;

	return;
}
//random Flamethrower and Bow and Arrow function.
int weaponAttack(int random) {
	srand(time(NULL));
	random = rand() % 4 + 1;
	return random;
}

//Random magic potion maker fucntion.
int weaponMagicPotion(int& random) {
	srand(time(NULL));
	random = rand() % 2 + 1;
	return random;
}

//human race function.
int human(int points) {

	points = 100;

	return points;
}

//ogre race function
int ogre(int points) {

	points = 200;

	return points;
}

//elf race function
int elf(int points) {

	points = 300;

	return points;
}

//potion creation success function.
int potionSuccess(int success) {
	success = 200;
	return success;
}

//potion creation failure function.
int potionFail(int fail) {
	fail = -100;
	return fail;
}

//saves hiscore to "highscore.txt" function
void saveHighscore(string& name, int& highscore) {
	fstream hFile;

	hFile.open("highscore.txt", ios::out);

	if (hFile) {
		cout << "\n\tPlease Enter Your Name: ";

		cin.ignore();

		getline(cin, name);
		// Write to file

		hFile << name << endl << highscore;


	}
	//closes file
	hFile.close();
	return;
}
//reads and checksto see the highest score and also calls the saveHighscore().
void readHighscore(int highscore, string name, string& currentName, int& currentScore) {
	fstream  hFile;
	if (hFile) {
		hFile.open("highscore.txt", ios::in);

		cout << "\n\tChecking Score....\n";

		if (!hFile) {
			saveHighscore(name, highscore);
			cout << "\n\t----------------------------------\n";
			cout << name << " Highscore is: " << highscore;
			cout << "\n\tSaved Highscore";
			cout << "\n\t----------------------------------\n";
		}
		else if (hFile)
			while (hFile >> currentName) {

				getline(hFile, currentName);

				hFile >> currentScore;

				if (currentScore <= highscore) {
					cout << "\n\tYou have the New Highscore!\n";
					saveHighscore(name, highscore);
					cout << "\t----------------------------------";
					cout << "\n\tNew Highscore is: " << name << " with " << highscore << endl;
					cout << "\t----------------------------------\n";

				}
				else
					cout << "\n\tYou Dont have the Highscore.\n";
			}



	}

	//close file
	hFile.close();
	return;
}

