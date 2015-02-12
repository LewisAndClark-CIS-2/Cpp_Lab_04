/****************************
 * Author: Brandon McCurry
 *			Nate Rowe
 *			Matt Jones
 *			Matt Gilmore
 *			Andy Rotton
 * Date: 2/12/15
 * Description: Chapter 8-4
 ****************************/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Critter
{
private:
	string name;
	int hunger;
	int boredom;
	void pass_time()
	{
		hunger++;
		boredom++;
	}
public:
	Critter(string inputName)
	{
		name = inputName;
		hunger = 0;
		boredom = 0;
	}

	string getName()
	{
		return name;
	}

	string mood()
	{
		int unhappiness = hunger + boredom;
		string m = "";
		if (unhappiness < 5)
		{
			m = "happy";
		}
		else if (5 <= unhappiness || unhappiness <= 10)
		{
			m = "okay";
		}
		else if (11 <= unhappiness <= 15)
		{
			m = "frustrated";
		}
		else
		{
			m = "mad";
		}
		return m;
	}

	void talk()
	{
		cout << "I'm " << name << " and I feel " << mood() << " now." << endl;
	}

	void eat(int food = 4)
	{
		cout << "Brrupppp. Thank you." << endl;
		hunger -= food;
		if (hunger < 0)
		{
			hunger = 0;
		}
		pass_time();
	}
	void play(int fun = 4)
	{
		cout << "Wheeee!" << endl;
		boredom -= fun;
		if (boredom < 0)
		{
			boredom = 0;
		}
		pass_time();
	}

	void back_door()
	{
		cout << "Name: " << name << endl << "Hunger: " << hunger << endl
			<< "Boredom: " << boredom << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	int num = NULL;
	string critName = "";
	string printName = "";
	vector<Critter> farm;
	char choice = NULL;


	cout << "what do you want to name your critter?: ";
	getline(cin, critName);
	cout << endl;
	Critter crit(critName);
	farm.push_back(crit);

	while (choice != '0')
	{
		cout << "Critter Caretaker" << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Listen to a pet" << endl;
		cout << "2 - Feed a pet" << endl;
		cout << "3 - Play with a pets" << endl;
		cout << "4 - Add another pet" << endl;
		cout << "5 - Feed all pets" << endl;
		cout << "6 - Play with all pets" << endl;
		cout << "7 - Listen to all pets" << endl;

		cout << endl << endl << "Choice: ";
		cin >> choice;
		cout << endl;
		if (choice == '0')
		{
			cout << "Goodbye.";
			cout << endl << endl << "press <Enter> to exit";
			cin.ignore();
			cin.ignore();
		}

		else if (choice == '1')
		{
			for (int i = 0; i < farm.size(); i++)
			{
				printName = farm[i].getName();
				cout << i << " : " << printName << endl;
			}
			cout << endl;
			cout << "Which critter would you like to listen to?: ";
			cin >> num;
			while (num < 0 || num > (farm.size() - 1))
			{
				cout << "Which critter would you like to listen to?: ";
				cin >> num;
			}
			cout << endl;
			farm[num].talk();
			cout << endl;
		}

		else if (choice == '2')
		{
			for (int i = 0; i < farm.size(); i++)
			{
				printName = farm[i].getName();
				cout << i << " : " << printName << endl;
			}
			cout << endl;
			cout << "Which critter would you like to feed?: ";
			cin >> num;
			while (num < 0 || num > (farm.size() - 1))
			{
				cout << "Which critter would you like to feed?: ";
				cin >> num;
			}
			cout << endl;
			farm[num].eat();
			cout << endl;


		}

		else if (choice == '3')
		{
			for (int i = 0; i < farm.size(); i++)
			{
				printName = farm[i].getName();
				cout << i << " : " << printName << endl;
			}
			cout << endl;
			cout << "Which critter would you like to play with?: ";
			cin >> num;
			while (num < 0 || num > (farm.size() -1))
			{
				cout << "Which critter would you like to play with?: ";
				cin >> num;
			}
			cout << endl;
			farm[num].play();
			cout << endl;

		}

		else if (choice == '4')
		{
			cout << "what do you want to name your critter?: ";
			cin.ignore();
			getline(cin, critName);
			cout << endl;
			Critter crit(critName);
			farm.push_back(crit);
		}

		else if (choice == '5')
		{
			for (int i = 0; i < farm.size(); i++)
			{
				farm[i].eat();
			}
			cout << endl;
		}
		else if (choice == '6')
		{
			for (int i = 0; i < farm.size(); i++)
			{
				farm[i].play();
			}
			cout << endl;
		}
		else if (choice == '7')
		{
			for (int i = 0; i < farm.size(); i++)
			{
				farm[i].talk();
			}
			cout << endl;
		}
	}



	return 0;
}
