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
int Position::pawn_move_check(Move& m) {

	if (m.piece == wP) {
		if (((m.position - m.current_position == -12) && (m.position==es)) || (((m.current_position >= 98) || (m.current_position <= 95)) && (m.position - m.current_position == -24)) || (((m.position - m.current_position == -13) || (m.position - m.current_position == -11)) && (board[m.position] > 0))) {
			return true;
		}
	}
	else if (m.piece = bP) {
		if (((m.position - m.current_position == 12) && (m.position==es)) || (((m.current_position >= 38) || (m.current_position <= 45)) && (m.position - m.current_position == 24)) || (((m.position - m.current_position == 13) || (m.position - m.current_position == 11)) && (board[m.position] > 0))) {
			return true;
		}
	}
}
void Position::move(Move &m) {
	//skakac
	if ((m.piece == bN) || (m.piece == wN)){
		if (((m.position == m.current_position + 25) || (m.position == m.current_position - 25) || (m.position == m.current_position + 23) || (m.position == m.current_position - 23) || (m.position == m.current_position + 10) || (m.position == m.current_position - 10) || (m.position == m.current_position + 14) || (m.position == m.current_position - 14)) && (board[m.position] >= 0)) {
			if (board[m.position] != 0) {
				m.eaten_piece = board[m.position];
			}
			board[m.position] = m.piece;
			board[m.current_position] = es;
			

		}
		else {
			throw NurseException();
		}
	}
	//lovac
	//lovac se krece po svim poljima koja su +-13 ili +-11 od njegovog trenutnog polozaja
	//sto znaci da razlika polja na koje zeli biti igram i trenutnog polja mora biti
	//djeljiva s 13 ili 11
	else if ((m.piece == wB) || (m.piece == bB)) {
		if (((m.position - m.current_position % 13 == 0) || (m.position - m.current_position % 11 == 0)) && board[m.position] >= 0) {
			if (board[m.position] != 0) {
				m.eaten_piece = board[m.position];
			}
			board[m.position] = m.piece;
			board[m.current_position] = es;

		}
		else
			throw BishopException();
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
			if (board[m.position] != 0) {
				m.eaten_piece = board[m.position];
			}
			board[m.position] == m.piece;
			board[m.current_position] = es;
		}
		else
			throw RookException();
	}
	else if ((m.piece == wQ) || (m.piece == bQ)) {
		int current_row;
		int current_col;
		int move_row;
		int move_col;
		transform(m.position, move_row, move_col);
		transform(m.current_position, current_row, current_col);
		if ((((m.position - m.current_position % 13 == 0) || (m.position - m.current_position % 11 == 0)) || (m.position - m.current_position % 12 == 0) || (current_row == move_row)) && (board[m.position] >= 0)) {
			if (board[m.position] != 0) {
				m.eaten_piece = board[m.position];
			}
			board[m.position] == m.piece;
			board[m.current_position] = es;
		}
		else
			throw QueenException();
	}
	else if ((m.piece == wK) || (m.piece == bK)) {
		if ((m.position == m.current_position + 1) || (m.position == m.current_position - 1) || (m.position == m.current_position + 12) || (m.position == m.current_position - 12) || (m.position == m.current_position + 11) || (m.position == m.current_position - 11) || (m.position == m.current_position + 13) || (m.position == m.current_position - 13) && (board[m.position] >= 0)) {
			//Ovdje treba dodati provjeru dali je polje na koje kralj želi igrati pod šahom
			if (board[m.position] != 0) {
				m.eaten_piece = board[m.position];
			}
			board[m.position] == m.piece;
			board[m.current_position] = es;
		}
		else
			throw KingException();
		}
	else if ((m.piece == wP) || (m.piece == bP)) {
		if (pawn_move_check(m)) {
			if (board[m.position] != 0) {
				m.eaten_piece = board[m.position];
			}
			board[m.position] = m.piece;
			board[m.current_position] = es;
			
		}
		else
			throw KingException();

		}
}




