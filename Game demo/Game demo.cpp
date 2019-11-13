//https://www.programmingsimplified.com/c/conio.h
//https://www.programmingsimplified.com/c/conio.h/kbhit

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void renderScreen(int charPosX, int charPosY);
void interpretMovement(int charPressed, int& charPosX, int& charPosY);

const int CONSOLE_X_LIMIT = 40;
const int CONSOLE_Y_LIMIT = 20;
const char TOP_LEFT_CORNER = 201;
const char TOP_RIGHT_CORNER = 187;
const char BOTTOM_LEFT_CORNER = 200;
const char BOTTOM_RIGHT_CORNER = 188;
const char TOP_WALL = 205;
const char RIGHT_WALL = 186;
const char BOTTOM_WALL = 205;
const char LEFT_WALL = 186;


int main()
{
	bool running = true;

	int characterPosX = 1;
	int characterPosY = 1;

	while (running) {
		system("CLS");
		
		renderScreen(characterPosX, characterPosY);

		interpretMovement(_getch(), characterPosX, characterPosY);
		
	}
}

void renderScreen(int charPosX, int charPosY) {
	for (int i = 0; i <= CONSOLE_Y_LIMIT; i++) {
		for (int j = 0; j <= CONSOLE_X_LIMIT; j++) {
			if (i == 0) {
				if (j == 0) {
					cout << TOP_LEFT_CORNER;
				}
				else if (j == CONSOLE_X_LIMIT) {
					cout << TOP_RIGHT_CORNER;
				}
				else {
					cout << TOP_WALL;
				}
			}
			else if (j == 0) {
				if (i == 0) {
					break;
				}
				else if (i == CONSOLE_Y_LIMIT) {
					cout << BOTTOM_LEFT_CORNER;
				}
				else {
					cout << LEFT_WALL;
				}
			}
			else if (j == CONSOLE_X_LIMIT) {
				if (i == 0) {
					break;
				}
				else if (i == CONSOLE_Y_LIMIT) {
					cout << BOTTOM_RIGHT_CORNER;
				}
				else {
					cout << RIGHT_WALL;
				}
			}
			else if (i == CONSOLE_Y_LIMIT) {
				if (j == 0 || j == CONSOLE_X_LIMIT) {
					break;
				}
				else {
					cout << BOTTOM_WALL;
				}
			}
			else if (i == charPosX && j == charPosY) {
				cout << "C";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

void interpretMovement(int charPressed, int& charPosX, int& charPosY) {
	switch (static_cast<char>(charPressed)) {
	case 'w':
		if (charPosX > 1) {
			charPosX--;
		}
		break;
	case 'a':
		if (charPosY > 1) {
			charPosY--;
		}
		break;
	case 's':
		if (charPosX < CONSOLE_Y_LIMIT - 1) {
			charPosX++;
		}
		break;
	case 'd':
		if (charPosY < CONSOLE_X_LIMIT - 1) {
			charPosY++;
		}
		break;
	}
}