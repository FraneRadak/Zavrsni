#include "board.hpp"
#include "PositionStack.hpp"

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

void Position::print_possible_moves(const Move* moves, const int& move_counter) {
	for (int i = 0; i < move_counter; i++) {
		cout << "Move " << i << ": " << endl;
		cout << "with piece " << piecelist[moves[i].piece] << endl;
		cout << "from square " << square_list[moves[i].current_position] << endl;
		cout << "to square " << square_list[moves[i].position] << endl;
		cout << endl;
	}
	cout << "Total moves: " << move_counter << endl;;
}