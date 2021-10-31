#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
enum{es,wP,wR,wB,wN,wQ,wK,bP,bR,bB,bN,bQ,bK};

class Move {
public:
	int piece;
	int position;
	int eaten_piece = 0;
	int current_position;
	Move(int piece, int current_position, int position);


};
class Position {
private:
	bool check = false;
	bool check_mate = false;
	int nn = -1000;
	int** Board_index;
	int piece_counter=32;
	int board[144] = {
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,bR,bN,bB,bQ,bK,bB,bN,bR,nn,nn,
	nn,nn,bP,bP,bP,bP,bP,bP,bP,bP,nn,nn,
	nn,nn,es,es,es,es,es,es,es,es,nn,nn,
	nn,nn,es,es,es,es,es,es,es,es,nn,nn,
	nn,nn,es,es,es,es,es,es,es,es,nn,nn,
	nn,nn,es,es,es,es,es,es,es,es,nn,nn,
	nn,nn,wP,wP,wP,wP,wP,wP,wP,wP,nn,nn,
	nn,nn,wR,wN,wB,wQ,wK,wB,wN,wR,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn
	};

	//aktivna polja su od 26 do 117
	//enum { es, wP, wR, wB, wN, wQ, wK, bP, bR, bB, bN, bQ, bK };
	string piecelist[13] = { "es","wP","wR","wB","wN","wQ",
	"wK","bP","bR","bB","bN","bQ","bK"};
	void transform(int pos, int& br_red, int& br_st) {
		br_red = (int)pos / 100;
		br_st = pos - br_red * 12;
	}
	int anti_transform(int row, int col) {
		return row * 12 + col;
	}
	bool pawn_move_check(Move& m);
	bool legality_check(Move& m);
	bool path_checker(Move& m);
	int search_for_king(Move& m);
	bool castle_check(Move& m);
public:
	Position();
	void printPosition();
	void move(Move& m);
	void is_check(Move& m);
	
};


