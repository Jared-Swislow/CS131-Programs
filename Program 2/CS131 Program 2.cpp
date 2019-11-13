////
//Name: Jared Swislow
//Section: A
//Program Name: Easy Win Dice Game
//
//Description: This program will allow the user
//to play a dice game where three dice are rolled
//for one dollar. Three ones will reward $20, and
//three of another number will reward $10. Two of
//any of the same number will reward $2. Otherwise,
//no money will be rewarded. It will ask the user
//if they want to keep running until they have no
//money.
////

#include <iostream>
#include <ctime>

using namespace std;

const int ANY_TWO_DICE_EQUAL = 2;
const int ALL_THREE_DICE_EQUAL = 10;
const int ALL_DICE_ARE_ONE = 20;

int main()
{
	int currentMoney = 20;
	int diceRolls[3] = {0};
	char playAgain = '0';
	srand(static_cast<unsigned int>(time(nullptr)));

	cout << "You have " << currentMoney << " dollars." << endl;
	cout << "Press enter when you are ready to play." << endl;
	system("pause");
	cout << endl << endl;

	do {

		currentMoney--;

		/*
		cout << "[DEBUG MODE]" << endl << "Choose your dice rolls: ";
		cin >> diceRolls[0];
		cin >> diceRolls[1];
		cin >> diceRolls[2];
		cout << endl;
		*/

		//Random dice rolls
		for (int i = 0; i < 3; i++) {
			diceRolls[i] = rand() % 6 + 1;
		}
		
		cout << "Your dice rolls are " << diceRolls[0] << ", " << diceRolls[1] << ", and " << diceRolls[2] << "." << endl;

		if (diceRolls[0] == diceRolls[1] && diceRolls[1] == diceRolls[2]) {
			if (diceRolls[0] == 1) {
				//Won ALL_DICE_ARE_ONE
				cout << "All three of your dice are 1! You won $" << ALL_DICE_ARE_ONE << ".";
				currentMoney += ALL_DICE_ARE_ONE;
			}
			else {
				//Won ANY_THREE_DICE_EQUAL
				cout << "All three of your dice are the same! You won $" << ALL_THREE_DICE_EQUAL << ".";
				currentMoney += ALL_THREE_DICE_EQUAL;
			}
		}
		else if (diceRolls[0] == diceRolls[1] || diceRolls[1] == diceRolls[2] || diceRolls[2] == diceRolls[0]) {
			//Won ANY_TWO_DICE_EQUAL
			cout << "Two of your dice are the same! You won $" << ANY_TWO_DICE_EQUAL << ".";
			currentMoney += ANY_TWO_DICE_EQUAL;
		}
		else {
			//Lost
			cout << "You lost! Good luck next time!";
		}

		cout << endl;
		if (currentMoney > 0) {
			cout << "You have " << currentMoney << " dollars." << endl;
		}
		else {
			cout << "You are out of money!" << endl;
			break;
		}
		
		cout << "Would you like to play again? (Y for yes, N for no): ";
		cin >> playAgain;
		cout << endl << endl;


	} while ((playAgain == 'y' || playAgain == 'Y') && currentMoney > 0);

	cout << "Thanks for playing!" << endl << endl << endl;
}

//Test outputs

/*
You have 20 dollars.
Press enter when you are ready to play.
Press any key to continue . . .


[DEBUG MODE]
Choose your dice rolls: 1
1
1

Your dice rolls are 1, 1, and 1.
All three of your dice are 1! You won $20.
You have 39 dollars.
Would you like to play again? (Y for yes, N for no): y


[DEBUG MODE]
Choose your dice rolls: 2
2
2

Your dice rolls are 2, 2, and 2.
All three of your dice are the same! You won $10.
You have 48 dollars.
Would you like to play again? (Y for yes, N for no): y


[DEBUG MODE]
Choose your dice rolls: 1
2
2

Your dice rolls are 1, 2, and 2.
Two of your dice are the same! You won $2.
You have 49 dollars.
Would you like to play again? (Y for yes, N for no): y


[DEBUG MODE]
Choose your dice rolls: 2
4
2

Your dice rolls are 2, 4, and 2.
Two of your dice are the same! You won $2.
You have 50 dollars.
Would you like to play again? (Y for yes, N for no): y


[DEBUG MODE]
Choose your dice rolls: 5
5
1

Your dice rolls are 5, 5, and 1.
Two of your dice are the same! You won $2.
You have 51 dollars.
Would you like to play again? (Y for yes, N for no): y


[DEBUG MODE]
Choose your dice rolls: 1
2
3

Your dice rolls are 1, 2, and 3.
You lost! Good luck next time!
You have 50 dollars.
Would you like to play again? (Y for yes, N for no): n


Thanks for playing!
*/

/*
You have 20 dollars.
Press enter when you are ready to play.
Press any key to continue . . .


Your dice rolls are 3, 6, and 6.
Two of your dice are the same! You won $2.
You have 21 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 3, 6, and 3.
Two of your dice are the same! You won $2.
You have 22 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 3, 5, and 5.
Two of your dice are the same! You won $2.
You have 23 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 5, 4, and 2.
You lost! Good luck next time!
You have 22 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 2, 6, and 3.
You lost! Good luck next time!
You have 21 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 5, 4, and 3.
You lost! Good luck next time!
You have 20 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 3, 2, and 1.
You lost! Good luck next time!
You have 19 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 4, 4, and 6.
Two of your dice are the same! You won $2.
You have 20 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 4, 4, and 6.
Two of your dice are the same! You won $2.
You have 21 dollars.
Would you like to play again? (Y for yes, N for no): y


Your dice rolls are 4, 1, and 6.
You lost! Good luck next time!
You have 20 dollars.
Would you like to play again? (Y for yes, N for no): n


Thanks for playing!
*/
