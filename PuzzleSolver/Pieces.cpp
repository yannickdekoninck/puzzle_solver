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

	// cross piece views
	pv_cross.initialize(3, 3);
	pv_cross.piece_description[0][1] = piece_symbol;
	pv_cross.piece_description[1][0] = piece_symbol;
	pv_cross.piece_description[1][1] = piece_symbol;
	pv_cross.piece_description[1][2] = piece_symbol;
	pv_cross.piece_description[2][1] = piece_symbol;

	// cross piece
	cross.piece_views.push_back(&pv_cross);

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

	// Small triangle
	pv_small_triangle_1.initialize(2, 2);
	pv_small_triangle_1.piece_description[0][0] = piece_symbol;
	pv_small_triangle_1.piece_description[1][0] = piece_symbol;
	pv_small_triangle_1.piece_description[1][1] = piece_symbol;

	pv_small_triangle_2 = pv_small_triangle_1;
	pv_small_triangle_2.mirror_x();

	pv_small_triangle_3 = pv_small_triangle_1;
	pv_small_triangle_3.mirror_y();

	pv_small_triangle_4 = pv_small_triangle_1;
	pv_small_triangle_4.mirror_x();
	pv_small_triangle_4.mirror_y();

	small_triangle.piece_views.push_back(&pv_small_triangle_1);
	small_triangle.piece_views.push_back(&pv_small_triangle_2);
	small_triangle.piece_views.push_back(&pv_small_triangle_3);
	small_triangle.piece_views.push_back(&pv_small_triangle_4);

	// Big triangle
	pv_big_triangle_1.initialize(3, 3);
	pv_big_triangle_1.piece_description[0][0] = piece_symbol;
	pv_big_triangle_1.piece_description[1][0] = piece_symbol;
	pv_big_triangle_1.piece_description[2][0] = piece_symbol;
	pv_big_triangle_1.piece_description[2][1] = piece_symbol;
	pv_big_triangle_1.piece_description[2][2] = piece_symbol;

	pv_big_triangle_2 = pv_big_triangle_1;
	pv_big_triangle_2.mirror_x();

	pv_big_triangle_3 = pv_big_triangle_1;
	pv_big_triangle_3.mirror_y();

	pv_big_triangle_4 = pv_big_triangle_1;
	pv_big_triangle_4.mirror_x();
	pv_big_triangle_4.mirror_y();

	big_triangle.piece_views.push_back(&pv_big_triangle_1);
	big_triangle.piece_views.push_back(&pv_big_triangle_2);
	big_triangle.piece_views.push_back(&pv_big_triangle_3);
	big_triangle.piece_views.push_back(&pv_big_triangle_4);

	// Little B view
	pv_little_b_1.initialize(2, 3);
	pv_little_b_1.piece_description[0][0] = piece_symbol;
	pv_little_b_1.piece_description[1][0] = piece_symbol;
	pv_little_b_1.piece_description[1][1] = piece_symbol;
	pv_little_b_1.piece_description[2][0] = piece_symbol;
	pv_little_b_1.piece_description[2][1] = piece_symbol;

	pv_little_b_2 = pv_little_b_1;
	pv_little_b_2.mirror_x();

	pv_little_b_3 = pv_little_b_1;
	pv_little_b_3.mirror_y();

	pv_little_b_4 = pv_little_b_1;
	pv_little_b_4.mirror_x();
	pv_little_b_4.mirror_y();

	pv_little_b_5.initialize(3, 2);
	pv_little_b_5.piece_description[0][0] = piece_symbol;
	pv_little_b_5.piece_description[0][1] = piece_symbol;
	pv_little_b_5.piece_description[1][1] = piece_symbol;
	pv_little_b_5.piece_description[0][2] = piece_symbol;
	pv_little_b_5.piece_description[1][2] = piece_symbol;

	pv_little_b_6 = pv_little_b_5;
	pv_little_b_6.mirror_x();

	pv_little_b_7 = pv_little_b_5;
	pv_little_b_7.mirror_y();

	pv_little_b_8 = pv_little_b_5;
	pv_little_b_8.mirror_x();
	pv_little_b_8.mirror_y();

	little_b.piece_views.push_back(&pv_little_b_1);
	little_b.piece_views.push_back(&pv_little_b_2);
	little_b.piece_views.push_back(&pv_little_b_3);
	little_b.piece_views.push_back(&pv_little_b_4);
	little_b.piece_views.push_back(&pv_little_b_5);
	little_b.piece_views.push_back(&pv_little_b_6);
	little_b.piece_views.push_back(&pv_little_b_7);
	little_b.piece_views.push_back(&pv_little_b_8);

	// Shifted B view
	pv_shifted_b_1.initialize(2, 4);
	pv_shifted_b_1.piece_description[0][0] = piece_symbol;
	pv_shifted_b_1.piece_description[1][0] = piece_symbol;
	pv_shifted_b_1.piece_description[2][0] = piece_symbol;
	pv_shifted_b_1.piece_description[2][1] = piece_symbol;
	pv_shifted_b_1.piece_description[3][1] = piece_symbol;

	pv_shifted_b_2 = pv_shifted_b_1;
	pv_shifted_b_2.mirror_x();

	pv_shifted_b_3 = pv_shifted_b_1;
	pv_shifted_b_3.mirror_y();

	pv_shifted_b_4 = pv_shifted_b_1;
	pv_shifted_b_4.mirror_x();
	pv_shifted_b_4.mirror_y();

	pv_shifted_b_5.initialize(4, 2);
	pv_shifted_b_5.piece_description[0][0] = piece_symbol;
	pv_shifted_b_5.piece_description[0][1] = piece_symbol;
	pv_shifted_b_5.piece_description[0][2] = piece_symbol;
	pv_shifted_b_5.piece_description[1][2] = piece_symbol;
	pv_shifted_b_5.piece_description[1][3] = piece_symbol;

	pv_shifted_b_6 = pv_shifted_b_5;
	pv_shifted_b_6.mirror_x();

	pv_shifted_b_7 = pv_shifted_b_5;
	pv_shifted_b_7.mirror_y();

	pv_shifted_b_8 = pv_shifted_b_5;
	pv_shifted_b_8.mirror_x();
	pv_shifted_b_8.mirror_y();

	shifted_b.piece_views.push_back(&pv_shifted_b_1);
	shifted_b.piece_views.push_back(&pv_shifted_b_2);
	shifted_b.piece_views.push_back(&pv_shifted_b_3);
	shifted_b.piece_views.push_back(&pv_shifted_b_4);
	shifted_b.piece_views.push_back(&pv_shifted_b_5);
	shifted_b.piece_views.push_back(&pv_shifted_b_6);
	shifted_b.piece_views.push_back(&pv_shifted_b_7);
	shifted_b.piece_views.push_back(&pv_shifted_b_8);

	// Little u view
	pv_little_u_1.initialize(2, 3);
	pv_little_u_1.piece_description[0][0] = piece_symbol;
	pv_little_u_1.piece_description[0][1] = piece_symbol;
	pv_little_u_1.piece_description[1][0] = piece_symbol;
	pv_little_u_1.piece_description[2][0] = piece_symbol;
	pv_little_u_1.piece_description[2][1] = piece_symbol;

	pv_little_u_2 = pv_little_u_1;
	pv_little_u_2.mirror_x();
	pv_little_u_2.mirror_y();

	pv_little_u_3.initialize(3, 2);
	pv_little_u_3.piece_description[0][0] = piece_symbol;
	pv_little_u_3.piece_description[1][0] = piece_symbol;
	pv_little_u_3.piece_description[0][1] = piece_symbol;
	pv_little_u_3.piece_description[0][2] = piece_symbol;
	pv_little_u_3.piece_description[1][2] = piece_symbol;

	pv_little_u_4 = pv_little_u_3;
	pv_little_u_4.mirror_x();
	pv_little_u_4.mirror_y();

	little_u.piece_views.push_back(&pv_little_u_1);
	little_u.piece_views.push_back(&pv_little_u_2);
	little_u.piece_views.push_back(&pv_little_u_3);
	little_u.piece_views.push_back(&pv_little_u_4);

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

	// Long L view
	pv_long_l_1.initialize(2, 4);
	pv_long_l_1.piece_description[0][0] = piece_symbol;
	pv_long_l_1.piece_description[1][0] = piece_symbol;
	pv_long_l_1.piece_description[2][0] = piece_symbol;
	pv_long_l_1.piece_description[3][0] = piece_symbol;
	pv_long_l_1.piece_description[3][1] = piece_symbol;

	pv_long_l_2 = pv_long_l_1;
	pv_long_l_2.mirror_x();

	pv_long_l_3 = pv_long_l_1;
	pv_long_l_3.mirror_y();

	pv_long_l_4 = pv_long_l_1;
	pv_long_l_4.mirror_x();
	pv_long_l_4.mirror_y();

	pv_long_l_5.initialize(4, 2);
	pv_long_l_5.piece_description[0][0] = piece_symbol;
	pv_long_l_5.piece_description[0][1] = piece_symbol;
	pv_long_l_5.piece_description[0][2] = piece_symbol;
	pv_long_l_5.piece_description[0][3] = piece_symbol;
	pv_long_l_5.piece_description[1][3] = piece_symbol;

	pv_long_l_6 = pv_long_l_5;
	pv_long_l_6.mirror_x();

	pv_long_l_7 = pv_long_l_5;
	pv_long_l_7.mirror_y();

	pv_long_l_8 = pv_long_l_5;
	pv_long_l_8.mirror_x();
	pv_long_l_8.mirror_y();

	long_l.piece_views.push_back(&pv_long_l_1);
	long_l.piece_views.push_back(&pv_long_l_2);
	long_l.piece_views.push_back(&pv_long_l_3);
	long_l.piece_views.push_back(&pv_long_l_4);
	long_l.piece_views.push_back(&pv_long_l_5);
	long_l.piece_views.push_back(&pv_long_l_6);
	long_l.piece_views.push_back(&pv_long_l_7);
	long_l.piece_views.push_back(&pv_long_l_8);

	// shifted L view
	pv_little_w_1.initialize(3, 3);
	pv_little_w_1.piece_description[0][0] = piece_symbol;
	pv_little_w_1.piece_description[1][0] = piece_symbol;
	pv_little_w_1.piece_description[1][1] = piece_symbol;
	pv_little_w_1.piece_description[2][1] = piece_symbol;
	pv_little_w_1.piece_description[2][2] = piece_symbol;

	pv_little_w_2 = pv_little_w_1;
	pv_little_w_2.mirror_x();

	pv_little_w_3 = pv_little_w_1;
	pv_little_w_3.mirror_y();

	pv_little_w_4 = pv_little_w_1;
	pv_little_w_4.mirror_x();
	pv_little_w_4.mirror_y();

	// shifted L view
	pv_shifted_l_1.initialize(2, 4);
	pv_shifted_l_1.piece_description[0][0] = piece_symbol;
	pv_shifted_l_1.piece_description[1][0] = piece_symbol;
	pv_shifted_l_1.piece_description[2][0] = piece_symbol;
	pv_shifted_l_1.piece_description[3][0] = piece_symbol;
	pv_shifted_l_1.piece_description[2][1] = piece_symbol;

	pv_shifted_l_2 = pv_shifted_l_1;
	pv_shifted_l_2.mirror_x();

	pv_shifted_l_3 = pv_shifted_l_1;
	pv_shifted_l_3.mirror_y();

	pv_shifted_l_4 = pv_shifted_l_1;
	pv_shifted_l_4.mirror_x();
	pv_shifted_l_4.mirror_y();

	pv_shifted_l_5.initialize(4, 2);
	pv_shifted_l_5.piece_description[0][0] = piece_symbol;
	pv_shifted_l_5.piece_description[0][1] = piece_symbol;
	pv_shifted_l_5.piece_description[0][2] = piece_symbol;
	pv_shifted_l_5.piece_description[0][3] = piece_symbol;
	pv_shifted_l_5.piece_description[1][2] = piece_symbol;

	pv_shifted_l_6 = pv_shifted_l_5;
	pv_shifted_l_6.mirror_x();

	pv_shifted_l_7 = pv_shifted_l_5;
	pv_shifted_l_7.mirror_y();

	pv_shifted_l_8 = pv_shifted_l_5;
	pv_shifted_l_8.mirror_x();
	pv_shifted_l_8.mirror_y();

	shifted_l.piece_views.push_back(&pv_shifted_l_1);
	shifted_l.piece_views.push_back(&pv_shifted_l_2);
	shifted_l.piece_views.push_back(&pv_shifted_l_3);
	shifted_l.piece_views.push_back(&pv_shifted_l_4);
	shifted_l.piece_views.push_back(&pv_shifted_l_5);
	shifted_l.piece_views.push_back(&pv_shifted_l_6);
	shifted_l.piece_views.push_back(&pv_shifted_l_7);
	shifted_l.piece_views.push_back(&pv_shifted_l_8);
}
