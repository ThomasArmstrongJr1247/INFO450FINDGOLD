#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;



int x = 0; int y = 0;
char init_Table[8][8];
char live_Minefield[8][8];
void createTable();			//Initializes game board
int BOMB = 0;	int GOLD = 0;

void createTable() {
	int x = 0; int y = 0;
	for ( x = 0; x < 8; x++)
		for ( y = 0; y < 8; y++)
			init_Table[x][y] = '?';
}

void populateMinefield() {

	srand(time(NULL));		//Random Seed
	while (BOMB == 0) {
		x, y = rand() % 8;
		if (init_Table[8][8] == '?') {
			live_Minefield[x][y] = 'B';
			BOMB++;
		}
	}			//Planting the Bomb

	while (GOLD < 5) {
		x, y = rand() % 8;
		if (init_Table[8][8] == '?' && live_Minefield[x][y] != 'B') {
			live_Minefield[8][8] = 'G';
			GOLD++;
		}
	}			//Burying Treasure
}

int main() {
	int guess = 5;
	createTable();
	populateMinefield();


	system("pause");
	return 0;
}