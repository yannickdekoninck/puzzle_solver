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
		std::cout << "Number of views: " << p.all_pieces[i]->number_of_views() << std::endl;
	}

	Board b(11, 5);
	b.put_piece(*p.cross.get_view(0), 1, 1);
	b.put_piece(*p.square.get_view(0), 5, 1);

	print_board(b);


	std::cout << "Done!" << std::endl;

	return 0;
}
