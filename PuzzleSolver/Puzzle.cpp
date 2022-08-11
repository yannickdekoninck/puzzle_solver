#include "Puzzle.h"

PieceView::PieceView(): width(0), height(0)
{
	piece_description = nullptr;
}

PieceView::PieceView(int width, int height)  {
	initialize(width, height);
}

PieceView::~PieceView()
{
	free_piece_description();
}

void PieceView::initialize(int width, int height)
{
	if (piece_description != nullptr){
		free_piece_description();
	}
	// Create an empty piece description
	piece_description = new int* [height];
	for (int i = 0; i < height; i++) {
		piece_description[i] = new int[width];
		for (int j = 0; j < width; j++) {
			piece_description[i][j] = 0;
		}
	}
}

std::string PieceView::to_string()
{
	return std::string();
}

void PieceView::free_piece_description()
{
	if (piece_description != nullptr) {
		for (int i = 0; i < height; i++) {
			delete[] piece_description[i];
		}
		delete[] piece_description;
	}
}
