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
	GridView pv_square;

	GridView pv_cross;

	GridView pv_line_1;
	GridView pv_line_2;

	GridView pv_small_triangle_1;
	GridView pv_small_triangle_2;
	GridView pv_small_triangle_3;
	GridView pv_small_triangle_4;

	GridView pv_big_triangle_1;
	GridView pv_big_triangle_2;
	GridView pv_big_triangle_3;
	GridView pv_big_triangle_4;

	GridView pv_little_u_1;
	GridView pv_little_u_2;
	GridView pv_little_u_3;
	GridView pv_little_u_4;

	GridView pv_little_w_1;
	GridView pv_little_w_2;
	GridView pv_little_w_3;
	GridView pv_little_w_4;

	GridView pv_short_l_1;
	GridView pv_short_l_2;
	GridView pv_short_l_3;
	GridView pv_short_l_4;
	GridView pv_short_l_5;
	GridView pv_short_l_6;
	GridView pv_short_l_7;
	GridView pv_short_l_8;

	GridView pv_shifted_b_1;
	GridView pv_shifted_b_2;
	GridView pv_shifted_b_3;
	GridView pv_shifted_b_4;
	GridView pv_shifted_b_5;
	GridView pv_shifted_b_6;
	GridView pv_shifted_b_7;
	GridView pv_shifted_b_8;

	GridView pv_little_b_1;
	GridView pv_little_b_2;
	GridView pv_little_b_3;
	GridView pv_little_b_4;
	GridView pv_little_b_5;
	GridView pv_little_b_6;
	GridView pv_little_b_7;
	GridView pv_little_b_8;

	GridView pv_long_l_1;
	GridView pv_long_l_2;
	GridView pv_long_l_3;
	GridView pv_long_l_4;
	GridView pv_long_l_5;
	GridView pv_long_l_6;
	GridView pv_long_l_7;
	GridView pv_long_l_8;

	GridView pv_shifted_l_1;
	GridView pv_shifted_l_2;
	GridView pv_shifted_l_3;
	GridView pv_shifted_l_4;
	GridView pv_shifted_l_5;
	GridView pv_shifted_l_6;
	GridView pv_shifted_l_7;
	GridView pv_shifted_l_8;
};
