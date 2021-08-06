#include <string>

class gol
{
private:
	int _dimension;
	int** _odd;
	int** _even;
	int _tick;
	int _get_next_state(int x, int y);
	int** currentArray() {return _tick % 2 ? _odd : _even; }
	int** nextArray() { return _tick % 2 ? _even : _odd; }
	void resetArray(int** array);
	void seedArray(int** array);
	bool inBounds(int row, int col, int x, int y);

public:
	~gol();
	std::string tester;
	gol(int dimension);
	void step();
	void pretty_print();
};