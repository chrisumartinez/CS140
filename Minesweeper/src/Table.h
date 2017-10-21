/*
 * Table.h
 *
 *  Created on: Apr 26, 2016
 *      Author: Bizzy
 */

#ifndef TABLE_H_
#define TABLE_H_

#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Create the Class Table.
 *
 */
class MinesweeperTable {
public:
	void initMinesweeper();
	void createTable();
	void promptTableWidth();
	void promptMines();
	void setMines();
	void setNum();
	void display();
	void findMines();
private:
	int tableWidth;
	int tableRow;
	int tableColumn;
	char table[15][15];
	char inputTable[15][15];
	int mineRow;
	int mineColumn;
	char inputMine;
};
int response;

void MinesweeperTable::initMinesweeper() {
	promptTableWidth();
	cout <<"Table: " << endl;
	promptMines();
	cout << "Creating Table..." << endl;
	createTable();
	display();
	cout << "Displaying Numbers..." << endl;
	setNum();
	display();
}
/*
 * Asks for input.
 */
void MinesweeperTable::promptTableWidth() {
	cout << "Input: " << endl;
	response = 0;
	cin >> response;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		promptTableWidth();
	} else {
		tableRow = response;
		tableColumn = response;
	}

}
void MinesweeperTable::promptMines(){
	for(int i = 0; i < tableColumn; i++){
		cout << "Row: " << i << endl;
		for(int j = 0; j < tableRow; j++){
			cin >> inputMine;
			inputTable[i][j] = inputMine;
		}

	}
}
/*
 * initalize it to False;
 */
void MinesweeperTable::createTable() {
	for(int i = 0; i < tableColumn; i++){
		for(int j = 0; j < tableRow; j++){
			table[i][j] = inputTable[i][j];
		}
	}
}
/*
 * Set Random Mines
 */
/*
 * sets up the numbers from
 */
void MinesweeperTable::setNum(){
	//check for the numbers
	for(int i = 0; i < tableRow; i++){
		for(int j = 0; j < tableColumn; j++){
			int counter = 0;
			if(table[i][j] != '*'){
				int counter  = 0;
				//Look for Mines
				if(table[i][j+1] == '*'){
					counter++;
				}
				if(table[i][j-1] == '*'){
					counter++;
				}
				if(table[i+1][j+1] == '*'){
					counter++;
				}
				if(table[i-1][j-1] == '*'){
					counter++;
				}
				if(table[i+1][j] == '*'){
					counter++;
				}
				if(table[i-1][j] == '*'){
					counter++;
				}
				if(table[i-1][j+1] == '*'){
					counter++;
				}
				if(table[i+1][j-1] == '*'){
					counter++;
				}
				table[i][j] = (char)counter + 48;
			}
		}
	}

}
void MinesweeperTable::display() {
	for (int i = 0; i < tableRow; i++) {
		for (int j = 0; j < tableColumn; j++) {
			cout << std::setw(5) << table[i][j];
		}
		cout <<"" << endl;

	}
}

#endif /* TABLE_H_ */
