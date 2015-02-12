/***********************************
 * Author: Brandon McCurry
 *			Nate Rowe
 *			Matt Jones
 *			Matt Gilmore
 *			Andy Rotten
 * Date: 2/12/15
 * Description: Chapter 8-1
************************************/

#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>
#include <string>
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
	Critter()
	{
		string name = "";
		hunger = 0;
		boredom = 0;
		
	}
	void setName(string crit_name){
		name = crit_name;
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
int main()
{
	string crit_name;
	Critter crit;
	char choice;
	int food;
	int fun;
	cout << "What do you want to name your critter: ";
	cin >> crit_name;
	crit.setName(crit_name);
	choice = NULL;
	while (choice != '0'){
		cout << "Critter Caretaker";
		cout << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Listen to your critter"<< endl;
		cout << "2 - Feed your critter" << endl;
		cout << "3 - Play with your critter" << endl;
		cout << "choice: " << endl;
		cin >> choice;
		if (choice == '0'){
			cout << "Good-bye" << endl;
		}
		else if (choice == '1'){
			crit.talk();
			cin.ignore();
			cin.ignore();
		}
		else if (choice == '2'){
			cout << "how much do you want to feed your pet?:" << endl;
			cin >> food;
			while (food < 1 || food < 10){
				cout << "how much do you want to feed your pet?:" << endl;
				cin >> food;
				crit.eat(food);
			}
		}
		else if (choice == '3'){
			cout << "how long do you want to play with your pet?:" << endl;
			cin >> fun;
			while (fun < 1 || fun < 10){
				cout << "how much do you want to feed your pet?:" << endl;
				cin >> fun;
				crit.play(fun);
			}
		}
		else{
			cout << "Sorry, but" << choice << "is not a valid choice" << endl;
		}
	}
	return 0;
}

