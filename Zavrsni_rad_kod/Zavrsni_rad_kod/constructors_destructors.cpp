#include "board.hpp"
#include "PositionStack.hpp"


Move::Move(int piece, int current_position, int position) {
	this->piece = piece;
	this->current_position = current_position;
	this->position = position;
}
Position::Position() {

}
Move::Move() {

}
