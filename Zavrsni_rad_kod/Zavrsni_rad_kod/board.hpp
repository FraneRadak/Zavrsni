#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#pragma once

#define white true
#define black false
#define nn -1000

//#include "PositionStack.hpp"
using namespace std;
typedef unsigned long long int Long;
enum{es,wP,wR,wB,wN,wQ,wK,bP,bR,bB,bN,bQ,bK};

class Move {
public:
	int piece=0;
	int position=0;
	int eaten_piece = 0;
	int current_position=0;
	bool en_passant=false;
	Move();
	Move(int piece, int current_position, int position);
	void setPosition(int x);
	void setCurrent_Position(int x);
	void setPiece(int x);
	void setEaten_Piece(int x = 0);
	void setEnPassant();
};

class Position {
private:
	int white_enpassant_field=0;
	int black_enpassant_field = 0;
	bool enpassant_flag = false;
	bool turn=white;
	bool check = false;
	bool check_mate = false;
	int piece_counter=32;
	int board[144] = {
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,bR,es,es,es,bK,es,es,bR,nn,nn,
	nn,nn,bP,es,bP,bP,bQ,bP,bB,es,nn,nn,
	nn,nn,bB,bN,es,es,bP,bN,bP,es,nn,nn,
	nn,nn,es,es,es,wP,wN,es,es,es,nn,nn,
	nn,nn,es,bP,es,es,wP,es,es,es,nn,nn,
	nn,nn,es,es,wN,es,es,wQ,es,bP,nn,nn,
	nn,nn,wP,wP,wP,wB,wB,wP,wP,wP,nn,nn,
	nn,nn,wR,es,es,es,wK,es,es,wR,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn
	};
	bool white_small_castle = true;
	bool white_big_castle = true;
	bool black_small_castle = true;
	bool black_big_castle = true;
	void diagonal_movement(Move* possible_moves, int& move_counter, int i);
	void forward_backward_movement(Move* possible_moves, int& move_counter, int i);
	void horizontal_movement(Move* possible_moves, int& move_counter, int i);
	void knight_movement(Move* possible_moves, int& move_counter, int i);
	void pawn_movement(Move* possible_moves, int& move_counter, int i);
	bool promotion_check(Move* possible_moves, int& move_counter, int i);
	void king_movement(Move* possible_moves, int& move_counter, int i);
	bool eat_own_piece(int current_index, int move_index);
	void castle_crusher(Move& m);
	void move_generator(int& move_counter,Move* possible_moves);
	void print_possible_moves(const Move* moves, const int& move_counter);
	bool is_legal(const Move& m);
	int search_for_piece(int piece,const Position&position);
	bool diagonal_check(int king_index);
	bool horizontal_vertical_check(int king_index);
	bool knight_check(int king_index);
	bool is_attacked(int index);
	bool pawn_check(int king_index);
	//void set_enpassant(int index);
	//bool check_enpassant(int index,int& enpassant_index);
	//------------------------------------------------
	void openNode(ofstream& file);
	void closeNode(ofstream& file);
	void writeContent(ofstream& file, int num_of_moves, Move* moves,Move lastMove);
	string writeXmlMoves(Move* moves, int number);
	string pieceToFENletter(int i);
	int FENLetterToPiece(char c);
public:
	Position();
	Long perft(int depth,ofstream*file,Move&lastMove);
	void make_move(const Move& m);
	void printPosition();
	void move();
	void undo_move();
	string toFEN();
	void setFromFEN(string FEN);
};
/*
//perft position 1 - start position
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
//perft position 2
int board[144] = {
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,bR,es,es,es,bK,es,es,bR,nn,nn,
	nn,nn,bP,es,bP,bP,es,bP,bB,es,nn,nn,
	nn,nn,bB,bN,es,es,bP,bN,bP,es,nn,nn,
	nn,nn,es,es,es,wP,wN,es,es,es,nn,nn,
	nn,nn,es,bP,es,es,wP,es,es,es,nn,nn,
	nn,nn,es,es,wN,es,es,wQ,es,bP,nn,nn,
	nn,nn,wP,wP,wP,wB,wB,wP,wP,wP,nn,nn,
	nn,nn,wR,es,es,es,wK,es,es,wR,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,
	nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn,nn
};
*/