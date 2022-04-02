
#include "board.hpp"
#include "PositionStack.hpp"
#include "const.hpp"
void Position::king_movement(Move* possible_moves, int& move_counter, int i) {
	for (int j = 0; j < 10; j++) {
		if (board[i + king_delta[j]] < 0) {
			continue;
		}
		//rohada
		if (king_delta[j] == 2 || king_delta[j] == -2) {
			//mala rohada
			if (king_delta[j] == 2) {
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
					if (board[i] == wK) {
						if (!is_attacked(i + 1) && !is_attacked(i + 2) && board[i + 3] == wR) {
							//Move m(board[i], i, i + king_delta[j]);
							possible_moves[move_counter].setPiece(board[i]);
							possible_moves[move_counter].setCurrent_Position(i);
							possible_moves[move_counter].setPosition(i + king_delta[j]);
							move_counter++;
						}
					}
					else {
						if (!is_attacked(i + 1) && !is_attacked(i + 2) && board[i + 3] == bR) {
							//Move m(board[i], i, i + king_delta[j]);
							possible_moves[move_counter].setPiece(board[i]);
							possible_moves[move_counter].setCurrent_Position(i);
							possible_moves[move_counter].setPosition(i + king_delta[j]);
							move_counter++;
						}
					}
				}
			}
			//velika rohada
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
					if (board[i] == wK) {
						if (!is_attacked(i - 1) && !is_attacked(i - 2) && board[i - 4] == wR) {
							//Move m(board[i], i, i + king_delta[j]);
							possible_moves[move_counter].setPiece(board[i]);
							possible_moves[move_counter].setCurrent_Position(i);
							possible_moves[move_counter].setPosition(i + king_delta[j]);
							move_counter++;
						}
					}
					else {
						if (!is_attacked(i - 1) && !is_attacked(i - 2) && board[i - 4] == bR) {
							//Move m(board[i], i, i + king_delta[j]);
							possible_moves[move_counter].setPiece(board[i]);
							possible_moves[move_counter].setCurrent_Position(i);
							possible_moves[move_counter].setPosition(i + king_delta[j]);
							move_counter++;
						}
					}
				}

			}
		}
		else {
			if (!(eat_own_piece(i, i + king_delta[j]) && board[i + king_delta[j]] >= 0)&& !is_attacked(i+ king_delta[j])) {
				//Move m(board[i], i, i + king_delta[j]);
				possible_moves[move_counter].setPiece(board[i]);
				possible_moves[move_counter].setCurrent_Position(i);
				possible_moves[move_counter].setPosition(i + king_delta[j]);
				if (!is_attacked(i + king_delta[j])) {
					if (board[i + king_delta[j]] != es) {
						//m.eaten_piece = board[i + king_delta[j]];
						possible_moves[move_counter].setEaten_Piece(i + king_delta[j]);
					}
					move_counter++;
				}
			}
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
				possible_moves[move_counter].setCurrent_Position(m.current_position);
				possible_moves[move_counter].setPosition(m.position);
				possible_moves[move_counter].setPiece(m.piece);
				move_counter++;
			}
		}
		//pjesak s pocetnog polja moze ici 2 polja naprijed
		if (i >= 98 && i <= 105) {
			if (board[i - 24] == es && board[i - 12] == es) {
				Move m(board[i], i, i - 24);
				if (is_legal(m)) {
					white_enpassant_field = i - 12;
					possible_moves[move_counter].setCurrent_Position(m.current_position);
					possible_moves[move_counter].setPosition(m.position);
					possible_moves[move_counter].setPiece(m.piece);
					move_counter++;
				}
			}
		}
			// u slucaju da jedemo figuru
			if (board[i - 13] > 6) {
				Move m(board[i], i, i - 13);
				if (is_legal(m)) {
					possible_moves[move_counter].setCurrent_Position(m.current_position);
					possible_moves[move_counter].setPosition(m.position);
					possible_moves[move_counter].setPiece(m.piece);
					possible_moves[move_counter].setEaten_Piece(board[i - 13]);
					move_counter++;

				}
			}
			if (board[i - 11] > 6) {
				Move m(board[i], i, i - 11);
				if (is_legal(m)) {
					possible_moves[move_counter].setCurrent_Position(m.current_position);
					possible_moves[move_counter].setPosition(m.position);
					possible_moves[move_counter].setPiece(m.piece);
					possible_moves[move_counter].setEaten_Piece(board[i - 11]);
					move_counter++;
				}
			}
			//en-passant
			if (this->black_enpassant_field!=0 &&(board[i + 1] == bP || board[i - 1] == bP)) {
				if (black_enpassant_field == i - 11) {
					Move m(board[i], i, i - 11);
					if (is_legal(m)) {
						possible_moves[move_counter].setCurrent_Position(m.current_position);
						possible_moves[move_counter].setPosition(m.position);
						possible_moves[move_counter].setPiece(m.piece);
						possible_moves[move_counter].setEaten_Piece(bP);
						possible_moves[move_counter].setEnPassant();
						move_counter++;
					}
				}
				else if (black_enpassant_field == i - 13) {
					Move m(board[i], i, i - 13);
					if (is_legal(m)) {
						possible_moves[move_counter].setCurrent_Position(m.current_position);
						possible_moves[move_counter].setPosition(m.position);
						possible_moves[move_counter].setPiece(m.piece);
						possible_moves[move_counter].setEaten_Piece(bP);
						possible_moves[move_counter].setEnPassant();
						move_counter++;
					}
				}
			}
		}
	if (board[i] == bP) {
		//kretanje jedno polje naprijed
		if (board[i + 12] == es) {
			Move m(board[i], i, i + 12);
			if (is_legal(m)) {
				possible_moves[move_counter].setCurrent_Position(m.current_position);
				possible_moves[move_counter].setPosition(m.position);
				possible_moves[move_counter].setPiece(m.piece);
				move_counter++;
			}
		}
		//pjesak s pocetnog polja moze ici 2 polja naprijed
		if (i >= 38 && i <= 45) {
			if (board[i + 24] == es && board[i + 12] == es) {
				Move m(board[i], i, i + 24);
				if (is_legal(m)) {
					black_enpassant_field = i + 12;
					possible_moves[move_counter].setCurrent_Position(m.current_position);
					possible_moves[move_counter].setPosition(m.position);
					possible_moves[move_counter].setPiece(m.piece);
					move_counter++;
				}
			}
		}
		// u slucaju da jedemo figuru
		if (board[i + 13] < 6 && board[i + 13] >0) {
			Move m(board[i], i, i + 13);
			if (is_legal(m)) {
				possible_moves[move_counter].setCurrent_Position(m.current_position);
				possible_moves[move_counter].setPosition(m.position);
				possible_moves[move_counter].setPiece(m.piece);
				possible_moves[move_counter].setEaten_Piece(board[i + 13]);
				move_counter++;
			}
		}
		if (board[i + 11] < 6 && board[i + 11] >0) {
			Move m(board[i], i, i + 11);
			if (is_legal(m)) {
				possible_moves[move_counter].setCurrent_Position(m.current_position);
				possible_moves[move_counter].setPosition(m.position);
				possible_moves[move_counter].setPiece(m.piece);
				possible_moves[move_counter].setEaten_Piece(board[i + 11]);
				move_counter++;
			}
		}
		//en passant
		if (this->white_enpassant_field != 0 && (board[i + 1] == wP || board[i - 1] == wP)) {
			if (white_enpassant_field == i + 11) {
				Move m(board[i], i, i + 11);
				if (is_legal(m)) {
					possible_moves[move_counter].setCurrent_Position(m.current_position);
					possible_moves[move_counter].setPosition(m.position);
					possible_moves[move_counter].setPiece(m.piece);
					possible_moves[move_counter].setEaten_Piece(wP);
					possible_moves[move_counter].setEnPassant();
					move_counter++;
				}
			}
			else if (white_enpassant_field == i + 13) {
				Move m(board[i], i, i + 13);
				if (is_legal(m)) {
					possible_moves[move_counter].setCurrent_Position(m.current_position);
					possible_moves[move_counter].setPosition(m.position);
					possible_moves[move_counter].setPiece(m.piece);
					possible_moves[move_counter].setEaten_Piece(wP);
					possible_moves[move_counter].setEnPassant();
					move_counter++;
				}
			}
		}
	}
}

void Position::forward_backward_movement(Move* possible_moves, int& move_counter, int i) {
	for (int j = 0; j < 2; j++) {
		int temp = i;
		while (board[temp] >= 0) {
			temp += forward_backward_delta[j];
			if (board[temp] < 0)
				break;
			//ako naidemo na figuru iste boje nemozemo je pojest
			if (eat_own_piece(i, temp)) {
				break;
			}
			Move m(board[i], i, temp);
			if (is_legal(m)) {
				possible_moves[move_counter].setCurrent_Position(m.current_position);
				possible_moves[move_counter].setPosition(m.position);
				possible_moves[move_counter].setPiece(m.piece);
				move_counter++;
				if (board[temp] != es) {
					possible_moves[move_counter-1].eaten_piece = board[temp];
					break;
				}
			}
		}
	}
}

void Position::knight_movement(Move* possible_moves, int& move_counter, int i) {
	for (int j = 0; j < 8; j++) {
		if ((!(eat_own_piece(i, i + knight_delta[j]))) && board[i + knight_delta[j]] >= 0) {
			Move m(board[i], i, i + knight_delta[j]);
			if (is_legal(m)) {
				if (board[i + knight_delta[j]] != es)
					m.eaten_piece = board[i + knight_delta[j]];
				possible_moves[move_counter].setCurrent_Position(m.current_position);
				possible_moves[move_counter].setPosition(m.position);
				possible_moves[move_counter].setPiece(m.piece);
				possible_moves[move_counter].setEaten_Piece(board[i + 11]);
				move_counter++;
			}
		}
	}
}
void Position::horizontal_movement(Move* possible_moves, int& move_counter, int i) {
	for (int j = 0; j < 2; j++) {
		int temp = i;
		while (board[temp] >= 0) {
			temp += horizontal_delta[j];
			if (board[temp] < 0) {
				break;
			}
			if (eat_own_piece(i, temp)) {
				break;
			}
			Move m(board[i], i, temp);
			if (is_legal(m)) {
				possible_moves[move_counter].setCurrent_Position(m.current_position);
				possible_moves[move_counter].setPosition(m.position);
				possible_moves[move_counter].setPiece(m.piece);
				move_counter++;
				if (board[temp] != es) {
					possible_moves[move_counter-1].eaten_piece = board[temp];
					break;
				}
			}
		}
	}
}
void Position::diagonal_movement(Move* possible_moves, int& move_counter, int i) {
	for (int j = 0; j < 4; j++) {
		int temp = i;
		while (board[temp] >= 0) {
			temp += diagonal_delta[j];
			if (board[temp] < 0)
				break;
			//ako naidemo na figuru iste boje ne mozemo je pojest
			if (eat_own_piece(i, temp)) {
				break;
			}
			Move m(board[i], i, temp);
			if (is_legal(m)) {
				possible_moves[move_counter].setCurrent_Position(m.current_position);
				possible_moves[move_counter].setPosition(m.position);
				possible_moves[move_counter].setPiece(m.piece);
				move_counter++;
				if (board[temp] != es) {
					possible_moves[move_counter-1].eaten_piece = board[temp];
					break;
				}
			}
		}
	}
}

