// DD8_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Critter {
	//A virtual pet
private:
	string name;
	int hunger = 0;
	int boredom = 0;

	void pass_time(){
		boredom++;
		hunger++;
	}

public:
	string m;
	string mood(){
		int unhappiness = hunger + boredom;
		if (unhappiness < 5){
			m = "happy";
		}
		else if (5 <= unhappiness <= 10){
			m = "okay";

		}
		else if (11 <= unhappiness <= 15){
			m= "frusterated";
		}
		else{
			m = "mad";
		}
		return m;

	}
	void talk(){
		cout << "I'm " << name << " and I feel " << mood() << " now.\n";
		pass_time();

	}

	void eat(int food){
		cout << "Brruppp.  Thank you.";
		hunger -= food;
		if (hunger < 0){
			hunger = 0;
		}
		pass_time();
	}

	void play(int fun){
		cout << "Wheeee!";
		boredom -= fun;
		if (boredom < 0){
			boredom = 0;
		}
		pass_time();
	}

	void naming(string namer){
		name = namer;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string namer = "";
	Critter crit;
	cout << "What do you want to name your critter?\n";
	cin >> namer;
	crit.naming(namer);

	string choice = "hi";
	while (choice != "0"){
		cout <<
			"Critter\n\n" <<
			"0 - Quit\n" <<
			"1 - Listen to your critter\n" <<
			"2 - feed your critter\n" <<
			"3 - -Play with your critter\n";


		cout << "\n\nWhat choice would you like to pick? ";
		cin >> choice;
		if (choice == "0"){
			cout << "Good bye\n";
		}
		else if (choice == "1"){
			crit.talk();
		}
		else if (choice == "2"){
			cout << "how much food can your critter eat? ";
			int amount;
			cin >> amount;
			crit.eat(amount);
		}
		else if (choice == "3"){
			cout << "how long can your critter play? ";
			int time;
			cin >> time;
			crit.play(time);
		}
		else{
			cout << "\n sorry but " << choice << " is not a valid choice.";
		}
		
	}
	return 0;
}

