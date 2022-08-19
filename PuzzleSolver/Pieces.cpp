#include "Pieces.h"

Pieces::Pieces() : square('A'),
				   cross('B'),
				   line('C'),
				   little_u('D'),
				   little_b('E'),
				   shifted_b('F'),
				   short_l('G'),
				   long_l('H'),
				   little_w('I'),
				   shifted_l('J'),
				   small_triangle('K'),
				   big_triangle('L')
{
	// A Long list to initialize all the pieces and their pieceviews
	// Square piece views
	GridView pv_square;
	pv_square.initialize(2, 2);
	pv_square.set_description(0, 0, piece_symbol);
	pv_square.set_description(0, 1, piece_symbol);
	pv_square.set_description(1, 0, piece_symbol);
	pv_square.set_description(1, 1, piece_symbol);
	square.initialize_with_grid_view(pv_square);

	// cross piece views
	GridView pv_cross;
	pv_cross.initialize(3, 3);
	pv_cross.set_description(0, 1, piece_symbol);
	pv_cross.set_description(1, 0, piece_symbol);
	pv_cross.set_description(1, 1, piece_symbol);
	pv_cross.set_description(1, 2, piece_symbol);
	pv_cross.set_description(2, 1, piece_symbol);
	cross.initialize_with_grid_view(pv_cross);

	// cross piece

	// Line piece views
	GridView pv_line;
	pv_line.initialize(1, 4);
	for (int i = 0; i < 4; i++)
	{
		pv_line.set_description(0, i, piece_symbol);
	}
	line.initialize_with_grid_view(pv_line);

	// Small triangle
	GridView pv_small_triangle;
	pv_small_triangle.initialize(2, 2);
	pv_small_triangle.set_description(0, 0, piece_symbol);
	pv_small_triangle.set_description(1, 0, piece_symbol);
	pv_small_triangle.set_description(1, 1, piece_symbol);

	small_triangle.initialize_with_grid_view(pv_small_triangle);

	// Big triangle
	GridView pv_big_triangle;
	pv_big_triangle.initialize(3, 3);
	pv_big_triangle.set_description(0, 0, piece_symbol);
	pv_big_triangle.set_description(1, 0, piece_symbol);
	pv_big_triangle.set_description(2, 0, piece_symbol);
	pv_big_triangle.set_description(2, 1, piece_symbol);
	pv_big_triangle.set_description(2, 2, piece_symbol);
	big_triangle.initialize_with_grid_view(pv_big_triangle);

	// Little B view
	GridView pv_little_b;
	pv_little_b.initialize(3, 2);
	pv_little_b.set_description(0, 0, piece_symbol);
	pv_little_b.set_description(1, 0, piece_symbol);
	pv_little_b.set_description(1, 1, piece_symbol);
	pv_little_b.set_description(2, 0, piece_symbol);
	pv_little_b.set_description(2, 1, piece_symbol);

	little_b.initialize_with_grid_view(pv_little_b);

	// Shifted B view
	GridView pv_shifted_b;
	pv_shifted_b.initialize(4, 2);
	pv_shifted_b.set_description(0, 0, piece_symbol);
	pv_shifted_b.set_description(1, 0, piece_symbol);
	pv_shifted_b.set_description(2, 0, piece_symbol);
	pv_shifted_b.set_description(2, 1, piece_symbol);
	pv_shifted_b.set_description(3, 1, piece_symbol);

	shifted_b.initialize_with_grid_view(pv_shifted_b);

	// Little u view
	GridView pv_little_u;
	pv_little_u.initialize(3, 2);
	pv_little_u.set_description(0, 0, piece_symbol);
	pv_little_u.set_description(0, 1, piece_symbol);
	pv_little_u.set_description(1, 0, piece_symbol);
	pv_little_u.set_description(2, 0, piece_symbol);
	pv_little_u.set_description(2, 1, piece_symbol);
	little_u.initialize_with_grid_view(pv_little_u);

	// Short L view
	GridView pv_short_l;
	pv_short_l.initialize(3, 2);
	pv_short_l.set_description(0, 0, piece_symbol);
	pv_short_l.set_description(1, 0, piece_symbol);
	pv_short_l.set_description(2, 0, piece_symbol);
	pv_short_l.set_description(2, 1, piece_symbol);
	short_l.initialize_with_grid_view(pv_short_l);

	// Long L view
	GridView pv_long_l;
	pv_long_l.initialize(4, 2);
	pv_long_l.set_description(0, 0, piece_symbol);
	pv_long_l.set_description(1, 0, piece_symbol);
	pv_long_l.set_description(2, 0, piece_symbol);
	pv_long_l.set_description(3, 0, piece_symbol);
	pv_long_l.set_description(3, 1, piece_symbol);
	long_l.initialize_with_grid_view(pv_long_l);

	// shifted L view
	GridView pv_little_w;
	pv_little_w.initialize(3, 3);
	pv_little_w.set_description(0, 0, piece_symbol);
	pv_little_w.set_description(1, 0, piece_symbol);
	pv_little_w.set_description(1, 1, piece_symbol);
	pv_little_w.set_description(2, 1, piece_symbol);
	pv_little_w.set_description(2, 2, piece_symbol);
	little_w.initialize_with_grid_view(pv_little_w);

	// shifted L view
	GridView pv_shifted_l;
	pv_shifted_l.initialize(4, 2);
	pv_shifted_l.set_description(0, 0, piece_symbol);
	pv_shifted_l.set_description(1, 0, piece_symbol);
	pv_shifted_l.set_description(2, 0, piece_symbol);
	pv_shifted_l.set_description(3, 0, piece_symbol);
	pv_shifted_l.set_description(2, 1, piece_symbol);
	shifted_l.initialize_with_grid_view(pv_shifted_l);

	// Add all pieces to all_pieces

	all_pieces.push_back(&square);
	all_pieces.push_back(&cross);
	all_pieces.push_back(&line);
	all_pieces.push_back(&little_u);
	all_pieces.push_back(&little_b);
	all_pieces.push_back(&little_w);
	all_pieces.push_back(&shifted_b);
	all_pieces.push_back(&short_l);
	all_pieces.push_back(&long_l);
	all_pieces.push_back(&shifted_l);
	all_pieces.push_back(&small_triangle);
	all_pieces.push_back(&big_triangle);
}
