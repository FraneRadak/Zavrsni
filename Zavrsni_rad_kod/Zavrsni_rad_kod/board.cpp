#include "board.hpp"
Position::Position() {
	this->Board_index = new int* [8]; //(int*)malloc(8*sizeof(int*))
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
	for (int i = 2; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			cout <<piecelist[board[i][j]] << " ";
		}
		cout << endl;
	}
}
void Position::move(int piece , int square) {
}


