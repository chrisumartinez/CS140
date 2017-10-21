/*
 * Deck.h
 *
 *  Created on: Apr 6, 2016
 *      Author: Bizzy
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include "Card.h"
#include <stdlib.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Deck{
public:
	vector<Card> deal();
	bool isEmpty();
	void shuffle();
	vector<Card> getDeck();
	int sizeOF();
private:
	vector<Card> Hand;
	vector<Card> deck;
	Card newCard;
	int rankMax = 13;
	int suitMax = 4;
};
/*
 * Deals the Cards from the Deck.
 */
vector<Card> Deck::deal() {
	Hand.clear();
	if (isEmpty()) {
		shuffle();
		for (int i = 0; i < 5; i++) {
			newCard = deck.back();
			deck.pop_back();
			Hand.push_back(newCard);
		}
	} else {
		if (deck.size() < 5) {
			shuffle();
			for (int i = 0; i < 5; i++) {
				newCard = deck.back();
				deck.pop_back();
				Hand.push_back(newCard);
			}
		}
		else{
			for (int i = 0; i < 5; i++) {
				newCard = deck.back();
				deck.pop_back();
				Hand.push_back(newCard);
			}

		}
	}


	return Hand;
}
/*
 * Checks if the Deck is empty.
 */
bool Deck::isEmpty() {
	if (deck.size() == 0) {
		return true;
	} else {
		return false;
	}
}
/*
 * Shuffles the Deck.
 */
void Deck::shuffle() {

	deck.clear();
	for (int i = 1; i < rankMax; i++) {
		for (int j = 0; j < suitMax; j++) {
			Card newCard;
			newCard.setRank(i);
			newCard.setSuit(j);
			deck.push_back(newCard);
		}

	}
	random_shuffle(deck.begin(), deck.end());
}
/*
 * returns the Size of the deck.
 */
int Deck::sizeOF() {
	return deck.size();

}
vector<Card> Deck::getDeck() {
	return deck;
}


#endif /* DECK_H_ */
