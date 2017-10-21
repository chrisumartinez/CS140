//============================================================================
// Name        : Dictionary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <cctype>


using namespace std;

/*
 * Vars
 */
string dictionary;
vector<string> stringDict;
char response;
string newWord;

/*
 * functions
 */
void readFileToString();
void sortVector();
string makeLowerCase(string);
void removeDuplicates();
void addWord(string);
void deleteWord(string);
void verify(string);
void displayVector();
void menu();
void load();

int main() {
	load();
	cout <<"Hello to print your list, type 'p'. " << endl;
	cout << "To add, type 'a'. " << endl;
	cout << "To Delete a word, type 'd'. " << endl;
	cout <<"To Verify a word, type 'v'. " << endl;
	cout <<" To Quit, type 'q'. " << endl;
	menu();
	return 0;
}
void readFileToString(){
	ifstream inFile;
	inFile.open("dictionary.txt", ios::in);
	while(!inFile.eof()){
		string word;
		getline(inFile,word);
		string lowerWord = makeLowerCase(word);
		stringDict.push_back(lowerWord);
	}

}
string makeLowerCase(string word){
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	return word;
}
void addWord(string word){
	cout << "Adding: " << word << endl;
	bool flag = false;
	string lowerWord = makeLowerCase(word);
	for(int i = 0; i < stringDict.size(); i++){
		if(lowerWord == stringDict[i]){
			flag = true;
			break;
		}
	}
	if(flag == true){
		cout <<"Sorry, Cannot add the word." << endl;
	}
	else{
		stringDict.push_back(lowerWord);
		sortVector();
		cout << "Added." << endl;
	}
}
void deleteWord(string word){
	cout << "Deleting: " << word << endl;
	bool flag = false;
	string lowerWord = makeLowerCase(word);
	for(int i = 0; i < stringDict.size(); i++){
		if(lowerWord == stringDict[i]){
			flag = true;
			stringDict.erase(stringDict.begin() + i);
		}
	}
	if(flag == false){
		cout << "Sorry, Word Not Found." << endl;
	}
	else{
		cout << "Deleted." << endl;
	}
}
void removeDuplicates(){
	stringDict.erase(unique(stringDict.begin(), stringDict.end()), stringDict.end());
}
void sortVector(){
	sort(stringDict.begin(), stringDict.end());
	cout << "Dictionary List: " << endl;
}
void verify(string word){
	cout << "Verifying: " << word << endl;
	bool flag = false;
	string lowerWord = makeLowerCase(word);
	for(int i = 0; i < stringDict.size(); i++){
		if(lowerWord == stringDict[i]){
			flag = true;
		}
	}
	if (flag == true){
		cout << "Verified. Word is in the Dictionary." << endl;
	}
	else{
		cout << "Sorry, Word is not in the Dictionary." << endl;
	}
}
void menu(){
	newWord = "";
	cout << "Response? " << endl;
	cin >> response;
		switch(response){
		case 'a':{
		cout << "Add your word: " << endl;
		cin >> newWord;
		addWord(newWord);
		break;
		}
		case 'd':{
			cout << "Delete a Word: " << endl;
			cin >> newWord;
			deleteWord(newWord);
			break;
		}
		case 'v':{
			cout << "Verify Word: " << endl;
			cin >> newWord;
			verify(newWord);
			break;
		}
		case 'q':{
			exit(1);
		}
		case 'p':{
			displayVector();
			break;
		}
		default:{
			menu();
		}
	}
	menu();


}
void displayVector(){
	for(int i = 0; i < stringDict.size(); i++){
		cout << stringDict[i] << " " << endl;
	}
}
void load(){
	readFileToString();
	sortVector();
	removeDuplicates();

}
