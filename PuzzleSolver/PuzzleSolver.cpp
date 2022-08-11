// PuzzleSolver.cpp : Defines the entry point for the application.
//

#include "PuzzleSolver.h"
#include "Pieces.h"
using namespace std;

int main()
{

	Pieces p;

	cout << "Hello CMake." << endl;
	cout << "Piece: " << p.line.piece_views[0]->piece_description[0][0] << endl;
	return 0;
}
