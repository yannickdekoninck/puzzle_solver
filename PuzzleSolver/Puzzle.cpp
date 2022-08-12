#include "Puzzle.h"

PieceView::PieceView() : width(0), height(0)
{
	piece_description = nullptr;
}

PieceView::PieceView(int width, int height)
{
	initialize(width, height);
}

PieceView::PieceView(const PieceView &other)
{
	width = other.width;
	height = other.height;
	piece_description = nullptr;
	if (other.piece_description == nullptr)
	{
		return;
	}
	initialize(width, height);
	copy_piece_description(other);
}

PieceView::~PieceView()
{
	free_piece_description();
}

PieceView &PieceView::operator=(const PieceView &other)
{
	width = other.width;
	height = other.height;
	piece_description = nullptr;
	if (other.piece_description != nullptr)
	{
		initialize(width, height);
		copy_piece_description(other);
	}
	return *this;
}

void PieceView::initialize(int width, int height)
{
	this->width = width;
	this->height = height;
	if (piece_description != nullptr)
	{
		free_piece_description();
	}
	// Create an empty piece description
	piece_description = new char *[height];
	for (int i = 0; i < height; i++)
	{
		piece_description[i] = new char[width];
		for (int j = 0; j < width; j++)
		{
			piece_description[i][j] = empty_symbol;
		}
	}
}

void PieceView::mirror_x()
{
	if (piece_description == nullptr)
	{
		return;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < (width / 2); j++)
		{
			// Flipping values
			char temp = piece_description[i][j];
			piece_description[i][j] = piece_description[i][width - 1 - j];
			piece_description[i][width - 1 - j] = temp;
		}
	}
}
void PieceView::mirror_y()
{
	if (piece_description == nullptr)
	{
		return;
	}
	for (int i = 0; i < height / 2; i++)
	{
		// Flipping pointers
		char *temp = piece_description[i];
		piece_description[i] = piece_description[height - 1 - i];
		piece_description[height - 1 - i] = temp;
	}
}

char PieceView::get_description(int x, int y)
{
	return piece_description[y][x];
}

void PieceView::set_description(int x, int y, char descr)
{
	piece_description[y][x] = descr;
}

std::string PieceView::to_string()
{
	if (piece_description == nullptr)
	{
		// Return empty string if piece is not initialized
		return std::string();
	}
	std::string out;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			out.append(&(piece_description[i][j]), 1);
		}
		out.append("\n");
	}
	return out;
}

void PieceView::copy_piece_description(const PieceView &other)
{
	// Check if piece description copy cannot be done
	if ((other.width != width) || (other.height != height) || (other.piece_description == nullptr) || (piece_description == nullptr))
	{
		return;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// Copying values
			piece_description[i][j] = other.piece_description[i][j];
		}
	}
}

void PieceView::free_piece_description()
{
	if (piece_description != nullptr)
	{
		for (int i = 0; i < height; i++)
		{
			delete[] piece_description[i];
		}
		delete[] piece_description;
	}
}

void Piece::add_piece_view(const PieceView &new_p)
{
	piece_views.push_back((PieceView *)(&new_p));
}