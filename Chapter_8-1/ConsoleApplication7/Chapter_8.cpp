// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string crit_name;
	char choice;
	int food;
	int fun;
	cout << "What do you want to name your critter";
	cin >> crit_name;
	choice = NULL;
	while (choice != '0'){
		cout << "Critter Caretaker";
		cout << endl;
		cout << "0 - Quit";
		cout << "1 - Listen to your critter";
		cout << "2 - Feed your critter";
		cout << "3 - Play with your critter";
		cout << "choice: ";
		cin >> choice;
		if (choice == '0'){
			cout << "Good-bye" << endl;
		}
		else if (choice == '1'){
			crit.talk();
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
	return 0;
}

