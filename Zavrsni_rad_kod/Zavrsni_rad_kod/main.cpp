
#include "board.hpp"
#include "PositionStack.hpp"
#include "const.hpp"


void main() {
	DEBUG = true;
	stack = new PositionStack;
	Position p;
	int start;
	int stop;
	double speed;
	Long nodes;
	if (DEBUG) {
		ofstream file("tree.xml");
		if (!file.is_open()) {
			cout << "Error openning file" << endl;
		}
		//file << "<?xml version=" << "\"1.0\" " << "encoding" << "=" << "\"UTF-8\"?>" << endl;
		file << XmlFileHeader << endl;
		start = clock();
		Move m;
		nodes = p.perft(3, &file, m);
		cout << "Num of nodes is " << nodes << endl;
		stop = clock();
	}
	else {
		start = clock();
		Move m;
		nodes = p.perft(3, NULL, m);
		cout << "Num of nodes is " << nodes << endl;
		stop = clock();
	}
	double time = ((double)(stop - start)) / CLOCKS_PER_SEC;
	speed = nodes / time;
	cout << "Time: " << time << endl;
	cout << "Speed: " << speed << endl;
}