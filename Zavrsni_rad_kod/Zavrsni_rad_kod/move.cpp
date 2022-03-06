#include "board.hpp"
#include "PositionStack.hpp"

void Position::make_move(const Move& m) {
	//rohada
	if ((m.piece == wK || m.piece == bK) && abs(m.current_position - m.position) == 2) {
		stack->push(*this);
		//velika rohada
		if (m.position - m.current_position == 2) {
			board[m.position] = m.piece;
			this->board[m.current_position] = es;
			board[m.position - 1] = board[m.position + 1];
			board[m.position + 1] = es;
		}
		else {
			board[m.position] = m.piece;
			this->board[m.current_position] = es;
			board[m.position + 1] = board[m.position - 2];
			board[m.position - 2] = es;
		}
	}
	else {
		stack->push(*this);
		this->board[m.position] = m.piece;
		this->board[m.current_position] = es;
		this->turn = !this->turn;
	}
}

void Position::undo_move() {
	*this = stack->pop();
}
void Position::move() {
	int move_counter = 0;
	Move moves[255];
	move_generator(move_counter, moves);
	print_possible_moves(moves, move_counter);
}