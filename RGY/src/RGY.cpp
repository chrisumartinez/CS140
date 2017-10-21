//============================================================================
// Name        : Game.cpp
// Author      : Christian Martinez
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

/*Vars*/
string strRand;
string strGuess;
int randInt;
/*Class*/
class game {
public:
	void initPrompt();
	void generateRandomNum();
	void askForNextGuess();
	void checkGuess();
	string convertGuess(int);
	int guess;
private:

};
int main() {
	game newGame;
	newGame.generateRandomNum();
	newGame.initPrompt();
	newGame.checkGuess();
	while (newGame.guess != randInt) {
		newGame.askForNextGuess();
		newGame.checkGuess();
	}

	return 0;
}
void game::initPrompt() {
	cout << "Please Enter a Guess?" << endl;
	cin >> guess;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		initPrompt();
	}
}
void game::generateRandomNum()
{
	srand(time(NULL));
	randInt = rand() % 900 + 100;

	stringstream convert; // stringstream used for the conversion
	convert << randInt;
	strRand = convert.str();
}
void game::askForNextGuess() {
	cout << " Please Enter the Next Guess?" << endl;
	cin >> guess;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		askForNextGuess();
	}
}
string  game::convertGuess(int guess)
{
	stringstream convert; // stringstream used for the conversion

	convert << guess;

	string result = convert.str();

	return result;
}
void game::checkGuess() {
	bool check[3] = {false};
	int amountGreen = 0;
	int amountYellow = 0;
	int amountRed = 0;
	strGuess = convertGuess(guess);

	if (randInt == guess) {
		cout << "CONGRATULATIONS, YOU ARE CORRECT!!!!!!!!!!!!" << endl;
		return;
	}

	cout << "Random Number: " << randInt << endl;


	for (int j = 0; j < 3; j++) {
		//Check for Green
		if (strGuess[j] == strRand[j])
		{
			amountGreen++;
			check[j] = true;
		}
		//Check for Yellow
	}

	for (int r = 0; r < 3; r++)
	{
		if (check[r])
			continue;
		else
			{
				for (int s = 0; s < 3; s++)
				{
					if (check[s])
						continue;
					if (strGuess[s] == strRand[r])
						amountYellow++;
				}
			}
	}

//	if (check[0] == false)
//	{
//		if (check[1])
//			strRand[1] = 'y';
//		if (check[2])
//			strRand[2] = 'z';
//		if (strGuess[0] == strRand[1])
//			amountYellow++;
//		if (strGuess[0] == strRand[2])
//			amountYellow++;
//	}
//	if (check[1] == false)
//	{
//		if (check[2] == true)
//			strRand[2] = 'z';
//		if (check[0])
//			strRand[0] = 'y';
//		if (strGuess[1] == strRand[2])
//			amountYellow++;
//		if (strGuess[1] == strRand[0])
//			amountYellow++;
//	}
//
//	if (check[2] == false) {
//		if (check[1] == true)
//			strRand[1] = 'z';
//		if (check[0] == true)
//			strRand[0] = 'y';
//		if (strGuess[2] == strRand[0])
//			amountYellow++;
//		if (strGuess[2] == strRand[1])
//			amountYellow++;
//	}






	//check for Red
	amountRed = 3 - (amountGreen + amountYellow);
	//Output Guess
	cout << "You Have: " << endl;
	cout << amountRed << ": Red" << endl;
	cout << amountYellow << ": Yellow" << endl;
	cout << amountGreen << ": Green" << endl;
}

