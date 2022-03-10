#include "board.hpp"

string Position::toFEN() {
	string FEN = "";
	for (int i = 26; i < 122; i+=12) {
		int empty_square_counter = 0;
		int j = 0;
		while (j < 8) {
			if (board[i + j] == 0) {
				while (board[i + j] == 0) {
					empty_square_counter++;
					j++;
					if (j == 8) {
						FEN += to_string(empty_square_counter);
						empty_square_counter = 0;
						FEN += "/";
						break;
					}
				}
				if (j == 8) {
					break;
				}
				FEN += to_string(empty_square_counter);
				empty_square_counter = 0;
			}
			else {
				FEN += pieceToFENletter(i + j);
				j++;
				if (j == 8) {
					FEN += "/";
					break;
				}
			}
		}
	}
	FEN.pop_back();
	FEN += " ";
	if (this->turn == white) {
		FEN += "w";
	}
	if (this->turn == black) {
		FEN += "b";
	}
	FEN += " ";
	if (this->white_small_castle) {
		FEN += "K";
	}
	if (this->white_big_castle) {
		FEN += "Q";
	}
	if (this->black_small_castle) {
		FEN += "k";
	}
	if (this->black_big_castle) {
		FEN += "q";
	}
	FEN += " ";
	FEN += "-";
	FEN += " ";
	FEN += "0";
	FEN += " ";
	FEN += "0";
	return FEN;
}