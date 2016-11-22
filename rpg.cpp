/*
	Victor Martins & Fayyaadh Razak

	rpg.cpp

	Create an RPG that will show your knowledge of everything that you
	have learned so far in this class, which includes, but is not
	limited to:
	- Functional Decomposition
	- Looping
	- Conditional Statements

	Input: Main menu choice, Character choice, Weapon choice

	Processing:
		1. Display menu of choices 1-3 for player to choose from
		2. When player chooses "2" at the start menu, then begin the game
		3. Add to player's point total based on what character they choose
		4. Start a specific minigame based on what weapon the player chooses:
			- If they choose "1" or "2", then they can attack as many monsters as they want to,
			  and points will be accumulated based on what monsters they attack
			- If they choose "3", then they will have the chance to create a potion, and they
			  will gain or lose points based on whether or not they successfully made the potion
		5. Check points in "highscore.txt" and points that the current player accumulated. If
		   current player got the new highscore, then their info will replace the info in
		   "highscore.txt".

	Output: Highscore of the player to a file (if it is higher than current high score)
*/

// Header Files
#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<fstream>

using namespace std;

// Function Prototypes
void quit();
void rules();
void game();
int human(int);
int ogre(int);
int elf(int);
int weaponAttack(int);
int goblinGrunt(int);
int harpyMonster(int);
int balrogMonster(int);
int potionSuccess(int);
int potionFail(int);
int weaponMagicPotion(int&);
void saveHighscore(string&, int&);
void readHighscore(int, string, string&, int&);

int main() {

	// Run the entire game from one function
	game();

	return 0;
}



/*
	void game()

	Uses all other functions in order to run the game
	instead of putting the majority of the code in main

	Return Value: None
*/
void game() {
	// Variable Declarations
	string name, currentName;
	int choice = 0, points = 0, random = 0;
	int weapon = 0, race = 0, highscore = 0;
	int goblin = 1, harpy = 2, balrog = 3, miss = 4, monster = 0;
	int Success = 0, Fail = 0, currentScore;
	char keepPlaying;

	// Main selection menu
	do {
		cout << setw(30) << right << endl << "\n\tWelcome to RPG Adventures!" << endl << endl;
		cout << "Please Select an Option: " << endl
			<< "\t1. See Rules" << endl
			<< "\t2. Play Game" << endl
			<< "\t3. Quit" << endl
			<< "\tChoice: ";
		cin >> choice;

		if (choice < 1 || choice > 3) {
			cout << "\n\tInvalid input... Try again...";
		}

		switch (choice) {
		case 1:
			rules();
			break;

		case 2:		// Pick character
			do {
				cout << "\n\tChoose your character:" << endl
					<< "\t1. Human" << endl
					<< "\t2. Ogre" << endl
					<< "\t3. Elf" << endl
					<< "\tChoice: ";

				cin >> race;

				if (race < 1 || race > 3)
					cout << "\n\Invalid value... Try again..." << endl;
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

			} while (race < 1 || race > 3);

			// Pick Weapon
			do {		
				cout << "\n\tPick your Weapon:" << endl
					<< "\t1. Flamethrower" << endl
					<< "\t2. Bow and Arrow(s)" << endl
					<< "\t3. Magic Potion" << endl
					<< "\tChoice: ";
				cin >> weapon;

				if (weapon < 1 || weapon > 3)
					cout << "\n\Invalid value... Try again..." << endl;
			} while (weapon < 1 || weapon > 3);

			// Flamethrower Battle
			if (weapon == 1) {
				cout << "\n\tYou have Entered the Blasted Lands!" << endl;
				int attack = 0;
				cout << "\n\tYou have encountered a monster. Do you wish to use your flamethrower?" << endl
					<< "\tPress 1 to equip your flamethrower, or press 2 to give up the fight: ";

				do {
					cin >> attack;

					if (attack != 1 && attack != 2)
						cout << "\n\tInvalid input... Try again: ";

					if (attack == 1) {
						// Random flamethrower attack options

						cout << "\n\tYou aim your flamethrower..." << endl;

						if (weaponAttack(random) == goblin) {
							cout << "\n\tYou have BURNED A Goblin Grunt! \n\n";
							highscore += goblinGrunt(monster);
							cout << "\tPress 1 to Attack again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\tChoice: ";
						}

						else if (weaponAttack(random) == harpy) {
							cout << "\n\tYou have BURNED A Harpy! \n";
							highscore += harpyMonster(monster);
							cout << "\tPress 1 to Attack again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\tChoice: ";
						}
						else if (weaponAttack(random) == balrog) {
							cout << "\n\tYou have BURNED A Balrog! \n";
							highscore += balrogMonster(monster);
							cout << "\tPress 1 to Attack again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\tChoice: ";
						}
						else if (weaponAttack(random) == miss) {
							cout << "\n\tYou missed!\n";
							cout << "\tPress 1 to Attack again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\tChoice: ";
						}
					}

				} while (attack != 2);

			}	// End of weapon 1 if statement

			// Bow and Arrow Battle
			if (weapon == 2) {
				cout << "\tYou have Entered the Archer Forest..." << endl;
				int attack = 0;
				cout << "\n\tYou have encountered a monster. Do you wish to take out your bow and arrow(s) from your quiver?" << endl;
				cout << "\tPress 1 to begin your session: ";

				// Random bow and arrow attack options
				do {
					cin >> attack;

					if (attack == 1) {
						if (weaponAttack(random) == goblin) {
							cout << "\n\tYou have SHOT A Goblin Grunt!" << endl << endl;
							highscore += goblinGrunt(monster);
							cout << "\tPress 1 to Attack again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\tChoice: ";
						}

						else if (weaponAttack(random) == harpy) {
							cout << "\n\tYou have SHOT A Harpy!" << endl;
							highscore += harpyMonster(monster);
							cout << "\tPress 1 to Attack again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\tChoice: ";
						}
						else if (weaponAttack(random) == balrog) {
							cout << "\n\tYou have SHOT A Balrog!" << endl;
							highscore += balrogMonster(monster);
							cout << "\tPress 1 to Attack again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\tChoice: ";
						}
						else if (weaponAttack(random) == miss) {
							cout << "\n\tYou missed..." << endl;
							cout << "\tPress 1 to Attack again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\tChoice: ";
						}
					}

					else if (attack == 2)
						break;

					else
						cout << "\n\tIncorrect choice... Try again: ";

				} while (attack != 2);	// Allows player to continue until 2 is pressed


			}	// End of weapon 2 if statement

			// Crafting Potion
			if (weapon == 3) {
				cout << "\n\tYou have entered the Crafting Tavern!" << endl;
				int attack = 0;
				cout << "\n\tYou walk up to an Alchemy Table..." << endl
					<< "\tPress 1 to start crafting potions" << endl
					<< "\tChoice: ";

				do {
					cin >> attack;

					cout << "\n\tYou begin mixing magical ingredients..." << endl;

					if (attack > 2)
						cout << "\n\tInvalid input... Try again...";

					if (attack == 1) {

						// If you are successful, this if statement executes
						if (weaponMagicPotion(random) == 1) {
							cout << "\tYou have created a Magic Potion! CONGRATULATIONS!" << endl << endl;
							Success = potionSuccess(Success);

							highscore += Success;

							cout << "\tPress 1 to craft again" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\t Choice: ";
						}

						// If you fail, this statement executes
						else if (weaponMagicPotion(random) == 2) {
							cout << "\tYou destroyed the Tavern..." << endl << endl;
							Fail = potionFail(Fail);

							highscore += Fail;

							cout << "\tPress 1 to craft at another Tavern" << endl
								<< "\tPress 2 to End your session" << endl
								<< "\t Choice: ";
						}

					}	//Main if attack 3


				} while (attack != 2);	//Random attacks


			}	// weapon 3 if statement.

			// See if the player got the highscore
			readHighscore(highscore, name, currentName, currentScore);

			// Replay the game if the player wants to
			do {
				cout << "\nWould you like restart your entire journey?" << endl
					<< "(Type Y for Yes or N for No): ";
				cin >> keepPlaying;

				if (keepPlaying == 'Y' || keepPlaying == 'y') {
					points = 0;
				}
				if (keepPlaying == 'N' || keepPlaying == 'n') {
					choice = 3;
					cout << "\nThanks for playing!" << endl << endl;
				}
				else if (keepPlaying != 'Y' && keepPlaying != 'y' && keepPlaying != 'N' && keepPlaying != 'n')
					cout << "Error ... Invalid choice ... Try again ..." << endl;
			} while (keepPlaying != 'Y' && keepPlaying != 'y' && keepPlaying != 'N' && keepPlaying != 'n');

			break;

		case 3:	// Quit game
			quit();
		} // End of Switch statement

	} while (choice != 3);	// End of do while

	return;
}

/*
	void quit()

	Quits the game

	Return Value: None
*/
void quit() {
	cout << "\n\tThanks for playing!" << endl << endl;
	exit(EXIT_SUCCESS);

	return;
}

/*
	void rules()

	Displays the rules of the game

	Return Value: None
*/
void rules() {

	cout << "\n\tRULES" << endl
				<< "First, you will pick your character: " << endl
				<< "\tHuman" << endl
				<< "\tOgre" << endl
				<< "\tElf" << endl << endl;
			cout << "Next you will pick from three weapons: " << endl
				<< "\t1. Flame Thrower" << endl
				<< "\t2. Bow and Arrow" << endl
				<< "\t3. Magic Potion" << endl << endl;
			cout << "If you pick Flame Thrower or Bow and Arrow, then you will"
				<< " \nbe taken to a practice session to test your skills"
				<< " \non the battlefield, and you will obtain points based on" 
				<< " \nhow well you did." << endl << endl;
			cout << "If you pick Magic Potion, then you will"
				<< " \nattempt to create a potion."
				<< " \nYou will gain or lose points based on how successful you were." << endl << endl;

	return;
}

/*
	int weaponAttack(int random)

	Assigns a random value between 1 and 4 to caller

	Return Value: Which enemy was attacked
*/
int weaponAttack(int random) {
	srand(time(NULL));

	random = rand() % 4 + 1;

	return random;
}

/*
	int weaponMagicPotion(int& random)

	Assigns a random value between 1 and 2 to caller

	Return Value: Whether or not the potion creation was successful
*/
int weaponMagicPotion(int& random) {
	srand(time(NULL));

	random = rand() % 2 + 1;

	return random;
}

/*
	int human(int points)

	Assigns value of 100 to caller

	Return Value: Points for choosing Human character
*/
int human(int points) {

	points = 100;

	return points;
}

/*
	int ogre(int points)

	Assigns value of 200 to caller

	Return Value: Points for choosing Ogre character
*/
int ogre(int points) {

	points = 200;

	return points;
}

/*
	int elf(int points)

	Assigns value of 300 to caller

	Return Value: Points for choosing Elf character
*/
int elf(int points) {

	points = 300;

	return points;
}

/*
	int goblinGrunt(int monster)

	Assigns value of 100 to caller

	Return Value: Points for attacking a Goblin Grunt
*/
int goblinGrunt(int monster) {

	monster = 100;

	return monster;
}

/*
	int harpyMonster(int monster)

	Assigns value of 200 to caller

	Return Value: Points for attacking a Harpy
*/
int harpyMonster(int monster) {

	monster = 200;

	return monster;
}

/*
	int balrogMonster(int monster)

	Assigns value of 300 to caller

	Return Value: Points for attacking a Balrog
*/
int balrogMonster(int monster) {

	monster = 300;

	return monster;
}

/*
	int potionSuccess(int success)

	Assigns value of 200 to caller

	Return Value: Points for a successful potion creation
*/
int potionSuccess(int success) {

	success = 200;

	return success;
}

/*
	int potionFail(int fail)

	Assigns value of -100 to caller

	Return Value: Points for a failed potion creation
*/
int potionFail(int fail) {

	fail = -100;

	return fail;
}

/*
	void saveHighscore(string& name, int& highscore)

	Writes player's name and highscore to highscore.txt

	Return Value: None
*/
void saveHighscore(string& name, int& highscore) {
	fstream hFile;

	hFile.open("highscore.txt", ios::out);

	if (hFile) {
		cout << "\n\tPlease enter your name: ";

		cin.ignore();
		getline(cin, name);
		
		// Write to file
		hFile << name << endl << highscore;
	}

	// Close file
	hFile.close();

	return;
}

/*
	void readHighscore(int highscore, string name, string& currentName, int& currentScore) 

	Reads in score from highscore.txt, checks to see if player's score is higher than score
	in file, then replaces file score with current player's score. If player's score is higher, then
	the player's score will replace the score in the file and the player will be prompted for their name.
	If player's score is not higher, then a message will be displayed saying "You don't have the highscore :(".

	Return Value: None
*/
void readHighscore(int highscore, string name, string& currentName, int& currentScore) {
	fstream  hFile;
	if (hFile) {
		hFile.open("highscore.txt", ios::in);

		cout << "\n\tChecking Score....\n";

		if (!hFile) {
			saveHighscore(name, highscore);
			cout << "\n\t------------------------------------\n";
			cout << name << ", your highscore is: " << highscore;
			cout << "\n\tSuccessfully saved your highscore";
			cout << "\n\t------------------------------------\n";
		}
		else if (hFile)
			while (hFile >> currentName) {

				getline(hFile, currentName);

				hFile >> currentScore;

				if (currentScore <= highscore) {
					cout << "\n\tYou have the new highscore!\n";
					saveHighscore(name, highscore);
					cout << "\t----------------------------------";
					cout << "\n\tThe highest scoring player is: " << name << " with " << highscore << " points." << endl;
					cout << "\t----------------------------------\n";
				}
				else
					cout << "\n\tYou don't have the highscore :(\n";
			}
	}

	// Close file
	hFile.close();

	return;
}
