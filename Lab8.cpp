//C++ Program:		Lab8.cpp
//Course:			CSE1311 (C++) Section 002
//Name:				Vadym Strelnykov
//Assignment:		Lab 8
//Due Date:			Oct 26, 2016

//Purpose:
/*  To make use of multiple functions, make use of an array to store data and to make use of sorting and searching techniques.
The program reads in temperatures from a file, finds average temperature, prints that. Then, the program prints out the 
temperature in a table format alongside with the corresponding hour/posiotion and the difference from the average temperature.
Then the program finds the position and the actual temperature of lowest and highest temperature during the day, followed by 
organizing the temperatures in descending order. 
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
using namespace std;
double a;

void ReadArray (int array[], int size);
void PrintArray (int array[], int size, double a);
void Min (int y[], int m);
void Max (int z[], int n);
double FindAvg (int array[], int size);
void SwapTemp (int array [], int size);

int main ()
{
	int temp [24];
	double a;
	ReadArray (temp,24);
	a = FindAvg (temp,24);
	cout << "The average temperature is: " << a << "\n" << endl;
	PrintArray (temp, 24, a);
	
	Min (temp, 24);
	Max (temp, 24);
	
	SwapTemp(temp, 24);
	
	cout << "\n\nThis program was written by Vadym Strelnykov" << endl;
	system("PAUSE");
	return 0;	
}

void ReadArray (int array[], int size)
{
	ifstream fin ("Lab8Input.txt");
	for (int i=0; i<size; ++i)
		fin >> array[i];
	fin.close();
}

void PrintArray (int array[], int size, double a)
{
	cout << "Hour" << "\t" << "Temperature" << "\t" << "Difference from the Average" << endl;
	for (int i=0; i<size; ++i)
		cout <<setprecision(2)<< i << "\t" << array[i] << "\t\t" << array[i] - a << endl;
	cout << "\n";
	
}

void SwapTemp (int array [], int size)
{
	int temporary = 0;
	for (int i=0; i<size; ++i)
	{
		for (int j=0; j<size; ++j)
		{
			if (array [i] > array [j])
			{
				temporary = array [j];
				array [j] = array [i];
				array [i] = temporary; 
			}
		}
	}
	cout << "The temperature in descending order is: " << endl;
	for (int w =0; w<size; ++w)
		cout << array [w] << " " ;
		
}

void Min (int y[], int m)
{
	int low = y[0], savelow = 0;
	for (int i=0; i<m; ++i)
		if (y[i] < low)
		{
			low = y[i];
			savelow = i;
		}
	cout << "Lowest Temperature is: " << low << endl;
	cout << "In position: " << savelow << "\n" << endl;
		
}
void Max (int z[], int n)
{
	int high = z[0], savehigh = 0;
	for (int i=0; i<n; ++i)
		if (z[i] > high)
		{
			high = z[i];
			savehigh = i;
		}
	cout << "Highest Temperature is: " << high << endl;
	cout << "In position: " << savehigh << "\n" << endl;
}
double FindAvg (int array[], int size)
{
	double total = 0;
	for (int i=0; i<size; ++i)
		total += array [i];
	return total/size;
}

