#pragma once
#include <vector>
#include <string>

const char piece_symbol = 'a';
const char empty_symbol = '0';

class GridView
{
public:
	// Constructors / destructor
	GridView();
	GridView(const GridView &other);
	GridView(int width, int height);
	~GridView();

	GridView &operator=(const GridView &other);

	// Methods
	void initialize(int width, int height);
	void mirror_x();
	void mirror_y();
	std::string to_string();

	void replace_symbol(const char new_symbol);

	inline char get_description(int x, int y) { return piece_description[y][x]; }
	inline void set_description(int x, int y, char descr) { piece_description[y][x] = descr; }
	inline int get_width() { return width; }
	inline int get_height() { return height; }

private:
	char **piece_description;
	// Variables
	int width;
	int height;

private:
	// Methods
	void free_piece_description();
	void copy_piece_description(const GridView &other);
};

class Piece
{
public:
	Piece() : id(piece_symbol){};
	Piece(const char symbol) : id(symbol){};
	char id;
	void add_piece_view(GridView &new_p);

private:
	std::vector<GridView *> piece_views;
};

class Board
{
public:
	int *width;
	int heigth;
	int **board_content;
};