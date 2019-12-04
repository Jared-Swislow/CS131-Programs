#include <iostream>
#include <vector>

using namespace std;

int factorial(int input);

int main()
{
	int amt;
	string originalStr;
	vector<string> unusedChars;
	string* permutations;

	cin >> originalStr;

	const char* originalCStr = new char[originalStr.length() + 1];
	originalCStr = originalStr.c_str();
	unusedChars.resize(originalStr.length());
	for (int i = 0; i < originalStr.length(); i++) {
		unusedChars[i] = originalCStr[i];
	}
	//delete[] originalCStr; //This need to work eventually
	//Now originalStr(String) and unusedChars(Vector) store the same thing
	
	amt = factorial(originalStr.length());
	permutations = new string[amt];

	for (int i = 0; i < amt; i++) { //Looping until used all of the chars
		//Need to go through the unusedChars vector and make a kinda tree with each one
		//eventually delete the character in the vector i think(?)
	}
	
}

int factorial(int input) {
	/*if (input < 0) {
		throw "Factorial function does not accept negative numbers";
	}*/
	int fact = 1;
	for (int i = 2; i <= input; i++) {

		fact *= i;

	}
	return fact;
}