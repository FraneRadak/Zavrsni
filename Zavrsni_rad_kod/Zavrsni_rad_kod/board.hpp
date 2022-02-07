#include <iostream>
#include <cstdlib>

#pragma once

#define white true
#define black false
#define nn -1000

//#include "PositionStack.hpp"
using namespace std;
enum{es,wP,wR,wB,wN,wQ,wK,bP,bR,bB,bN,bQ,bK};

class Move {
public:
	int piece=0;
	int position=0;
	int eaten_piece = 0;
	int current_position=0;
	Move(int piece, int current_position, int position);
	Move();
};

class Position {

private:
	bool turn=white;
	bool check = false;
	bool check_mate = false;
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
	string square_list[144] = {
		"out","out","out","out","out","out","out","out","out","out","out","out",
		"out","out","out","out","out","out","out","out","out","out","out","out",
		"out","out","a8","b8","c8","d8","e8","f8","g8","h8","out","out",
		"out","out","a7","b7","c7","d7","e7","f7","g7","h7","out","out",
		"out","out","a6","b6","c6","d6","e6","f6","g6","h6","out","out",
		"out","out","a5","b5","c5","d5","e5","f5","g5","h5","out","out",
		"out","out","a4","b4","c4","d4","e4","f4","g4","h4","out","out",
		"out","out","a3","b3","c3","d3","e3","f3","g3","h3","out","out",
		"out","out","a2","b2","c2","d2","e2","f2","g2","h2","out","out",
		"out","out","a1","b1","c1","d1","e1","f1","g1","h1","out","out",
		"out","out","out","out","out","out","out","out","out","out","out","out",
		"out","out","out","out","out","out","out","out","out","out","out","out"
	};
	bool white_small_castle = true;
	bool white_big_castle = true;
	bool black_small_castle = true;
	bool black_big_castle = true;
	//aktivna polja su od 26 do 117
	//enum { es, wP, wR, wB, wN, wQ, wK, bP, bR, bB, bN, bQ, bK };
	string piecelist[13] = { "es","wP","wR","wB","wN","wQ",
	"wK","bP","bR","bB","bN","bQ","bK"};
	void diagonal_movement(Move* possible_moves, int& move_counter, int i);
	void forward_backward_movement(Move* possible_moves, int& move_counter, int i);
	void horizontal_movement(Move* possible_moves, int& move_counter, int i);
	void knight_movement(Move* possible_moves, int& move_counter, int i);
	void pawn_movement(Move* possible_moves, int& move_counter, int i);
	bool promotion_check(Move* possible_moves, int& move_counter, int i);
	void king_movement(Move* possible_moves, int& move_counter, int i);
	bool eat_own_piece(int current_index, int move_index);
	void castle_crusher(Move& m);
	Move* move_generator(int& move_counter);
	void print_possible_moves(const Move* moves, const int& move_counter);
	bool is_under_check(const Move& m);
	int search_for_piece(int piece,const Position&position);
	bool diagonal_check(int king_index,const Position&p);
	bool horizontal_vertical_check(int king_index, const Position& p);
	bool knight_check(int king_index, const Position& p);
	bool is_attacked(int index);
public:
	Position();
	void make_move(const Move& m);
	void printPosition();
	void move();
	void undo_move();
};