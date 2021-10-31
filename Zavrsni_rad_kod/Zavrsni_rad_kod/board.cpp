#include "board.hpp"
#include "exceptions.hpp"

//Vjerojatno nije potrebno , al nek stoji zasad 
Position::Position() {
	Board_index = new int* [12];
	for (int i = 0; i < 12; i++) {
		Board_index[i] = new int[12];
	};
	int square_counter = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			Board_index[i][j] = square_counter;
			square_counter++;
		}
	}
}
Move::Move(int piece, int current_position, int position){
	this->piece = piece;
	this->current_position = current_position;
	this->position = position;
}
void Position::printPosition() {
	int counter = 0;
	int startcounter = 0;
	int endcounter = 0;
	for (int i = 24; i < 120; i++) {
		if (counter > 1 && counter <= 9) {
			cout<<piecelist[board[i]] << " ";
		}
		counter++;
		if (counter == 12) {
			cout << endl;
			counter = 0;
		}
	}
}
bool Position::pawn_move_check(Move& m) {

	if (m.piece == wP) {
		if (((m.position - m.current_position == -12) && (m.position == es)) || (((m.current_position >= 98) || (m.current_position <= 105)) && (m.position - m.current_position == -24)) || (((m.position - m.current_position == -13) || (m.position - m.current_position == -11)) && (board[m.position] > 0)) && board[m.position]>=0) {
			return true;
		}
	}
	else if (m.piece == bP) {
		if (((m.position - m.current_position == 12) && (m.position==es)) || (((m.current_position >= 38) || (m.current_position <= 45)) && (m.position - m.current_position == 24)) || (((m.position - m.current_position == 13) || (m.position - m.current_position == 11)) && (board[m.position] > 0))&& board[m.position]>=0) {
			return true;
		}
	}
	return false;
}
bool Position::castle_check(Move& m) {
	if (!(((m.piece == wK) && (board[114] == wK)) || ((m.piece == bK) && (board[30] == bK)))) {
		return;
	}
	//mala rohada
	if (m.position > m.current_position) {
		if (board[m.current_position + 3] != bR || board[m.current_position + 3] != wR) {
			return;
		}
		else {
			int temp = m.current_position;
			while (temp < m.position) {
				temp++;
				if (board[temp] != es)
					return false;
			}
			//treba dodati provjeru dali je već igran potez s kraljem i topom ! 
			//provjera saha 
			board[m.position] = m.piece;
			board[m.current_position] = es;
			board[m.position + 1] = board[m.current_position + 3];
			board[m.current_position + 3] = es;
			return true;
		}
	}
	else if (m.position < m.current_position) {
		if (board[m.current_position - 4] != bR || board[m.current_position - 4] != wR) {
			return;
		}
		else {
			int temp = m.position;
			while (temp < m.current_position) {
				temp++;
				if (board[temp] != es)
					return false;
			}
			//treba dodati provjeru dali je već igran potez s kraljem i topom ! 
			//provjera saha 
			board[m.position] = m.piece;
			board[m.current_position] = es;
			board[m.position - 1] = board[m.current_position - 4];
			board[m.current_position - 4] = es;
			return true;
		}
	}
}
bool Position::legality_check(Move& m) {
	//skakac
	if ((m.piece == bN) || (m.piece == wN)) {
		if (((m.position == m.current_position + 25) || (m.position == m.current_position - 25) || (m.position == m.current_position + 23) || (m.position == m.current_position - 23) || (m.position == m.current_position + 10) || (m.position == m.current_position - 10) || (m.position == m.current_position + 14) || (m.position == m.current_position - 14)) && (board[m.position] >= 0)) {
			return true;
		}
		else {
			return false;
		}
	}
	//lovac
	//lovac se krece po svim poljima koja su +-13 ili +-11 od njegovog trenutnog polozaja
	//sto znaci da razlika polja na koje zeli biti igram i trenutnog polja mora biti
	//djeljiva s 13 ili 11
	else if ((m.piece == wB) || (m.piece == bB)) {
		if ((((m.position - m.current_position) % 13 == 0) || ((m.position - m.current_position) % 11 == 0)) && board[m.position] >= 0 ) {
			return true;

		}
		else
			return false;
	}
	//top
	else if ((m.piece == wR) || (m.piece == bR)) {
		int current_row;
		int current_col;
		int move_row;
		int move_col;
		transform(m.position, move_row, move_col);
		transform(m.current_position, current_row, current_col);
		if (((m.position - m.current_position % 12 == 0) || (current_row == move_row)) && (board[m.position] >= 0)) {
			return true;
		}
		else
			return false();
	}
	//Dama
	else if ((m.piece == wQ) || (m.piece == bQ)) {
		int current_row;
		int current_col;
		int move_row;
		int move_col;
		transform(m.position, move_row, move_col);
		transform(m.current_position, current_row, current_col);
		if ((((m.position - m.current_position % 13 == 0) || (m.position - m.current_position % 11 == 0)) || (m.position - m.current_position % 12 == 0) || (current_row == move_row)) && (board[m.position] >= 0)) {
			return true;
		}
		else
			return false;
	}
	else if ((m.piece == wK) || (m.piece == bK)) {
		if ((m.position == m.current_position + 1) || (m.position == m.current_position - 1) || (m.position == m.current_position + 12) || (m.position == m.current_position - 12) || (m.position == m.current_position + 11) || (m.position == m.current_position - 11) || (m.position == m.current_position + 13) || (m.position == m.current_position - 13) && (board[m.position] >= 0)) {
			//Ovdje treba dodati provjeru dali je polje na koje kralj želi igrati pod šahom
			return true;
		}
		else
			return false;
	}
	else if ((m.piece == wP) || (m.piece == bP)) {
		if (pawn_move_check(m)) {
			return true;
		}
		else
			return false;

	}
}
bool Position::path_checker(Move& m) {

	// Ova funkcija provjerava dali je put od jednog do drugog polja slobodan...npr za lovca
	if ((m.piece != wP) && (m.piece != bP) && (m.piece != wK) && (m.piece != bK) && (m.piece != bN) && (m.piece != wN)) {
		//lovac
		if ((m.piece == wB) || (m.piece == bB)) {
			if ((m.position - m.current_position) % 13 == 0) {
				if (m.position > m.current_position) {
					int temp = m.current_position;
					while (temp < m.position) {
						temp += 13;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
					return true;
				}
				else if (m.position < m.current_position) {
					int temp = m.current_position;
					while (temp > m.position) {
						temp -= 13;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
					return true;
				}
			}
			else if ((m.position - m.current_position) % 11 == 0) {
				if (m.position > m.current_position) {
					int temp = m.current_position;
					while (temp < m.position) {
						temp += 11;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}
				if (m.position < m.current_position) {
					int temp = m.position;
					while (temp < m.current_position) {
						temp += 11;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}

			}
		}
		else if ((m.piece == bQ) || (m.piece == wQ)) {
			if ((m.position - m.current_position) % 13 == 0) {

				if (m.position > m.current_position) {
					int temp = m.current_position;
					while (temp < m.position) {
						temp += 13;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}
				else if (m.position < m.current_position) {
					int temp = m.position;
					while (temp < m.current_position) {
						temp += 13;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}
			}
			else if (m.position - m.current_position % 11 == 0) {
				if (m.position > m.current_position) {
					int temp = m.current_position;
					while (temp < m.position) {
						temp += 11;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}

				else if (m.position < m.current_position) {
					int temp = m.position;
					while (temp < m.current_position) {
						temp += 11;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}

			}
			else if (m.position - m.current_position % 12 == 0) {
				if (m.position > m.current_position) {
					int temp = m.current_position;
					while (temp < m.position) {
						temp += 12;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}
				else if (m.position < m.current_position) {
					int temp = m.position;
					while (temp < m.current_position) {
						temp += 12;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}
			}
			else {
				int current_row;
				int current_col;
				int move_row;
				int move_col;
				transform(m.position, move_row, move_col);
				transform(m.current_position, current_row, current_col);
				if (current_col < move_col) {
					int temp = current_col;
					while (temp < move_col) {
						temp++;
						if ((m.piece >= 1 && m.piece <= 6 && board[anti_transform(current_row, temp)] >= 1 && board[anti_transform(current_row, temp)] <= 6) || (m.piece > 6 && board[anti_transform(current_row, temp)] > 6)) {
							return false;
						}
					}
				}
				else if (current_col > move_col) {
					int temp = move_col;
					while (temp < current_col) {
						temp++;
						if ((m.piece >= 1 && m.piece <= 6 && board[anti_transform(current_row, temp)] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[anti_transform(current_row, temp)] > 6)) {
							return false;
						}
					}
				}
			}
		}
		else if ((m.piece == wR) || (m.piece == bR)) {
			if ((m.position - m.current_position % 12 == 0) && (board[m.position] >= 0)) {
				if (m.position > m.current_position) {
					int temp = m.current_position;
					while (temp < m.position) {
						temp += 12;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}
				else if (m.position < m.current_position) {
					int temp = m.position;
					while (temp < m.current_position) {
						temp += 12;
						if ((m.piece >= 1 && m.piece <= 6 && board[temp] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[temp] > 6)) {
							return false;
						}
					}
				}
			}
			else {
				int current_row;
				int current_col;
				int move_row;
				int move_col;
				transform(m.position, move_row, move_col);
				transform(m.current_position, current_row, current_col);
				if (current_col < move_col) {
					int temp = current_col;
					while (temp < move_col) {
						temp++;
						if ((m.piece >= 1 && m.piece <= 6 && board[anti_transform(current_row, temp)] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[anti_transform(current_row, temp)] > 6)) {
							return false;
						}
					}
				}
				else if (current_col > move_col) {
					int temp = move_col;
					while (temp < current_col) {
						temp++;
						if ((m.piece >= 1 && m.piece <= 6 && board[anti_transform(current_row, temp)] >= 1 && board[temp] <= 6) || (m.piece > 6 && board[anti_transform(current_row, temp)] > 6)) {
							return false;
						}
					}
				}

			}
		}
	}
		return true;
	}

	

void Position::move(Move& m) {
	if (castle_check(m)) {
		return;
	}
	if (legality_check(m)) {
		if (path_checker(m)) {
			 if (board[m.position] != es) {
				m.eaten_piece = board[m.position];
			}
			board[m.current_position] = es;
			board[m.position] = m.piece;
		}
	}
	else {
		cout << "Invalid move" << endl;
		return;
	}
}
/*
int Position::search_for_king(Move& m) {
	if ((m.piece == wB) || (m.piece == wR) || (m.piece == wN) || (m.piece == wQ) || (m.piece == wP)) {
		for (int i=26; i <= 117; i++) {
			if (board[i] == bK)
				return i;
		}
	}
	else{
		for (int i = 117; i >= 26; i--) {
			if (board[i] == wK)
				return i;
	}
	}
	return 0;
}
//Ne radi,trebam pomoc oko provjere saha 
void Position::is_check(Move& m) {
	int king_ind = search_for_king(m);
	Move temp(m.piece, m.position, king_ind);
	if (legality_check(temp) && path_checker(temp))
		check = true;
	else
		check = false;

}
*/

