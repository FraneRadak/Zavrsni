#include "board.hpp"
#include "exceptions.hpp"


void main() {
	Position p;
	p.printPosition();
	cout << "----------------------------------------" << endl;
	Move m(wP, 102, 78);
	try {
		p.move(m);
		p.printPosition();
		Move m1(bP, 41, 65);
		p.move(m1);
		cout << "----------------------------------------" << endl;
		p.printPosition();
		cout << "----------------------------------------" << endl;
		Move m2(wP, 78, 65);
		p.move(m2);
		p.printPosition();
		
	}
	catch (Exception& e) {
		e.ThrowException();
	}
}