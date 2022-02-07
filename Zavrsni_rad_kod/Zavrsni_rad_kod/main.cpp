
#include "board.hpp"
#include "PositionStack.hpp"

void main() {
	Position p;
	stack = new PositionStack;
	Move m(wP, 101, 77);
	p.make_move(m);
	p.printPosition();
	cout << "----------------------" << endl;
	p.undo_move();
	p.printPosition();
}