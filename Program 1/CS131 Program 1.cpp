////
// Name: Jared Swislow
// Section: A
// Program Name: Change Machine
//
// Description: This program will take an amount of
//cents(0-99) and convert it to an amount of quarters,
//dimes, nickels, and pennies. My program will display
//two outputs; one will be the basic one, and the
//other will use conditionals to format the output better.
////





#include <iostream>

using namespace::std;

int main()
{
	int amountOfCents = 0;
	int amountOfQuarters = 0;
	int amountOfDimes = 0;
	int amountOfNickels = 0;
	int amountOfPennies = 0;
	int amountOfUniqueCoins = 4;
	cout << "How many cents do you have? (0-99): ";
	cin >> amountOfCents;
	if (amountOfCents == 0) {
		cout << "You don't need any change.";
		return 0;
	}
	for (int i = amountOfCents / 25; i > 0; i--) {
		amountOfQuarters++;
		amountOfCents -= 25;
	}
	for (int i = amountOfCents / 10; i > 0; i--) {
		amountOfDimes++;
		amountOfCents -= 10;
	}
	for (int i = amountOfCents / 5; i > 0; i--) {
		amountOfNickels++;
		amountOfCents -= 5;
	}
	amountOfPennies = amountOfCents;
	//Finding how many unique coins you have to give out
	if (amountOfQuarters == 0) {
		amountOfUniqueCoins--;
	}
	if (amountOfDimes == 0) {
		amountOfUniqueCoins--;
	}
	if (amountOfNickels == 0) {
		amountOfUniqueCoins--;
	}
	if (amountOfPennies == 0) {
		amountOfUniqueCoins--;
	}
	//Normal Output
	cout << "You need " << amountOfQuarters << " quarters, " << amountOfDimes << " dimes, " << amountOfNickels << " nickels, and " << amountOfPennies << " pennies." << endl;
	/*
	Advanced Output
	This will do proper formatting such that there will be no "0 quarters", extra commas, etc.
	*/
	cout << "You need ";
	//Printing quarters
	if (amountOfQuarters > 1) {
		cout << amountOfQuarters << " quarters";
	}
	else if (amountOfQuarters == 1) {
		cout << "1 quarter";
	}
	//Checking if we should print a comma here
	if (amountOfUniqueCoins > 2 && amountOfQuarters != 0) {
		cout << ", ";
	}
	//Checking if we should print "and" here
	if (amountOfUniqueCoins > 2 && amountOfPennies == 0 && amountOfNickels == 0 && amountOfDimes != 0) {
		cout << "and ";
	}
	else if (amountOfUniqueCoins == 2 && amountOfPennies == 0 && amountOfNickels == 0 && amountOfDimes != 0) {
		cout << " and ";
	}
	//Printing Dimes
	if (amountOfDimes > 1) {
		cout << amountOfDimes << " dimes";
	}
	else if (amountOfDimes == 1) {
		cout << "1 dime";
	}
	//Checking if we should print a comma here
	if (amountOfUniqueCoins > 2 && amountOfDimes != 0) {
		cout << ", ";
	}
	//Checking if we should print "and" here
	if (amountOfUniqueCoins > 2 && amountOfPennies == 0 && amountOfNickels != 0) {
		cout << "and ";
	}
	else if (amountOfUniqueCoins == 2 && amountOfPennies == 0 && amountOfNickels != 0) {
		cout << " and ";
	}
	//Printing Nickels
	if (amountOfNickels > 1) {
		cout << amountOfNickels << " nickels";
	}
	else if (amountOfNickels == 1) {
		cout << "1 nickel";
	}
	//Checking if we should print a comma here
	if (amountOfUniqueCoins > 2 && amountOfNickels != 0) {
		cout << ", ";
	}
	//Checking if we should print "and" here
	if (amountOfUniqueCoins > 2 && amountOfPennies != 0) {
		cout << "and ";
	}
	else if (amountOfUniqueCoins == 2 && amountOfPennies != 0) {
		cout << " and ";
	}

	//Printing Pennies
	if (amountOfPennies > 1) {
		cout << amountOfPennies << " pennies";
	}
	else if (amountOfPennies == 1) {
		cout << "1 penny";
	}
	cout << "." << endl;
}


/*

Example Outputs

*/

/*
How many cents do you have? (0-99): 8
You need 0 quarters, 0 dimes, 1 nickels, and 3 pennies.
You need 1 nickel and 3 pennies.
*/
/*
How many cents do you have? (0-99): 42
You need 1 quarters, 1 dimes, 1 nickels, and 2 pennies.
You need 1 quarter, 1 dime, 1 nickel, and 2 pennies.
*/
/*
How many cents do you have? (0-99): 99
You need 3 quarters, 2 dimes, 0 nickels, and 4 pennies.
You need 3 quarters, 2 dimes, and 4 pennies.
*/
