#pragma once
#include <vector>
#include <string>

const char piece_symbol = 'a';
const char empty_symbol = '0';

class PieceView
{
public:
	// Constructors / destructor
	PieceView();
	PieceView(int width, int height);
	~PieceView();

	// Methods
	void initialize(int width, int height);
	std::string to_string();

	// Variables
	int width;
	int height;
	char **piece_description;

private:
	// Methods
	void free_piece_description();
};

class Piece
{
public:
	int id;
	std::vector<PieceView *> piece_views;
};

class Board
{
public:
	int *width;
	int heigth;
	int **board_content;
};