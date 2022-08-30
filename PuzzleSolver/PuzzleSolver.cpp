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

PuzzleSolverApp::PuzzleSolverApp(int argc, char **argv) : board_width(11), board_height(5)
{
	// Initialize basics
	board = nullptr;
	max_solutions = 10;
	// parse inputs

	for (int i = 1; i < argc; i++)
	{
		// Load from file
		if (strcmp(argv[i], "-i") == 0)
		{
			if (i + 1 >= argc)
			{
				// Not the right arguments
				print_usage();
				return;
			}
			const char *filename = argv[i + 1];

			std::string board_string = load_board_from_file(filename);
			if (board_string.size() != (size_t)(board_width * board_height))
			{
				std::cout << "ERROR: Board size is not the expected " << board_width << "x" << board_height << "items.";
				return;
			}
			board = new Board(board_width, board_height, p.all_pieces, board_string.c_str());
			if (board->validate_board() == false)
			{
				// Free board memory because it is invalid
				delete board;
				print_usage();
				return;
			}
			i++;
			continue;
		}
		// Set number of solutions
		if (strcmp(argv[i], "-c") == 0)
		{
			if (i + 1 >= argc)
			{
				// Not the right arguments
				std::cout << "Can't set solution count - defaulting to " << max_solutions << std::endl;
				continue;
			}
			int proposed_max_solutions;
			try
			{
				proposed_max_solutions = atoi(argv[i + 1]);
			}
			catch (...)
			{
				std::cout << "Can't set solution count - defaulting to " << max_solutions << std::endl;
				continue;
			}
			max_solutions = proposed_max_solutions;
			i++;
		}
	}

	// Set board if it was not loaded through a file
	if (board == nullptr)
	{
		board = new Board(board_width, board_height, p.all_pieces);
	}
}

PuzzleSolverApp::~PuzzleSolverApp()
{
	delete board;
}

bool PuzzleSolverApp::initialized()
{
	// App is properly initialized if the board is not a nullpointer
	return (board != nullptr);
}

void PuzzleSolverApp::run()
{
	std::cout << "Here's the starting board" << std::endl
			  << std::endl;
	std::cout << "Input sequence: " << std::endl;
	print_board(*board);
	board->update_open_neighbours();
	board->max_solutions = max_solutions;
	auto start = std::chrono::high_resolution_clock::now();
	board->clear_solutions();
	board->solve();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i < board->solution_count(); i++)
	{
		std::cout << "Solution #" << (i + 1) << std::endl;
		print_board(*board->get_solution(i));
		std::cout << std::endl;
	}
	std::cout << "Found " << board->solution_count() << " solutions in " << duration.count() << "ms using " << board->tries << " iterations" << std::endl;
}

int main(int argc, char **argv)
{

	PuzzleSolverApp p(argc, argv);

	if (p.initialized() == false)
	{
		return 0;
	}

	p.run();

	return 0;
}
