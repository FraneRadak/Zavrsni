#include "board.hpp"
#include "PositionStack.hpp"

Move* Position::move_generator(int& move_counter) {
	Move* possible_moves = new Move[255];
	//int move_counter = 0;
	if (this->turn == white) {
		for (int i = 26; i <= 117; i++) {
			if (board[i] > 0) {
				int temp = i;
				if (board[i] == wB) {
					diagonal_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == wQ) {
					diagonal_movement(possible_moves, move_counter, i);
					forward_backward_movement(possible_moves, move_counter, i);
					horizontal_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == wR) {
					forward_backward_movement(possible_moves, move_counter, i);
					horizontal_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == wN) {
					knight_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == wP) {
					pawn_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == wK) {
					king_movement(possible_moves, move_counter, i);
				}
			}
		}
	}
	else if (this->turn == black) {
		for (int i = 26; i <= 117; i++) {
			if (board[i] > 0) {
				int temp = i;
				if (board[i] == bB) {
					diagonal_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == bQ) {
					diagonal_movement(possible_moves, move_counter, i);
					forward_backward_movement(possible_moves, move_counter, i);
					horizontal_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == bR) {
					forward_backward_movement(possible_moves, move_counter, i);
					horizontal_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == bN) {
					knight_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == bP) {
					pawn_movement(possible_moves, move_counter, i);
				}
				else if (board[i] == bK) {
					king_movement(possible_moves, move_counter, i);
				}
			}
		}
	}
	return possible_moves;
}