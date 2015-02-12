// challenge2_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class teleVision{
private:
	int channel = NULL;
		int  defaultVolume = 0;
		int  defaultChannel = 0;
		string button = NULL;
public:
	void defaultvolume(){
			cout << "What do you want the volume to be ( 1 - 100)? " << endl;
			cin >> defaultVolume;
		}
		int getChannel(){
			cout << channel << endl;
			return channel;
		}
		void remote(){
			if (button == ""){
				cout << "invalid input" << endl;

			}
			else if (button == "+")
			{
				cout << "adds to the volume" << endl;
				defaultVolume++;
				
				if (defaultVolume > 100){
					cout << "thats too loud" << endl;

				}
			}
			else if (button == "-"){
				cout << "subtracts the volume" << endl;
				defaultVolume--;

			}
			else if (defaultChannel > 0){
				cout << "adds to the channel" << endl;
				defaultChannel++;
				if (defaultChannel > 100){
					cout << "you can't go that high"<< endl;

				}
			}
			
			
			
			else if (defaultChannel < 0){
				cout << "invalid input" << endl;
				defaultChannel--;
				if (defaultChannel > 0){
					cout << "enjoy the show" << endl;
				}
			
			}
		}

};
int main()
{
	int volume = 100;
	int channel = 100;
	cout << "(off) turn tv off: (+) turn the sound up: (-) turn the sound down" << endl;
	cout << " (1 - 100) changes the channel" << endl;
	string b = "";
	cout << "what do you want to do" << endl;
	cin >> b ;
	teleVision Tv;
	while (b != "off")
	{
		Tv.remote();
	}
	return 0;
}

