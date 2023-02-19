//C++ Program:		Project2.cpp
//Course:			CSE1311 (C++) Section 02
//Name:				Vadym Strelnykov
//Assignment:		Project 2
//Due Date:			October 3, 2016

//Purpose:
/*  To generate a random number between 1 and 100 and prompt the user to guess the number, replying to 
their guess and making them guess until they have guessed the right number. Then, displaying how long it
them to guess right, and prompting them if they want to repeat.
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main ()
{
char repeat = 'y';
while (repeat == 'y')
{
	int tries = 0;
	int userguess;
	srand (time(0));
	int pcguess = rand () % 100 + 1;
	
	cout << "Please guess a number between 1 and 100 \n " << endl;
	cout << "Enter -1 to quit \n " << endl;
	cin >> userguess;
	do
	{ 
		if (userguess > 100)
			cout << "Number is out of range" << endl;
		else if (userguess > pcguess)	
			cout << "Too high " << endl;
		else if (userguess < pcguess)
			cout << "Too low " << endl;
		else if (userguess == pcguess)
		{
			cout << "Correct \n" << "Took you " << tries << " tries " << endl;
			break;
		}
		tries++;
		cin >> userguess;
	} 
	while (userguess != -1);
	if (userguess == -1)
	{
		cout << "You have quit the game \n " << endl;
		cout << "Your number of attmepts is: " << tries << endl;
		break;
	}
	cout << "Would you like to repeat? (y/n) \n "<< endl;
	cin>> repeat;
}

	cout << "This program was written by Vadym Strelnykov" << endl;
	system("PAUSE");
	return 0;
}	

