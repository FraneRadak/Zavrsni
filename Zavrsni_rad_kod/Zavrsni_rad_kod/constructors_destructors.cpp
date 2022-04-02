#include "board.hpp"
#include "PositionStack.hpp"

Position::Position() {
}
Move::Move() {
}
Move::Move(int piece, int current_position, int position) {
	this->piece = piece;
	this->current_position = current_position;
	this->position = position;
}
void Move::setCurrent_Position(int x) {
	this->current_position = x;
}
void Move::setEaten_Piece(int x ) {
	this->eaten_piece = 0;
}
void Move::setPiece(int x) {
	this->piece = x;
}
void Move::setPosition(int x) {
	this->position = x;
}
void Move::setEnPassant() {
	this->en_passant = true;
}
