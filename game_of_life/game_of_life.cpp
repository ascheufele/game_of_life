// game_of_life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>
#include "gol.h"
using namespace std;

int main()
{
	//game of life
	//flow of program

	//game tick will be mod by 2 to determine which array is for reading and which for writing
	//2 arrays, current and next state

	//determine which array is current

	//perform computation on current array
	//get next state (int** arr2d) will iterate thru the current array and assign the next state to the other one

	//print current array
	  
	string word;
	gol test(15);
	for (int a = 0; a < 10000; a++)
	{
		test.pretty_print();
		test.step();
		Sleep(150);
		//std::cout << "iter" << endl;
		//std::getline(std::cin, word);
	}




	return 0;
}