//============================================================================
// Name        : CS140.cpp
// Author      : Christian Martinez
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

/*Constants*/
int MAXSCOOPS = 5;
int MAXCONES = 10;
int nextScoop = .75;

/*Variables*/
int custCones;
int custScoops;
int flavor[6];
float charge = 0;

/* Declarations*/
void setupStore();
void getConeAmount();
void getCustFlavor();
void getScoopAmount();
void printScoops();
void printCones();
void calcPay();
void createIceCream();

int main() {
	setupStore();
	getConeAmount();
	createIceCream();
	return 0;
}
/*
 * Sets up the initial store, with signs for prices.
 */
void setupStore() {
	cout << "Christian Martinez's Ice Cream Store: " << endl;
	cout << "1 Scoop ->			$1.00" << endl;
	cout << "2 Scoops ->			$2.00" << endl;
	cout << "Each Scoop After 2 ->		$0.50" << endl;

}

/*
 * Gets the Customer Amount. Only Integers between 1-10 are accepted.
 */
void getConeAmount() {
	bool validInput = false;
	do {
		cout << "How Many Cones would you like? (10 Max)" << endl;
		cin >> custCones;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		} else {
			if (custCones > 0 && custCones <= MAXSCOOPS) {
				validInput = true;
			} else {
				cout << "You Can Only Order 1-10 Cones." << endl;
			}
		}
	} while (!validInput);

	return;
}

/*
 * Get the scoop amount. Only Integers between 1-5 are accepted.
 */
void getScoopAmount() {
	cout << "How Many Scoops would you like?(Limit 5 Scoops per Cone)" << endl;
	cin >> custScoops;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "Enter a Real Amount. Don't Include Characters." << endl;
		getScoopAmount();

	}
	if ((custScoops > MAXSCOOPS) || custScoops == 0) {
		cout << "Sorry, You Can Only Order Between 1 - 5 Scoops." << endl;
		getScoopAmount();
	}
	return;
}

/*
 * Asks for the Customer's flavor.
 */
void getCustFlavor() {
	string safeInput;
	char scoopFlavor;
	int i = 0;
	do {
		cout << "Specify the Flavor for Scoop " << i + 1 << ": " << endl;
		cin >> safeInput;
		scoopFlavor = safeInput[0];
		flavor[i] = scoopFlavor;
		i++;
	} while (i < custScoops);
	return;
}

/*
 * Prints out the Scoops for the Ice Cream, with Flavors included.
 */
void printScoops() {
	cout << "Here is your cone! Enjoy!" << endl;
	int i = 0;
	do {
		cout << "(" << (char) flavor[i] << ")" << endl;
		i++;
	} while (i < custScoops);
}

/*
 * Prints out the cone.
 */
void printCones() {
	cout << (char) 92 << " /" << endl;
	cout << " |" << endl;
}

/*
 * Calculates the charge for the total of Ice Cream cones and Scoops.
 */
void calcPay() {
	float total = 0;
	int i = 0;
	int temp = 0;
	while (i < custCones)
	{
		if (custScoops == 1)
			total = 1.00;
		if (custScoops == 2)
			total = 2.00;
		if (custScoops > 2)
		{
			total = 2.00;
			int j = 0;
			temp = custScoops;
			while(j < (temp - 2))
			{
				total += .50;
				j++;
			}
		}
		i++;
	}
	charge += total;

	cout << "Total Charge: $" << setprecision(2) << fixed << charge << endl;
}

/*
 * Function that actually constructs the Ice Cream Cone.
 */
void createIceCream() {
	int i = 0;
	do {
		getScoopAmount();
		getCustFlavor();
		printScoops();
		printCones();
		calcPay();
		i++;
	} while (i < custCones);
}
