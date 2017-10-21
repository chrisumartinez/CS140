/*
 * Hand.h
 *
 *  Created on: Apr 16, 2016
 *      Author: Bizzy
 */

#ifndef HAND_H_
#define HAND_H_
#include "Card.h"
using namespace std;

class Hand {
public:
	void setHand(vector<Card>);
	vector<Card> getHand();
	void setCard(Card);
	Card getCard();
	// Rank the Hands from  0 - 8
	bool pair();
	bool twoPair();
	bool threeOfKind();
	bool fullHouse();
	bool straight();
	bool fourOfKind();
	bool flush();
	bool straightFlush();
	bool royalFlush();
	int returnResult();
	string stringResult();
	vector<Card> hand;
private:

	Card card;
	vector<Card> result;
};
void Hand::setHand(vector<Card> newHand){
	hand = newHand;
}
vector<Card> Hand::getHand() {
	return hand;
}
void Hand::setCard(Card card) {
	this->card = card;
}
/*
 * Returns true if player has a pair, else returns false.
 */
bool Hand::pair() {
	vector<int> ranks;
	bool check1, check2, check3, check4;
	for (int i = 0; i < hand.size(); i++) {
		ranks.push_back(hand[i].getRank());
	}
	sort(ranks.begin(), ranks.end());
	check1 = (ranks[0] == ranks[1]);
	check2 = (ranks[1] == ranks[2]);
	check3 = (ranks[2] == ranks[3]);
	check4 = (ranks[3] == ranks[4]);
	if (check1 || check2 || check3 || check4) {
		return true;
	} else {
		return false;
	}
}
/*
 * Returns true if the player has two pairs, else returns false.
 */
bool Hand::twoPair() {
	vector<int> ranks;
	bool check1, check2, check3;
	//Get the Ranks
	for (int i = 0; i < hand.size(); i++) {
		ranks.push_back(hand[i].getRank());
	}
	sort(ranks.begin(), ranks.end());
	check1 = ((ranks[0] == ranks[1]) && (ranks[3] == ranks[4]));
	check2 = ((ranks[1] == ranks[2]) && (ranks[3] == ranks[4]));
	check3 = ((ranks[0] == ranks[1]) && (ranks[2] == ranks[3]));
	if (check1 || check2 || check3) {
		return true;
	} else {
		return false;
	}

}
/*
 * Returns true if the player has a three of a kind, else returns false.
 */
bool Hand::threeOfKind() {
	vector<int> ranks;
	int counter = 0;
	for (int i = 0; i < hand.size(); i++) {
		ranks.push_back(hand[i].getRank());

	}
	if (ranks[0] == ranks[1]) {
		counter++;
	}
	if (ranks[0] == ranks[2]) {
		counter++;
	}
	if (ranks[0] == ranks[3]) {
		counter++;
	}
	if (ranks[0] == ranks[4]) {
		counter++;
	}
	if (ranks[1] == ranks[2]) {
		counter++;
	}
	if (ranks[1] == ranks[3]) {
		counter++;
	}
	if (ranks[1] == ranks[4]) {
		counter++;
	}
	if (ranks[2] == ranks[3]) {
		counter++;
	}
	if (ranks[2] == ranks[4]) {
		counter++;
	}
	if (ranks[3] == ranks[4]) {
		counter++;
	}
	if (counter == 3) {
		return true;
	} else {
		return false;
	}
}
/*
 * Returns true if the player has a full house, else returns false.
 */
bool Hand::fullHouse() {
	vector<int> ranks;
	bool type1, type2;

	for (int i = 0; i < hand.size(); i++) {
		ranks.push_back(hand[i].getRank());
	}
	sort(ranks.begin(), ranks.end());
	type1 = ((ranks[0] == ranks[1]) && (ranks[1] == ranks[2])
			&& (ranks[3] == ranks[4]));
	type2 = ((ranks[0] == ranks[1]) && (ranks[2] == ranks[3])
			&& (ranks[3] == ranks[4]));
	return (type1 || type2);

}
/*
 * Returns true if the player has straight, else returns false.
 */
bool Hand::straight() {
	vector<int> ranks;
	for (int i = 0; i < hand.size(); i++) {
		ranks.push_back(hand[i].getRank());
	}
	sort(ranks.begin(), ranks.end());
	for (int j = 0; j < (ranks.size() - 1); j++) {
		if (ranks[j] != ranks[j + 1]) {
			return false;
		}
	}
	return true;
}
/*
 * Returns true if the player has a four of a kind, else returns false.
 */
bool Hand::fourOfKind() {
	vector<int> ranks;
	int counter = 0;
	for (int i = 0; i < hand.size(); i++) {
		ranks.push_back(hand[i].getRank());

	}
	if (ranks[0] == ranks[1]) {
		counter++;
	}
	if (ranks[0] == ranks[2]) {
		counter++;
	}
	if (ranks[0] == ranks[3]) {
		counter++;
	}
	if (ranks[0] == ranks[4]) {
		counter++;
	}
	if (ranks[1] == ranks[2]) {
		counter++;
	}
	if (ranks[1] == ranks[3]) {
		counter++;
	}
	if (ranks[1] == ranks[4]) {
		counter++;
	}
	if (ranks[2] == ranks[3]) {
		counter++;
	}
	if (ranks[2] == ranks[4]) {
		counter++;
	}
	if (ranks[3] == ranks[4]) {
		counter++;
	}
	if (counter == 6) {
		return true;
	} else {
		return false;
	}
}
/*
 * Returns true if the player has a flush, else returns false.
 */
bool Hand::flush() {
	vector<int> suits;
	for (int i = 0; i < hand.size(); i++) {
		suits.push_back(hand[i].getSuit());
	}
	if ((suits[0] == suits[1]) && (suits[0] == suits[2])
			&& (suits[0] == suits[3]) && (suits[0] == suits[4])
			&& (suits[1] == suits[2]) && (suits[1] == suits[3])
			&& (suits[1] == suits[4]) && (suits[2] == suits[3])
			&& (suits[2] == suits[4]) && (suits[3] == suits[4])) {
		return true;
	} else {
		return false;
	}

}
/*
 * Returns true if the player has straight flush, else returns false.
 */
bool Hand::straightFlush() {
	if ((straight() == true) && (flush() == true)) {
		return true;
	} else {
		return false;
	}
}
/*
 * Returns true if the player has a royal flush, else returns false.
 */
bool Hand::royalFlush() {
	if ((straight() == true) && (flush() == true)) {
		vector<int> ranks;
		for (int i = 0; i < hand.size(); i++) {
			ranks.push_back(hand[i].getRank());
		}
		sort(ranks.begin(), ranks.end());
		if (ranks[0] == 1) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
/*
 * returns the integer amount relative to the result of the players hand.
 */
int Hand::returnResult() {
	if (royalFlush() == true) {
		return 10;
	} else {
		if (straightFlush() == true) {
			return 9;
		} else {
			if (fourOfKind() == true) {
				return 8;
			} else {
				if (fullHouse() == true) {
					return 7;
				} else {
					if (flush() == true) {
						return 6;
					} else {
						if (straight() == true) {
							return 5;
						} else {
							if (threeOfKind() == true) {
								return 4;
							} else {
								if (twoPair() == true) {
									return 3;
								} else {
									if (pair() == true) {
										return 2;
									} else {
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}

}
/*
 * converts to the integer result into a string.
 */
string Hand::stringResult() {
	string result;
	if (returnResult() == 1) {
		result = "No Pair";
	} else {
		if (returnResult() == 2) {
			result = "Pair";
		} else {
			if (returnResult() == 3) {
				result = "Two Pairs";
			} else {
				if (returnResult() == 4) {
					result = "Three of A Kind.";
				} else {
					if (returnResult() == 5) {
						result = "Straight.";
					} else {
						if (returnResult() == 6) {
							result = "Flush";
						} else {
							if (returnResult() == 7) {
								result = "Full-House.";
							} else {
								if (returnResult() == 8) {
									result = "Four of a Kind";
								} else {
									if (returnResult() == 9) {
										result = "Straight Flush";
									} else {
										result = "Royal Flush";
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return result;
}

#endif /* HAND_H_ */
