//============================================================================
// Name : MagicSquares.cpp
// Author :
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

//Variables

//Class MagicSquare
class square {
public:
square(int);
void display();
private:
int size;
vector<vector<int> > numVector;
};
square::square(int num) :
size(num), numVector(size, vector<int>(size)) {
//Create and place the Integer in their correct order
//TODO: Create and Compile the rules for Creating a Magic Square

//start the initial condition

int initRow = 0;
int initColumn = num / 2;
int maxSize = size * size;
int column = initColumn;
int row = initRow;

//Counter from 1 to n^2 to place the int into an its correct slot
for (int k = 1; k <= maxSize; k++) {
//if there is something already filled, move down
if (numVector[row][column] != 0) {
numVector[++row][column] = k;
}
else{
numVector[row][column] = k;
}
// cout << "Number Added: " << k << endl;
// cout << "Position At: " << "(" << row << "," << column << ")" << endl;
int tempRow = row;
int tempColumn = column;
row--;
if(row < 0){
row = num - 1;
}
column++;
if(column > (num-1)){
column = 0;
}
if(numVector[row][column] != 0){
row = tempRow;
column = tempColumn;
row++;
}
//square::display();
}
}

int main() {
cout << "Magic Square: N = 5" << endl;
square magic(5);
magic.display();
return 0;
}
/*
* Displays the Magic Number Table.
*/
void square::display() {
for (int i = 0; i < numVector.size(); i++) {
for (int j = 0; j < numVector[i].size(); j++) {
cout << std::setw(5) << numVector[i][j];

}
cout << endl;
}
cout << endl;

}

