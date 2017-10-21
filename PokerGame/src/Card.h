/*
 * Cards.h
 *
 *  Created on: Apr 6, 2016
 *      Author: Bizzy
 */

#ifndef CARD_H_
#define CARD_H_
#include<string>
using namespace std;

//Create a CardSuit
class Card {
public:
	bool equals(Card);
	string convertRankToString(int);
	string convertSuitToString(int);
	int getRank();
	int getSuit();
	void setRank(int);
	void setSuit(int);
	string toString();
private:
	enum SUIT {
		SPADES = 0, HEARTS = 1, DIAMONDS = 2, CLUBS = 3
	};
	enum CARDVALUE {
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5,
		SIX = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE = 9,
		TEN = 10,
		JACK = 11,
		QUEEN = 12,
		KING = 13,
		ACE = 1,
	};
	int rank;
	int cardSuit;
};
/*
 * Checks if it is Less than, Greater than, or equal to the card.
 */
bool Card::equals(Card) {
	bool flag;
	return flag;

}
/*
 * Gets the Rank of the Card.
 */
int Card::getRank() {
	return rank;
}
/*
 * Returns the Suit of the Card.
 */
int Card::getSuit() {
	return cardSuit;
}
void Card::setRank(int newRank) {
	rank = newRank;
}
void Card::setSuit(int newSuit) {
	cardSuit = newSuit;
}
string Card::convertSuitToString(int cardSuit) {
	string suitStr;
	cardSuit = getSuit();
	switch (cardSuit) {
	case 0: {
		suitStr = "Spades";
		return suitStr;
		break;
	}
	case 1: {
		suitStr = "Hearts";
		return suitStr;
		break;
	}
	case 2: {
		suitStr = "Diamonds";
		return suitStr;
		break;
	}
	case 3: {
		suitStr = "Clubs";
		return suitStr;
		break;
	}
	default:
		return suitStr;
		break;
	}
}
string Card::convertRankToString(int rank) {
	string rankStr;
	rank = getRank();
	switch (rank) {
	case 2: {
		rankStr = "Two";
		return rankStr;
		break;
	}
	case 3: {
		rankStr = "Three";
		return rankStr;
		break;
	}
	case 4: {
		rankStr = "Four";
		return rankStr;
		break;
	}
	case 5: {
		rankStr = "Five";
		return rankStr;
		break;
	}
	case 6: {
		rankStr = "Six";
		return rankStr;
		break;
	}
	case 7: {
		rankStr = "Seven";
		return rankStr;
		break;
	}
	case 8: {
		rankStr = "Eight";
		return rankStr;
		break;
	}
	case 9: {
		rankStr = "Nine";
		return rankStr;
		break;
	}
	case 10: {
		rankStr = "Ten";
		return rankStr;
		break;
	}
	case 11: {
		rankStr = "Jack";
		return rankStr;
		break;
	}
	case 12: {
		rankStr = "Queen";
		return rankStr;
		break;
	}
	case 13: {
		rankStr = "King";
		return rankStr;
		break;
	}
	case 1: {
		rankStr = "Ace";
		return rankStr;
		break;
	}
	default:
		return rankStr;
		break;
	}
}
/*
 * Converts the Card into a String.
 */
string Card::toString() {
	int curRank = getRank();
	string cardString;
	cardString.append(convertRankToString(curRank));
	cardString.append(" Of ");
	int curSuit = getSuit();
	cardString.append(convertSuitToString(curSuit));
	return cardString;
}
#endif /* CARD_H_ */
