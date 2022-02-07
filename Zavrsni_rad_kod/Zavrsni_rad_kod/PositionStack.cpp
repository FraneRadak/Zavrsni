#include "PositionStack.hpp"

PositionStack* stack;

PositionStack::PositionStack() {
	p = new Position[300];
	last_index = 0;
	}
	void PositionStack:: push(const Position& position) {
		p[last_index] = position;
		last_index++;
	}
	Position PositionStack:: pop() {
		last_index--;
		return p[last_index];
	}
	PositionStack::~PositionStack() {
		delete[] p;
	}



