/*
To Do:
Look at warnings
Separate renderScreen into two functions: collision and actual rendering

*/

//https://www.programmingsimplified.com/c/conio.h
//https://www.programmingsimplified.com/c/conio.h/kbhit

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>

//#include <chrono>
//#include <thread>
//#include <time.h>

using namespace std;

const int CONSOLE_X_LIMIT = 100;
const int CONSOLE_Y_LIMIT = 25;
const char TOP_LEFT_CORNER = 201;
const char TOP_RIGHT_CORNER = 187;
const char BOTTOM_LEFT_CORNER = 200;
const char BOTTOM_RIGHT_CORNER = 188;
const char TOP_WALL = 205;
const char RIGHT_WALL = 186;
const char BOTTOM_WALL = 205;
const char LEFT_WALL = 186;

struct Position {
	int posX, posY;
};

class Character {
private:
	Position characterPos = { 1,1 };

public:
	
	Character(int initialX, int initialY) {
		characterPos.posX = characterPos.posY = 1;
		setPos(initialX, initialY);
	}

	Character() {
		setPos(1, 1);
	}

	void interpretMovement(int charPressed) {
		switch (static_cast<char>(charPressed)) {
		case 'w':
			if (characterPos.posX > 1) {
				characterPos.posX--;
			}
			break;
		case 'a':
			if (characterPos.posY > 1) {
				characterPos.posY--;
			}
			break;
		case 's':
			if (characterPos.posX < CONSOLE_Y_LIMIT - 1) {
				characterPos.posX++;
			}
			break;
		case 'd':
			if (characterPos.posY < CONSOLE_X_LIMIT - 1) {
				characterPos.posY++;
			}
			break;
		}
	}

	Position getPos() {
		return characterPos;
	}

	int getXPos() {
		return characterPos.posX;
	}

	int getYPos() {
		return characterPos.posY;
	}

	void setPos(int newXPos, int newYPos) {
		if (!(newXPos > CONSOLE_Y_LIMIT - 2 || newXPos < 2)) {
			characterPos.posX = newXPos;
		}
		if (!(newYPos > CONSOLE_X_LIMIT - 2 || newYPos < 2)){
			characterPos.posY = newYPos;
		}
	}

};

class BasicEnemy {
private:
	Position enemyPos;

public:

	BasicEnemy(int initialX, int initialY) {
		enemyPos.posX = enemyPos.posY = 1;
		setPos(initialX, initialY);
	}

	BasicEnemy() {
		enemyPos.posX = enemyPos.posY = 1;
	}

	Position getPos() {
		return enemyPos;
	}

	int getXPos() {
		return enemyPos.posX;
	}

	int getYPos() {
		return enemyPos.posY;
	}

	void setPos(int newXPos, int newYPos) {
		if (!(newXPos > CONSOLE_Y_LIMIT - 2 || newXPos < 2)) {
			enemyPos.posX = newXPos;
		}
		if (!(newYPos > CONSOLE_X_LIMIT - 2 || newYPos < 2)) {
			enemyPos.posY = newYPos;
		}
	}

};

void death();
void renderScreen(const Position& characterPosition, vector<BasicEnemy>& basicEnemyV);
//void interpretMovement(int charPressed, int& charPosX, int& charPosY); //Deprecated

int main()
{
	bool running = true;

	Character character(2, 3);

	vector<BasicEnemy> basicEnemyVect;

	BasicEnemy enemy1(5, 3);
	basicEnemyVect.push_back(enemy1);
	BasicEnemy enemy2(7, 10);
	basicEnemyVect.push_back(enemy2);
	BasicEnemy enemy3(11, 3);
	basicEnemyVect.push_back(enemy3);

	//srand(static_cast<unsigned int>(time(nullptr)));

	while (running) {
		system("CLS");
		
		renderScreen(character.getPos(), basicEnemyVect);

		character.interpretMovement(_getch());
	}
}

void renderScreen(const Position &characterPosition, vector<BasicEnemy> &basicEnemyV) {
	vector<Position> basicEnemyPositions;
	for (int i = 0; i < basicEnemyV.size(); i++) {
		basicEnemyPositions.push_back(basicEnemyV[i].getPos());
	}
	for (int i = 0; i < basicEnemyV.size(); i++) {
		if (basicEnemyPositions[i].posX == characterPosition.posX && basicEnemyPositions[i].posY == characterPosition.posY) {
			death();
		}
	}
	
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
			//Character Rendering
			else if (i == characterPosition.posX && j == characterPosition.posY) {
				cout << "C";
			}
			//Enemy Rendering
			else if (i == basicEnemyPositions[i].posX && j == basicEnemyPositions[i].posY) { //!!!!!!!!!!!!!!!!!!!!!!!!!! goes through the wrong element in basicEnemyPositions
				cout << "E";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	
}

void death() {
	//cout << "you dead bruh" << endl;

	system("CLS");

	cout << TOP_LEFT_CORNER;
	for (int i = 0; i < CONSOLE_X_LIMIT; i++) {
		cout << TOP_WALL;
	}
	cout << TOP_RIGHT_CORNER << endl;


	for (int i = 0; i < CONSOLE_Y_LIMIT; i++) {
		cout << LEFT_WALL;
		for (int j = 0; j < CONSOLE_X_LIMIT; j++) {
			cout << " ";
		}
		cout << RIGHT_WALL << endl;
	}
		
/*
	cout << LEFT_WALL << "                     _____          __  __ ______    ______      ________ _____                   " << RIGHT_WALL << endl;
	cout << LEFT_WALL << "                    / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \                  " << RIGHT_WALL << endl;
	cout << LEFT_WALL << "                   | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |                 " << RIGHT_WALL << endl;
	cout << LEFT_WALL << "                   | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  /                  " << RIGHT_WALL << endl;
	cout << LEFT_WALL << "                   | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \                  " << RIGHT_WALL << endl;
	cout << LEFT_WALL << "                    \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\                 " << RIGHT_WALL << endl;*/

	cout << BOTTOM_LEFT_CORNER;
	for (int i = 0; i < CONSOLE_X_LIMIT; i++) {
		cout << BOTTOM_WALL;
	}
	cout << BOTTOM_RIGHT_CORNER << endl;

	system("pause");
	exit(1);
}

/*********************************** Deprecated interpretMovementFunction
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
*/