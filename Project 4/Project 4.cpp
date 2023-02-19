//C++ Program:		Project4.cpp
//Course:			CSE1311 (C++) Section 002
//Name:				Vadym Strelnykov
//Assignment:		Project 4
//Due Date:			Nov 30, 2016

//Purpose:
/*  To create a list of people and their weight and then to
calculate how many of them will fit on an elevator with a 
certain weight restriction, sort the list in ascending and
descending orders and calculate again, then see which method
yields the most people on the elevator. 
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

void PrintArray (string n[], int w[], int size);
int HowMany (int w[]);
void InsertSort (int x[], int size, string n[]);
void Descend (int x[], int size, string n[]);
void MostPeople (int a, int b, int c);
ofstream fout ("output.txt");
int size = 12;

int main ()
{
	int weight[100];
	string name[100];

	fstream fin1 ("projectinput.txt");
	if (fin1.fail())
		cout << "can't open file" << endl;
	for (int i = 0; i < size; ++i)	
		fin1 >> name[i] >> weight[i];
	PrintArray (name, weight, size);

	fout << "\nThis is from Run 1 " << endl;
	int a = HowMany (weight);
	PrintArray (name, weight, a);

	InsertSort (weight, size, name);
	fout << endl << endl;
	PrintArray (name, weight, size);

	fout << "\nThis is from Run 2 " << endl;
	int b = HowMany(weight);
	PrintArray (name, weight, b);

	Descend (weight, size, name);
	fout << endl << endl;
	PrintArray (name, weight, size);

	fout << "\nThis is from Run 3 " << endl;
	int c = HowMany(weight);
	PrintArray (name, weight, c);

	fout << endl;
	MostPeople (a, b, c);


	fin1.close();
	fout << "\n\nThis program was written by Vadym Strelnykov" << endl;
	fout.close();
	system("PAUSE");
	return 0;	
}
void PrintArray (string n[], int w[], int size)
{
	fout << "Names\t\tWeights" << endl << endl;
	for (int i = 0; i < size; ++i)
		fout << n[i] << "\t\t" << w[i] << endl;
}
int HowMany (int w[])
{
	int total = 0;
	int i = 0;
	while (total <= 1100)
	{
		total += w[i];
		i++;
	}
	i--;
	fout << "Total Weight " << total - w[i] << endl;
	fout << "Total people on elevator " << i << endl << endl;
	return i;
}

void InsertSort(int x[], int size, string n[])
{
 	for (int i = 0; i < size; i++)
  	{
 		int key = x[i];
		int position = i;
		while (position > 0 && x[position-1] >key)
		{
			x[position] = x[position-1];
			position--;
		}	
		x[position] = key;
 	}
}

void Descend (int x[], int size, string n[])
{
	int temp;
	string tempstr;
	for ( int i = 0; i <size; i++)
	for (int j = i+1; j < size; j++)
		if (x[i] < x[j])
		{
			temp = x[i];
			x[i] = x[j];
			x[j] = temp;
			tempstr = n[i];
			n[i] = n[j];
			n[j] = tempstr;
		}
}

void MostPeople (int a, int b , int c)
{
	if (a > b && a > c)
		fout << "First method fit most people which was  " << a << endl;
	else if (b > a && b > c)
		fout << "Ascending order fit most people which was  " << b << endl;
	else if (c > a && c > b)
		fout << "Descending order fit most people which was  " << c << endl;
}