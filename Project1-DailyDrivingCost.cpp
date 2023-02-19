//C++ Program			Project1.cpp
//Course				CSE1311 (C++)
//Name					Vadym Strelnykov
//Assignment#:			Project #1, Driving Costs
//Due Date:				Sept 7, 2016

//Purpose:
/* To have the user input total, miles, cost per gallon, average MPG, parking fees and 
daily tolls, and to use arithmetic functions to figure out what is the users daily cost 
of driving is. */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char repeat = 'y';
	while (repeat == 'y')
	{
		double miles, cost, gallons, average, parking, tolls, result, x, z;

		cout << "Please input the number of total miles driven" << endl;
		cin >> miles;

		cout << "Please input the cost per gallon of gas" << endl;
		cin >> cost;

		cout << "Please input the average miles per gallon" << endl;
		cin >> average;

		cout << "Please input parking fees per day" << endl;
		cin >> parking;

		cout << "Please input the tolls per day" << endl;
		cin >> tolls;

		x = parking + tolls;				//pure money addition

		gallons = miles / average;			//to figure out the amount of gallons spent

		z = gallons * cost;					//cost of gas for the distance traveled 

		result = x + z;						//adding all the cost

		cout << "   " << endl;
		cout << "Your total miles driven is: " << miles << endl;				
		cout << "Your total cost per gallon is: " << cost << endl;
		cout << "Your average miles per gallon is: " << average << endl;
		cout << "Your parking fees for the day are: " << parking << endl;
		cout << "Your daily tolls are: " << tolls << endl;
		cout << "User's cost per day is: " << setprecision (4) << result << endl;
		cout << "  " << endl;

		cout << "Do you want to repeat?(y/n):";
		cout << "  " << endl;
		cin >> repeat;
	}

	cout << "This program written by Vadym Strelnykov.";
	return 0;

}
