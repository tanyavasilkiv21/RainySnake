#pragma once
#include <vector>
enum eDirection {
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
class Snake{
private:
	int intX, intY, intLenght, intWidth = 50, intHeight = 25;
	eDirection dirDirection = STOP;
	std::vector<int> vecBodyOnX, vecBodyOnY;
public:
	Snake();

	//Logic funtions
	void ChangeDir(eDirection dir);
	void MoveSnake();
	bool CrashSnake();
	bool EatenFruit(int intFruitX, int intFruitY);
	void GrowSnake();

	//utility functions
	int ShowX();
	int ShowY();
	std::vector<int> ShowBodyOnX();
	std::vector<int> ShowBodyOnY();
};

