#include "board.hpp"
#include "PositionStack.hpp"

int Position::search_for_piece(int piece, const Position& position) {
	if (piece < 6) {
		for (int i = 117; i >= 26; i--) {
			if (position.board[i] == piece) {
				return i;
			}
		}
	}
	else {
		for (int i = 26; i <= 117; i++) {
			if (position.board[i] == piece) {
				return i;
			}
		}
	}
}