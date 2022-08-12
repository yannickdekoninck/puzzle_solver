#pragma once
#include "Puzzle.h"
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
	// Pieceviews
	PieceView pv_square;

	PieceView pv_cross;

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

	PieceView pv_little_u_1;
	PieceView pv_little_u_2;
	PieceView pv_little_u_3;
	PieceView pv_little_u_4;

	PieceView pv_little_w_1;
	PieceView pv_little_w_2;
	PieceView pv_little_w_3;
	PieceView pv_little_w_4;

	PieceView pv_short_l_1;
	PieceView pv_short_l_2;
	PieceView pv_short_l_3;
	PieceView pv_short_l_4;
	PieceView pv_short_l_5;
	PieceView pv_short_l_6;
	PieceView pv_short_l_7;
	PieceView pv_short_l_8;

	PieceView pv_shifted_b_1;
	PieceView pv_shifted_b_2;
	PieceView pv_shifted_b_3;
	PieceView pv_shifted_b_4;
	PieceView pv_shifted_b_5;
	PieceView pv_shifted_b_6;
	PieceView pv_shifted_b_7;
	PieceView pv_shifted_b_8;

	PieceView pv_little_b_1;
	PieceView pv_little_b_2;
	PieceView pv_little_b_3;
	PieceView pv_little_b_4;
	PieceView pv_little_b_5;
	PieceView pv_little_b_6;
	PieceView pv_little_b_7;
	PieceView pv_little_b_8;

	PieceView pv_long_l_1;
	PieceView pv_long_l_2;
	PieceView pv_long_l_3;
	PieceView pv_long_l_4;
	PieceView pv_long_l_5;
	PieceView pv_long_l_6;
	PieceView pv_long_l_7;
	PieceView pv_long_l_8;

	PieceView pv_shifted_l_1;
	PieceView pv_shifted_l_2;
	PieceView pv_shifted_l_3;
	PieceView pv_shifted_l_4;
	PieceView pv_shifted_l_5;
	PieceView pv_shifted_l_6;
	PieceView pv_shifted_l_7;
	PieceView pv_shifted_l_8;
};
