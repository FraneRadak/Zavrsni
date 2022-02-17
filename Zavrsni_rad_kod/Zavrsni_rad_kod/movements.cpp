#include "board.hpp"
#include "PositionStack.hpp"
void Position::king_movement(Move* possible_moves, int& move_counter, int i) {
	int delta[10] = { 1,-1,12,-12,13,-13,11,-11,2,-2 };
	for (int j = 0; j < 8; j++) {
		//rohada
		if (delta[j] == 2 || delta[j] == -2) {
			//mala rohada
			if (delta[j] == 2) {
				if (board[i] == wK && !(white_small_castle)) {
					continue;
				}
				else if (board[i] == bK && !(black_small_castle)) {
					continue;
				}
				else if (board[i + 1] != es || board[i + 2] != es) {
					continue;
				}
				else {
					Move m(board[i], i, i + 2);
					possible_moves[move_counter] = m;
					move_counter++;
				}
			}
			else {
				if (board[i] == wK && !(white_big_castle)) {
					continue;
				}
				else if (board[i] == bK && !(black_big_castle)) {
					continue;
				}
				else if (board[i - 1] != es || board[i - 2] != es || board[i - 3] != es) {
					continue;
				}
				else {
					Move m(board[i], i, i - 2);
					possible_moves[move_counter] = m;
					move_counter++;
				}
			}
		}
		if (!eat_own_piece(i, i + delta[j]) && board[i + delta[j]] >= 0) {
			Move m(board[i], i, i + delta[j]);
			//treba dodati provjeru dali je polje tuceno od strane druge figure
			//tj jeli figura koju kralj zeli pojesti branjena
			if (board[i + delta[j]] != es) {
				//treba dodati provjeru
				m.eaten_piece = board[i + delta[j]];
			}
			possible_moves[move_counter] = m;
			move_counter++;
		}
	}
}
void Position::pawn_movement(Move* possible_moves, int& move_counter, int i) {
	int temp = i;
	if (board[i] == wP) {
		//kretanje jedno polje naprijed
		if (board[i - 12] == es) {
			Move m(board[i], i, i - 12);
			if (is_legal(m)) {
				possible_moves[move_counter] = m;
				move_counter++;
			}
		}
		//pjesak s pocetnog polja moze ici 2 polja naprijed
		if (i >= 98 && i <= 105) {
			if (board[i - 24] == es && board[i-12]==es) {
				Move m(board[i], i, i - 24);
				if (is_legal(m)) {
					possible_moves[move_counter] = m;
					move_counter++;
				}
			}
		}
		// u slucaju da jedemo figuru
		if (board[i - 13] > 6) {
			Move m(board[i], i, i - 13);
			if (is_legal(m)) {
				m.eaten_piece = board[i - 13];
				possible_moves[move_counter] = m;
				move_counter++;
			}
		}
		if (board[i - 11] > 6) {
			Move m(board[i], i, i - 11);
			if (is_legal(m)) {
				m.eaten_piece = board[i - 11];
				possible_moves[move_counter] = m;
				move_counter++;
			}
		}
		//treba dodati opciju za en-passant uzimanje
	}
	if (board[i] == bP) {
		//kretanje jedno polje naprijed
		if (board[i + 12] == es) {
			Move m(board[i], i, i + 12);
			if (is_legal(m)) {
				possible_moves[move_counter] = m;
				move_counter++;
			}
		}
		//pjesak s pocetnog polja moze ici 2 polja naprijed
		if (i >= 38 && i <= 45) {
			if (board[i + 24] == es && board[i+12]==es) {
				Move m(board[i], i, i + 24);
				if (is_legal(m)) {
					possible_moves[move_counter] = m;
					move_counter++;
				}
			}
		}
		// u slucaju da jedemo figuru
		if (board[i + 13] < 6 && board[i + 11] >0) {
			Move m(board[i], i, i + 13);
			if (is_legal(m)) {
				m.eaten_piece = board[i + 13];
				possible_moves[move_counter] = m;
				move_counter++;
			}
		}
		if (board[i + 11] < 6 && board[i + 11] >0) {
			Move m(board[i], i, i + 11);
			if (is_legal(m)) {
				m.eaten_piece = board[i + 11];
				possible_moves[move_counter] = m;
				move_counter++;
			}
		}
		//treba dodati opciju za en-passant uzimanje
	}
}

void Position::forward_backward_movement(Move* possible_moves, int& move_counter, int i) {
	int delta[2] = { 12,-12 };
	for (int j = 0; j < 2; j++) {
		int temp = i;
		while (board[temp] >= 0) {
			temp += delta[j];
			if (board[temp] < 0)
				break;
			//ako naidemo na figuru iste boje nemozemo je pojest
			if (eat_own_piece(i, temp)) {
				break;
			}
			Move m(board[i], i, temp);
			if (is_legal(m)) {
				possible_moves[move_counter] = m;
				move_counter++;
				if (board[temp] != es) {
					possible_moves[move_counter - 1].eaten_piece = board[temp];
					break;
				}
			}
		}
	}
}

void Position::knight_movement(Move* possible_moves, int& move_counter, int i) {
	int delta[8] = { 23,-23,14,-14,10,-10,25,-25 };
	for (int j = 0; j < 8; j++) {
		if ((!(eat_own_piece(i, i + delta[j]))) && board[i + delta[j]] >= 0) {
			Move m(board[i], i, i + delta[j]);
			if (is_legal(m)) {
				if (board[i + delta[j]] != es)
					m.eaten_piece = board[i + delta[j]];
				possible_moves[move_counter] = m;
				move_counter++;
			}
		}
	}
}
void Position::horizontal_movement(Move* possible_moves, int& move_counter, int i) {
	int delta[2] = { 1,-1 };
	for (int j = 0; j < 2; j++) {
		int temp = i;
		while (board[temp] >= 0) {
			temp += delta[j];
			if (board[temp] < 0) {
				break;
			}
			if (eat_own_piece(i, temp)) {
				break;
			}
			Move m(board[i], i, temp);
			if (is_legal(m)) {
				possible_moves[move_counter] = m;
				move_counter++;
				if (board[temp] != es) {
					possible_moves[move_counter - 1].eaten_piece = board[temp];
					break;
				}
			}
		}
	}
}
void Position::diagonal_movement(Move* possible_moves, int& move_counter, int i) {
	int delta[4] = { 11,-11,13,-13 };
	for (int j = 0; j < 4; j++) {
		int temp = i;
		while (board[temp] >= 0) {
			temp += delta[j];
			if (board[temp] < 0)
				break;
			//ako naidemo na figuru iste boje ne mozemo je pojest
			if (eat_own_piece(i, temp)) {
				break;
			}
			Move m(board[i], i, temp);
			if (is_legal(m)) {
				possible_moves[move_counter] = m;
				move_counter++;
				if (board[temp] != es) {
					possible_moves[move_counter - 1].eaten_piece = board[temp];
					break;
				}
			}
		}
	}
}