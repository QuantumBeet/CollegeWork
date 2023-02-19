//C++ Program:		Project3.cpp
//Course:			CSE1311 (C++) Section 002
//Name:				Vadym Strelnykov
//Assignment:		Project 3
//Due Date:			Nov 2, 2016

//Purpose:
/*To have a program that accepts any two dates and then calculates the number
of days in between the two dates to include the last day. The program compares
month, and years, and calculates accordingly using functions, and then prints
out the starting and end dates as well as the total number of dates between 
those two dates.
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
using namespace std;

void Print (int, int, int, int, int, int, int);
int DaysInYear (int);
int DaysInMonth (int, int);
bool LeapYear (int);

int d1, d2, m1, m2, year1, year2, total;
int main ()
{	
	ifstream fin ("input.txt");
	if (fin.fail())
		cout << "can't open file" << endl;
	
	while (!fin.eof())
	{
		total = 0;
		fin >> m1 >> d1 >> year1;
		fin >> m2 >> d2 >> year2;

		if (m1 == m2 && year1 == year2)
		{
			total = d2 - d1 + 1;
		}
		else if (year1 == year2)
		{
			total = DaysInMonth (m1, year1) - d1 + 1 ;
			for (int i = m1 + 1; i < m2; ++i)
			{
				total += DaysInMonth(i,year1);
			}
			total += d2;
		}
		else
		{
			total = DaysInMonth (m1,year1) - d1 + 1;	
		for (int i = m1 + 1; i <= 12; ++i)
			total += DaysInMonth(i,year1);
		for (int i = year1 + 1; i < year2; ++i)
			total += DaysInYear (i);
		for (int i = 1; i < m2; ++i)
			total += DaysInMonth (i, year2);
		total += d2;
		}
		Print (total,m1,m2,d1,d2,year1,year2);
	}
	fin.close();
	cout << "This program was written by Vadym Strelnykov" << endl;
	system("PAUSE");
	return 0;	
}

bool LeapYear (int y)
{
	if (y % 400 == 0)
		return true;
	else if (y % 4 == 0 && y % 100 != 0)
		return true;
	else
		return false;
}

int DaysInMonth (int m,int y)
{
	switch (m)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
		case 4: case 6: case 9: case 11: return 30;
		case 2: if (LeapYear (y) == true)
					return 29;
				else
					return 28;
	}
}

int DaysInYear (int y)
{
	if (LeapYear (y) == true)
		return 366;
	else
		return 365;
}

void Print (int total, int m1, int m2, int d1, int d2, int year1, int year2)
{
	cout << "The beginning date is: " << m1 << "/" << d1 << "/" << year1 << endl;
	cout << "The end date is: " << m2 << "/" << d2 << "/" << year2 << endl;
	cout << "The total number of days is: " << total << "\n" << endl;
}

