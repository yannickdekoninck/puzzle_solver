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

	// Short L view
	pv_short_l_1.initialize(2, 3);
	pv_short_l_1.piece_description[0][0] = piece_symbol;
	pv_short_l_1.piece_description[1][0] = piece_symbol;
	pv_short_l_1.piece_description[2][0] = piece_symbol;
	pv_short_l_1.piece_description[2][1] = piece_symbol;

	pv_short_l_2 = pv_short_l_1;
	pv_short_l_2.mirror_x();

	pv_short_l_3 = pv_short_l_1;
	pv_short_l_3.mirror_y();

	pv_short_l_4 = pv_short_l_1;
	pv_short_l_4.mirror_x();
	pv_short_l_4.mirror_y();

	pv_short_l_5.initialize(3, 2);
	pv_short_l_5.piece_description[0][0] = piece_symbol;
	pv_short_l_5.piece_description[0][1] = piece_symbol;
	pv_short_l_5.piece_description[0][2] = piece_symbol;
	pv_short_l_5.piece_description[1][2] = piece_symbol;

	pv_short_l_6 = pv_short_l_5;
	pv_short_l_6.mirror_x();

	pv_short_l_7 = pv_short_l_5;
	pv_short_l_7.mirror_y();

	pv_short_l_8 = pv_short_l_5;
	pv_short_l_8.mirror_x();
	pv_short_l_8.mirror_y();

	short_l.piece_views.push_back(&pv_short_l_1);
	short_l.piece_views.push_back(&pv_short_l_2);
	short_l.piece_views.push_back(&pv_short_l_3);
	short_l.piece_views.push_back(&pv_short_l_4);
	short_l.piece_views.push_back(&pv_short_l_5);
	short_l.piece_views.push_back(&pv_short_l_6);
	short_l.piece_views.push_back(&pv_short_l_7);
	short_l.piece_views.push_back(&pv_short_l_8);
}
