
#include "board.hpp"
#include "PositionStack.hpp"


void main() {
	/*
	ofstream file("perftree.txt");
	if (!file.is_open()) {
		cout << "Error openning file" << endl;
		return;
	}
	Position p;
	stack = new PositionStack;
	int start = clock();
	cout << "Num of nodes is " << p.perft(3,file) << endl;
	int stop = clock();
	cout << "Time: " << ((double)(stop - start)) / CLOCKS_PER_SEC << endl;
	*/
	ofstream file("tree.xml");
	if (!file.is_open()) {
		cout << "Error openning file" << endl;
	}
	file << "<?xml version=" << "\"1.0\" " << "encoding" << "=" << "\"UTF-8\"?>" << endl;
	Position p;
	stack = new PositionStack;
	int start = clock();
	Move m;
	cout << "Num of nodes is " << p.perft(3, file,m) << endl;
	int stop = clock();
	cout << "Time: " << ((double)(stop - start)) / CLOCKS_PER_SEC << endl;
}