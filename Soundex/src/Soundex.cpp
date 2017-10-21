//============================================================================
// Name        : Soundex.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Functions
void getInput();
string convertString();
void printOutput();
string convertNum(char);
//Variables
string input;
string finalString;
string removeLetters = "aeiouyhw";
string replaceFirstSet = "bfpv";
string replaceSecondSet = "cgjkqsxz";
string replaceThirdSet = "dt";
string replaceFourthSet = "l";
string replaceFifthSet = "m,n";
string replaceSixthSet = "r";
string zero = "0";
char d;
char lower;
char h = 'h';
char w = 'w';
int main()
{
	getInput();
	convertString();
	printOutput();
	return 0;
}
void getInput() {
	cout << "Input: " << endl;
	cin >> input;
}
string convertString() {
	string inputString = input;
	string firstLetter;

	//Get the first letter of inputString
	char c = inputString[0];

	//Append to string Final
	firstLetter = c;


	//String Before checking the first and next Integer
	cout << "String before Checking if first and consecutive char are the same: " << endl;
	cout << inputString << endl;

	d = inputString[0];
	char f = tolower(int(d));
	string lower;
	lower  = convertNum(f);
	char n = lower[0];

	if (n == inputString[1]){
		inputString.erase(1, 1);
	}

	//Replace consonants with digits
		//b,f,p,v, = 1;
		//c,g,j,k,q,s,x,z = 2;
		//d,t, = 3
		// l = 4;
		// m , n = 5;
		// r = 6;

	size_t one = inputString.find_first_of(replaceFirstSet);
	while(one != string::npos){
		if (inputString[one] == inputString[one + 1]){
			inputString.erase(one, 1);
		}
		inputString.replace(one, 1, "1");
		one = inputString.find_first_of(replaceFirstSet);
	}
	size_t two = inputString.find_first_of(replaceSecondSet);
	while (two != string::npos){
		if (inputString[two] == inputString[two + 1]){
					inputString.erase(two, 1);
				}
		inputString.replace(two, 1, "2");
		two = inputString.find_first_of(replaceSecondSet);
	}
	size_t three = inputString.find_first_of(replaceThirdSet);
	while (three != string::npos){
		if (inputString[three] == inputString[three + 1]){
					inputString.erase((three+ 1), 1);
				}
		inputString.replace(three, 1, "3");
		three = inputString.find_first_of(replaceThirdSet);
	}
	size_t four = inputString.find_first_of(replaceFourthSet);
	while(four != string::npos){
		if (inputString[four] == inputString[four + 1]){
					inputString.erase((four+ 1), 1);
				}
		inputString.replace(four, 1, "4");
		four = inputString.find_first_of(replaceFourthSet);
	}
	size_t five = inputString.find_first_of(replaceFifthSet);
	while(five != string::npos){
		if (inputString[five] == inputString[five + 1]){
					inputString.erase((five+ 1), 1);
				}
		inputString.replace(five, 1, "5");
		five = inputString.find_first_of(replaceFifthSet);
	}
	size_t six = inputString.find_first_of(replaceSixthSet);
	while(six != string::npos){
		if (inputString[six] == inputString[six + 1]){
					inputString.erase((six+ 1), 1);
				}
		inputString.replace(six, 1, "6");
		six = inputString.find_first_of(replaceSixthSet);
	}


	//Step Three
	/*
	 * If 2 o more Letters with the same number are adjacent in the original name (Before Step 1)
	 * only retain the first letter with the same number seperated by 'h' or 'w' are coded
	 * by a single number, whereas such letters seperated by a vowel are coded twice. This rule also applies
	 * to the first letter.
	 */

	cout << "String before Removing Adjacent Numbers: " << endl;
	cout << inputString << endl;



	//Remove all Adjacent Numbers
	for (int t = 0; t < inputString.length(); t++){
		char letter = inputString[t];
		if ((inputString[t + 1] == 'h') || (inputString[t + 1] == 'w')){
			if (inputString[t + 2] == inputString[t]){
				inputString.erase(t, 1);
			}
		}
		if (letter == inputString[t+1])
		{
			inputString.erase(t, 1);
		}
	}


	cout << "String Before removing Vowels: " << endl;
	cout << inputString << endl;


	//Remove all occurrences of a,e,i,o,u,y,h,w
	size_t found = inputString.find_first_of(removeLetters);
	while(found != string::npos){
		inputString.erase(found, 1);
		found = inputString.find_first_of(removeLetters);

	}
	cout << "String before Replacing Consonants with Digits: " << endl;
	cout << inputString << endl;








	//Step Four
		//Check if String Size is less than four

	cout << "String before Appending: " << endl;
	cout << inputString << endl;
	//append '0's
	if (inputString.length() < 4){
		for (int k = inputString.length(); k < 4; k++){
			inputString.append(zero);
		}
	}
		//if length is Greater than four
	if (inputString.length() >= 4){
		for (int r = inputString.length(); r > 3; r--){
			inputString.erase(r);
		}
	}
	finalString += inputString;

	return finalString;
}
void printOutput(){
	cout << "Output: " << endl;
	cout << finalString << endl;
}
string convertNum(char d){
	char rf = tolower(int(d));
	string s;
	s += rf;
	size_t one = s.find_first_of(replaceFirstSet);
	while (one != string::npos) {

		s.replace(one, 1, "1");
		one = s.find_first_of(replaceFirstSet);
	}
	size_t two = s.find_first_of(replaceSecondSet);
	while (two != string::npos) {

		s.replace(two, 1, "2");
		two = s.find_first_of(replaceSecondSet);
	}
	size_t three = s.find_first_of(replaceThirdSet);
	while (three != string::npos) {

		s.replace(three, 1, "3");
		three = s.find_first_of(replaceThirdSet);
	}
	size_t four = s.find_first_of(replaceFourthSet);
	while (four != string::npos) {

		s.replace(four, 1, "4");
		four = s.find_first_of(replaceFourthSet);
	}
	size_t five = s.find_first_of(replaceFifthSet);
	while (five != string::npos) {

		s.replace(five, 1, "5");
		five = s.find_first_of(replaceFifthSet);
	}
	size_t six = s.find_first_of(replaceSixthSet);
	while (six != string::npos) {

		s.replace(six, 1, "6");
		six = s.find_first_of(replaceSixthSet);
	}
	return s;
}
