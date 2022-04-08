#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "board.hpp"
using namespace std;
const static string commands[4] = {
	"go perft",
	"position fen",
	"generate positions",
	"exit"
};
const static int num_of_commands = 4;

void run(Position& p);
bool is_valid(string command);
int execute_command(string line,Position& p);
void format_string(string& command);