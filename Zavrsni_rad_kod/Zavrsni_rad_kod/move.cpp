#include "board.hpp"
#include "PositionStack.hpp"

void Position::make_move(const Move& m) {
	stack->push(*this);
	//rohada
	if ((m.piece == wK || m.piece == bK) && abs(m.current_position - m.position) == 2) {
		//velika rohada
		if (m.position - m.current_position == 2) {
			board[m.position] = m.piece;
			this->board[m.current_position] = es;
			board[m.position - 1] = board[m.position + 1];
			board[m.position + 1] = es;
		}
		//mala rohada
		else {
			board[m.position] = m.piece;
			this->board[m.current_position] = es;
			board[m.position + 1] = board[m.position - 2];
			board[m.position - 2] = es;
		}
	}
	//en passant uzimanje
	if (m.en_passant){
		this->board[m.position] = m.piece;
		this->board[m.current_position] = es;
		if (m.piece == bP) {
			this->board[m.position - 12] = es;
		}
		else {
			this->board[m.position + 12] = es;
		}
		cout << "En-passant" << endl;
	}
	else {
		this->board[m.position] = m.piece;
		this->board[m.current_position] = es;
	}
	enpassant_flag = false;
	white_enpassant_field = 0;
	black_enpassant_field = 0;
	this->turn = !this->turn;
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