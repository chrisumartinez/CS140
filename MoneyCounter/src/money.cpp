//============================================================================
// Name        : MoneyCounter.cpp
// Author      : Christian Martinez
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
/* Variables*/
int counter;
int maxAmount = 9999;
int maxCounter = 9999;
int maxInput;
/*Constants*/
/*Functions*/
void prompt();
/*Classes*/
class Counter
{
public:
	void reset();
	Counter(int);
	Counter();
	void incr1(int);
	void incr10(int);
	void incr100(int);
	void incr1000(int);
	bool overflow(int);
	void setMaximumAmount();
	void takeInput();
	int takeNumInput();
	void checkOverflow();
	void status();
	void promptUser();
	void promptforMax();

};






int main()
{
	prompt();
	return 0;
}
void Counter::reset()
{
	counter = 0;
}
void Counter::incr1(int aug)
{
	counter += 1 * aug;
}
void Counter::incr10(int aug)
{
	counter += 10 * aug;
}
void Counter::incr100(int aug)
{
	counter += 100 * aug;
}
void Counter::incr1000(int aug)
{
	counter += 1000 * aug;
}
void Counter::takeInput()
{
	char input;
	cout <<"Enter a key, either a,s,d,f or o  for overflow" << endl;
	cin >> input;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		Counter::takeInput();
	}
	switch(input)
	{
	case 'a':
	{
		int aug = Counter::takeNumInput();
		Counter::incr1(aug);
		break;
	}
	case 's':
	{
		int aug = Counter::takeNumInput();
		Counter::incr10(aug);
		break;
	}
	case 'd':
	{
		int aug = Counter::takeNumInput();
		Counter::incr100(aug);
		break;
	}
	case 'f':
	{
		int aug = Counter::takeNumInput();
		Counter::incr1000(aug);
		break;
	}
	case 'o':
	{
		Counter::checkOverflow();
		break;
	}
	default:
		Counter::takeInput();
	}
	if (input == 'o')
		return;

	Counter::status();
	cout << "" << endl;
	Counter::promptUser();
}
int Counter::takeNumInput()
{
	int input;
	cout << "How much do you want to add: " << endl;
	cin >> input;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		Counter::takeNumInput();
	}
	if ((input <= 0) || (input > 9))
	{
		cout <<"Select a valid number." << endl;
		Counter::takeNumInput();
	}
	return input;
}
void Counter::promptforMax()
{
	char input;
		cout << "Set a Maximum Amount? (y) for yes, (n) for no" << endl;
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024,'\n');
			Counter::promptUser();
		}
		if (input == 'y')
		{
			Counter::setMaximumAmount();
		}
		else if (input == 'n')
		{
			return;
		}
		else
			promptforMax();
}
void Counter::setMaximumAmount()
{
	if (maxCounter > 9999)
	{
		cout << "Enter a number less than 9999." << endl;
		void prompt();
	}
	else
		return;
}
void Counter::checkOverflow()
{
	if (counter > maxCounter)
		cout << "You Have gone over the Amount." << endl;
	else
		cout << "There is no overflow." << endl;

}
void Counter::status()
{
	cout <<"Maximum Value of the counter is: "<<maxCounter << endl;
	cout <<"Current Value of the counter is: "<<counter<<endl;
}
void Counter::promptUser()
{
	char input;
	cout << "Keep Adding? (y) for yes, (n) for no" << endl;
	cin >> input;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024,'\n');
		Counter::promptUser();
	}
	if (input == 'y')
	{
		Counter::takeInput();
	}
	else if (input == 'n')
	{
		return;
	}
	else
		promptUser();
}
Counter::Counter()
{
	maxCounter = 9999;
}
Counter::Counter(int a)
{
	maxCounter = a;
}
void prompt()
{
	cout << "Please Enter an integer Amount less than 9999 to initial the Counter, or Type Q to move to default.:" << endl;
		cin >> maxInput;
		if (cin.fail())
		{
			Counter moneyCounter;
			moneyCounter.status();
			moneyCounter.takeInput();
		}
		else if (maxInput > 9999)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			prompt();

		}
		else
		{
			Counter moneyCounter2(maxInput);
			moneyCounter2.setMaximumAmount();
			moneyCounter2.status();
			moneyCounter2.takeInput();
		}
}
