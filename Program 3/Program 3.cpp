////
//Jared Swislow
//Section A
//Program 3: Weight Converter
//
//This program will take pounds
//and ounces from the user an
//convert them to kilograms and
//grams.
////



#include <iostream>
#include <string>

using namespace std;

const double GRAMS_PER_POUND = 453.6;
const double GRAMS_PER_OUNCE = 28.3495;

int promptAndGetInt(string promptMessage);
int convertToGrams(int pounds, int ounces);
void outputResults(int pounds, int ounces, int grams);

int main() {

	int pounds, ounces, grams;

	cout << " Welcome message..........\n";

	pounds = promptAndGetInt("Pounds: ");
	ounces = promptAndGetInt("Ounces: ");
	grams = convertToGrams(pounds, ounces);

	outputResults(pounds, ounces, grams);

	return 0;
}

//promptAndGetInt() will output a prompt message and get an int from the user
int promptAndGetInt(string promptMessage) {
	cout << promptMessage;
	char c = ' ';
	int input = 0;
	do {
		cin >> c;
	} while (!(c >= '0' && c <= '9'));
	cin.putback(c);
	cin >> input;
	return input;
};

//convertToGrams() will convert pounds and ounces to grams
int convertToGrams(int pounds, int ounces) {
	double totalGrams = 0;
	totalGrams += pounds * GRAMS_PER_POUND;
	totalGrams += ounces * GRAMS_PER_OUNCE;
	return static_cast<int>(totalGrams + 0.5);
};

//outputResults() will convert grams to kilograms and grams, then outputs everything
void outputResults(int pounds, int ounces, int grams) {
	int kilograms = 0;
	for (int i = 1; i <= grams / 1000; i++) {
		kilograms++;
	}
	grams -= (kilograms * 1000);
	cout << pounds << " pounds and " << ounces << " ounces is " << kilograms << " kilograms and " << grams << " grams." << endl;
};

/*
 Welcome message..........
Pounds: 5
Ounces: 4
5 pounds and 4 ounces is 2 kilograms and 381 grams.
*/

/*
 Welcome message..........
Pounds: 13
Ounces: 11
13 pounds and 11 ounces is 6 kilograms and 209 grams.
*/