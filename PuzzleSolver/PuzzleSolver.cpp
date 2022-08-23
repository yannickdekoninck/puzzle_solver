// PuzzleSolver.cpp : Defines the entry point for the application.
//

#include "PuzzleSolver.h"
#include "Pieces.h"
#include "Board.h"
#include <windows.h>
#include "Utilities.h"
using namespace std;

int main()
{
	Pieces p;

	for (int i = 0; i < p.all_pieces.size(); i++)
	{
		std::cout << "Piece number: " << i;
		std::cout << "Number of views: " << p.all_pieces[i]->number_of_views() << std::endl;
		for (int j = 0; j < p.all_pieces[i]->number_of_views(); j++)
		{
			std::cout << "View number " << j;
			print_board(p.all_pieces[i]->get_view(j)->grid_view);
			std::cout << std::endl;
		}
	}

	Board b(11, 5, p.all_pieces);
	b.put_piece(*p.long_l.get_view(6), 0, 0);
	b.put_piece(*p.small_triangle.get_view(2), 0, 3);
	b.put_piece(*p.short_l.get_view(3), 1, 1);

	p.long_l.placed = true;
	p.small_triangle.placed = true;
	p.short_l.placed = true;

	print_board(b);
	b.update_open_neighbours();
	b.solve();
	std::cout << b.tries << std::endl;
	print_board(b);

	std::cout << "Done!" << std::endl;

	return 0;
}
