#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "Snake.h"
#include "Fruit.h"

const int intWidth = 50, intHeight = 25; // width and height for board

void DrawBoard(Snake LittleSnake, Fruit SweetFruit) {
	// this func draw board and snake 

	std::vector<int> vecSnakeBodyOnX = LittleSnake.ShowBodyOnX();
	std::vector<int> vecSnakeBodyOnY = LittleSnake.ShowBodyOnY();

	for (int i = 0; i < intHeight; i++) {
		std::cout << "~";
		for (int j = 0; j < intWidth - 2; j++) {
			if (i == 0 || i == intHeight - 1)
				std::cout << "~";
			else if (i == LittleSnake.ShowY() && j+1 == LittleSnake.ShowX()) // snake`s head
				std::cout << "O";
			else if (i == SweetFruit.ShowFruitY() && j+1 == SweetFruit.ShowFruitX()) // fruit
				std::cout << "$";
			else {
				bool boolPartOfSnake = false;
				for (int l = 0; l <  (vecSnakeBodyOnX.size() - 1); l++) { //vecSnakeBodyOnX and vecSnakeBodyOnY have same size thats no matter which I will choose
					if (i == vecSnakeBodyOnY[l] && j+1  == vecSnakeBodyOnX[l]) {//snake`s body
						std::cout << "o";
						boolPartOfSnake = true;
					}
				}
				if (!boolPartOfSnake)
					std::cout << " ";
			}
		}
		std::cout << "~" << std::endl;
		
	}
}

int main(){
	std::srand(time(NULL));
	int intExit = 0;
	std::cout << "\n\n\t\t\t\t\t\t\t    Rainy\n\n";
	std::cout << "\n\t\t     *****         ****        **           *****           **         *      ********";
	std::cout << "\n\t\t  **       **      **   *      **          **   **          **       *        **     ";
	std::cout << "\n\t\t ***               **  *       **         **     **         **    *           **     ";
	std::cout << "\n\t\t      ***          **    *     **        **       **        ** *              ********";
	std::cout << "\n\t\t          ***      **      *   **       *************       **    *           **     ";
	std::cout << "\n\t\t  **      **       **     *    **      **           **      **       *        **     ";
	std::cout << "\n\t\t     *****         **        * **     **             **     **         *      ********";
	std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t     Menu:\n\t\t\t\t\t\t\tPlay, enter 1\n\t\t\t\t\t\t\tExit, enter 2\n";
	std::cin >> intExit;
	system("cls");

	clock_t LastFrameTime = 0;
	while (intExit != 2) {
		int  intScore = 0;
		Snake LittleSnake;
		Fruit SweetFruit;
		bool boolGameOver = false;
		while (!boolGameOver) {
			clock_t CurrentFrameTime = clock();
			if (CurrentFrameTime - LastFrameTime < 100) {
				continue;
			}
			else {
				LastFrameTime = CurrentFrameTime;
			}
			DrawBoard(LittleSnake, SweetFruit);
			//Changing the direction of the snake
			if (_kbhit()) { //Checking of pressing button
				switch (_getch()) { // checking what button was pressed
				case 'w':
					LittleSnake.ChangeDir(UP);
					break;
				case 'a':
					LittleSnake.ChangeDir(LEFT);
					break;
				case 's':
					LittleSnake.ChangeDir(DOWN);
					break;
				case 'd':
					LittleSnake.ChangeDir(RIGHT);
					break;
				case 'l':
					boolGameOver = true;
					break;
				}
			}
			if (LittleSnake.CrashSnake())
				boolGameOver = true;

			//if snake eat fruit, it will grows and fruit will spawns in another place
			if (LittleSnake.EatenFruit(SweetFruit.ShowFruitX(), SweetFruit.ShowFruitY())) {
				intScore++;
				SweetFruit.SetFruitX();
				std::vector<int> vecBodySnakeX = LittleSnake.ShowBodyOnX();
				for (int i = 0; i < vecBodySnakeX.size() - 1; i++) {
					if (vecBodySnakeX[i] == SweetFruit.ShowFruitX()) {
						SweetFruit.SetFruitX();
					}
				}
				SweetFruit.SetFruitY();
				std::vector<int> vecBodySnakeY = LittleSnake.ShowBodyOnY();
				for (int i = 0; i < vecBodySnakeY.size() - 1; i++) {
					if (vecBodySnakeY[i] == SweetFruit.ShowFruitY()) {
						SweetFruit.SetFruitY();
					}
				}
				LittleSnake.GrowSnake();
			}
			LittleSnake.MoveSnake();
			
			std::cout << "\t\t   Your score: " << intScore << std::endl;
			std::cout << "\n\t\tFor autolose, press L " << std::endl;
			// Designed to prevent flickering, the command returns the cursor to position {0, 0}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
		}
		system("cls");

		std::cout << "\n\n\n\t\t\t   U are lose!\n\t\t\t  Your score: " << intScore << std::endl;
		std::cout << "\n\n\n\t\t        Wanna play again?\n\t\tFor play enter 1, for exit enter 2" << std::endl;
		std::cin >> intExit;
		system("cls");
	}
}
