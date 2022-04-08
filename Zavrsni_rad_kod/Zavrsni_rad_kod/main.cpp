
#include "board.hpp"
#include "PositionStack.hpp"
#include "const.hpp"
#include "IO.hpp"

void main() {
	DEBUG = false;
	stack = new PositionStack;
	Position p;
	run(p);
	/*
	p.setFromFEN("r3k2r/p1ppqpb1/bnN1pnp1/3P4/1p2P3/2N2Q1p/PPPBBPPP/R3K2R b KQkq - 1 1");
	cout << p.toFEN() << endl;
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
		nodes = p.perft(2, &file, m);
		cout << "Num of nodes is " << nodes << endl;
		stop = clock();
	}
	else {
		start = clock();
		Move m;
		nodes = p.perft(2, NULL, m);
		cout << "Num of nodes is " << nodes << endl;
		stop = clock();
	}
	double time = ((double)(stop - start)) / CLOCKS_PER_SEC;
	speed = nodes / time;
	cout << "Time: " << time << endl;
	cout << "Speed: " << speed <<" npm"<< endl;
	*/
}