//============================================================================
// Name        : InClass.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;


/*
 * functions
 */

void readFileToString();
string makeLowerCase(string);
string  removePunctuation(string);
void checkDuplicates(string);
void display();

/*
 * Vars
 */
map<string, int> Map;
map<string, int>::iterator iter;
int wordCounter;

int main() {
	readFileToString();
	display();

	return 0;
}
void readFileToString(){
	//Read the File into a map;
	ifstream inFile;
	inFile.open("input.txt", ios::in);
	while(!inFile.eof()){
		string word;
		int counter = 1;
		inFile >> word;

		string lowerWord = makeLowerCase(word);
		string correctWord = removePunctuation(lowerWord);
		checkDuplicates(correctWord);
		Map.insert(make_pair(correctWord, counter));
	}
	}
void  checkDuplicates(string word){
	int counter =  0;

	for(iter = Map.begin(); iter != Map.end(); iter++){
		if(word.compare(iter -> first) == 0){
			counter  = iter -> second;
			cout << "Iter-> First: " << iter -> first << "  Compare: " << word << endl;
			iter -> second++;
			cout <<"Counter: " << counter << endl;
		}
	}
}
string makeLowerCase(string word){
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	return word;
}

string removePunctuation(string word){
	word.erase(std::remove(word.begin(), word.end(), '\''), word.end());
	word.erase(std::remove(word.begin(), word.end(), '\.'), word.end());
	word.erase(std::remove(word.begin(), word.end(), '\,'), word.end());


	return word;
}

void display(){
	cout << "Map: " << endl;
	cout << "" << endl;

	for(iter = Map.begin(); iter != Map.end(); iter++)
	{
		cout << "Word: " << iter-> first << endl;
		cout << "Occurence: " << iter -> second << endl;
	}
}
