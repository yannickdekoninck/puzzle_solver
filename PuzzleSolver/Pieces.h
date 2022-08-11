#pragma once
#include "Puzzle.h"

class Pieces
{
public:
	Pieces();

	Piece square;
	Piece line;
	Piece short_l;

private:
	// Pieceviews
	PieceView pv_square;

	PieceView pv_line_1;
	PieceView pv_line_2;

	PieceView pv_short_l_1;
	PieceView pv_short_l_2;
	PieceView pv_short_l_3;
	PieceView pv_short_l_4;
	PieceView pv_short_l_5;
	PieceView pv_short_l_6;
	PieceView pv_short_l_7;
	PieceView pv_short_l_8;
};
