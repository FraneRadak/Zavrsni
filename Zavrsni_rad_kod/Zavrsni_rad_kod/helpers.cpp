#include "board.hpp"
#include "PositionStack.hpp"

string Position::pieceToFENletter(int i) {
	if (board[i] == wP) {
		return "P";
	}
	else if (board[i] == bP) {
		return  "p";
	}
	else if (board[i] == wB) {
		return "B";
	}
	else if (board[i] == bB) {
		return "b";
	}
	else if (board[i] == wK) {
		return "K";
	}
	else if (board[i] == bK) {
		return "k";
	}
	else if (board[i] == wQ) {
		return "Q";
	}
	else if (board[i] == bQ) {
		return "q";
	}
	else if (board[i] == wN) {
		return "N";
	}
	else if (board[i] == bN) {
		return "n";
	}
	else if (board[i] == wR) {
		return "R";
	}
	else if (board[i] == bR) {
		return "r";
	}
	return "X";
}
int Position::search_for_piece(int piece, const Position& position) {
	for (int i = 0; i < 144; i++) {
		if (position.board[i] == piece) {
			return i;
		}
	}
}
int Position::FENLetterToPiece(char c) {
	if (c == 'P') {
		return wP;
	}
	else if (c == 'p') {
		return bP;
	}
	if (c == 'B') {
		return wB;
	}
	if (c == 'b') {
		return bB;
	}
	if (c == 'R') {
		return wR;
	}
	if (c == 'r') {
		return bR;
	}
	if (c == 'Q') {
		return wQ;
	}
	if (c == 'q') {
		return bQ;
	}
	if (c == 'N') {
		return wN;
	}
	if (c == 'n') {
		return bN;
	}
	if (c == 'k') {
		return bK;
	}
	if (c == 'K') {
		return wK;
	}
}