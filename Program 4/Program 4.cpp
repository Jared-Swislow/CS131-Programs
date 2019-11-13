////
//Name: Jared Swislow
//Section: A
//Program Name: P4 Word Counter
//
//Description: This program will ask the user for a text
//document in the current directory and report how much
//each length of word appears, from 1 letter to 8 letter
//and greater than 8 letters.
////
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin;

	string fileName;
	string stringFromFile;

	int wordLengths[9]{};
	int wordCount = 0;

	while (true) {
		for (int i = 0; i < 9; i++) {
			wordLengths[i] = { 0 };
		}
		wordCount = 0;

		cout << "Enter a file name for a report (or type exit to quit): ";

		do {
			cin >> fileName;
			if (fileName == "exit") {
				exit(1);
			}
			fin.open(fileName);
			if (fin.fail()) {
				cout<< fileName << " could not be read." << endl;
				cout<< "Make sure you have the file extension"
					<< "and correct file name." << endl;
				cout<< "Try again: ";
			}
		} while (fin.fail());

		while (fin >> stringFromFile) {
			int len = stringFromFile.length();
			wordCount++;
			if (0 < len && len < 9) {
				wordLengths[len - 1]++;
			}
			else {
				wordLengths[8]++;
			}
		}

		fin.close();

		cout << endl << "Word report for " << fileName << ": " << endl;
		for (int i = 0; i < 9; i++) {
			if (i == 8) {
				cout << setw(5) << ">8" << setw(5) << wordLengths[i] << endl;
			}
			else {
				cout << setw(5) << i + 1 << setw(5) << wordLengths[i] << endl;
			}
		}
		cout << "Word Count: " << wordCount << endl << endl;
	}
}

/*
Enter a file name for a report (or type exit to quit): infile
infile could not be read.
Make sure you have the file extension and correct file name.
Try again: infile.txt

Word report for infile.txt:
	1   42
	2   91
	3  103
	4  115
	5   57
	6   47
	7   25
	8   27
   >8   17
Word Count: 524

Enter a file name for a report (or type exit to quit): exit
*/