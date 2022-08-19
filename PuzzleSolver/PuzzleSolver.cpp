// PuzzleSolver.cpp : Defines the entry point for the application.
//

#include "PuzzleSolver.h"
#include "Piece.h"
using namespace std;

int main()
{
	GridView pv_little_b_1;

	pv_little_b_1.initialize(3, 2);
	pv_little_b_1.set_description(0, 0, piece_symbol);
	pv_little_b_1.set_description(1, 0, piece_symbol);
	pv_little_b_1.set_description(1, 1, piece_symbol);
	pv_little_b_1.set_description(2, 0, piece_symbol);
	pv_little_b_1.set_description(2, 1, piece_symbol);

	Piece little_b(pv_little_b_1);

	PieceView *pv = little_b.get_view(6);
	std::cout << pv->grid_view.to_string() << std::endl;

	std::cout << " Done!" << std::endl;

	return 0;
}
