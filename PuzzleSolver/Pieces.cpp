#include "Puzzle.h"
#include "Pieces.h"

Pieces::Pieces()
{
	// A Long list to initialize all the pieces and their pieceviews
	// Square piece views
	pv_square.initialize(2, 2);
	pv_square.piece_description[0][0] = piece_symbol;
	pv_square.piece_description[0][1] = piece_symbol;
	pv_square.piece_description[1][0] = piece_symbol;
	pv_square.piece_description[1][1] = piece_symbol;

	// Square piece
	square.piece_views.push_back(&pv_square);

	// Line piece views
	pv_line_1.initialize(1, 4);
	pv_line_2.initialize(4, 1);
	for (int i = 0; i < 4; i++)
	{
		pv_line_1.piece_description[i][0] = piece_symbol;
		pv_line_2.piece_description[0][i] = piece_symbol;
	}
	// Line
	line.piece_views.push_back(&pv_line_1);
	line.piece_views.push_back(&pv_line_2);
}
