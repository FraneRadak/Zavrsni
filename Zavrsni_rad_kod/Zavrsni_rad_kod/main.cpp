#include "board.hpp"
#include "exceptions.hpp"


void main() {
	Position p;
	p.printPosition();
	cout << "----------------------------------------" << endl;
	try {
		Move m(wP, 102, 78);
		p.move(m);
		p.printPosition();
		cout << "----------------------------------------" << endl;
		Move m1(bP, 42, 66);
		p.move(m1);
		p.printPosition();
		cout << "----------------------------------------" << endl;
		Move m2(wB, 115, 76);
		p.move(m2);
		p.printPosition();
		cout << "----------------------------------------" << endl;
		Move m3(bB, 31, 64);
		p.move(m3);
		p.printPosition();
		cout << "----------------------------------------" << endl;
		Move m4(wN, 116, 91);
		p.move(m4);
		p.printPosition();
		cout << "----------------------------------------" << endl;
		Move m5(bN, 32, 57);
		p.move(m5);
		p.printPosition();
		cout << "----------------------------------------" << endl;
		Move m6(wN, 91, 66);
		p.move(m6);
		p.printPosition();
		cout << "----------------------------------------" << endl;
		Move m7(bQ, 29, 68);
		p.move(m7);
		p.printPosition();
	}
	catch (Exception& e) {
		e.ThrowException();
	}
}