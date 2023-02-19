//C++ Program:		Lab3.cpp
//Course:			CSE1311 (C++)
//Name:				Vadym Strelnykov
//Assignment:		Lab 3
//Due Date:			Sept 7, 2016

//Purpose:
/*  To write a program to play "rock, paper, scissors." have the player input their choice, 
create a random number seed, translate that seed into computer's choice, compare the two choices
and to print out both choices and whether or not te user have won or lost, and then ask the user
if they want to play again
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main ()
{
	char repeat = 'Y', pc, user;
	srand (time(NULL));
	
	
	while (repeat == 'Y')
	{

	int seed = rand () % 3;
	
	cout << "Please enter your choice (R)ock, (P)aper, or (S)cissors " << endl;
	cin>> user;
	
	
	switch (seed)
		{
			case 0: pc = 'R';
			break;
			case 1: pc = 'P';
			break;
			case 2: pc = 'S';
			break;
		}
	
	if (user == 'R')
		cout << "Your choice is Rock " << endl;		
	else if (user== 'P')
		cout << "Your choice is Paper " << endl;
	else if (user == 'S')
		cout << "Your choice of Scissors " << endl;
	
	
	
	if (pc == 'R' )
		cout << "Computer chose Rock " << endl;
	else if (pc == 'P')
		cout << "Computer chose Paper " << endl;
	else if (pc == 'S')
		cout << "Computer chose Scissors " << endl;
	
	
	
	if (pc == user)
		cout << "It's a tie " << endl;
	else if (pc == 'R')
		{if (user == 'S')
			cout << "Rock crushes scissors! \n" << "You lose! " << endl;		
		else if (user == 'P')
			cout << "Paper covers rock \n" << "You win! " << endl;		
		}
	else if(pc == 'P')
		{if (user == 'S')
			cout << "Scissors cut up paper \n" << "You win! " << endl;		
		else if (user == 'R')
			cout << "Paper covers rock \n" << "You lose! " << endl;	
		}
	else if(pc == 'S')
		{if (user == 'P')
			cout << "Scissors cut up paper \n" << "You lose! " << endl;		
		else if (user == 'R')
			cout << "Rock crushes scissors \n" << "You win! " << endl;	
		}
		
	
	cout << "Do you want to replay? (Y/N)" << endl;
	cin>> repeat;
	}
	
	cout << "This program was written by Vadym Strelnykov" << endl;
	system("PAUSE");
	return 0;
}	

