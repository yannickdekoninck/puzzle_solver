#include "Puzzle.h"

PieceView::PieceView() : width(0), height(0)
{
	piece_description = nullptr;
}

PieceView::PieceView(int width, int height)
{
	initialize(width, height);
}

PieceView::~PieceView()
{
	free_piece_description();
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
