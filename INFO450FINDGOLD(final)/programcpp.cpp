#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;

void createTable();			//Initializes game board
void populateMinefield();	//Hides the Bomb and the Gold
void showgameMap(char);		//Prints game map for UI
bool game_over_Lose = false;//Game win/lose condition check
void number_Cell();

int SIZE = 8;				//Sets gameboard width and length to 8
char init_Table[SIZE][SIZE]; char live_Minefield[SIZE + 1][SIZE + 1];
int x = 0; int y = 0; int found_Gold = 0;

void number_Cell() {
	if ((x >= 0) && (x < 9) && (y >= 0) && (y < 9) && (live_Minefield[x][y] != 'B'))
		live_Minefield[x][y]++;
}

void createTable() {
	int x = 0; int y = 0;
	for ( x = 0; x < SIZE; x++)
		for ( y = 0; y < SIZE; y++)
			init_Table[x][y] = '?';
}

void populateMinefield() {
	int BOMB = 0;	int GOLD = 0;
	srand(time(NULL));		//Random Seed

	while (BOMB == 0) {
		x, y = rand() % 8;
		if (init_Table[SIZE][SIZE] == '?') {
			live_Minefield[SIZE+1][SIZE+1] = 'B';
			BOMB++;
		}
	}					//Planting the Bomb

	while (GOLD < 5) {
		x, y = rand() % 8;
		if (init_Table[SIZE][SIZE] == '?' && live_Minefield[x][y] != 'B') {
			live_Minefield[SIZE+1][SIZE+1] = 'G';
			GOLD++;
		}
	}					//Burying Treasure
}

void showgameMap(char arr) {
	cout << "   ";
	for (x = 0; x < SIZE; x++)
		cout << setw(3) << x;
	cout << endl << "   ";
	for (x = 0; x < 26; x++)
		cout << "_";
	cout << endl;

	for (x = 0; x < SIZe; x++) {
		cout << setw(3) << x "|";
		for (y = 0; y < SIZE; y++)
			cout << setw(3) << arr[x][y];
		cout << endl;
	}
}

bool w_w_chkn_Dinner() {
	if (found_Gold = 5)
		return 1;
	else  (live_Minefield[SIZE + 1][SIZE + 1] == 'B'|| guess == 0)
		return 0;
}

int main() {
	int guess = 5;
	char input;
	cout << "Welcome to Thomas' Find - The - Gold - Game ! ! !" << endl;
	cout << "Rules: " << endl; cout << endl;
	cout << "Player gets 5 guesses" << endl;
	cout << "There are 5 pieces of Gold to find" << endl; cout << endl;
	cout << "Find all 5 to WIN, but hit the bomb and you LOSE" << endl;
	cout << "Press any key to continue" << endl;
	cout << "Press 0 at any time to exit program" << endl; cout << endl;
	cin >> input;
	do 
	{
		for (guess = 5; guess > 0; guess--) {
			createTable();
			populateMinefield();
			cout << "Enter the X coordinate of a cell: ";
			cin >> x; cout << endl;
			cout << "Enter the Y coordinate of a cell: ";
			cin >> y; cout << endl;

			if (live_Minefield[x][y] == 'G') {
				init_Table[SIZE][SIZE] = 'F';
				found_Gold++;
				cout << "You found gold!" << endl;
				cout << "Gold pieces found: " << found_Gold << endl;
			}
			if (game_over_Lose) {
				showgameMap(init_Table);
				cout << endl << "Game over... Sorry!" << endl;
			}
			if (w_w_chkn_Dinner()) {
				cout << endl << "Winner!" << endl;
				showgameMap(init_Table);
				
			}
			guess--;
			cout << "Guesses Left: " << guess << endl;
		}
	} while (input != '0');
	system("pause");
	return 0;
}