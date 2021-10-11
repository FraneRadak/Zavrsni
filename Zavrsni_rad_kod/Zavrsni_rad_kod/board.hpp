#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
enum{es,wP,bP,wR,bR,wN,bN,wB,bB,wQ,bQ,wK,bK};

class Move {
public:
	int piece;
	int position;
	int eaten_piece=0;
	int current_position;

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
	string piecelist[13] = { "es","wP","bP","wR","bR","wN",
	"bN","wB","bB","wQ","bQ","wK","bK"};
public:
	Position();
	void printPosition();
	void move(Move&m);
};

