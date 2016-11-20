/*
	Fayyaadh Razak & Victor Martins

	rolePlayingGame.cpp

	Create an RPG that will show your knowledge of everything that you
	have learned so far in this class, which includes, but is not
	limited to:
		- Functional Decomposition
		- Looping
		- Conditional Statements

	Input: 

	Processing:
		1. 

	Output: 
*/

// Header Files
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

// Function Prototypes


int main() {
	// Variable Declarations
	int points = 0, random, menuChoice, raceChoice, weaponChoice, highScore;
	char keepPlaying;
	string playerName, highScoreName;
	fstream myFile;

	// Seed random function to current time
	srand(time(NULL));

	do {
		// Display menu
		cout << "\n\tWelcome to RPG Adventures!" << endl
			<< "\nSelect from the following options:" << endl
			<< "1) See Rules" << endl
			<< "2) Play Game" << endl
			<< "3) Quit" << endl
			<< "What do you choose?: ";
		cin >> menuChoice;

		// Display rules
		if (menuChoice == 1) {
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
		}

		// Start game
		else if (menuChoice == 2) {
			do {
				cout << "\tCHARACTER SELECTION" << endl
					<< "\t1) Human" << endl
					<< "\t2) Ogre" << endl
					<< "\t3) Elf" << endl
					<< "What do you choose?: ";
				cin >> raceChoice;

				// Gameplay for Human
				if (raceChoice == 1) {
					points += 100;

					do {
						cout << "\nCHOOSE YOUR WEAPON" << endl
							<< "\t1) Flame Thrower" << endl
							<< "\t2) Bow and Arrow" << endl
							<< "\t3) Magic Potion" << endl
							<< "What do you choose?: ";
						cin >> weaponChoice;

						// Flame Thrower Practice Session
						if (weaponChoice == 1) {
							cout << "\n\tWELCOME TO FLAME THROWER PRACTICE SESSION" << endl;
							
							random = rand() % 4 + 1;

							if (random == 1) {
								cout << "You burned the Infected Snail to a crisp!" << endl;
								points += 100;
							}
							else if (random == 2) {
								cout << "You burned the Skeltal Archer to a crisp!" << endl;
								points += 200;
							}
							else if (random == 3) {
								cout << "You burned the Vampire to a crisp!" << endl;
								points += 300;
							}
							else if (random == 4) {
								cout << "You missed every target! Great job!" << endl;
								points += 0;
							}
						}

						// Bow and Arrow Practice Session
						else if (weaponChoice == 2) {
							cout << "\n\tWELCOME TO BOW AND ARROW PRACTICE SESSION" << endl;

							random = rand() % 4 + 1;

							if (random == 1) {
								cout << "You impaled the Infected Snail!" << endl;
								points += 100;
							}
							else if (random == 2) {
								cout << "You impaled the Skeltal Archer!" << endl;
								points += 200;
							}
							else if (random == 3) {
								cout << "You impaled the Vampire!" << endl;
								points += 300;
							}
							else if (random == 4) {
								cout << "You missed every target! Great job!" << endl;
								points += 0;
							}
						}

						// Try to create a potion
						else if (weaponChoice == 3) {
							cout << "\n\tPOTION CRAFTING" << endl;

							random = rand() % 2;

							if (random == 1) {
								cout << "You made the potion successfully!" << endl;
								points += 200;
							}
							else {
								cout << "You failed the potion creation!" << endl;
								points -= 100;
							}
						}
						else
							cout << "Error ... Invalid choice ... Try again ..." << endl;
					} while (weaponChoice != 1 && weaponChoice != 2 && weaponChoice != 3);
				}

				// Gameplay for Ogre
				else if (raceChoice == 2) {
					points += 200;

				}

				// Gameplay for Elf
				else if (raceChoice == 3) {
					points += 300;

				}

				else
					cout << "Error ... Invalid choice ... Try again ..." << endl;
			} while (raceChoice != 1 && raceChoice != 2 && raceChoice != 3);

			// Display player's final score
			cout << "\n\tYour final score is: " << points << endl;

			// First, read file to get high score info
			myFile.open("highscore.txt", ios::in);

			if (myFile) {
				if (getline(myFile, highScoreName)) {
					myFile >> highScore;
				}
			}
			else {
				cout << "Could not read from highscore.txt... Creating file..." << endl;
			}

			// Close file
			myFile.close();

			// Next, create/modify the high score file
			myFile.open("highscore.txt", ios::out);

			if (myFile) {
				// Prompt user for their name for high score file
				cout << "\nEnter your name to input your"
					<< "\nhigh score (if it's the all-time highest): ";
				cin.ignore();
				getline(cin, playerName);

				if (points >= highScore) {
					myFile << playerName << endl
						<< points;
				}
			}
			else {
				cout << "Error ... Could not create/modify highscore.txt" << endl;
				return 5;	// Input/Output Error Code
			}

			// Close file
			myFile.close();

			// Replay the game if the player wants to
			do {
				cout << "Would you like to continue playing?" << endl
					<< "(Type Y for Yes or N for No): ";
				cin >> keepPlaying;

				if (keepPlaying == 'Y' || keepPlaying == 'y') {
					points = 0;
				}
				if (keepPlaying == 'N' || keepPlaying == 'n') {
					menuChoice = 3;
					cout << "\nThanks for playing!" << endl << endl;
				}
				else if(keepPlaying != 'Y' && keepPlaying != 'y' && keepPlaying != 'N' && keepPlaying != 'n')
					cout << "Error ... Invalid choice ... Try again ..." << endl;
			} while (keepPlaying != 'Y' && keepPlaying != 'y' && keepPlaying != 'N' && keepPlaying != 'n');
		}

		// Quit game
		else if (menuChoice == 3) {
			cout << "\n\tThanks for playing!" << endl << endl;
		}
		else
			cout << "Error ... Invalid choice ... Try again ..." << endl;
	} while (menuChoice != 3);

	return 0;
}



/*

*/
