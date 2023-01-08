#include "Fruit.h"
#include <iostream>

Fruit::Fruit() {
	intFruitX = rand() % (intWidth - 3) + 1;
	intFruitY = rand() % (intHeight - 3) + 1;
}
void Fruit::SetFruitX() {
	intFruitX = rand() % (intWidth - 3) + 1;
}
void Fruit::SetFruitY() {
	intFruitY = rand() % (intHeight - 3) + 1;
}
int Fruit::ShowFruitX() {
	return intFruitX;
}
int Fruit::ShowFruitY() {
	return intFruitY;
}