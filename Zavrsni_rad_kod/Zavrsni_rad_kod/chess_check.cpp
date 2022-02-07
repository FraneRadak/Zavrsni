#include "board.hpp"
#include "PositionStack.hpp"
bool Position::is_under_check(const Move& m) {
	Position pos = *this;
	pos.make_move(m);
	int king_index = 0;
	//pos.make_move(m);
	if (m.piece < 6) {
		king_index = search_for_piece(wK, pos);
	}
	else if (m.piece > 6) {
		king_index = search_for_piece(bK, pos);
	}
	if (this->diagonal_check(king_index, pos) || this->horizontal_vertical_check(king_index, pos) || this->knight_check(king_index, pos)) {
		return true;
	}
	return false;
}
bool Position::is_attacked(int index) {
	int diagonal_delta[4]= { 13,-13,11,-11 };
	for (int i = 0; i < 4; i++) {
		int temp = index;
		while (board[temp] >= 0) {
			temp += diagonal_delta[i];
			if (board[temp] < 0) {
				break;
			}
			if (this->turn == white && board[temp] <= 6) {
				break;
			}
			else if (this->turn == black && board[temp] > 6) {
				break;
			}
			else if (this->turn == black && (board[temp] == wQ || board[temp] == wR)) {
				return true;
			}
			else if (this->turn = white && (board[temp] == bQ || board[temp] == bR)) {
				return true;
			}
		}
	}
	int horizontal_vertical_delta[4] = { 1,-1,12,-12 };
	for (int i = 0; i < 4; i++) {
		int temp = index;
		while (board[temp] >= 0) {
			temp += horizontal_vertical_delta[i];
			if (board[temp] < 0) {
				break;
			}
			if (this->turn == white && board[temp] <= 6) {
				break;
			}
			else if (this->turn == black && board[temp]>6) {
				break;
			}
			else if (this->turn==black && (board[temp]==wQ || board[temp]==wR)) {
				return true;
			}
			else if (this->turn = white && (board[temp] == bQ || board[temp] == bR)) {
				return true;
			}
		}
	}
	int knight_delta[8] = { 23,-23,14,-14,10,-10,25,-25 };
	for (int i = 0; i < 8; i++) {
		if (this->turn == white && board[index + knight_delta[i]] == bN) {
			return true;
		}
		else if (this->turn == black && board[index + knight_delta[i]] == wN) {
			return true;
		}
	}
	
	if (this->turn == white) {
		if (board[index - 11] == bP || board[index - 13] == bP) {
			return true;
		}
	}
	if (this->turn == black) {
		if (board[index + 11] == wP || board[index + 13] == wP) {
			return true;
		}
	}
	int king_delta[8] = { 1,-1,12,-12,13,-13,11,-11}; 
	for (int i = 0; i < 8; i++) {
		if (this->turn == white && board[index + king_delta[i]] == bK) {
			return true;
		}
		else if (this->turn == black && board[index + king_delta[i]] == wK) {
			return true;
		}
	}
	return false;
}
bool Position::diagonal_check(int index, const Position& position) {
	int delta[4] = { 13,-13,11,-11 };
	int temp = index;
	for (int i = 0; i < 4; i++) {
		temp += delta[i];
		while (board[temp] >= 0) {
			if (board[temp] != es) {
				if (eat_own_piece(index, temp)) {
					return false;
				}
				else {
					if ((board[temp] == bQ || board[temp] == bB) && board[index]==wK) {
						return true;
					}
					else if ((board[temp] == wQ || board[temp] == wB) && board[index]==bK) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool Position::horizontal_vertical_check(int index, const Position& p) {
	int delta[4] = { 1,-1,12,-12 };
	int temp = index;
	for (int i = 0; i < 4; i++) {
		temp += delta[i];
		while (temp >= 0) {
			if (board[temp] != es) {
				if (eat_own_piece(index, temp)) {
					return false;
				}
				else {
					if ((board[temp] == bQ || board[temp] == bR) && this->turn == white) {
						return true;
					}
					else if ((board[temp] == wQ || board[temp] == wR) && this->turn == black) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool Position::knight_check(int index, const Position& p) {
	int delta[8] = { 23,-23,14,-14,10,-10,25,-25 };
	if (this->turn == white) {
		for (int i = 0; i < 8; i++) {
			if (board[delta[i] + index] == bN) {
				return true;
			}
		}
		return false;
	}
	else if (this->turn == black) {
		for (int i = 0; i < 8; i++) {
			if (board[delta[i] + index] == wN) {
				return true;
			}
		}
		return false;
	}
}