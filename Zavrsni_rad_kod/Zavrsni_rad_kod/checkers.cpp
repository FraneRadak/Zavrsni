#include "board.hpp"
#include "PositionStack.hpp"

void Position::castle_crusher(Move& m) {
	if (m.piece == wK) {
		white_small_castle = false;
		white_big_castle = false;
	}
	else if (m.piece == bK) {
		black_small_castle = false;
		black_big_castle = false;
	}
	else if (m.piece == wR && m.current_position == 110) {
		white_big_castle = false;
	}
	else if (m.piece == wR && m.current_position == 117) {
		white_small_castle = false;
	}
	else if (m.piece == bR && m.current_position == 26) {
		black_big_castle = false;
	}
	else if (m.piece == bR && m.current_position == 117) {
		white_small_castle = false;
	}
}
bool Position::promotion_check(Move* possible_moves, int& move_counter, int i) {
	if (possible_moves[move_counter - 1].piece == wP) {
		if (possible_moves[move_counter - 1].position >= 26 && possible_moves[move_counter - 1].position <= 33) {
			return true;
		}
	}
	if (possible_moves[move_counter - 1].piece == bP) {
		if (possible_moves[move_counter - 1].position >= 98 && possible_moves[move_counter - 1].position <= 105) {
			return true;
		}
	}
	return false;
}
bool Position::eat_own_piece(int current_index, int move_index) {
	if (((board[current_index] <= 6 && board[move_index] <= 6) || (board[current_index] > 6 && board[move_index] > 6)) && board[move_index] != es) {
		return true;
	}
	return false;
}
/*
void Position::set_enpassant(int index) {
	if (board[index] == wP) {
		white_enpassant_piece = board[index];
	}
	else {
		black_enpassant_piece = board[index];
	}
}
*/
/*
bool Position::check_enpassant(int index,int& enpassant_index) {
	if (board[index] == wP) {
		if (board[index + 1] == bP && black_enpassant_piece == board[index + 1]) {
			enpassant_index = index + 1;
			return true;
		}
		else if (board[index - 1] == bP && black_enpassant_piece == board[index - 1]) {
			enpassant_index = index - 1;
			return true;
		}
		return false;
	}
	else if (board[index] == bP) {
		if (board[index + 1] == wP && white_enpassant_piece == board[index + 1]) {
			enpassant_index = index + 1;
			return true;
		}
		else if (board[index - 1] == wP && white_enpassant_piece == board[index - 1]) {
			enpassant_index = index - 1;
			return true;
		}
		return false;
	}
}
*/