// PuzzleSolver.cpp : Defines the entry point for the application.
//

#include "PuzzleSolver.h"
#include "Pieces.h"
using namespace std;

int main()
{

	Pieces p;

	int number_of_pieces = (int)p.all_pieces.size();
	for (int i = 0; i < number_of_pieces; i++)
	{
		int number_of_views = (int)p.all_pieces[i]->piece_views.size();
		std::cout << "Piece " << i << " has " << number_of_views << " views:" << std::endl;
		for (int j = 0; j < number_of_views; j++)
		{
			std::cout << "-- View number " << j << std::endl;
			std::cout << p.all_pieces[i]->piece_views[j]->to_string() << std::endl;
		}
	}
	return 0;
}
