// PuzzleSolver.cpp : Defines the entry point for the application.
//

#include "PuzzleSolver.h"
#include "Pieces.h"
#include "Board.h"
#include <windows.h>
#include "Utilities.h"
#include <chrono>
using namespace std;

void print_usage()
{
	const char *usage_string = "Usage: \n"
							   "Option 1: PuzzleSolver.exe \t\t\t-> Solves empty board\n"
							   "Option 2: PuzzleSolver.exe -i filename.txt \t-> Solves the board defined in filename.txt\n";
	std::cout << usage_string << std::endl;
}

int main(int argc, char **argv)
{

	// Parse CLI arguments
	// Let's assume 2 cases for now:
	// - case 1: there's no CLI arguments -> empty board
	// - case 2: the CLI arguments are of the form:
	//   -i filename.txt
	// And this filename contains an ascii representation of the board.
	// Extract filename of initial board position
	// Load file into board
	// Check if board is valid
	// Solve puzzle
	// Print out result
	// Loading the board

	Board *bp;
	Pieces p;
	int width = 11;
	int height = 5;

	std::cout << "Welcome to PuzzleSolver!" << std::endl
			  << std::endl;
	if (argc < 2)
	{
		bp = new Board(width, height, p.all_pieces);
	}
	else if (argc == 3)
	{
		if (!(strcmp(argv[1], "-i") == 0))
		{
			print_usage();
			return 0;
		}
		// Load file
		const char *filename = argv[2];

		std::string board = load_board_from_file(filename);
		if (board.size() != width * height)
		{
			std::cout << "ERROR: Board size is not the expected " << width << "x" << height << "items.";
		}
		bp = new Board(width, height, p.all_pieces, board.c_str());
		if (bp->validate_board() == false)
		{
			print_usage();
			return 0;
		}
	}
	else
	{
		print_usage();
		return 0;
	}

	// Let's create a reference to bp because that's a bit easier to work with
	Board &b = *bp;

	std::cout << "Here's the starting board" << std::endl
			  << std::endl;

	/*
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
	}*/

	// b.put_piece(*p.long_l.get_view(6), 0, 0);
	// b.put_piece(*p.small_triangle.get_view(2), 0, 3);
	// b.put_piece(*p.short_l.get_view(3), 1, 1);

	// p.long_l.placed = true;
	// p.small_triangle.placed = true;
	// p.short_l.placed = true;

	std::cout << "Input sequence: " << std::endl;
	print_board(b);
	b.update_open_neighbours();
	auto start = std::chrono::high_resolution_clock::now();
	b.clear_solutions();
	b.solve();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Solved puzzle in " << duration.count() << "ms using " << b.tries << " iterations" << std::endl;
	std::cout << std::endl;
	std::cout << "Found " << b.solution_count() << " solutions." << std::endl;
	for (unsigned int i = 0; i < b.solution_count(); i++)
	{
		std::cout << "Solution: " << i << ":" << std::endl;
		GridView *solution = b.get_solution(i);
		print_board(*solution);
		std::cout << std::endl;
	}

	std::cout << "Done!" << std::endl;

	// Clean up
	delete bp;

	return 0;
}
