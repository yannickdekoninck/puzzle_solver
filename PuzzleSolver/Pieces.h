#pragma once
#include "Puzzle.h"

class Pieces
{
public:
	Pieces();

	Piece square;
	Piece line;
	Piece short_l;
	Piece long_l;
	Piece small_triangle;
	Piece big_triangle;

private:
	// Pieceviews
	PieceView pv_square;

	PieceView pv_line_1;
	PieceView pv_line_2;

	PieceView pv_small_triangle_1;
	PieceView pv_small_triangle_2;
	PieceView pv_small_triangle_3;
	PieceView pv_small_triangle_4;

	PieceView pv_big_triangle_1;
	PieceView pv_big_triangle_2;
	PieceView pv_big_triangle_3;
	PieceView pv_big_triangle_4;

	PieceView pv_short_l_1;
	PieceView pv_short_l_2;
	PieceView pv_short_l_3;
	PieceView pv_short_l_4;
	PieceView pv_short_l_5;
	PieceView pv_short_l_6;
	PieceView pv_short_l_7;
	PieceView pv_short_l_8;

	PieceView pv_long_l_1;
	PieceView pv_long_l_2;
	PieceView pv_long_l_3;
	PieceView pv_long_l_4;
	PieceView pv_long_l_5;
	PieceView pv_long_l_6;
	PieceView pv_long_l_7;
	PieceView pv_long_l_8;
};
