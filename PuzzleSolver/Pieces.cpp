#include "Puzzle.h"
#include "Pieces.h"

Pieces::Pieces()
{
	// Square piece views
	pv_square.initialize(2, 2);
	pv_square.piece_description[0][0] = 1;
	pv_square.piece_description[0][1] = 1;
	pv_square.piece_description[1][0] = 1;
	pv_square.piece_description[1][1] = 1;

	// Square piece
	square.piece_views.push_back(&pv_square);

	// Line piece views
	pv_line_1.initialize(1, 4);
	pv_line_2.initialize(4, 1);
	for (int i = 0; i < 4; i++)
	{
		pv_line_1.piece_description[i][0] = 1;
		pv_line_2.piece_description[0][i] = 1;
	}
	// Line
	line.piece_views.push_back(&pv_line_1);
	line.piece_views.push_back(&pv_line_2);
}
