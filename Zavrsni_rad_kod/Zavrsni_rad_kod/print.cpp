#include "board.hpp"
#include "PositionStack.hpp"
#include "const.hpp"

void Position::openNode(ofstream& file) {
	file << "<Position>" << endl;
}
void Position::closeNode(ofstream& file) {
	file << "</Position>" << endl;
}
void Position::writeContent(ofstream& file,int num_of_moves,Move*moves,Move lastMove){
	file << "<FEN> " << this->toFEN() << " </FEN>" << endl;
	file << "<pos_num> " << pos_counter << " </pos_num>" << endl;
	file <<"<move_number> " << num_of_moves << " </move_number>" << endl;
	file << "<played_move>" << piecelist[lastMove.piece] << "_" << square_list[lastMove.current_position] << "-" << square_list[lastMove.position] << "</played_move>" << endl;
	file << "<moves>" << writeXmlMoves(moves, num_of_moves) << "</moves>" << endl;
}
string Position::writeXmlMoves(Move* moves, int number) {
	string temp;
	for (int i = 0; i < number; i++) {
		temp += to_string(i);
		temp += ".";
		temp += piecelist[moves[i].piece];
		temp += "_";
		temp += square_list[moves[i].current_position];
		temp += "-";
		temp += square_list[moves[i].position];
		temp += ",";
	}
	return temp;
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