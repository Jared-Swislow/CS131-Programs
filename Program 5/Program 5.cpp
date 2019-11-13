////////////
//Jared Swislow
//CS 131 Section A
//Program 5: Employee Data
//
//Program description: This program takes employee
//names and data from two files, totals their hours,
//then sorts them by highest amounts of hours.
/////////////

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILE1 = "empdata3.txt";
const string FILE2 = "empdata4.txt";
const int TOTAL_HOURS = 7;

void printArrays(string strings[], int ints[][8], int size,
	int amountOfEmployees);
void openFileAndReadIntoArray(ifstream &fin, const string fileName,
	int hours[50][8], string names[50], int &amountOfEmployees);
void sortArray(string names[], int hours[][8], int size);

int main()
{
	int hours[50][8]{ {0} }; //Sun-Sat are 0-6, 7 is total hours
	string names[50]{" "};
	int amountOfEmployees = 0;

	ifstream fin;

	openFileAndReadIntoArray(fin, FILE1, hours, names, amountOfEmployees);

	sortArray(names, hours, 50);

	printArrays(names, hours, 50, amountOfEmployees);

	fin.clear();
	fin.close();
	
	openFileAndReadIntoArray(fin, FILE2, hours, names, amountOfEmployees);

	sortArray(names, hours, 50);

	printArrays(names, hours, 50, amountOfEmployees);

	fin.clear();

}

void openFileAndReadIntoArray(ifstream& fin, const string fileName,
	int hours[50][8], string names[50], int& amountOfEmployees){

	string str;

	fin.open(fileName);
	if (fin.fail()) {
		cout << "The file " << fileName << " did not open.";
		exit(1);
	}

	fin >> amountOfEmployees;

	for(int i = 0; i < 50 && fin >> str; i++) {
		names[i] = str;
		for (int j = 0; j < 7; j++) {
			fin >> hours[i][j];
			hours[i][TOTAL_HOURS] += hours[i][j];
		}
	}
}

void sortArray(string names[], int hours[][8], int size) {
	bool swapped = false;
	do {
		swapped = false;
		for (int i = 0; i < size - 1; i++) {
			if (hours[i][7] < hours[i + 1][7]) {
				for (int j = 0; j < 8; j++) {
					swap(hours[i][j], hours[i + 1][j]);
				}
				swap(names[i], names[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);
}

void printArrays(string strings[], int ints[][8], int size,
	int amountOfEmployees) {
	cout << "Employee Weekly Hours:" << endl;
	cout << left << setw(16) << "Name: "
		<< " S  M  T  W  T  F  S TTL" << endl;
	for (int i = 0; i < amountOfEmployees; i++) {
		cout << setw(16) << strings[i] << " ";
		for (int j = 0; j < 8; j++) {
			cout << setw(3) << ints[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

/*
Employee Weekly Hours:
Name:            S  M  T  W  T  F  S TTL
Kirk,James       10 10 0  10 12 0  0  42
Bosco,Sam        7  3  8  7  2  5  7  39
Rugg,James       7  3  8  7  2  5  7  39
VanPelt,Grace    5  6  5  6  5  6  5  38
Peters,Greg      5  6  5  6  5  6  5  38
Jane,Patrick     9  3  7  5  8  0  0  32
Lisbon,Teresa    2  3  8  3  6  3  5  30
Rigsby,Wayne     9  10 4  7  0  0  0  30
Lilly,Jack       2  3  8  3  6  3  5  30
Theiss,Bill      9  10 4  7  0  0  0  30
Cho,Kimball      8  8  3  0  8  2  0  29
Daniels,Carl     8  8  3  0  8  2  0  29
Minelli,Virgil   2  5  3  0  4  9  4  27
McCoy,Lenard     0  4  0  8  4  0  2  18
Scott,Annis      1  6  2  0  0  1  0  10

Employee Weekly Hours:
Name:            S  M  T  W  T  F  S TTL
VanPelt,Grace    5  6  5  6  5  6  5  76
Jane,Patrick     9  3  7  5  8  0  0  74
Bosco,Sam        7  3  8  7  2  5  7  71
Lisbon,Teresa    2  3  8  3  6  3  5  69
Kirk,James       10 10 0  10 12 0  0  69
Cho,Kimball      8  8  3  0  8  2  0  68
Rigsby,Wayne     9  10 4  7  0  0  0  68
Rugg,James       7  3  8  7  2  5  7  68
Peters,Greg      5  6  5  6  5  6  5  67
Lilly,Jack       2  3  8  3  6  3  5  60
Theiss,Bill      9  10 4  7  0  0  0  60
Daniels,Carl     8  8  3  0  8  2  0  59
Minelli,Virgil   2  5  3  0  4  9  4  57
Ryan,Kevin       5  6  7  6  5  6  5  40
Leslie,Eddie     5  6  5  6  7  6  5  40
Uhura,Nyota      10 10 0  8  12 0  0  40
Chekov,Pavel     7  3  8  7  2  5  7  39
Parish,Lanie     7  3  8  6  2  5  7  38
McCoy,Lenard     0  4  0  8  4  0  2  36
Esposito,Javier  2  5  3  9  4  9  4  36
Beckett,Kate     2  8  8  3  6  3  5  35
Galloway,David   9  10 4  8  0  0  2  33
Castle,Richard   4  3  7  5  8  0  5  32
Sulu,Hikaru      2  3  8  5  6  3  5  32
Montgo,Roy       9  2  4  7  0  0  8  30
Rodgers,Martha   8  7  3  0  8  2  0  28
Chapel,Christine 1  6  2  8  9  1  0  27
Kyle,John        8  8  3  0  2  2  0  23
Scott,Annis      1  6  2  0  0  1  0  20
Rand,Janice      0  4  0  8  3  0  2  17
*/