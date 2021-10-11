#include "board.hpp"
#include "exceptions.hpp"

//Vjerojatno nije potrebno , al nek stoji zasad 
Position::Position() {
	Board_index = new int* [8];
	for (int i = 0; i < 8; i++) {
		Board_index[i] = new int[8];
	};
	int square_counter = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Board_index[i][j] = square_counter;
			square_counter++;
		}
	}
}
void Position::printPosition() {
	int counter = 0;
	int startcounter = 0;
	int endcounter = 0;
	for (int i = 24; i < 120; i++) {
		if (counter > 1 && counter <= 9) {
			cout <<i << " ";
		}
		counter++;
		if (counter == 12) {
			cout << endl;
			counter = 0;
		}
	}
}
void Position::move(Move &m) {
	//skakac
	if ((m.piece == bN) || (m.piece == wN)){
		if ((m.position == m.current_position + 25) || (m.position == m.current_position - 25) || (m.position == m.current_position + 23) || (m.position == m.current_position - 23) || (m.position == m.current_position + 10) || (m.position == m.current_position - 10) || (m.position == m.current_position + 14) || (m.position == m.current_position - 14) && (board[m.position] >= 0)) {

			board[m.position] = m.piece;
			board[m.current_position] = es;
			if (board[m.position] != 0) {
				m.eaten_piece = board[m.position];
			}

		}
		else {
			throw NurseException();
		}
	}
	//lovac
	else if ((m.piece == wB) || (m.piece == bB)) {
		if ((m.position - m.current_position == 13) || (m.position - m.current_position == -13) || (m.position - m.current_position == 11) || (m.position - m.current_position == -11)){
			board[m.position] = m.piece;
				board[m.current_position] = es;
				if (board[m.position] != 0) {
					m.eaten_piece = board[m.position];
				}
		}
	}
	//top




}


