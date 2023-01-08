#include "Snake.h"

Snake::Snake() {
	intY = intHeight / 2;
	intX = intWidth / 2;
	intLenght = 1;
	vecBodyOnX.push_back(intX);
	vecBodyOnY.push_back(intY);
}

//Logic funtions
void Snake::ChangeDir(eDirection dir) {
	dirDirection = dir;
}
void Snake::MoveSnake() {
	switch (dirDirection) {
	case RIGHT:
		intX++;
		break;
	case LEFT:
		intX--;
		break;
	case DOWN:
		intY++;
		break;
	case UP:
		intY--;
		break;
	}
	vecBodyOnX.push_back(intX);
	vecBodyOnY.push_back(intY);
	if (vecBodyOnX.size() > intLenght) {
		vecBodyOnX.erase(vecBodyOnX.begin());
		vecBodyOnY.erase(vecBodyOnY.begin());
	}
}
bool Snake::CrashSnake() {
	if (intY < 1 || intY > intHeight - 2 || intX < 1 || intX > intWidth - 2) {
		return true;
	}
	for (int i = 0; i < intLenght - 1; i++) {
		if (intX == vecBodyOnX[i] && intY == vecBodyOnY[i]) {
			return true;
		}
	}
	return false;
}
bool Snake::EatenFruit(int intFruitX, int intFruitY) {
	if (intX == intFruitX && intY == intFruitY)
		return true;
	else
		return false;
}
void Snake::GrowSnake() {
	intLenght = intLenght + 1;
}

//utility functions
int Snake::ShowX() {
	return intX;
}
int Snake::ShowY() {
	return intY;
}
std::vector<int> Snake::ShowBodyOnX() {
	return vecBodyOnX;
}
std::vector<int> Snake::ShowBodyOnY() {
	return vecBodyOnY;
}