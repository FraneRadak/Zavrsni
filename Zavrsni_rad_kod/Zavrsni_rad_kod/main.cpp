
#include "board.hpp"
#include "PositionStack.hpp"


void main() {
	stack = new PositionStack;
	ofstream file("tree.xml");
	if (!file.is_open()) {
		cout << "Error openning file" << endl;
	}
	file << "<?xml version=" << "\"1.0\" " << "encoding" << "=" << "\"UTF-8\"?>" << endl;
	Position p;
	int start = clock();
	Move m;
	cout << "Num of nodes is " << p.perft(2, file,m,0) << endl;
	int stop = clock();
	cout << "Time: " << ((double)(stop - start)) / CLOCKS_PER_SEC << endl;
}