#include "board.hpp"
#include "PositionStack.hpp"
#include "const.hpp"
bool Position::is_legal(const Move& m) {
	Position pos = *this;
	pos.make_move(m);
	int king_index = 0;
	if (m.piece < 6) {
		king_index = search_for_piece(wK, pos);
	}
	else if (m.piece > 6) {
		king_index = search_for_piece(bK, pos);
	}
	Position temp = stack->pop();
	pos.turn = !pos.turn;
	if (pos.diagonal_check(king_index) || pos.horizontal_vertical_check(king_index) || pos.knight_check(king_index) || pos.pawn_check(king_index)) {
		return true;//
	}
	return true;
}

bool Position::is_attacked(int index) {
	for (int i = 0; i < 4; i++) {
		int temp = index;
		while (board[temp] >= 0) {
			temp += diagonal_delta[i];
			if (board[temp] < 0 || (this->turn==white && board[temp]<wK) || (this->turn==black && board[temp]>bP)) {
				break;
			}
			if (this->turn == white && board[temp] <= 6) {
				break;
			}
			else if (this->turn == black && board[temp] > 6) {
				break;
			}
			else if (this->turn == white && (board[temp] == bB || board[temp] == bQ)) {
				return true;
			}
			else if (this->turn == black && (board[temp] == wB || board[temp] == wQ)) {
				return true;
			}

		}
	}
	for (int i = 0; i < 4; i++) {
		int temp = index;
		while (board[temp] >= 0) {
			if (board[temp] < 0) {
				break;
			}
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
	for (int i = 0; i < 8; i++) {
		if (this->turn == white && board[index + king_delta_light[i]] == bK) {
			return true;
		}
		else if (this->turn == black && board[index + king_delta_light[i]] == wK) {
			return true;
		}
	}
	return false;
}
bool Position::diagonal_check(int index) {
	for (int i = 0; i < 4; i++) {
		int temp = index;
		while (board[temp] >= 0) {
			temp += diagonal_delta[i];
			if (board[temp] != es) {
				if (eat_own_piece(index, temp)) {
					break;
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
bool Position::horizontal_vertical_check(int index) {
	for (int i = 0; i < 4; i++) {
		int temp = index;
		while (temp >= 0) {
			temp += horizontal_vertical_delta[i];
			if (board[temp] != es) {
				if (eat_own_piece(index, temp)) {
					break;
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
bool Position::knight_check(int index) {
	if (this->turn == white) {
		for (int i = 0; i < 8; i++) {
			if (board[knight_delta[i] + index] == bN) {
				return true;
			}
		}
		return false;
	}
	else if (this->turn == black) {
		for (int i = 0; i < 8; i++) {
			if (board[knight_delta[i] + index] == wN) {
				return true;
			}
		}
		return false;
	}
}
bool Position::pawn_check(int king_index) {
	if (this->turn == black) {
		if (board[king_index + 11] == wP || board[king_index + 13] == wP) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (this->turn == white) {
		if (board[king_index - 11] == bP || board[king_index - 13] == bP) {
			return true;
		}
		else {
			return false;
		}
	}
}