﻿// PuzzleSolver.cpp : Defines the entry point for the application.
//

#include "PuzzleSolver.h"
#include "Pieces.h"
#include "Board.h"
using namespace std;

int main()
{
	Pieces p;

	for (int i = 0; i < p.all_pieces.size(); i++)
	{
		std::cout << "Number of views: " << p.all_pieces[i]->number_of_views() << std::endl;
	}

	Board b(11, 5);

	std::cout << b.to_string() << std::endl;

	std::cout << "Done!" << std::endl;

	return 0;
}
