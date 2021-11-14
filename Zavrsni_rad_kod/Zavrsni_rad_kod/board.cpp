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
Move::Move(int piece, int current_position, int position) {
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
			cout << piecelist[board[i]] << " ";
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
		if (((m.position - m.current_position == -12) && (m.position == es)) || (((m.current_position >= 98) || (m.current_position <= 105)) && (m.position - m.current_position == -24)) || (((m.position - m.current_position == -13) || (m.position - m.current_position == -11)) && (board[m.position] > 0)) && board[m.position] >= 0) {
			return true;
		}
	}
	else if (m.piece == bP) {
		if (((m.position - m.current_position == 12) && (m.position == es)) || (((m.current_position >= 38) || (m.current_position <= 45)) && (m.position - m.current_position == 24)) || (((m.position - m.current_position == 13) || (m.position - m.current_position == 11)) && (board[m.position] > 0)) && board[m.position] >= 0) {
			return true;
		}
	}
	return false;
}
//potrebno modificirati

void Position::forward_backward_movement(Move* possible_moves, int& move_counter, int i) {
	int temp = i;
	while (board[temp] >= 0) {
		temp += 12;
		if (board[temp] < 0)
			break;
		//ako naidemo na figuru iste boje nemozemo je pojest
		if (((board[i] < 6 && board[temp] < 6) || (board[i] > 6 && board[temp] > 6)) && board[temp] != es) {
			break;
		}
		Move m(board[i], i, temp);
		if (board[temp] != es) {
			m.eaten_piece = board[temp];
		}
		possible_moves[move_counter] = m;
		move_counter++;
	}
	temp = i;
	while (board[temp] >= 0) {
		temp -= 12;
		if (board[temp] < 0)
			break;
		//ako naidemo na figuru iste boje nemozemo je pojest
		if (((board[i] < 6 && board[temp] < 6) || (board[i] > 6 && board[temp] > 6)) && board[temp] != es) {
			break;
		}
		Move m(board[i], i, temp);
		if (board[temp] != es) {
			m.eaten_piece = board[temp];
		}
		possible_moves[move_counter] = m;
		move_counter++;
	}

}
void Position::nurse_movement(Move* possible_moves, int& move_counter, int i) {
	if (board[i + 23] > 0 && ((board[i] < 6 && board[i + 23]>6) || (board[i] > 6 && board[i + 23] < 6) || board[i + 23] == es)) {
		Move m(board[i], i, i + 23);
		if (board[i + 23] != es)
			m.eaten_piece = board[i + 23];
		possible_moves[move_counter] = m;
		move_counter++;
	}
	if (board[i - 23] > 0 && ((board[i] < 6 && board[i - 23]>6) || (board[i] > 6 && board[i - 23] < 6) || board[i - 23] == es)) {
		Move m(board[i], i, i - 23);
		if (board[i - 23] != es)
			m.eaten_piece = board[i - 23];
		possible_moves[move_counter] = m;
		move_counter++;
	}
	if (board[i + 14] > 0 && ((board[i] < 6 && board[i + 14]>6) || (board[i] > 6 && board[i + 14] < 6) || board[i + 14] == es)) {
		Move m(board[i], i, i + 14);
		if (board[i + 14] != es)
			m.eaten_piece = board[i + 14];
		possible_moves[move_counter] = m;
		move_counter++;
	}
	if (board[i - 14] > 0 && ((board[i] < 6 && board[i - 14]>6) || (board[i] > 6 && board[i - 14] < 6) || board[i - 14] == es)) {
		Move m(board[i], i, i - 14);
		if (board[i -14] != es)
			m.eaten_piece = board[i -14];
		possible_moves[move_counter] = m;
		move_counter++;
	}
	if (board[i + 10] > 0 && ((board[i] < 6 && board[i + 10]>6) || (board[i] > 6 && board[i + 10] < 6) || board[i + 10] == es)) {
		Move m(board[i], i, i + 10);
		if (board[i + 10] != es)
			m.eaten_piece = board[i + 10];
		possible_moves[move_counter] = m;
		move_counter++;
	}
	if (board[i - 10] > 0 && ((board[i] < 6 && board[i - 10]>6) || (board[i] > 6 && board[i - 10] < 6) || board[i - 10] == es)) {
		Move m(board[i], i, i - 10);
		if (board[i - 10] != es)
			m.eaten_piece = board[i - 10];
		possible_moves[move_counter] = m;
		move_counter++;
	}
	if (board[i + 25] > 0 && ((board[i] < 6 && board[i + 25]>6) || (board[i] > 6 && board[i + 25] < 6) || board[i + 25] == es)) {
		Move m(board[i], i, i + 25);
		if (board[i + 25] != es)
			m.eaten_piece = board[i + 25];
		possible_moves[move_counter] = m;
		move_counter++;
	}
	if (board[i - 25] > 0 && ((board[i] < 6 && board[i - 25]>6) || (board[i] > 6 && board[i - 25] < 6) || board[i - 25] == es)) {
		Move m(board[i], i, i - 25);
		if (board[i - 25] != es)
			m.eaten_piece = board[i - 25];
		possible_moves[move_counter] = m;
		move_counter++;
	}
}
void Position::horizontal_movement(Move* possible_moves, int& move_counter, int i) {
	int temp = i;
	int current_row;
	int current_col;
	transform(temp, current_row, current_col);
	while (board[anti_transform(current_row, current_col)] >= 0) {
		current_col += 1;
		int temp = anti_transform(current_row, current_col);
		if (board[temp] < 0)
			break;
		//ako naidemo na figuru iste boje nemozemo je pojest
		if (((board[i] < 6 && board[temp] < 6) || (board[i] > 6 && board[temp] > 6)) && board[temp] != es) {
			break;
		}
		Move m(board[i], i, temp);
		if (board[temp] != es) {
			m.eaten_piece = board[temp];
		}
		possible_moves[move_counter] = m;
		move_counter++;
	}
	temp = i;
	transform(temp, current_row, current_col);
	while (board[anti_transform(current_row, current_col)] >= 0) {
		current_col -= 1;
		int temp = anti_transform(current_row, current_col);
		if (board[temp] < 0)
			break;
		//ako naidemo na figuru iste boje nemozemo je pojest
		if (((board[i] < 6 && board[temp] < 6) || (board[i] > 6 && board[temp] > 6)) && board[temp] != es) {
			break;
		}
		Move m(board[i], i, temp);
		if (board[temp] != es) {
			m.eaten_piece = board[temp];
		}
		possible_moves[move_counter] = m;
		move_counter++;
	}
}
void Position::diagonal_movement(Move* possible_moves, int& move_counter, int i) {
	int temp = i;
	while (board[temp] >= 0) {
		temp += 13;
		if (board[temp] < 0)
			break;
		//ako naidemo na figuru iste boje ne mozemo je pojest
		if (((board[i] < 6 && board[temp] < 6) || (board[i] > 6 && board[temp] > 6)) && board[temp] != es) {
			break;
		}
		Move m(board[i], i, temp);
		if (board[temp] != es) {
			m.eaten_piece = board[temp];
		}
		possible_moves[move_counter] = m;
		move_counter++;
	}
	temp = i;
	while (board[temp] >= 0) {
		temp += 11;
		if (board[temp] < 0)
			break;
		//ako naidemo na figuru iste boje nemozemo je pojest
		if (((board[i] < 6 && board[temp] < 6) || (board[i] > 6 && board[temp] > 6)) && board[temp] != es) {
			break;
		}
		Move m(board[i], i, temp);
		if (board[temp] != es) {
			m.eaten_piece = board[temp];
		}
		possible_moves[move_counter] = m;
		move_counter++;
	}
	temp = i;
	while (board[temp] >= 0) {
		temp -= 13;
		if (board[temp] < 0)
			break;
		//ako naidemo na figuru iste boje nemozemo je pojest
		if (((board[i] < 6 && board[temp] < 6) || (board[i] > 6 && board[temp] > 6)) && board[temp] != es) {
			break;
		}
		Move m(board[i], i, temp);
		if (board[temp] != es) {
			m.eaten_piece = board[temp];
		}
		possible_moves[move_counter] = m;
		move_counter++;
	}
	temp = i;
	while (board[temp] >= 0) {
		temp -= 11;
		if (board[temp] < 0)
			break;
		//ako naidemo na figuru iste boje nemozemo je pojest
		if (((board[i] < 6 && board[temp] < 6) || (board[i] > 6 && board[temp] > 6)) && board[temp] != es) {
			break;
		}
		Move m(board[i], i, temp);
		if (board[temp] != es) {
			m.eaten_piece = board[temp];
		}
		possible_moves[move_counter] = m;
		move_counter++;
	}
}
Move* Position::move_generator() {
	Move* possible_moves = new Move[255];
	int move_counter = 0;
	for (int i = 26; i <= 117; i++) {
		if (board[i] > 0) {
			int temp = i;
			if (board[i] == wB || board[i] == bB) {
				diagonal_movement(possible_moves, move_counter, i);
			}
			else if (board[i] == bQ || board[i] == wQ) {
				diagonal_movement(possible_moves, move_counter, i);
				forward_backward_movement(possible_moves, move_counter, i);
				horizontal_movement(possible_moves, move_counter, i);
			}
			else if (board[i] == wR || board[i] == bR) {
				forward_backward_movement(possible_moves, move_counter, i);
				horizontal_movement(possible_moves, move_counter, i);
			}
			else if (board[i] == wN || board[i] == bN) {
				nurse_movement(possible_moves, move_counter, i);
			}
			else if (board[i] == wP || board[i] == bP) {

			}

		}
	}
	return possible_moves;
}

void Position::move(Move& m) {


}

