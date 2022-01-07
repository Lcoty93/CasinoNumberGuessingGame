/*Casino Number Guessing Game
* Created by Luke Coty
* 01/07/2022
*/

#include <iostream>
#include <cstdlib>	//Needed to use rand() and srand() functions
#include <ctime>	//Needed to use time() function to seed the function random

using namespace std;

void printRules();



int main()
{
	
	string playerName; //Used to store the players name
	int balance=500, bettingAmount, guess, dice;
	bool choice;

	srand(time(0)); //seeds the function srand() to have a different number everytime
	dice = rand() % 10 + 1;

	cout << "\t==========WELCOME TO CASINO WORLD==========" << endl;
	cout << "\tEnter your name: ";
	cin >> playerName;
	
	system("cls"); //Clears the console log
	cout << "Welcome " << playerName << " let's go over the rules first..." << endl;
	printRules();
	system("pause"); //Pauses the system and prints out 
	//Press any key to continue . . .
	system("cls");

	cout << "\tYour starting balance is $" << balance << endl;

	//Do while loop that repeats the game until the player runs out of money
	//Like a real casino
	do {
		//Get Players betting balance
		do
		{
			cout << playerName << ", enter amount to bet: $";
			cin >> bettingAmount;
			if (bettingAmount > balance)
				cout << "Betting balance can't be more than current balance!\n" <<
				"Re-enter balance\n";
		} while (bettingAmount > balance);
		system("cls");

		//Get players number
		do
		{
			cout << "Guess any betting number between 0 - 10: ";
			cin >> guess;
			if (guess < 0 || guess > 10)
				cout << "Number should be be between 0 - 10\n" <<
				"Re-enter number:";
		} while (guess < 0 || guess > 10);

		if (dice == guess)
		{
			cout << "You are in luck!! You have won!" << endl;
			bettingAmount * 10;
			balance += bettingAmount;
			cout << "Your new balance is: $" << balance << endl;
		}
		else
		{
			cout << "Better luck next time! You lost $" << bettingAmount;
			balance -= bettingAmount;
			cout << "\nYour new balance is: $" << balance << endl;
		}
		cout << "The winning number was: " << dice << endl;
	} while (balance > 0);
	
	if (balance <= 0)
		cout << "Sorry, you have ran out of money." << endl;

	cout << "Thank you! have a great day!!";


	system("pause>0");
}

void printRules()
{
	cout << "\t==========CASINO NUMBER GUESSING RULES!==========" << endl;
	cout << "\tRule 1: Choose a number between 0 and 10." << endl;
	cout << "\tRule 2: Winner gets 10 times the money they bet." << endl;
	cout << "\tRule 3: Guess wrong and you lose the amount you bet." << endl;
}