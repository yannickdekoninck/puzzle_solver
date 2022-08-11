// PuzzleSolver.cpp : Defines the entry point for the application.
//

#include "PuzzleSolver.h"
#include "Pieces.h"
using namespace std;

int main()
{

	Pieces p;

	cout << "Hello CMake." << endl;
	cout << "Line pieceview 0: " << endl
		 << p.line.piece_views[0]->to_string() << endl;
	cout << "Line pieceview 1: " << endl
		 << p.line.piece_views[1]->to_string() << endl;
	cout << "Square pieceview 0: " << endl
		 << p.square.piece_views[0]->to_string() << endl;
	return 0;
}
