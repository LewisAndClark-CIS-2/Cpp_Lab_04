// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class television{
public:

	int change_v(int amount){
		if (amount > 100){
			amount = 100;
		}
		if (amount < 0){
			amount = 0;
		}
		return amount;
	}
	int change_c(int number){
		if (number > 15){
			number = 15;

		}
		if (number < 0){
			number = 0;
		}
		return number;
	}
	
};


int _tmain(int argc, _TCHAR* argv[])
{
	television sony;
	int vol = 0;
	int chan = 0;
	char choice = '9';
	while (choice != '0'){
		cout <<
			"--------------------------" << endl <<
			"0 - Quit" << endl <<
			"1 - change volume" << endl <<
			"2 - change channel" << endl <<
			"Volume  - " << vol << endl <<
			"channel - " << chan << endl <<
			"--------------------------" << endl;


		cout << "\n\nSelect an option\n";
		cin >> choice;
		if (choice == '0'){
			cout << "turning power off\n";

		}
		else if (choice == '1'){
			cout << "Enter the volume 1 - 100\n";
			cin >> vol;
			vol = sony.change_v(vol);
		}
		else if (choice == '2'){
			cout << "Enter the channel 1 - 15\n";
			cin >> chan;
			chan = sony.change_c(chan);
		}
		else{
			cout << " That was not a valid choice";
		}
	}
	return 0;
}
