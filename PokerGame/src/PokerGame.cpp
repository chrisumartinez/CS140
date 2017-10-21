//============================================================================
// Name        : PokerGame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "player.h"

using namespace std;
int playerAmount;
string response;
string playerName;
vector<player> players;
Deck deck;
string play = "p";
string quit = "q";

void specifyPlayers();
void showHands();
void printOutcomes();
bool askToPlay();
void deal();
void askForPlayerNames();
void addPlayers();

int main() {
	while(askToPlay() == true){
		srand(time(0));
		specifyPlayers();
		addPlayers();
		askForPlayerNames();
		deal();
		showHands();
		printOutcomes();
	}

}
/*
 * Adds the players to the players vector.
 */
void addPlayers(){
	players.clear();
	for(int i = 0;  i < playerAmount; i++){
		player newPlayer;
		players.push_back(newPlayer);
	}
}
/*
 * Prompts for the amount of players.
 */
void specifyPlayers() {
	cout << "How Many Players are playing?" << endl;
	cin >> playerAmount;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		specifyPlayers();
	} else {
		cout << "Ok." << endl;
	}

}
/*
 * Prompts if the player is going to continue playing or to quit.
 */
bool askToPlay() {
	cout << "Do you want to Play or Quit? (p or q)" << endl;
	cin >> response;
	if(response == play){
		return true;
	}
	else if(response == quit){
		return false;
	}
		else{
			askToPlay();
		}
	}
/*
 * Deals the cards into the players hands.
 */
void deal(){
	for(int i = 0; i < players.size(); i++){
		players[i].hand.setHand(deck.deal());
	}
}
/*
 * Prompts for the player names and sets them.
 */
void askForPlayerNames(){
	for(int i = 0; i < players.size(); i++){
		cout<< "Enter Player "<< i <<  " Name: ";
		cin >> playerName;
		players[i].setName(playerName);
	}
	cout << endl;

}
/*
 * Prints each players hands and results.
 */
void showHands() {
	for(int i = 0; i < players.size(); i++){
		cout << players[i].getName() << " Has: " << endl;
		for(int j = 0; j < players[i].hand.getHand().size(); j++){
			Card curCard = players[i].hand.getHand()[j];
			cout << curCard.toString() << endl;;
		}
		cout << "" <<endl;
		cout << players[i].getName() << " has " << players[i].hand.stringResult() << endl;
		cout << "" << endl;
	}

}
/*
 * Prints the Winner.
 */
void printOutcomes() {
	vector<int> results;
	for(int i = 0; i < players.size(); i++){
		results.push_back(players[i].hand.returnResult());
	}
	sort(results.begin(), results.end());
	int bestResult = results.back();
	for(int j = 0; j < players.size(); j++){
		if(bestResult == players[j].hand.returnResult()){
			cout << players[j].getName() << " is the Winner!" << endl;
		}
	}
}
