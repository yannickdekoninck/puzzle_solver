#pragma once
#include "Piece.h"
#include <vector>

class Pieces
{
public:
	Pieces();

	Piece square;
	Piece cross;
	Piece line;
	Piece little_u;
	Piece little_b;
	Piece shifted_b;
	Piece short_l;
	Piece long_l;
	Piece little_w;
	Piece shifted_l;
	Piece small_triangle;
	Piece big_triangle;

	std::vector<Piece *> all_pieces;

private:
};
