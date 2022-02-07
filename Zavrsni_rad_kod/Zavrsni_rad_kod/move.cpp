#include "board.hpp"
#include "PositionStack.hpp"

void Position::make_move(const Move& m) {
	stack->push(*this);
	this->board[m.position] = m.piece;
	this->board[m.current_position] = es;
	this->turn = !this->turn;
}

void Position::undo_move() {
	*this = stack->pop();
}
void Position::move() {
	int move_counter = 0;
	Move* moves = move_generator(move_counter);
	print_possible_moves(moves, move_counter);
}