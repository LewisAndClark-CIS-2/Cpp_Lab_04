// DD8_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;


class Critter {
	//A virtual pet
private:

	string name;
	int hunger = rand() % 10;
	int boredom = rand() % 10;

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
			m = "frusterated";
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
		cout << "Brruppp.  Thank you.\n";
		hunger -= food;
		if (hunger < 0){
			hunger = 0;
		}
		pass_time();
	}

	void play(int fun){
		cout << "Wheeee!\n";
		boredom -= fun;
		if (boredom < 0){
			boredom = 0;
		}
		pass_time();
	}

	void naming(string namer){
		name = namer;
	}

	void back_door(){
		cout << "Boredom - " << boredom << endl;
		cout << "Hunger  - " << hunger << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	std::srand (time(NULL));
	cout << "You are going to name your 4 critters" << endl;
	string namer = "";
	Critter crit[4];
	for (int i = 0; i < 4; i++){
		cout << "What do you want to name your critter?\n";
		cin >> namer;
		crit[i].naming(namer);
	}
	string choice = "hi";
	while (choice != "0"){
		cout <<
			"\n\n\nCritter\n\n" <<
			"0 - Quit\n" <<
			"1 - Listen to your critters\n" <<
			"2 - feed your critters\n" <<
			"3 - -Play with your critter\n";


		cout << "\n\nWhat choice would you like to pick? ";
		cin >> choice;
		if (choice == "0"){
			cout << "Good bye\n";
		}
		else if (choice == "1"){
			for (int i = 0; i < 4; i++){

				crit[i].talk();
			}
		}
		else if (choice == "2"){
			cout << "how much food can your critter eat? ";
			int amount;
			cin >> amount;
			for (int i = 0; i < 4; i++){
				crit[i].eat(amount);
			}

		}
		else if (choice == "3"){
			int option;
			cout << "which critter do you want to play with? 0 - 3";
			cin >> option;
			cout << "how long can your critter play? ";
			int time;
			cin >> time;
			crit[1].play(time);
		}
		
		
		else{
			cout << "\n sorry but " << choice << " is not a valid choice.";
		}

	}
	return 0;
	};

