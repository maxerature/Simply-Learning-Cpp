// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool correct = false;


int dieRoll(pair <int, int> diePair) {
	cout << "\n \nRolling " << diePair.first << " d" << diePair.second << " dice";
	int totalVal = 0;
	for (int i = 0; i < diePair.first; i++) {
		int result = rand() % diePair.second + 1;
		totalVal += result;
		cout << "\nResult: " << result;
	}
	cout << "\n\nTotal: " << totalVal;
	return 0;
}


int stringSplitter(string rollInput) {

	int dFind = rollInput.find('d');
	if (dFind != std::string::npos) {
		string preDeen;
		string postDeen;
		int stringLength = rollInput.length();
		int afterD = dFind + 1;

		for (int i = 0; i < dFind; i++) {
			preDeen += rollInput[i];
		}
		for (int i = afterD; i < stringLength; i++) {
			postDeen += rollInput[i];
		}

		int rollCount;
		int dieSides;
		stringstream rollCountStream(preDeen);
		stringstream dieSidesStream(postDeen);
		rollCountStream >> rollCount;
		dieSidesStream >> dieSides;
		pair <int, int> diePair;
		diePair.first = rollCount;
		diePair.second = dieSides;

		cout << '\n' << rollCount << '\n' << dieSides << '\n';
		dieRoll(diePair);
		return 0;
	}
	else {
		string errorMessage = "\n\nIncorrect Format.  Please use #d#. \n \n";
		cout << errorMessage;
		return 0;
	}
}

int main(){
	while (correct==false) {
		string rollInput;
		cout << "\n\n\n\n" << "Input a die Roll" << "\nUse the format #d#\n\n";
		getline(cin, rollInput);
		stringSplitter(rollInput);
	}
}