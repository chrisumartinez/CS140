/*
 * TreadMill.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Chris
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

/* Constants*/

float const kiloToMiles = 1.61;
char input;

/*Variables */
int minutes;
int seconds;
double kph;



/* Function Prototypes */

void convertToMPH(int, int);
void convertToMPH(double);
void promptUser();
void promptTime();
void promptKilo();

int main()
{
	promptUser();
	return 0;
}
/*
 * Prompts the User for Input on whether it is Time or KPH to convert.
 */
void promptUser()
{
	cout << "I can convert your time: Type in k to convert KPH to MPH or t for your time." << endl;
	cin >> input;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		promptUser();
	}
	else
		if (input == 'k')
			promptKilo();
		else
			if (input == 't')
				promptTime();
			else
				promptUser();

}
void promptTime()
{
	cout <<"Input your Minutes: " << endl;
	cin >> minutes;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		promptTime();
	}
	cout << "Input your Seconds: " << endl;
	cin >> seconds;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		promptTime();
	}
	convertToMPH(minutes,seconds);
}
void promptKilo()
{
	cout << "Input your KPH: "  << endl;
	cin >> kph;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		promptKilo();
	}
	convertToMPH(kph);
}
void convertToMPH(int, int)
{
	float minToSeconds = minutes * 60;
	float totalSeconds = minToSeconds + seconds;
	float hours = totalSeconds / 3600;
	float mph = 1 / hours;
	cout << " From your Time to MPH: " << mph << " MPH" << endl;
}
void convertToMPH(double)
{
	float conversion = kph / 1.61;
	cout <<"Converting from KPH to MPH: " << conversion << " MPH" << endl;
}
