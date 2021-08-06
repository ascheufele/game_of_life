#include <iostream>
#include "gol.h"
#include <ctime>

using namespace std;

gol::gol(int dimension)
{
	_tick = 0;
	this->_dimension = dimension;
	_odd = new int*[dimension];
	_even = new int*[dimension];
	for (int a = 0; a < dimension; a++)
	{
		_odd[a] = new int[dimension];
		_even[a] = new int[dimension];
	}
	resetArray(_odd);
	resetArray(_even);
	seedArray(_even);
}

gol::~gol()
{
	for (int a = 0; a < _dimension; a++)
	{
		delete _odd[a];
		delete _even[a];
	}
	delete _odd;
	delete _even;
}

void gol::step()
{
	for (int a = 0; a < _dimension; a++)
	{
		for (int b = 0; b < _dimension; b++)
		{
			nextArray()[a][b] = _get_next_state(a, b);
		}
	}
	
	
	_tick++;
}

void gol::pretty_print()
{
	int** curr = currentArray();

	for (int a = 0; a < _dimension; a++)
	{
		for (int b = 0; b < _dimension; b++)
		{
			std::cout << (curr[a][b] == 1 ? 'x' : ' ') << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void gol::resetArray(int** array)
{
	for (int a = 0; a < _dimension; a++)
	{
		for (int b = 0; b < _dimension; b++)
		{
			array[a][b] = 0;
		}
	}
}

//returns next state for given point at currentArray()[x][y]
int gol::_get_next_state(int x, int y)
{
	//x and y are coordinates within the _dimension x _dimension 2d array currentArray()
	//check immediate neighbors, keeping a tally of how many are living/dead
	//perform bounds checking on indices prior to accessing array
	//after checking all neighbors, write the proper next state to the non-current state array
	int living_neighbors = 0;
	int next_state = 0;

	for (int row = x - 1; row <= x + 1; row++)
	{
		for (int col = y - 1; col <= y + 1; col++)
		{
			if (inBounds(row, col, x, y) && currentArray()[row][col] == 1)
			{
				++living_neighbors;
			}
		}
	}
	switch (living_neighbors)
	{
	case 2:
		if (currentArray()[x][y] == 1)
		{
			next_state = 1;
		}
		break;
	case 3:
		next_state = 1;
		break;
	//default:
		//next_state = 0;

	}

	//cout << x << " " << y <<  " neighbors: " << living_neighbors << endl;
	return next_state;
}

// Checks to see if row and col point to valid array coordinates. Returns false if row == x && col == y.
bool gol::inBounds(int row, int col, int x, int y)
{

	if (row < 0 || row >= _dimension)
	{
		//cout << row << " " << col << " outbounds 1" << endl;
		return false;
	}
	if (col < 0 || col >= _dimension)
	{
		//cout << row << " " << col << " outbounds 2" << endl;
		return false;
	}
	if (row == x && col == y)
	{
		//cout << row << " " << col << " outbounds 3" << endl;
		return false;
	}
	//cout << row << " " << col << " inbounds" << endl;
	return true;
}

void gol::seedArray(int** array)
{
	srand(time(NULL));
	for (int a = 0; a < _dimension; a++)
	{
		for (int b = 0; b < _dimension; b++)
		{
			array[a][b] = rand() % 3 == 0 ? 1 : 0;
		}
	}
}