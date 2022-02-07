
#pragma once
#include "board.hpp"

class PositionStack {
private:
	Position* p;
	int last_index;
public:
	PositionStack();
	void push(const Position& position);
	Position pop();
	~PositionStack();
};

extern PositionStack* stack;

