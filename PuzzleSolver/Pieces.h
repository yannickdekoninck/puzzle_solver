#pragma once
#include "Puzzle.h"

class Pieces {
public:

	Pieces();

	 Piece square;
	 Piece line;

private:

	// Pieceviews
	PieceView pv_square;

	PieceView pv_line_1;
	PieceView pv_line_2;

};

