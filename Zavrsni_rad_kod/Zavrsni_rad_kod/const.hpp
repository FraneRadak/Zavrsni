
#include <iostream>
#include <cstdlib>
using namespace std;

#pragma once
extern bool DEBUG;

const int diagonal_delta[4] = { 13,-13,11,-11 };
const int horizontal_vertical_delta[4] = { 1,-1,12,-12 };
const int knight_delta[8] = { 23,-23,14,-14,10,-10,25,-25 };
const int king_delta_light[8] = { 1,-1,12,-12,13,-13,11,-11 };
const int king_delta[10] = { 1,-1,12,-12,13,-13,11,-11,2,-2 };
const static int forward_backward_delta[2] = { 12,-12 };
const static int horizontal_delta[2] = { 1,-1 };
const static string XmlFileHeader = "<?xml version= \"1.0\"  encoding = \"UTF-8\"?>";
const static string square_list[144] = {
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
const static string piecelist[13] = { "es","wP","wR","wB","wN","wQ",
	"wK","bP","bR","bB","bN","bQ","bK" };


