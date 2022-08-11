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
	PieceView(const PieceView &other);
	PieceView(int width, int height);
	~PieceView();

	PieceView &operator=(const PieceView &other);

	// Methods
	void initialize(int width, int height);
	void mirror_x();
	void mirror_y();
	std::string to_string();

	// Variables
	int width;
	int height;
	char **piece_description;

private:
	// Methods
	void free_piece_description();
	void copy_piece_description(const PieceView &other);
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